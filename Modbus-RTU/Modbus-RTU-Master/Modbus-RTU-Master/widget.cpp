#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    InterfaceInit();

    //显示历史消息
    connect(ui->HistoryMessageButton,&QPushButton::clicked,[=](){
        ShowHistoricalMessage();
    });
    //定时保存当前窗口信息
    connect(HistoryMessageClearTimer,&QTimer::timeout,[=](){
        ClearCurrentHistoryMessage();
    });

    //数据搜索
    connect(ui->CoilSearchButton,&QPushButton::clicked,[=](){
        Search(1);
    });
    connect(ui->RegisterSearchButton,&QPushButton::clicked,[=](){
        Search(2);
    });
    //打开串口
    connect(ui->SerialSwitchSettingButton,&QPushButton::clicked,[=](){
        GetSerialPortParameters();
        OpenOrCloseSerialPort();
    });
    //串口刷新
    connect(ui->RefreshSerialPortButton,&QPushButton::clicked,[=](){
        RefreshSerialPort();
    });

    //数据发送
    connect(ui->SendMessageButton,&QPushButton::clicked,[=](){
        SendRequestMessage();
    });
    //超时重发
    connect(ResendMessageTimer,&QTimer::timeout,[=](){
        ResendRequestMessage();
    });
    //数据接收,解析
    connect(RtuSerialPort,&QSerialPort::readyRead,[=](){
        RTUReadMessage();
    });

    //清除当前窗口信息
    connect(ui->ClearHistoryMessageButton,&QPushButton::clicked,[=](){
        ClearCurrentHistoryMessage();
    });

    connect(ui->BeginAddressNumber,&QLineEdit::textChanged,[=](){
        if(ui->BeginAddressNumber->text().toInt()+ui->DataNumber->text().toInt() > 65536)
        {
            QMessageBox::warning(this,"提示","请检查起始地址和数量是否合法！",QMessageBox::Ok,QMessageBox::NoButton);
            ui->BeginAddressNumber->clear();
        }

    });
    connect(ui->DataNumber,&QLineEdit::textChanged,[=](){
        if(ui->BeginAddressNumber->text().toInt()+ui->DataNumber->text().toInt() > 65536)
        {
            QMessageBox::warning(this,"提示","请检查起始地址和数量是否合法！",QMessageBox::Ok,QMessageBox::NoButton);
            ui->DataNumber->clear();
        }
    });

}

/***************************显示时间信息**************************/
//时钟函数
void Widget::ShowCurrentTime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString TimeFormat = time.toString(CLOCK_FORMAT);
    ui->ShowCurrentTime->setText(TimeFormat);
}
//时间事件函数
void Widget::timerEvent(QTimerEvent *event)
{
    int tmp = event->timerId();
    if(tmp == timer)
    {
        ShowCurrentTime();
    }
    else if(tmp == ReadMessageTimer)
    {

        if(isOpenSerialPort)
        {
             killTimer(ReadMessageTimer);
             if(isOpenSerialPort)
             {
                 isReceiveResponseMessage = true;
                 ShowResponseMessage(ReceiveMessageArray);
                 ParseResponseMessage(ReceiveMessageArray,RequestMessageArray);
             }
             ReceiveMessageArray.clear();
        }
    }
}
//时间函数
void Widget::TimeInformation()
{
    ui->messageBox->append("");
    ui->messageBox->append("["+QDateTime::currentDateTime().toString(CLOCK_FORMAT)+"]");
}
/***************************界面初始化**************************/
void Widget::InterfaceInit()
{
    //串口
    RtuSerialPort = new QSerialPort(this);
    //串口结构体
    serialport = new SerialPortParameters;
    //报文结构体
    requestmessage = new RequestMessageStruct;

    //界面时间显示
    timer = startTimer(CLOCK_REFRESH);
    settings = new QSettings(INI_FILE_PATH,QSettings::IniFormat);
    settings->setParent(this);

    //初始化历史窗口
    HistoryMessageWindow = new HistoryMessageDialog(this);
    HistoryMessageWindow->setWindowTitle("历史信息");

    //初始化历史窗口清理计时器
    HistoryMessageClearTimer = new QTimer(this);
    HistoryMessageClearTimer->setInterval(600000);
    HistoryMessageClearTimer->start();
    //初始化历史信息保存路径
    HistoryMessagePath = RECORD_PATH;

    //界面可用串口
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort SerialPort;
        SerialPort.setPort(info);
        if(SerialPort.open(QIODevice::ReadWrite))
        {
            ui->SerialPortName->addItem(SerialPort.portName());
            SerialPort.close();
        }
    }

    //设置从站地址背景提示
    ui->SlaveAddressNumber->setPlaceholderText("1-247");
    //限制从站范围为1-247
    ui->SlaveAddressNumber->setValidator(new QIntValidator(1,247,this));

    //设置起始地址背景提示
    ui->BeginAddressNumber->setPlaceholderText("0-65535");
    ui->BeginAddressNumber->setValidator(new QIntValidator(0,65535,this));

    //设置最大数量提示 0x01
    ui->DataNumber->setPlaceholderText("1-2000");
    ui->DataNumber->setValidator(new QIntValidator(1,2000,this));

    //设置消息框为只读
    ui->messageBox->setReadOnly(true);

    //初始化获取数据框
    //设置
    MaxNumberOfDefaultBackground();
    //ui文件设置波特率、数据位、校验位、停止位
    //波特率 9600、19200、115200  默认9600
    //数据位 8、7、6、5       默认8
    //校验位 无校验 奇校验 偶校验   默认无校验
    //停止位 1、2      默认1

    //设置串口打开状态，默认为false
    isOpenSerialPort = false;

    //初始化报文重发次数
    ResendNumber = 0;
    //初始化报文接收判断
    isReceiveResponseMessage = false;
    //报文重发计时器
    ResendMessageTimer = new QTimer(this);
    ResendMessageTimer->setInterval(3000);

    //ini数据初始化显示
    ShowIniData();

    //设置搜索框默认背景
    ui->CoilSearchNumber->setPlaceholderText("0-65535");
    ui->CoilSearchNumber->setValidator(new QIntValidator(0, 65535, this));

    ui->RegisterSearchNumber->setPlaceholderText("0-65535");
    ui->RegisterSearchNumber->setValidator(new QIntValidator(0, 65535, this));
}


