#include "widget.h"
#include "ui_widget.h"
#include "historymessagedialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(QSize(770,850));

    //设置消息框为只读类型
    ui->messageEdit->setReadOnly(true);

    //时钟刷新计时器打开
    clock = startTimer(CLOCK_REFRESH);
    RecordTimer = new QTimer(this);
    RecordTimer->setInterval(600000);
    RecordTimer->start();

    //指针分配内存
    PointerManagement(1);

    //初始化界面设置
    InterfaceInit();

    //1. 点击串口按钮触发槽函数
    connect(ui->portButton,&QPushButton::clicked,this,&Widget::PortButton);
    //3. 当接收到来自串口的消息时所触发的报文缓存槽函数
    connect(serialPort,&QSerialPort::readyRead,[=](){
        RTUReadMessage();
    });
    //2. 串口断开时触发串口断开检测函数
    connect(serialPort,static_cast<void(QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error)
            ,this,&Widget::handleSerialError);

    //6. 点击搜索按钮触发的槽函数
    connect(ui->coilSearchPushButton,&QPushButton::clicked,[=](){
        Search(1);
    });
    connect(ui->registerSearchPushButton,&QPushButton::clicked,[=](){
        Search(2);
    });

    //消息框更新显示槽函数
    connect(ui->messageEdit,&QTextEdit::textChanged,[=](){
         ui->messageEdit->moveCursor(QTextCursor::End);
    });

    //4. 点击查看历史消息，启动查看历史消息函数
    connect(ui->historyButton,&QPushButton::clicked,[=](){
        ViewHistoricalMessage();
    });

    //5. 点击清除窗口按钮时，启动清除消息窗口函数
    connect(ui->clearButton,&QPushButton::clicked,[=](){
        //清除消息窗口函数
        ClearMessageWin();
    });

    //6. 日志自动记录
    connect(RecordTimer,&QTimer::timeout,[=](){
        WriteHistoricalMessage();
    });
}

/*****************************************************时间****************************************************/
//1. 时钟函数
void Widget::showDateTime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString(CLOCK_FORMAT);
    ui->dateTimeEdit->setText(str);
}

//2. 时间信息函数
void Widget::TimeInformation()
{
    ui->messageEdit->append("");
    ui->messageEdit->append("[" + QDateTime::currentDateTime().toString(CLOCK_FORMAT) + "]");
}

//3. 时间事件函数
void Widget::timerEvent(QTimerEvent *event)
{
    int tmp = event->timerId();

    if(tmp == clock)
    {
        showDateTime();
    }
    else if(tmp == ReadMessageTime)
    {
        killTimer(ReadMessageTime);
        //当串口为打开状态时解析，如果关闭了就不解析
        if(*serialPortStatus == 1)
        {
            RTUAnalysisMessage(bufferArray);
        }

        bufferArray.clear();
    }

}

/***************************************************初始化*****************************************************/
//1. 初始化界面设置
void Widget::InterfaceInit()
{
    /***********************************串口号**********************************/
    //获取当前可用串口，并设置到选项中
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serialPort;
        serialPort.setPort(info);
        //判断该串口是否被占用
        if(serialPort.open(QIODevice::ReadWrite))
        {
            ui->portNumberBox->addItem(serialPort.portName());
            serialPort.close();
        }
    }

    /**********************************本机地址**********************************/
    //设置默认地址的背景提示
    ui->localAddressEdit->setPlaceholderText("1 - 247");
    //限制从站地址范围为1-247
    ui->localAddressEdit->setValidator(new QIntValidator(1, 247, this));

    /***********************************波特率**********************************/
    QStringList baudList;
    //设置波特率选项栏，默认选择第三项：9600
    baudList <<"9600"<<"19200"<<"115200";
    ui->baudBox->addItems(baudList);
    //默认波特率9600
    ui->baudBox->setCurrentIndex(0);

    /************************************校验**********************************/
    QStringList parityList;
    //设置校验选项栏，默认选择无
    parityList<<"无校验"<<"奇校验"<<"偶校验";
    ui->parityBox->addItems(parityList);
    //默认无校验
    ui->parityBox->setCurrentIndex(0);

    /***********************************数据位**********************************/
    QStringList dataBitsList;
    //设置数据位选项栏，默认选择8位
    dataBitsList<<"5"<<"6"<<"7"<<"8";
    ui->dataBitsBox->addItems(dataBitsList);
    //默认数据位为8
    ui->dataBitsBox->setCurrentIndex(3);

    /***********************************停止位**********************************/
    QStringList stopBitsList;
    //停止位默认选择1位
    stopBitsList<<"1"<<"2";
    ui->stopBitsBox->addItems(stopBitsList);
    //默认停止位是1
    ui->stopBitsBox->setCurrentIndex(0);

    /***********************************数据表**********************************/
    //设置表头
    QStringList TableHeader;
    TableHeader<<"地址"<<"数据";
    ui->coilTableWidget->setVerticalHeaderLabels(TableHeader);
    ui->coilTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->registerTableWidget->setVerticalHeaderLabels(TableHeader);
    ui->registerTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    /***********************************搜索框**********************************/
    //设置默认地址的背景提示
    ui->coilLineEdit->setPlaceholderText("0-65535");
    ui->regisetLineEdit->setPlaceholderText("0-65535");
    //设置搜索地址的范围
    ui->coilLineEdit->setValidator(new QIntValidator(0, 65535, this));
    ui->regisetLineEdit->setValidator(new QIntValidator(0, 65535, this));

    //显示ini文件数据到数据表
    ReadOutIniData();

    /**********************************控件权限**********************************/
    //串口号、波特率、数据位、停止位、校验位的输入框打开、串口按钮设置为打开
    boxDisconnect();
}

/*************************************************指针管理*****************************************************/
//1. 指针分配内存与删除函数
//   pattern是模式，0表示清理，1表示分配
void Widget::PointerManagement(int pattern)
{
    if(pattern == 0)
    {
        //清空内存
        delete HistoryMessageWindow;
        delete serialPort;
        delete serialPortStatus;
        delete baudRate;
        delete settings;

        return;
    }

    //pattern为1
    //初始化历史消息窗口对象
    HistoryMessageWindow = new HistoryMessageDialog(this);
    HistoryMessageWindow->setWindowTitle("历史信息");

    //初始化端口
    serialPort = new QSerialPort;
    //初始化端口状态标志默认为0
    serialPortStatus = new int(0);
    //初始化当前波特率
    baudRate = new int(0);
    //初始化设置对象
    settings = new QSettings(INIFILE_PATH,QSettings::IniFormat);

}

/***********************************************界面控件权限设置*************************************************/
//1. 输入框关闭，串口按钮设置为关闭函数
void Widget::boxConnect()
{
    //本机地址、串口号、波特率、数据位、停止位、校验位的输入框关闭
    ui->localAddressEdit->setEnabled(false);
    ui->portNumberBox->setEnabled(false);
    ui->baudBox->setEnabled(false);
    ui->dataBitsBox->setEnabled(false);
    ui->stopBitsBox->setEnabled(false);
    ui->parityBox->setEnabled(false);
    //设置串口按钮为”关闭串口“
    ui->portButton->setText("关闭串口");
}

//2. 输入框开启，串口按钮设置为打开函数
void Widget::boxDisconnect()
{
    //本机地址、串口号、波特率、数据位、停止位、校验位的输入框打开
    ui->localAddressEdit->setEnabled(true);
    ui->portNumberBox->setEnabled(true);
    ui->baudBox->setEnabled(true);
    ui->dataBitsBox->setEnabled(true);
    ui->stopBitsBox->setEnabled(true);
    ui->parityBox->setEnabled(true);
    //设置串口按钮为”打开串口“
    ui->portButton->setText("打开串口");
}

/*************************************************串口配置连接**************************************************/
//1. 串口按钮函数
void Widget::PortButton()
{
    //判断当前串口按钮状态，显示"打开串口"则进行打开操作，显示"关闭串口"则进行关闭操作
    if(ui->portButton->text() == "关闭串口")
    {
        PortDisConnect();

        return;
    }

    //初始化串口配置参数结构体
    portParameters portPara;
    portStructInitialize(&portPara);
    //进行打开操作，成功返回true，失败返回false
    bool portSetStatus = PortConnect(&portPara);
    if(portSetStatus == true)
    {
        //调整串口状态为打开
        *serialPortStatus = 1;
        //调整按钮，输入框关闭，发送按钮打开，设置串口按钮为”关闭串口“
        boxConnect();
        //输出成功提示信息
        OpenSuccessPrompt();
    }
    else
    {
        //输出失败提示信息
        OpenFailurePrompt();
    }

}

//2. 串口参数结构体初始化函数
void Widget::portStructInitialize(portParameters *structPt)
{
    //设置本机地址
    if(ui->localAddressEdit->text() == NULL)
    {
        structPt->localAddress = 1;
    }
    else
    {
        structPt->localAddress = ui->localAddressEdit->text().toInt();
    }
    structPt->portNumber = ui->portNumberBox->currentText();       //串口号

    //设置波特率、数据位、停止位、校验位
    //波特率
    switch (ui->baudBox->currentIndex())
    {
    case 0:
    {
        structPt->baudRate = QSerialPort::Baud9600;
        *baudRate = 9600;
        break;
    }
    case 1:
    {
        structPt->baudRate = QSerialPort::Baud19200;
        *baudRate = 19200;
        break;
    }
    case 2:
    {
        structPt->baudRate = QSerialPort::Baud115200;
        *baudRate = 115200;
        break;
    }
    default:
        break;
    }

    //数据位
    switch (ui->dataBitsBox->currentIndex())
    {
    case 0:
    {
        structPt->dataBits = QSerialPort::Data5;
        break;
    }
    case 1:
    {
        structPt->dataBits = QSerialPort::Data6;
        break;
    }
    case 2:
    {
        structPt->dataBits = QSerialPort::Data7;
        break;
    }
    case 3:
    {
        structPt->dataBits = QSerialPort::Data8;
        break;
    }
    default:
        break;
    }

    //停止位
    switch (ui->stopBitsBox->currentIndex())
    {
    case 0:
    {
        structPt->stopBits = QSerialPort::OneStop;
        break;
    }
    case 1:
    {
        structPt->stopBits = QSerialPort::TwoStop;
        break;
    }
    default:
        break;
    }

    //校验位
    switch (ui->parityBox->currentIndex())
    {
    case 0:
    {
        structPt->parity = QSerialPort::NoParity;
        break;
    }
    case 1:
    {
        structPt->parity = QSerialPort::OddParity;
        break;
    }
    case 2:
    {
        structPt->parity = QSerialPort::EvenParity;
        break;
    }
    default:
        break;
    }
}

//3. 串口连接函数
bool Widget::PortConnect(portParameters *structPt)
{
    //设置串口号
    serialPort->setPortName(structPt->portNumber);

    //如果打开失败则返回false
    if(!serialPort->open(QIODevice::ReadWrite))
    {
        return false;
    }

    //如果打开成功，则设置波特率、数据位、停止位、校验位
    //波特率
    serialPort->setBaudRate(structPt->baudRate);

    //数据位
    serialPort->setDataBits(structPt->dataBits);

    //停止位
    serialPort->setStopBits(structPt->stopBits);

    //校验位
    serialPort->setParity(structPt->parity);

    //流控制
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    return true;
}

//4. 串口关闭函数
void Widget::PortDisConnect()
{
    //调整串口状态为关闭
    *serialPortStatus = 0;
    //清空缓存区
    bufferArray.clear();
    //关闭串口、清除串口
    serialPort->clear();
    serialPort->close();
    //调整按钮，输入框打开，发送按钮关闭，设置串口按钮为”打开串口“
    boxDisconnect();
    //提示关闭串口信息
    ClosePortPrompt();
}