//设置最大数量背景提示
void Widget::MaxNumberOfDefaultBackground()
{
    connect(ui->FunctionCodeNumber,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](){
        int FuncCodeNumber;
        FuncCodeNumber = ui->FunctionCodeNumber->currentText().toInt(NULL,16);

        switch(FuncCodeNumber)
        {
        case 0x01:
            //设置0x01背景提示
            ui->DataNumber->setPlaceholderText("1 - 2000");         
            break;
        case 0x03:
            //设置0x03背景提示
            ui->DataNumber->setPlaceholderText("1 - 125");

            break;
        case 0x0f:
            //设置0x0f背景提示
            ui->DataNumber->setPlaceholderText("1 - 1968");
            break;
        case 0x10:
            //设置0x10背景提示
            ui->DataNumber->setPlaceholderText("1 - 123");
            break;
        }
    });
}

/***************************串口设置函数*******************************/
//获取串口参数并放置到串口结构体中
void Widget::GetSerialPortParameters()
{
    //串口名
    serialport->SerialPortSerialName = ui->SerialPortName->currentText();
    //波特率
    switch(ui->BaudRateNumber->currentIndex())
    {
    case 0:
        serialport->SerialPortBaudRate = QSerialPort::Baud9600;
        SerialPortBaudRate = 9600;
        break;
    case 1:
        serialport->SerialPortBaudRate = QSerialPort::Baud19200;
        SerialPortBaudRate = 19200;
        break;
    case 2:
        serialport->SerialPortBaudRate = QSerialPort::Baud115200;
        SerialPortBaudRate = 115200;
        break;
    }
    //数据位
    switch(ui->DataBitsNumber->currentText().toInt())
    {
    case 8:
        serialport->SerialPortDataBits = QSerialPort::Data8;
        break;
    case 7:
        serialport->SerialPortDataBits = QSerialPort::Data7;
        break;
    case 6:
        serialport->SerialPortDataBits = QSerialPort::Data6;
        break;
    case 5:
        serialport->SerialPortDataBits = QSerialPort::Data5;
    }
    //校验位
    QString paritystring;
    paritystring = ui->ParityName->currentText();
    if(paritystring == "无校验")
    {
        serialport->SerialPortParity = QSerialPort::NoParity;
    }
    else if(paritystring == "奇校验")
    {
        serialport->SerialPortParity = QSerialPort::OddParity;
    }
    else if(paritystring == "偶校验")
    {
        serialport->SerialPortParity = QSerialPort::EvenParity;
    }
    //停止位
    switch(ui->StopBitsName->currentText().toInt())
    {
    case 1:
        serialport->SerailPortStopBits = QSerialPort::OneStop;
        break;
    case 2:
        serialport->SerailPortStopBits = QSerialPort::TwoStop;
    }
}
//利用串口结构体初始化串口
void Widget::SerialPortInitialization()
{
    //设置串口参数
    RtuSerialPort->setBaudRate(serialport->SerialPortBaudRate);
    RtuSerialPort->setDataBits(serialport->SerialPortDataBits);
    RtuSerialPort->setParity(serialport->SerialPortParity);
    RtuSerialPort->setStopBits(serialport->SerailPortStopBits);
    //流控制
    RtuSerialPort->setFlowControl(QSerialPort::NoFlowControl);
}
//串口打开或关闭
void Widget::OpenOrCloseSerialPort()
{
   if(ui->SerialSwitchSettingButton->text() == "打开串口")
   {
       //打开串口
       //关闭串口刷新按钮
       ui->RefreshSerialPortButton->setEnabled(false);

       RtuSerialPort->setPortName(serialport->SerialPortSerialName);
       int openFlag = RtuSerialPort->open(QIODevice::ReadWrite);
       if(!openFlag)
       {
           TimeInformation();
           isOpenSerialPort = false;
           ui->messageBox->append("串口打开失败，请重新设置！");
           return;
       }
       else
       {
           TimeInformation();
           isOpenSerialPort = true;
           //设置串口参数
           SerialPortInitialization();
           //关闭串口参数相关控件
           CloseSerialPortParametersBox();
           ui->messageBox->append("串口打开成功！");
       }
       ui->SerialSwitchSettingButton->setText("关闭串口");
   }
   else if(ui->SerialSwitchSettingButton->text() == "关闭串口")
   {
       if(isOpenSerialPort)
       {
           //打开串口刷新按钮
           ui->RefreshSerialPortButton->setEnabled(true);
           RtuSerialPort->clear();
           RtuSerialPort->close();
           isOpenSerialPort = false;

           TimeInformation();
           ui->messageBox->append("串口关闭成功！");
           //打开串口参数相关控件
           OpenSerialPortParametersBox();
           ui->SerialSwitchSettingButton->setText("打开串口");
       }
   }
}
//串口刷新函数
void Widget::RefreshSerialPort()
{
    ui->SerialPortName->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {   //在portBox中显示可用串口
        ui->SerialPortName->addItem(info.portName());
    }
}
//串口参数控件关闭
void Widget::CloseSerialPortParametersBox()
{
    ui->SerialPortName->setEnabled(false);
    ui->BaudRateNumber->setEnabled(false);
    ui->StopBitsName->setEnabled(false);
    ui->DataBitsNumber->setEnabled(false);
    ui->ParityName->setEnabled(false);
}
//串口参数控件开启
void Widget::OpenSerialPortParametersBox()
{
    ui->SerialPortName->setEnabled(true);
    ui->BaudRateNumber->setEnabled(true);
    ui->StopBitsName->setEnabled(true);
    ui->DataBitsNumber->setEnabled(true);
    ui->ParityName->setEnabled(true);
}