//5. 串口断开检测函数
void Widget::handleSerialError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this,"Error","串口连接中断，请检查是否正确连接！");
        //时间
        TimeInformation();
        //消息窗口显示信息
        ui->messageEdit->append("串口连接中断，请检查是否正确连接！");
        PortDisConnect();
    }
}

/*************************************************提示信息函数**************************************************/
//1. 提示串口打开成功函数
void Widget::OpenSuccessPrompt()
{
    QMessageBox::information(this,"提示","串口打开成功！",QMessageBox::Ok);
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("成功打开串口! 串口号：" + ui->portNumberBox->currentText());
}

//2. 提示串口打开失败函数
void Widget::OpenFailurePrompt()
{
    QMessageBox::warning(this,"提示","串口打开失败！请检查串口！",QMessageBox::Ok);
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("串口打开失败！请检查串口！");
}

//3. 提示串口关闭函数
void Widget::ClosePortPrompt()
{
    QMessageBox::information(this,"提示","串口已关闭！",QMessageBox::Ok);
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("已关闭串口：" + ui->portNumberBox->currentText());
}

//4. 提示没有文件路径函数
void Widget::NoFilePathPrompt()
{
    //时间
    TimeInformation();
    //显示暂无文件路径，请先选择路径进行保存
    QMessageBox::information(this,"提示","无文件路径!，请先选择路径进行保存！",QMessageBox::Ok);
    //消息窗口显示信息
    ui->messageEdit->append("无文件路径!，请先选择路径进行保存！");
}

//5. 提示文件路径设置成功函数
void Widget::PathSettingSuccessPrompt()
{
    //时间
    TimeInformation();
    QMessageBox::information(this,"提示","文件路径设置成功!",QMessageBox::Ok);
    //消息窗口显示信息
    ui->messageEdit->append("文件路径设置成功!");
}

//6. 提示文件打开失败函数
void Widget::FailedOpenFilePrompt()
{
    //时间
    TimeInformation();
    QMessageBox::information(this,"提示","文件打开失败!",QMessageBox::Ok);
    //消息窗口显示信息
    ui->messageEdit->append("文件打开失败!");
}

//7. 文件信息函数，给出文件的文件名、地址、文件大小、创建日期和最后保存日期
void Widget::FileInformation()
{
    QFileInfo info(path);
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("保存至路径：" + info.filePath()
                            + "\n文件名称：" + info.fileName()
                            + "\n文件大小：" + QString::number(info.size())
                            + "\n创建日期：" + info.created().toString("yyyy-MM-dd hh:mm:ss")
                            + "\n最后保存日期：" + info.lastModified().toString("yyyy-MM-dd hh:mm:ss") + "\n");
}

//8. 显示请求报文函数
void Widget::ShowRequstMessage(QString Message)
{
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("收到来自串口 "
                            + ui->portNumberBox->currentText()
                            + " 的报文："
                            + Message);
}

/**************************************************消息处理函数*************************************************/
//1. 清除消息窗口函数
void Widget::ClearMessageWin()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"提示","确认要清除消息窗口?",
                                  QMessageBox::Yes|QMessageBox::No,
                                  QMessageBox::No);
    //如果选择确认，则清除消息窗口，并将数据保存到文件中
    if(reply == QMessageBox::Yes)
    {
        //记录清除窗口时间
        TimeInformation();
        //显示清除窗口
        ui->messageEdit->append("清除消息窗口！");
        //将现有历史记录写入文件
        WriteHistoricalMessage();
    }
}

//2. 查看历史消息函数
void Widget::ViewHistoricalMessage()
{

    if(path != NULL)
    {
        //打开显示窗口显示历史记录内容，传入路径参数
        HistoryMessageWindow->ShowHistoricalMessage(path);
        return;
    }
    //如果路径为空，提示没有文件路径
    NoFilePathPrompt();
    //让其选择文本文件路径
    path =  QFileDialog::getOpenFileName(this,"打开文件","../ModBus_RTU_slaver","TEXT(*.txt)");
    //如果为空，提示打开失败
    if(path == NULL)
    {
        FailedOpenFilePrompt();
        path = RECORD_PATH;
        ui->messageEdit->append("使用默认路径！");
        HistoryMessageWindow->ShowHistoricalMessage(path);
    }
    else
    {
        //提示文件路径设置成功
        PathSettingSuccessPrompt();
        //打开显示窗口显示历史记录内容，传入路径参数
        HistoryMessageWindow->ShowHistoricalMessage(path);
    }

}

//3. 写历史消息函数
void Widget::WriteHistoricalMessage()
{
    if(path.isEmpty())
    {
            path = RECORD_PATH;
    }
    //将历史记录写入文件，使用追加方式写入文件
    QFile file(path);
    file.open(QFileDevice::Append);
    file.write(ui->messageEdit->toPlainText().toUtf8().data());
    //消息分块
    file.write("\n\n");

    //清除消息框中的内容
    ui->messageEdit->clear();
    file.close();

    return;
}

/**************************************************读取报文函数*************************************************/
//1. 设置报文接收缓冲时间
int Widget::ReceivingTime()
{
    //RTU报文最大长度
    double maxMessageLength = RTU_MESSAGE_MAX_BYTE;
    //当前波特率
    double currentBaudRate = *baudRate;
    //计算读取缓冲时间
    int recTime = (8*maxMessageLength*1000/currentBaudRate);
    //返回读取缓冲时间
    return recTime;
}

//2. 报文缓存区
void Widget::RTUReadMessage()
{
    //获取当前接收缓冲时间
    int receiveTime = ReceivingTime();
    //启动计时器
    ReadMessageTime = startTimer(receiveTime);
    //存入缓冲区
    bufferArray.append(serialPort->readAll());
}

/**************************************************解析报文函数*************************************************/
//1. 解析请求报文
bool Widget::RTUAnalysisMessage(QByteArray MessageArray)
{
    bool analysisResult = false;
    /**************************************分析报文*************************************/
    //1. 先判断接收到的报文长度是否合法，合法最小长度为读取请求报文，为8字节
    if(MessageArray.size() < MINIMUM_MESSAGE_LENGTH || MessageArray.size() > RTU_MESSAGE_MAX_BYTE)
    {
        //消息窗口显示信息
        QString res = HexByteArrayToHexString(MessageArray,MessageArray.size(),1);
        ShowRequstMessage(res);
        ui->messageEdit->append("报文长度不合法！");
        return false;
    }

    //分析出公共数据项
    //初始化请求报文基础信息结构体
    MessageBasicInformation MessBasicInfo;
    //将请求报文基础信息存入结构体
    //  :报文长度、目的地址、功能码、起始地址、数量项、报文的CRC校验码
    messStructInitialize(&MessBasicInfo, MessageArray);

    /************************************显示收到的报文**********************************/
    //初始化报文字符串
    QString readMessage;
    //将十六进制数据转化成字符串，加空格
    readMessage = HexByteArrayToHexString(MessageArray, MessBasicInfo.Size, 1);
    //显示
    ShowRequstMessage(readMessage);

    /***************************************解析报文*************************************/
    //1. 判断CRC校验码是否正确，如果错误则返回
    bool judgeCRC = JudgeCRC(&MessBasicInfo, MessageArray);
    if(judgeCRC == false)
    {
        return false;
    }

    //2. 判断从站地址和本机地址是否匹配
    if(localAddress != MessBasicInfo.SlaveAddress)
    {
        return false;
    }

    //到此报文长度合法、传输无误、目标地址是本机
    //3. 判断功能码合法性
    if(MessBasicInfo.FuncCode != 0x01
            && MessBasicInfo.FuncCode != 0x03
            && MessBasicInfo.FuncCode != 0x0f
            && MessBasicInfo.FuncCode != 0x10)
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(MessBasicInfo.SlaveAddress, MessBasicInfo.FuncCode, 1, 1);
        return false;
    }

    //到此功能码是合法的
    //4. 判断合法功能码的类型，并进行后续操作
    switch(MessBasicInfo.FuncCode)
    {
    case 0x01:
    {
        //功能码0X01和0X03请求报文解析函数
        analysisResult = AnalysisMessage0X010X03(&MessBasicInfo, 41);
        break;
    }

    case 0x03:
    {
        //功能码0X01和0X03请求报文解析函数
        analysisResult = AnalysisMessage0X010X03(&MessBasicInfo, 43);
        break;
    }

    case 0x0f:
    {
        //功能码0X0F请求报文解析函数
        analysisResult = AnalysisMessage0X0F(&MessBasicInfo, MessageArray);
        break;
    }

    case 0x10:
    {
        //功能码0X10请求报文解析函数
        analysisResult = AnalysisMessage0X10(&MessBasicInfo, MessageArray);
        break;
    }
    }

    return analysisResult;
}

//2. 功能码0X01和0X03请求报文解析函数
//   参数1：请求报文基础信息结构体指针
//   参数2：请求报文数组
//   参数3：错误标识:
//         41.该请求报文的请求无法满足！所请求的线圈数量大于该起始地址可以读取的线圈数量！
//         43.该请求报文的请求无法满足！所请求的寄存器数量大于该起始地址可以读取的线圈数量！
bool Widget::AnalysisMessage0X010X03(MessageBasicInformation *structPt, int errorMark)
{
    //判断请求帧长度，01功能码请求报文为固定长度8
    if(structPt->Size != REQUEST_MESSAGE_LENGTH_0X01_0X03)
    {
        //消息窗口显示信息
        ui->messageEdit->append("该请求报文长度不正确！");
        return false;
    }

    //判断请求报文的起始地址是否合法
    if(structPt->BeginAddress < ADDRESS_MIN || structPt->BeginAddress > ADDRESS_MAX)
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 2, 2);
        return false;
    }
    if(structPt->FuncCode == 1)
    {
        //判断请求报文的线圈数量项是否合法
        if(structPt->Number < READ_COIL_MINNUM || structPt->Number > READ_COIL_MAXNUM)
        {
            //异常响应报文发送和显示
            AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 3, 3);
            return false;
        }
    }
    else
    {
        //判断请求报文的寄存器数量项是否合法
        if(structPt->Number < READ_REGISTER_MINNUM || structPt->Number > READ_REGISTER_MAXNUM)
        {
            //异常响应报文发送和显示
            AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 3, 3);
            return false;
        }
    }


    //判断该起始地址能否读取请求数量的线圈
    if((structPt->BeginAddress + structPt->Number) > (ADDRESS_MAX + 1))
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 2, errorMark);
        return false;
    }

    //正常响应报文发送并显示
    NorResMessSendAndPrompt(structPt);
    return true;
}

//3. 功能码0X0F请求报文解析函数
//   参数1：请求报文基础信息结构体指针
//   参数2：请求报文数组
bool Widget::AnalysisMessage0X0F(MessageBasicInformation *structPt, QByteArray messageArr)
{
    //判断请求报文的起始地址是否合法
    if(structPt->BeginAddress < ADDRESS_MIN || structPt->BeginAddress > ADDRESS_MAX)
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 2, 2);
        return false;
    }
    //判断请求报文的数量项是否合法
    if(structPt->Number < WRITE_COIL_MINNUM || structPt->Number > WRITE_COIL_MAXNUM)
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 3, 3);
        return false;
    }
    //判断该起始地址能否写入数量项的线圈
    if((structPt->BeginAddress + structPt->Number) > (ADDRESS_MAX + 1))
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 2, 42);
        return false;
    }

    //求响应报文字节数
    quint8 MessByteNum = (quint8)((structPt->Number + 7) / 8);

    quint8 MessArrByteNum = (quint8)messageArr.at(6);
    //判断字节数字段是否正确
    if(MessByteNum != MessArrByteNum)
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 3, 5);
        return false;
    }

    //判断字节字段长度是否匹配
    if(MessArrByteNum != (structPt->Size - 9))
    {
        //消息窗口显示信息
        ui->messageEdit->append("该请求报文长度不正确！");

        return false;
    }

    //如果都正确，将数据写入线圈数据表
    QString dataObtained;
    //取出要写的数据字节，并显示，数据从第7位开始
    for(int i = 0; i < MessArrByteNum; i++)
    {
        //先转化为2进制字符串
        QString str = QString::number((quint8)messageArr.at(7 + i),2);
        //再转化为2进制整形，由二进制整形转化为8位2进制字符串前面自动补0，从而保证8位
        str = QString("%1").arg((quint8)str.toInt(NULL,2),8,2,QChar('0'));
        //8bit字节倒转
        byteReverse(str);
        dataObtained += str;
    }

    //去除填充的0位，读出请求报文请求的线圈数
    dataObtained = dataObtained.left(structPt->Number);

    //更新线圈数据表和ini文件
    for(int i = 0; i < structPt->Number; i++)
    {
        int row = structPt->BeginAddress + i;
        QString coilData = dataObtained.mid(i,1);
        WriteCoilData(row, coilData);
    }

    //正常响应报文发送并显示
    NorResMessSendAndPrompt(structPt);

    return true;
}