/***************************报文相关函数******************************/
int Widget::ReceivingTime()
{
    //RTU报文最大长度
    int maxMessageLength = RTU_MESSAGE_MAX_BYTE;
    //当前波特率
    int currentBaudRate = SerialPortBaudRate;
    int recTime = (8*maxMessageLength*1000/currentBaudRate);
    //返回读取缓冲时间
    //计算读取缓冲时间
    if(currentBaudRate == 115200)
    {
        recTime = recTime*2;
    }
    return recTime;
}

void Widget::RTUReadMessage()
{
    //获取当前接收缓冲时间
    int receiveTime = ReceivingTime();
    //启动计时器
    ReadMessageTimer = startTimer(receiveTime);
    //存入缓冲区
    ReceiveMessageArray.append(RtuSerialPort->readAll());
}

//报文结构体初始化  查询报文
void Widget::RequestMessageStructInitialization()
{
    //从机地址
    QString SlaveAdderss;
    SlaveAdderss = ui->SlaveAddressNumber->text();
    if(SlaveAdderss != NULL)
    {
        requestmessage->SlaveAddress=(quint8)SlaveAdderss.toInt();
    }
    else
    {
        requestmessage->SlaveAddress = (quint8)1;
        ui->messageBox->append("使用默认值，从机地址设为：1");
    }

    //功能码
    int FuncCodeNumber;
    FuncCodeNumber = ui->FunctionCodeNumber->currentText().toInt(NULL,16);
    switch(FuncCodeNumber)
    {
    case 0x01:
        requestmessage->FunctionCode = (quint8)0x01;
        break;
    case 0x03:
        requestmessage->FunctionCode = (quint8)0x03;
        break;
    case 0x0f:
        requestmessage->FunctionCode = (quint8)0x0f;
        break;
    case 0x10:
        requestmessage->FunctionCode = (quint8)0x10;
        break;
    }

    //起始地址
    quint16 BeginAddress;
    BeginAddress = ui->BeginAddressNumber->text().toInt();
    requestmessage->BeginAddress = BeginAddress;
    //数量
    quint16 DataNumber;
    DataNumber = ui->DataNumber->text().toInt();
    requestmessage->DataNumber = DataNumber;
}
//0x01 0x03 正常报文生成
QByteArray Widget::RequestMessageBuild0X010X03(RequestMessageStruct *requestmessage)
{
    //声明字节数组
    QByteArray data;
    data.resize(REQUEST_MESSAGE_LENGTH_0X01_0X03 - 2);
    data[0]=requestmessage->SlaveAddress;
    data[1]=requestmessage->FunctionCode;
    data[2]=(requestmessage->BeginAddress) >> 8;
    data[3]=(requestmessage->BeginAddress) & 0xff;
    data[4]=(requestmessage->DataNumber) >> 8;
    data[5]=(requestmessage->DataNumber) & 0xff;

    quint16 CrcNumber = CRC16Modbus(data,0);

    data.resize(REQUEST_MESSAGE_LENGTH_0X01_0X03);

    data[6]=CrcNumber >> 8;
    data[7]=CrcNumber & 0xff;

    return data;
}