//4. 功能码0X10请求报文解析函数
//   参数1：请求报文基础信息结构体指针
//   参数2：请求报文数组
bool Widget::AnalysisMessage0X10(MessageBasicInformation *structPt, QByteArray messageArr)
{
    //判断请求报文的起始地址是否合法
    if(structPt->BeginAddress < ADDRESS_MIN || structPt->BeginAddress > ADDRESS_MAX)
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 2, 2);
        return false;
    }

    //判断请求报文的数量项是否合法
    if(structPt->Number < WRITE_REGISTER_MINNUM || structPt->Number > WRITE_REGISTER_MAXNUM)
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 3, 3);
        return false;
    }

    //判断该起始地址能否写入数量项的寄存器
    if((structPt->BeginAddress + structPt->Number) > (ADDRESS_MAX + 1))
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 2, 44);
        return false;
    }

    quint8 MessByteNum = (structPt->Number)*2;
    quint8 MessArrByteNum = (quint8)messageArr.at(6);
    //判断字节数字段是否正确
    if(MessByteNum != MessArrByteNum)
    {
        //异常响应报文发送和显示
        AbnorResMessSendAndPrompt(structPt->SlaveAddress, structPt->FuncCode, 3, 5);
        return false;
    }

    //判断字节字段长度是否匹配
    if(MessArrByteNum != (structPt->Size - 9))
    {
        //消息窗口显示信息
        ui->messageEdit->append("该请求报文长度不正确！");
        return false;
    }

    //如果都正确，将数据写入寄存器数据表
    QString dataObtained;

    //取出要写的寄存器，并显示，数据从第7个字节开始
    int row = structPt->BeginAddress;
    for(int i = 0; i < MessArrByteNum; i += 2)
    {
        dataObtained = QString::number(BondTwoUint8ToUint16((quint8)messageArr.at(7 + i),(quint8)messageArr.at(8 + i)));
        WriteRegistData(row, dataObtained);
        row++;
    }

    //正常响应报文发送并显示
    NorResMessSendAndPrompt(structPt);

    return true;
}

//2. 异常响应报文数组构建函数
//   参数1：本机地址
//   参数2：功能码
//   参数3：异常码类型
QByteArray Widget::AbnormalResponseMessage(quint8 localAddr, quint8 funcCode,int abnorCode)
{
    QString checkStringCrc;
    QString abnormalResponseStr;
    abnormalResponseStr.resize(5);
    QByteArray abnormalResponseArr;
    quint8 abnormalCode;

    switch (abnorCode)
    {
    case 1:
    {
        abnormalCode = 0x01;
        break;
    }
    case 2:
    {
        abnormalCode = 0x02;
        break;
    }
    case 3:
    {
        abnormalCode = 0x03;
        break;
    }
    }

    abnormalResponseStr = QString("%1").arg((quint8)localAddr,2,16,QLatin1Char('0'))
            + QString("%1").arg((quint8)(funcCode + 0x80),2,16,QLatin1Char('0'))
            + QString("%1").arg((quint8)abnormalCode,2,16,QLatin1Char('0'));

    //求出前3位数据的CRC校验码
    checkStringCrc = CRCCheck(abnormalResponseStr);

    //拼接上校验码
    abnormalResponseStr += checkStringCrc;

    //转换成QByteArray
    for(int i = 0; i < 5; i++)
    {
        abnormalResponseArr[i] = abnormalResponseStr.mid(2*i,2).toInt(NULL,16);
    }

    return abnormalResponseArr;
}

//3. 异常响应报文发送和显示函数
//   参数1：本机地址
//   参数2：功能码
//   参数3：异常码类型
//   参数4：错误标识:
//         1.非法功能码！
//         2.该请求报文的起始地址不合法！
//         3.该请求报文的数量项不合法！
//         41.该请求报文的请求无法满足！所请求的线圈数量大于该起始地址可以读取的线圈数量！
//         42.该请求报文的请求无法满足！所请求的线圈数量大于该起始地址可以写入的线圈数量！
//         43.该请求报文的请求无法满足！所请求的寄存器数量大于该起始地址可以读取的线圈数量！
//         44.该请求报文的请求无法满足！所请求的寄存器数量大于该起始地址可以写入的寄存器数量！
//         5.该请求报文的字节字段不合法！
void Widget::AbnorResMessSendAndPrompt(quint8 localAddr, quint8 funcCode, int abnorCode, int errorMark)
{
    //初始化响应报文数组和字符串和错误信息字符串
    QByteArray responseMessageArr;
    QString responseMessageStr;
    QString abnorResMessPrompt;



    //消息窗口显示错误类型
    switch (errorMark)
    {
    case 1:
    {
        abnorResMessPrompt = "非法功能码！";
        break;
    }
    case 2:
    {
        abnorResMessPrompt = "该请求报文的起始地址不合法！";
        break;
    }
    case 3:
    {
        abnorResMessPrompt = "该请求报文的数量项不合法！";
        break;
    }
    case 41:
    {
        abnorResMessPrompt = "该请求报文的请求无法满足！所请求的线圈数量大于该起始地址可以读取的线圈数量！";
        break;
    }
    case 42:
    {
        abnorResMessPrompt = "该请求报文的请求无法满足！所请求的线圈数量大于该起始地址可以写入的线圈数量！";
        break;
    }
    case 43:
    {
        abnorResMessPrompt = "该请求报文的请求无法满足！所请求的寄存器数量大于该起始地址可以读取的线圈数量！";
        break;
    }
    case 44:
    {
        abnorResMessPrompt = "该请求报文的请求无法满足！所请求的寄存器数量大于该起始地址可以写入的寄存器数量！";
        break;
    }
    case 5:
    {
        abnorResMessPrompt = "该请求报文的字节字段不合法！";
        ui->messageEdit->append(abnorResMessPrompt);
        return;
        break;
    }
    }

    //显示异常
    ui->messageEdit->append(abnorResMessPrompt);

    //得到异常响应报文数组
    responseMessageArr = AbnormalResponseMessage(localAddr, funcCode, abnorCode);
    //生成显示报文字符串，加空格
    responseMessageStr = HexByteArrayToHexString(responseMessageArr, ABNORMAL_RESPONSE_LENGTH, 1);

    //发送响应报文
    serialPort->write(responseMessageArr);

    //显示异常响应报文
    ui->messageEdit->append("已向主机发送异常响应报文：" + responseMessageStr);
}

//4. 0x01正常响应报文线圈数据获取函数
QByteArray Widget::NorResseMessBuild0x01data(MessageBasicInformation *structPt)
{
    //声明读取的数据字符串
    QString getDataString;
    //声明响应报文字节数项
    quint8 responseMessageByteNum;
    //求响应报文字节数
    responseMessageByteNum = (quint8)((structPt->Number + 7) / 8);

    //从数据表中读取需要数量的线圈数据,形成二进制形式字符串
    for(int i = structPt->BeginAddress; i < (structPt->BeginAddress + structPt->Number); i++)
    {
        QString buffer = ui->coilTableWidget->item(1,i)->text();
        if(buffer == "ON")
        {
            getDataString += "1";
        }
        else
        {
            getDataString += "0";
        }
    }

    //二进制字符串补0
    for(int i = 1; i <= (8*responseMessageByteNum - structPt->Number); i++)
    {
        getDataString += "0";
    }

    //声明线圈数据数组
    QByteArray coilsDataArr;
    coilsDataArr.resize(responseMessageByteNum);
    //将二进制字符串按字节填入响应报文数组
    for(int i = 0; i < responseMessageByteNum; i++)
    {
        //对8位1字节进行反转处理
        QString buffer = getDataString.mid((8 * i),8);
        //字节反转
        byteReverse(buffer);
        //存入响应报文数组
        coilsDataArr[i] = buffer.toInt(NULL,2);
    }

    return coilsDataArr;
}

//5. 0x03正常响应报文寄存器数据获取函数
QByteArray Widget::NorResseMessBuild0x03data(MessageBasicInformation *structPt)
{
    //声明读取的数据字符串
    QString getDataString;
    //声明响应报文字节数项
    quint8 responseMessageByteNum;

    //求响应报文字节数项，为请求报文数量项的两倍，一个寄存器两个字节
    responseMessageByteNum = (structPt->Number)*2;

    //声明线圈数据数组
    QByteArray registersDataArr;
    registersDataArr.resize(responseMessageByteNum);

    //从数据表中读取需要数量的寄存器数据,形成二进制形式字符串
    for(int i = 0; i < structPt->Number; i++)
    {
        //取出10进制字符串
        getDataString = ui->registerTableWidget->item(1,(i + structPt->BeginAddress))->text();
        //转化为2进制字符串，不足补0，凑足16位
        getDataString  = QString("%1").arg((quint16)getDataString.toInt(NULL,10),16,2,QLatin1Char('0'));
        //前8位为一个字节
        registersDataArr[2*i] = getDataString.mid(0,8).toInt(NULL,2);
        //后8位为一个字节
        registersDataArr[2*i + 1] = getDataString.mid(8,8).toInt(NULL,2);
    }

    return registersDataArr;
}

//6. 0x01和0x03正常响应报文构建函数
//   参数1：请求报文基础信息结构体指针
//   参数2：数据字节数组
QByteArray Widget::NorResseMessBuild0x010x03(MessageBasicInformation *structPt, QByteArray byteArr)
{
    //1. 初始化响应报文数组和字符串
    //声明响应报文数组
    QByteArray responseMessageArr;
    //声明响应报文CRC检测字符串
    QString responseMessageCheckString;
    //声明响应报文字节数项
    quint8 responseMessageByteNum;
    //声明响应报文CRC校验码
    QString responseMessageCRCCheck;

    //求响应报文字节数
    if(structPt->FuncCode == 1)
    {
        responseMessageByteNum = (quint8)((structPt->Number + 7) / 8);
    }
    else
    {
        responseMessageByteNum = 2*structPt->Number;
    }

    //设置响应报文数组大小
    int responseMessageArrSize = responseMessageByteNum + 5;
    responseMessageArr.resize(responseMessageArrSize);
    //从站地址
    responseMessageArr[0] = structPt->SlaveAddress;
    //功能码
    responseMessageArr[1] = structPt->FuncCode;
    //字节数
    responseMessageArr[2] = responseMessageByteNum;

    //将数据字节项填入响应报文
    for(int i = 0; i < responseMessageByteNum; i++)
    {
        responseMessageArr[3 + i] = byteArr[i];
    }

    //添加CRC校验
    //先将响应现有响应报文数组转为2位16进制字符串形式
    responseMessageCheckString = HexByteArrayToHexString(responseMessageArr, (responseMessageArrSize - 2), 0);

    //计算出响应报文的当前CRC校验码字符串
    responseMessageCRCCheck = CRCCheck(responseMessageCheckString);;

    //添加CRC校验码到响应报文数组
    responseMessageArr[responseMessageArrSize - 2] = responseMessageCRCCheck.mid(0,2).toInt(NULL,16);
    responseMessageArr[responseMessageArrSize - 1] = responseMessageCRCCheck.mid(2,2).toInt(NULL,16);

    //返回响应报文数组
    return responseMessageArr;
}