QByteArray Widget::RequestMessageBuild0X0f0X10(RequestMessageStruct *requestmessage,QByteArray Data)
{
    //声明字节数组
    // 设备地址+功能码+起始地址+数量+字节数+n字节数据+差错校验
    // 1+1+2+2+1+n+2

    QByteArray data;
    data.resize(REQUEST_MESSAGE_LENGTH_0X01_0X03 - 1);
    data[0]=requestmessage->SlaveAddress;
    data[1]=requestmessage->FunctionCode;
    data[2]=(requestmessage->BeginAddress) >> 8;
    data[3]=(requestmessage->BeginAddress) & 0xff;
    data[4]=(requestmessage->DataNumber) >> 8;
    data[5]=(requestmessage->DataNumber) & 0xff;
    data[6]=(quint8)Data.size();

    QByteArray Message;
    Message.append(data);
    Message.append(Data);

    quint16 CrcNumber = CRC16Modbus(Message,0);

    Message.append(CrcNumber >> 8);
    Message.append(CrcNumber & 0xff);

    return Message;

}
quint16 Widget::CRC16Modbus(const QByteArray &data,int flag)
{
    static const quint16 crc16Table[] =
    {
        0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
        0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
        0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
        0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
        0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
        0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
        0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
        0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
        0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
        0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
        0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
        0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
        0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
        0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
        0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
        0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
        0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
        0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
        0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
        0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
        0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
        0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
        0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
        0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
        0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
        0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
        0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
        0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
        0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
        0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
        0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
        0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
    };

    quint8 buf;
    quint16 crc16 = 0xFFFF;

    for ( auto i = 0; i < data.size(); ++i )
    {
        buf = data.at( i ) ^ crc16;
        crc16 >>= 8;
        crc16 ^= crc16Table[ buf ];
    }

   auto crcl = crc16&0xFF; //crc低位
   auto crch = crc16>>8;//crc高位
   auto crc161=0xFFFF;
   crc161 = (((crc161&0x0)|crcl)<<8)|(crch);

   if(flag)
   {
    return crc16;
   }
   else
   {
    return crc161;
   }
}