//7. 0x0f和0x10正常响应报文构建函数
//   参数：请求报文基础信息结构体指针
QByteArray Widget::NorResseMessBuild0x0f0x10(MessageBasicInformation *structPt)
{
    //声明响应报文数组
    QByteArray responseMessageArr;
    //声明响应报文CRC检测字符串
    QString responseMessageCheckString;
    //声明响应报文CRC校验码
    QString responseMessageCRCCheck;
    //设置响应报文数组大小
    int responseMessageArrSize = WRITE_RESPONSE_LENGTH;
    responseMessageArr.resize(responseMessageArrSize);

    //将从站地址、功能码、起始地址、数量项赋值给响应报文数组
    //从站地址
    responseMessageArr[0] = structPt->SlaveAddress;
    //功能码
    responseMessageArr[1] = structPt->FuncCode;
    //起始地址
    responseMessageArr[2] = structPt->BeginAddress >> 8;
    responseMessageArr[3] = structPt->BeginAddress & 0x0ff;
    //数量项
    responseMessageArr[4] = structPt->Number >> 8;
    responseMessageArr[5] = structPt->Number & 0x0ff;

    //添加CRC校验
    //先将响应现有响应报文数组转为2位16进制字符串形式
    responseMessageCheckString = HexByteArrayToHexString(responseMessageArr, (responseMessageArrSize - 2), 0);
    //计算出响应报文的当前CRC校验码字符串
    responseMessageCRCCheck = CRCCheck(responseMessageCheckString);;

    //添加CRC校验码到响应报文数组
    responseMessageArr[6] = responseMessageCRCCheck.mid(0,2).toInt(NULL,16);
    responseMessageArr[7] = responseMessageCRCCheck.mid(2,2).toInt(NULL,16);

    //返回响应报文数组
    return responseMessageArr;
}

//8. 正常响应报文发送和显示函数
//   参数1：自定义结构体对象
//   参数2：对象消息字节数组
void Widget::NorResMessSendAndPrompt(MessageBasicInformation *structPt)
{
    //初始化响应报文数组和字符串
    QByteArray responseMessageArr;
    QString responseMessageStr;

    //生成正常响应报文
    switch (structPt->FuncCode)
    {
    case 0x01:
    {
        //0x01正常响应报文构建函数
        QByteArray byteArray;
        byteArray = NorResseMessBuild0x01data(structPt);
        responseMessageArr = NorResseMessBuild0x010x03(structPt, byteArray);
        break;
    }
    case 0x03:
    {
        //0x03正常响应报文构建函数
        QByteArray byteArray;
        byteArray = NorResseMessBuild0x03data(structPt);
        responseMessageArr = NorResseMessBuild0x010x03(structPt, byteArray);
        break;
    }
    default:
    {
        //0x0f和0x10正常响应报文构建函数
        responseMessageArr = NorResseMessBuild0x0f0x10(structPt);
        break;
    }
    }

    //由响应报文数组得到响应报文字符串
    responseMessageStr = HexByteArrayToHexString(responseMessageArr, responseMessageArr.size(), 1);

    //发送响应报文
    serialPort->write(responseMessageArr);
    //消息窗口显示信息
    TimeInformation();
    ui->messageEdit->append("请求报文解析成功！");
    ui->messageEdit->append("已向主机发送响应报文：" + responseMessageStr);
}

//9. 结构体初始化函数
//   参数1：自定义结构体对象
//   参数2：对象消息字节数组
void Widget::messStructInitialize(MessageBasicInformation *structPt, QByteArray messageArr)
{
    //报文长度
    structPt->Size = messageArr.size();
    //目的地址
    structPt->SlaveAddress = (quint8)messageArr.at(0);
    //功能码
    structPt->FuncCode = (quint8)messageArr.at(1);
    //起始地址
    structPt->BeginAddress = BondTwoUint8ToUint16((quint8)messageArr.at(2),(quint8)messageArr.at(3));
    //数量项
    structPt->Number = BondTwoUint8ToUint16((quint8)messageArr.at(4),(quint8)messageArr.at(5));
    //报文的CRC校验码
    structPt->CrcCheck = QString("%1").arg((quint8)messageArr.at(structPt->Size - 2),2,16,QLatin1Char('0'))
            + QString("%1").arg((quint8)messageArr.at(structPt->Size - 1),2,16,QLatin1Char('0'));
}

//10. 十六进制数组转十六进制字符串
//   参数1：目标十六进制数组
//   参数2：需要转化的长度
//   参数3：转化模式，两种模式，默认模式为pattern=0不加空格，pattern=1位加空格
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

//11. CRC校验码计算函数
QString Widget::CRCCheck(QString &checkStr)
{
    QString checkStrCrc; //计算出的CRC
    quint8 buffer;  //定义中间变量
    quint16 wcrc16 = 0xFFFF; //预置CRC校验码，全为1
    QByteArray data  = QByteArray::fromHex(checkStr.toLocal8Bit());

    //循环计算每个数据
    for (int i = 0; i < data.size(); i++ )
    {
        buffer = data.at(i);
        wcrc16 = wcrc16 ^ buffer;
        for(int j = 0; j < 8; j++)
        {
            //判断右移出的是不是1，如果是1则与多项式进行异或
            if(wcrc16 & 0x0001)
            {
                //右移一位
                wcrc16 = wcrc16 >> 1;
                //异或
                wcrc16 = wcrc16 ^ 0xA001;
            }
            else
            {
                //如果不是1直接移出
                wcrc16 = wcrc16 >> 1;
            }
        }
    }

    //拼凑成4个16进制字符，空位补0
    checkStrCrc = QString("%1").arg(wcrc16, 4, 16, QLatin1Char('0'));

    //交换高低位
    QString leftBuffer = checkStrCrc.mid(0,2);
    QString rightBuffer = checkStrCrc.mid(2,2);
    //拼接
    checkStrCrc = rightBuffer + leftBuffer;

    return checkStrCrc;
}