//报文解析
bool Widget::ParseResponseMessage(QByteArray responseMessage,QByteArray RequestMessageArray)
{
    //RequestMessageArray 接收报文

    //长度判断：最大长度、最小长度
    if(responseMessage.size() > RTU_MESSAGE_MAX_BYTE)
    {
        ui->messageBox->append("-----------异常报文----------");
        ui->messageBox->append("报文长度错误，超出RTU最大报文长度！");
        return false;
    }
    if(responseMessage.size() < ABNORMAL_RESPONSE_LENGTH)
    {
        ui->messageBox->append("-----------异常报文----------");
        ui->messageBox->append("报文长度错误,小于RTU最小报文长度！");
        return false;
    }
    //从机地址是否正确
    if(RequestMessageArray[0] != responseMessage[0])
    {
        ui->messageBox->append("-----------异常报文----------");
        ui->messageBox->append("从机地址错误，响应报文与请求报文的从机地址不一致！");
        return false;
    }
    //是否是异常报文
    if(responseMessage.size() == ABNORMAL_RESPONSE_LENGTH)
    {
        //判断异常功能码是否正确
        // 0x81 - 129 | 0x83 - 131 | 0x8f - 143 | 0x90 - 144
        quint8 FuncCodeNumber;
        FuncCodeNumber = (quint8)responseMessage.at(1);
        if(FuncCodeNumber != 129 && FuncCodeNumber != 131 && FuncCodeNumber != 143 && FuncCodeNumber != 144)
        {
            ui->messageBox->append("-----------异常报文----------");
            ui->messageBox->append("异常报文，报文长度错误");
            return false;
        }
        //判断差错码是否正常
        quint8 ErrorCode;
        ErrorCode = (quint8)responseMessage.at(2);
        if(ErrorCode != 1 && ErrorCode != 2 && ErrorCode != 3)
        {
            ui->messageBox->append("异常响应报文，差错码错误！");
            return false;
        }
        //判断校验码是否正常
        quint16 AbnormalMessageCRC;
        AbnormalMessageCRC = BondTwoUint8ToUint16((quint8)responseMessage[3],(quint8)responseMessage[4]);
        QByteArray AbnormalMessageData;
        AbnormalMessageData = responseMessage.left(3);
        quint16 AbnormalMessageCrcCheck;
        AbnormalMessageCrcCheck = CRC16Modbus(AbnormalMessageData,0);
        if(AbnormalMessageCRC != AbnormalMessageCrcCheck)
        {
            ui->messageBox->append("异常响应报文，校验码错误！");
            return false;
        }
        //正常异常响应报文
        ui->messageBox->append("-----------异常响应报文----------");
        QString AbnormalFuncCode ;
        QByteArray temp;
        temp.append(responseMessage[2]);
        AbnormalFuncCode = HexByteArrayToHexString(temp,temp.size(),1);
        ui->messageBox->append("异常功能码为："+AbnormalFuncCode);
        return true;
    }
    //功能码是否合法
    quint8 responseMessageFuncCode;
    responseMessageFuncCode = (quint8)responseMessage[1];
    if(responseMessageFuncCode != 1 && responseMessageFuncCode != 3 && responseMessageFuncCode != 15 && responseMessageFuncCode !=16)
    {
        ui->messageBox->append("-----------异常报文----------");
        ui->messageBox->append("功能码非法，响应报文中功能码非法！");
        return false;
    }
    //请求与响应的功能码是否一致
    quint8 RequestMessageArrayFuncCode;
    RequestMessageArrayFuncCode = (quint8)RequestMessageArray[1];
    if(RequestMessageArrayFuncCode != responseMessageFuncCode)
    {
        ui->messageBox->append("-----------异常报文----------");
        ui->messageBox->append("功能码错误，响应报文与请求报文中的功能码不一致！");
        return false;
    }

    //CRC差错校验
    quint16 responseMessageCRC;
    responseMessageCRC = CRC16Modbus(responseMessage.mid(0,responseMessage.size()-2),0);
    quint16 CrcCheck;
    CrcCheck = BondTwoUint8ToUint16((quint8)responseMessage[responseMessage.size()-2],(quint8)responseMessage[responseMessage.size()-1]);

    if(CrcCheck != responseMessageCRC)
    {
        ui->messageBox->append("-----------异常报文----------");
        ui->messageBox->append("校验码错误，响应报文中校验码错误！");
        return false;
    }

    //与请求报文比较
    switch(responseMessageFuncCode)
    {
    case 1:
    case 3:
        //0x01 0x03
        //正常报文响应长度 1+1+1+n+2
        //响应报文中 数据域字节数 与 实际数据所用字节总数 是否一致
        quint8 responseMessageDataNumber;
        responseMessageDataNumber = responseMessage.size() - 5;
        if((quint8)responseMessage[2] != responseMessageDataNumber)
        {
            ui->messageBox->append("-----------异常报文----------");
            ui->messageBox->append("字节数错误，响应报文中数据域字节数和实际数据字节总数不一致！");
            return false;
        }
        break;
    case 15:
    case 16:
        //0x0f 0x10
        //正常响应正常长度8  1+1+2+2+2
        //起始地址是否一致
        quint16 responseMessageBeginAddress;
        responseMessageBeginAddress=BondTwoUint8ToUint16((quint8)responseMessage[2],(quint8)responseMessage[3]);
        quint16 RequestMessageArrayBeginAddress;
        RequestMessageArrayBeginAddress=BondTwoUint8ToUint16((quint8)RequestMessageArray[2],(quint8)RequestMessageArray[3]);
        if(responseMessageBeginAddress != RequestMessageArrayBeginAddress)
        {
             ui->messageBox->append("-----------异常报文----------");
             ui->messageBox->append("起始地址错误，响应报文中起始地址与请求报文的不一致！");
             return false;
        }
        //查询数量是否一致
        quint16 responseMessageNumber;
        responseMessageNumber=BondTwoUint8ToUint16((quint8)responseMessage[4],(quint8)responseMessage[5]);
        quint16 RequestMessageArrayNumber;
        RequestMessageArrayNumber=BondTwoUint8ToUint16((quint8)RequestMessageArray[4],(quint8)RequestMessageArray[5]);
        if(responseMessageNumber != RequestMessageArrayNumber)
        {
            ui->messageBox->append("-----------异常报文----------");
            ui->messageBox->append("数量错误，响应报文中写入数据数量与请求报文的不一致！");
            return false;
        }
        break;
    }

    //无异常，显示查询报文数据
    //响应报文数据
    QByteArray DataArray;
    DataArray = responseMessage.mid(3,responseMessage.size() - 5);
    //请求报文 起始地址
    quint16 BeginAddress;
    BeginAddress = BondTwoUint8ToUint16((quint8)RequestMessageArray[2],(quint8)RequestMessageArray[3]);
    //请求报文 数据个数
    quint16 DataNumber;
    DataNumber = BondTwoUint8ToUint16((quint8)RequestMessageArray[4],(quint8)RequestMessageArray[5]);
    QString res;
    switch(responseMessageFuncCode)
    {
    case 1:
        res = HexByteArrayToBinString(DataArray,DataNumber);
        UpdateCoilsData(BeginAddress,DataNumber,res);
        ui->messageBox->append("起始地址为："+QString::number(BeginAddress)+" 数量："+QString::number(DataNumber));
        ui->messageBox->append("查询的线圈数据为："+res);
        break;
    case 3:
        res = HexByteArrayToDecString(DataArray);
        UpdateRegistersData(BeginAddress,DataNumber,res);
        ui->messageBox->append("起始地址为："+QString::number(BeginAddress)+" 数量："+QString::number(DataNumber));
        ui->messageBox->append("查询的寄存器数据为："+res);
        break;
    }

    return true;
}

//正常报文发送
void Widget::SendRequestMessage()
{
    //生成报文
    if(isOpenSerialPort)
    {
        int FuncCode;
        FuncCode = ui->FunctionCodeNumber->currentText().toInt(NULL,16);

        switch(FuncCode)
        {
        case 0x01:
        case 0x03:
            RequestMessageStructInitialization();
            RequestMessageArray = RequestMessageBuild0X010X03(requestmessage);
            break;
        case 0x0f:
        case 0x10:
            QByteArray Data;
            if(ui->FunctionCodeNumber->currentText().toInt(NULL,16) == 0x0f)
            {
                   Data  = InputCoils();
            }
            else if(ui->FunctionCodeNumber->currentText().toInt(NULL,16) == 0x10)
            {
                   Data  = InputRegisters();
            }
            RequestMessageStructInitialization();
            RequestMessageArray = RequestMessageBuild0X0f0X10(requestmessage,Data);
            break;
        }
    }
    else
    {
        TimeInformation();
        ui->messageBox->append("串口未打开");
        return;
    }

    //报文发送
    RtuSerialPort->write(RequestMessageArray);
    ResendMessageTimer->start();
    QString res;
    res= HexByteArrayToHexString(RequestMessageArray,RequestMessageArray.size(),1);
    TimeInformation();
    ui->messageBox->append("报文发送： "+res);
    //设置接收报文状态为false
    isReceiveResponseMessage = false;
}
//报文重发
void Widget::ResendRequestMessage()
{
    if(!isReceiveResponseMessage)
    {
        if(ResendNumber < RESEND_MESSAGE_MAX_NUMBER)
        {
            RtuSerialPort->write(RequestMessageArray);
            TimeInformation();
            ui->messageBox->append("从站无响应，第"+QString::number(1+ResendNumber)+"次重发报文！");
            ResendNumber++;
        }
        else
        {
            TimeInformation();
            ui->messageBox->append("从站无响应，重传无效！");
            //重置重传次数
            ResendNumber = 0;
            ResendMessageTimer->stop();
        }

    }
}
//接收报文显示
void Widget::ShowResponseMessage(QByteArray responseMessage)
{
    QString res = HexByteArrayToHexString(responseMessage,responseMessage.size(),1);
    TimeInformation();
    ui->messageBox->append("报文接收： "+res);
}