//12. 判断报文CRC正确性函数
//   参数1：自定义结构体对象
//   参数2：对象消息字节数组
bool Widget::JudgeCRC(MessageBasicInformation *structPt, QByteArray messageArr)
{
    QString checkStr,checkStrCrc;
    //取出crc校验码之前的数据，计算其crc校验码，与得到的crc校验码进行对比
    checkStr = HexByteArrayToHexString(messageArr, structPt->Size - 2, 0);
    //计算出数据的当前CRC校验码
    checkStrCrc = CRCCheck(checkStr);

    //比较两个CRC校验码是否相同
    if(checkStrCrc != structPt->CrcCheck)
    {
        //消息窗口显示信息
        ui->messageEdit->append("该报文CRC校验出错！");
        return false;
    }
    else
    {
        return true;
    }
}

//13. 连接两个quint8数据为一个quint16数据
quint16 Widget::BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum)
{
    quint16 bondNum = (preNum << 8) | afterNum;
    return bondNum;
}

//14.字节反转函数
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

/***********************************************数据存取函数************************************************/
//1. 读出ini数据函数，ini文件->数据表
void Widget::ReadOutIniData(void)
{
    for(int i = 0; i < (ADDRESS_MAX + 1); i++)
    {
        //地址设置
        QString adr =  "0x" + QString("%1").arg(i,4,16,QLatin1Char('0'));
        ui->coilTableWidget->setItem(0,i, new QTableWidgetItem(QString(adr)));
        ui->coilTableWidget->item(0,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->registerTableWidget->setItem(0,i, new QTableWidgetItem(QString(adr)));
        ui->registerTableWidget->item(0,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
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
        ui->coilTableWidget->setItem(1,i,new QTableWidgetItem(coilData));
        //设置表格内文字水平+垂直对齐
        ui->coilTableWidget->item(1,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //在寄存器数据表中显示数据
        ui->registerTableWidget->setItem(1,i,new QTableWidgetItem(registerData));
        //设置表格内文字水平+垂直对齐
        ui->registerTableWidget->item(1,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
}


//2. 写入线圈数据函数
void Widget::WriteCoilData(int row, QString coilData)
{
    //锁住写入线圈数据信号，进行阻塞
    ui->coilTableWidget->blockSignals(true);

    //更新ini文件数据
    settings->setValue("Section" + QString::number(row + 1) + "/coil",coilData);

    //更新线圈数据表中数据
    if(coilData == "1")
    {
        coilData = "ON";
    }
    else
    {
        coilData = "OFF";
    }
    ui->coilTableWidget->setItem(1,row,new QTableWidgetItem(coilData));
    //设置表格内文字水平+垂直对齐
    ui->coilTableWidget->item(1,row)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    //解锁写入线圈数据信号
    ui->coilTableWidget->blockSignals(false);
}

//3. 写入寄存器数据函数
void Widget::WriteRegistData(int row, QString registerData)
{
    //锁住写入寄存器数据信号，进行阻塞
    ui->registerTableWidget->blockSignals(true);

    //更新ini文件数据
    settings->setValue("Section" + QString::number(row + 1) + "/regi",registerData);

    //更新线圈数据表中数据
    ui->registerTableWidget->setItem(1,row,new QTableWidgetItem(registerData));

    //设置表格内文字水平+垂直对齐
    ui->registerTableWidget->item(1,row)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    //解锁写入寄存器数据信号
    ui->registerTableWidget->blockSignals(false);
}

//4. 转到指定位置数据函数
void Widget::Search(int type)
{
    //1为线圈数据表搜索，2为寄存器数据表搜索
    if(type == 1)
    {
        //获取用户输入的搜索地址
        int coilIndex = ui->coilLineEdit->text().toInt(NULL,10);

        //获取搜索位置的指针
        QTableWidgetItem *coilItem = ui->coilTableWidget->item(NULL,coilIndex);

        //将数据表的显示设定为指定指针
        ui->coilTableWidget->setCurrentItem(coilItem);
        //滚动到指向位置，并将指定位置显示在表格顶部
        ui->coilTableWidget->scrollToItem(coilItem,QAbstractItemView::PositionAtCenter);
    }
    else
    {
        //获取用户输入的搜索地址
        int registerIndex = ui->regisetLineEdit->text().toInt(NULL,10);

        //获取搜索位置的指针
        QTableWidgetItem *registerItem = ui->registerTableWidget->item(NULL,registerIndex);

        //将数据表的显示设定为指定指针
        ui->registerTableWidget->setCurrentItem(registerItem);
        //滚动到指向位置，并将指定位置显示在表格顶部
        ui->registerTableWidget->scrollToItem(registerItem,QAbstractItemView::PositionAtCenter);
    }
}

/************************************************程序关闭处理函数************************************************/
void Widget::closeEvent(QCloseEvent *event) //系统自带退出确定程序
{
    int choose;
    choose= QMessageBox::question(this, tr("退出程序"),
                                   QString(tr("确认退出程序?")),
                                   QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

    //选择不退出，则程序继续运行，选择退出，则进行保存数据流程
    if (choose== QMessageBox::No)
    {
          event->ignore();  //忽略//程序继续运行
    }
    else if (choose== QMessageBox::Yes)
    {
        //关闭界面，保存日志
        //消息窗口显示信息
        FileInformation();
        WriteHistoricalMessage();
        //关闭时钟
        RecordTimer->stop();
        killTimer(clock);
        //清空指针内存
        PointerManagement(0);
        //退出程序
        event->accept();
    }
}

/**************************************************析构函数*****************************************************/
Widget::~Widget()
{
    delete ui;
}