//重写界面关闭事件
void Widget::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton close;
    close = QMessageBox::question(this,"提示","确认退出程序？",QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

    if(close == QMessageBox::Yes)
    {
        //关闭界面，保存日志
        WriteHistoricalMessage(HistoryMessagePath);
        event->accept();
    }
    else
    {
        event->ignore();
    }

}
//显示历史消息
void Widget::ShowHistoricalMessage()
{
    HistoryMessagePath = QFileDialog::getOpenFileName(this,"打开文件","../Modbus-RTU-Master","TEXT(*.txt)");

    if(HistoryMessagePath == NULL)
    {
        //使用默认路径
        TimeInformation();
        HistoryMessagePath = RECORD_PATH;
        ui->messageBox->append("使用默认路径！");
        ui->messageBox->append(HistoryMessagePath);
    }
    else
    {
        TimeInformation();
        ui->messageBox->append("文件路径设置成功！");
        ui->messageBox->append(HistoryMessagePath);

    }
    HistoryMessageWindow->ShowHistoryMessage(HistoryMessagePath);

}
//保存历史消息到文件
void Widget::WriteHistoricalMessage(QString path)
{
    //消息框内显示清除的时间，和文件夹路径
    QFileInfo info(path);
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageBox->append("保存至路径：" + info.filePath() + "\n文件名称：" + info.fileName()
                            + "\n文件大小：" + QString::number(info.size()) + "\n创建日期：" + info.created().toString("yyyy-MM-dd hh:mm:ss")
                            + "\n最后保存日期：" + info.lastModified().toString("yyyy-MM-dd hh:mm:ss") + "\n");

    //将历史记录写入文件，使用追加方式写入文件
    QFile file(path);
    file.open(QFileDevice::Append);
    file.write(ui->messageBox->toPlainText().toUtf8().data());
    //消息分块
    file.write("\n\n");
    //清除消息框中的内容
    ui->messageBox->clear();
    file.close();
}
//清除当前窗口的信息
void Widget::ClearCurrentHistoryMessage()
{
    //将历史记录写入文件，使用追加方式写入文件
    QFile file(HistoryMessagePath);
    file.open(QFileDevice::Append);
    file.write(ui->messageBox->toPlainText().toUtf8().data());
    //消息分块
    file.write("\n\n");
    //清除消息框中的内容
    ui->messageBox->clear();
    file.close();
}
//输入线圈数据
QByteArray Widget::InputCoils()
{
    /***********************************获取用户的线圈输入（二进制）*********************************/
    //判断字符串是否合法返回值，默认为false
    //bool isLegal = false;

    //获取输入框内的字符串,默认为空
    QString writeCoils = NULL;
    //字符串长度，默认为0
    int writeCoilsLength = 0;
    //初始化对话框
    InputDataDialog *input = new InputDataDialog;
    input->setModal(true);
    input->hide();
    //发送按钮暂时关闭
    while((writeCoils.isEmpty())
         || (ui->DataNumber->text().toInt() != writeCoilsLength)
          )//|| (!isLegal))
    {
        //输入标题
        QString inputDialogTitle = "0x0f 线圈写入";
        //输入提示
        QString writeGuide = "请输入" + ui->DataNumber->text() + "个线圈的数据：";
        //获取字符串
        input->show();
        writeCoils = input->getText(inputDialogTitle,writeGuide);

        //获取字符串长度
        writeCoilsLength = writeCoils.length();
        //判断字符串合法性
        //isLegal = coilsLegality(writeCoils);
    }

    delete input;
    /*************************************处理用户的线圈输入***********************************/
    //求出字节数
    int numOfByte = (writeCoilsLength + 7) / 8;

    //对字符串空位进行补0
    for(int i = 1; i <= (8*numOfByte - writeCoilsLength); i++)
    {
        writeCoils += '0';
    }

    /***********************************将输入的线圈存入字节数组***********************************/
    //创建线圈输入数组
    QByteArray coilsInputArr;
    coilsInputArr.resize(numOfByte);

    //字节：1字节*numOfByte
    for(int i = 0; i < numOfByte; i++)
    {
        //对8位1字节进行反转处理
        QString vector = writeCoils.mid((8 * i),8);
        //字节反转
        byteReverse(vector);
        //存入请求报文数组
        coilsInputArr[i] = vector.toInt(NULL,2);
    }

    return coilsInputArr;
}
//输入寄存器数据
QByteArray Widget::InputRegisters()
{
    //获取输入寄存器数量
    int num = ui->DataNumber->text().toInt();
    //需要的字节数，一个寄存器需要2字节
    int numOfByte = 2*num;
    //创建寄存器输入数组
    QByteArray RegistersInputArr;
    RegistersInputArr.resize(numOfByte);

    for(int i = 0; i < num; i++)
    {

        //获取输入框内的字符串,默认为空
        QString writeRegister = NULL;

        //初始化模态对话框
        InputDataDialog *input = new InputDataDialog;
        input->setModal(true);

        input->hide();
        //发送按钮暂时关闭
        ui->SendMessageButton->setEnabled(false);

        while(writeRegister.isEmpty() )//|| (!isLegal))
        {
            //输入标题
            QString inputDialogTitle = "0x10 寄存器写入";
            //输入提示
            QString writeGuide = "请输入第" + QString::number(i + 1) + "个寄存器的数据：";
            //获取字符串
            input->show();

            writeRegister = input->getText(inputDialogTitle,writeGuide);
        }
        delete input;
        //发送按钮打开
        ui->SendMessageButton->setEnabled(true);

        //转化为2进制字符串，不足补0，凑足16位
        writeRegister = QString("%1").arg((quint16)writeRegister.toInt(NULL,10),16,2,QLatin1Char('0'));
        //前8位为一个字节
        RegistersInputArr[2*i] = writeRegister.mid(0,8).toInt(NULL,2);
        //后8位为一个字节
        RegistersInputArr[2*i + 1] = writeRegister.mid(8,8).toInt(NULL,2);
    }
    return RegistersInputArr;
}
//字节反转函数
void Widget::byteReverse(QString &coils)
{
    // 定义临时字符变量
    QChar temp;

    for(int i=0; i < 4; i++)
    {
        temp = coils[i];        // 将第i个元素存入临时字符变量
        coils[i] = coils[8-i-1];  // 将第i个字符元素和第n-i-1个元素对调
        coils[8-i-1] = temp;    // 将临时字符变量的值赋给第n-i-1个元素
    }
}
quint16 Widget::BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum)
{
    quint16 bondNum = (preNum << 8) | afterNum;
    return bondNum;
}
//16进制数组转字符串为pattern=0不加空格，pattern=1位加空格
QString Widget::HexByteArrayToHexString(QByteArray HexByteArr,int ConvertLen, int pattern = 0)
{
    //获得目标数组大小
    int HexByteArrSize = HexByteArr.size();
    //判断长度是否合法，如果长度大于数组长度，则设为数组长度，小于0则设置为0
    if(ConvertLen > HexByteArrSize)
    {
        ConvertLen = HexByteArrSize;
    }
    else if(ConvertLen < 0)
    {
        ConvertLen = 0;
    }

    //声明目标字符串
    QString readMes = NULL;

    for(int i = 0; i < ConvertLen; i++)
    {
        readMes += QString("%1").arg((quint8)HexByteArr.at(i),2,16,QLatin1Char('0'));
        //判断转换的模式
        if(pattern == 1)
        {
            readMes += " ";
        }
    }

    //返回转化后的十六进制字符串
    return readMes;
}


//将ini中的数据展示到表格
void Widget::ShowIniData()
{
    for(int i = 0; i < (ADDRESS_MAX + 1); i++)
    {
        //地址设置
        QString adr =  "0x" + QString("%1").arg(i,4,16,QLatin1Char('0'));
        ui->CoilsDataTable->setItem(0,i, new QTableWidgetItem(QString(adr)));
        ui->CoilsDataTable->item(0,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->RegistersDataTable->setItem(0,i, new QTableWidgetItem(QString(adr)));
        ui->RegistersDataTable->item(0,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //读出线圈数据
        QString coilData = settings->value("Section" + QString::number(i+1) + "/coil").toString();
        //读出寄存器数据
        QString registerData = settings->value("Section" + QString::number(i+1) + "/regi").toString();

        //在线圈数据表中显示数据
        if(coilData == "1")
        {
            coilData = "ON";
        }
        else
        {
            coilData = "OFF";
        }
        ui->CoilsDataTable->setItem(1,i,new QTableWidgetItem(coilData));
        //设置表格内文字水平+垂直对齐
        ui->CoilsDataTable->item(1,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //在寄存器数据表中显示数据
        ui->RegistersDataTable->setItem(1,i,new QTableWidgetItem(registerData));
        //设置表格内文字水平+垂直对齐
        ui->RegistersDataTable->item(1,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
}

void Widget::Search(int type)
{
    //1为线圈数据表搜索，2为寄存器数据表搜索
    if(type == 1)
    {
        //获取用户输入的搜索地址
        int coilIndex = ui->CoilSearchNumber->text().toInt(NULL,10);

        //获取搜索位置的指针
        QTableWidgetItem *coilItem = ui->CoilsDataTable->item(NULL,coilIndex);

        //将数据表的显示设定为指定指针
        ui->CoilsDataTable->setCurrentItem(coilItem);
        //滚动到指向位置，并将指定位置显示在表格顶部
        ui->CoilsDataTable->scrollToItem(coilItem,QAbstractItemView::PositionAtCenter);
    }
    else
    {
        //获取用户输入的搜索地址
        int registerIndex = ui->RegisterSearchNumber->text().toInt(NULL,10);

        //获取搜索位置的指针
        QTableWidgetItem *registerItem = ui->RegistersDataTable->item(NULL,registerIndex);

        //将数据表的显示设定为指定指针
        ui->RegistersDataTable->setCurrentItem(registerItem);
        //滚动到指向位置，并将指定位置显示在表格顶部
        ui->RegistersDataTable->scrollToItem(registerItem,QAbstractItemView::PositionAtCenter);
    }
}

QString Widget::HexByteArrayToBinString(QByteArray DataArray,quint16 DataNumber)
{
    QString dataObtained;
    //取出所读的多个线圈，并显示，数据从第九位开始
    for(int i = 0; i < DataArray.size(); i++)
    {
        //先转化为2进制字符串
        QString str = QString::number((quint8)DataArray.at(i),2);
        //再转化为2进制整形，由二进制整形转化为8位2进制字符串前面自动补0，从而保证8位
        str = QString("%1").arg((quint8)str.toInt(NULL,2),8,2,QChar('0'));
        //8bit字节倒转
        byteReverse(str);
        //添加到数据中
        dataObtained += str;
    }
    //去除填充的0位，读出请求报文请求的线圈数
    dataObtained = dataObtained.left(DataNumber);

    return dataObtained;

}
QString Widget::HexByteArrayToDecString(QByteArray DataArray)
{
    QString dataObtained;

    for(int i = 0; i < DataArray.size(); i += 2)
    {
        dataObtained += QString::number(BondTwoUint8ToUint16((quint8)DataArray.at(i),(quint8)DataArray.at(i+1)));
        dataObtained += " ";
    }

    return dataObtained.left(dataObtained.size()-1);
}
void Widget::WriteCoilsData(int Column, QString CoilData)
{
    //更新ini文件数据
    settings->setValue("Section" + QString::number(Column + 1) + "/coil",CoilData);
    //更新线圈数据表中数据
    if(CoilData == "1")
    {
        CoilData = "ON";
    }
    else
    {
        CoilData = "OFF";
    }
    ui->CoilsDataTable->setItem(1,Column,new QTableWidgetItem(CoilData));
    //设置表格内文字水平+垂直对齐
    ui->CoilsDataTable->item(1,Column)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
}
void Widget::UpdateCoilsData(quint16 BeginAddress, quint16 DataNumber, QString DataString)
{
    //锁住写入线圈数据信号，进行阻塞
    ui->CoilsDataTable->blockSignals(true);
    for(int i=0;i<DataNumber;i++)
    {
        int Column = BeginAddress + i;
        QString coilData = DataString.at(i);
        WriteCoilsData(Column,coilData);
    }
    //解锁写入线圈数据信号
    ui->CoilsDataTable->blockSignals(false);
}
//写寄存器
void Widget::WriteRegistersData(int Column, QString registerData)
{
    //更新ini文件数据
    settings->setValue("Section" + QString::number(Column + 1) + "/regi",registerData);
    //更新线圈数据表中数据
    ui->RegistersDataTable->setItem(1,Column,new QTableWidgetItem(registerData));
    //设置表格内文字水平+垂直对齐
    ui->RegistersDataTable->item(1,Column)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
}
void Widget::UpdateRegistersData(quint16 BeginAddress, quint16 DataNumber, QString DataString)
{
    //锁住写入寄存器数据信号，进行阻塞
    ui->RegistersDataTable->blockSignals(true);
    //写入寄存器
    QString temp;
    int j=0;
    for(int i=0;i<DataNumber;i++)
    {
        while(j< DataString.size() && DataString[j] != ' ')
        {
            temp +=DataString[j];
            j++;
        }
        WriteRegistersData(BeginAddress+i,temp);
        temp.clear();
        j++;
    }
    //解锁写入寄存器数据信号
    ui->RegistersDataTable->blockSignals(false);
}
Widget::~Widget()
{
    delete ui;
}
