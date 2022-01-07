#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    tcpServer = new QTcpServer(this);
    this->resize(QSize(760,770));

    //初始化服务器
    TcpServerInit();
    //监听指定端口
    connect(ui->connectButton,&QPushButton::clicked,this,&Widget::ListenTcpServer);

    //刷新IP地址
    connect(ui->FlushIPAddressButton,&QPushButton::clicked,[=](){
        ui->ipAddressData->setText(getLocalIp());
    });
    //显示新建连接
    connect(tcpServer,&QTcpServer::newConnection,[&](){
        //连接提示
        CreateNewConnect();   
        //接收到数据
        connect(tcpReceiveSocket,&QTcpSocket::readyRead,this,[=](){
                //显示接收数据
                ShowRequestMessage();
                bool flag = TcpRequestMessageAnalysis(TcpRequestMessage);

        });
        //客户端断开提示
        connect(tcpReceiveSocket,static_cast<void(QAbstractSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error),
                [&](QAbstractSocket::SocketError socketError){ShowTcpServerDisconnect(socketError);}
        );

    });

    //手动关闭连接
    connect(ui->disconnectButton,&QPushButton::clicked,[=](){
         if(TcpServerConnectState == true)
         {
             tcpReceiveSocket->close();
             TcpServerConnectState = false;
             TimeInformation();
             ui->messageBox->append("断开连接："+MasterIpAddress+":"+QString::number(MasterPortNumber));
         }

    });

    //搜索框定位
    //线圈搜索框定位
    connect(ui->coilSearchPushBotton,&QPushButton::clicked,[=](){
        Search(1);
    });
    //寄存器搜索框定位
    connect(ui->registerSearchPushBotton,&QPushButton::clicked,[=](){
        Search(2);
    });

    //历史信息
    //历史信息显示
    connect(ui->ShowHistoryMessageButton,&QPushButton::clicked,[=](){
        HistoryMessageWindow->ShowHistoryMessage(RECORD_PATH);
    });
    //历史信息每隔2分钟自动记录
    connect(RecordTimer,&QTimer::timeout,[=](){
        WriteHistoricalMessage();
    });
    //清除窗口信息
    connect(ui->ClearHistoryButton,&QPushButton::clicked,[=](){
        WriteHistoricalMessage();
    });

}
/********************************时间相关函数************************************/
//时钟函数
void Widget::ShowDateTime()
{
    QDateTime time =QDateTime::currentDateTime();
    QString str= time.toString("yyyy-MM-dd hh:mm:ss");
    ui->showCurrentTime->setText(str);
}
//时间事件函数
void Widget::timerEvent(QTimerEvent *event)
{
    int tmp = event->timerId();

    if(tmp == timer)
    {
        ShowDateTime();
    }
}
//显示当前时间
void Widget::TimeInformation()
{
    ui->messageBox->append("");
    ui->messageBox->append("["+QDateTime::currentDateTime().toString(CLOCK_FORMAT)+"]");
}
/***********************************初始化相关函数**********************************/
//初始化默认Ip
void Widget::IpDefault()
{
    if(ui->ipAddressData->text().isEmpty())
    {
        ipAddress = defaultIpAddress;
        ui->ipAddressData->setText(ipAddress);
    }
}
//获取本地Ip地址
QString Widget::getLocalIp()
{
    QString hostName=QHostInfo::localHostName();            //本地主机名
    QHostInfo hostInfo=QHostInfo::fromName(hostName);      //本机IP地址
    QList<QHostAddress> addList=hostInfo.addresses();      //IP地址列表
     for (int i=0;i<addList.count();i++)
     {
         QHostAddress aHost=addList.at(i); //每一项是一个QHostAddress
         if(QAbstractSocket::IPv4Protocol==aHost.protocol())
         {
             return aHost.toString(); //显示出Ip地址
         }
     }
     return defaultIpAddress;
}
//初始化默认端口
void Widget::PortDefault()
{
    if(ui->portNumberData->text().isEmpty())
    {
        portNumber = defaultPortNumber;
        ui->portNumberData->setText(QString::number(portNumber));
    }
}
//初始化从机地址
void Widget::SlaveAddressDefault()
{
    if(ui->SlaveAddressNumber->text().isEmpty())
    {
        SlaveAddress = defaultSlaveAddress;
        ui->SlaveAddressNumber->setText(QString::number(SlaveAddress));
    }
}
//服务器初始化
void Widget::TcpServerInit()
{
    //初始化QString, ini文件格式
    settings = new QSettings(INIFILE_PATH,QSettings::IniFormat);

    //初始化历史窗口
    HistoryMessageWindow = new HistoryMessageDialog;
    HistoryMessageWindow->setWindowTitle("历史信息");

    //开始计时器
    timer = startTimer(CLOCK_REFRESH);
    RecordTimer = new QTimer(this);
    RecordTimer->setInterval(120000);
    RecordTimer->start();

    //设置默认ip、端口、从机地址的背景显示
    ui->ipAddressData->setPlaceholderText(defaultIpAddress);
    ui->portNumberData->setPlaceholderText(QString::number(defaultPortNumber));
    ui->SlaveAddressNumber->setPlaceholderText(QString::number(defaultSlaveAddress));
    //限制从机地址取值
    ui->SlaveAddressNumber->setValidator(new QIntValidator(1, 247, this));
    //设置搜索框背景提示并居中
    ui->coilSearchNumber->setPlaceholderText("0 - 65535");
    ui->coilSearchNumber->setAlignment(Qt::AlignHCenter);
    ui->registerSearchNumber->setPlaceholderText("0 - 65535");
    ui->registerSearchNumber->setAlignment(Qt::AlignHCenter);

    //限制显示搜索框取值
    ui->coilSearchNumber->setValidator(new QIntValidator(0,65535,this));
    ui->registerSearchNumber->setValidator(new QIntValidator(0,65535,this));

    //设置Ip默认值、端口默认值、从机地址默认值
    IpDefault();
    PortDefault();
    SlaveAddressDefault();

    //设置表格
    QStringList TableHeader;
    TableHeader << "地址" << "数据";
    ui->coilsTable->setVerticalHeaderLabels(TableHeader);
    ui->coilsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->registersTable->setVerticalHeaderLabels(TableHeader);
    ui->registersTable->setSelectionMode(QAbstractItemView::SingleSelection);

    //将ini文件中的数据展示到表格
    ReadOutIniData();
}
/***********************************端口相关函数*************************************/
//端口监听控制
void Widget::ListenTcpServer()
{
    //对端口建立监听
    if(ui->connectButton->text() == "开始监听")
    {
        //当前端口正在监听
        if(tcpServer->isListening())
        {
            //关闭当前端口监听
            tcpServer->close();
        }

        //获取输入框内ip地址、端口号、从机地址
        //判断ip地址是否为空
        if(ui->ipAddressData->text().isEmpty())
        {
            ipAddress = defaultIpAddress;
            TimeInformation();
            ui->messageBox->append("ip地址为空，使用默认ip地址："+ipAddress);
        }
        else
        {
           //ip地址不为空，判断ip是否合法
           bool ipAddressIsLegal;
           QHostAddress ip(ui->ipAddressData->text());
           ip.toIPv4Address(&ipAddressIsLegal);
           if(!ipAddressIsLegal)
           {
               ipAddress = defaultIpAddress;
               TimeInformation();
               ui->messageBox->append("ip地址非法，使用默认ip地址："+ipAddress);
           }
           else
           {
               //输入ip合法
               ipAddress = ui->ipAddressData->text();
           }
        }

        //判断端口是否为空
        if(ui->portNumberData->text().isEmpty())
        {
            portNumber = defaultPortNumber;
            TimeInformation();
            ui->messageBox->append("端口号为空，使用默认端口号："+QString::number(portNumber));
        }
        else
        {
            //端口不为空
            //判断端口是否合法
            bool PortNumberIsLegal;
            portNumber = ui->portNumberData->text().toUShort(&PortNumberIsLegal,10);
            if(!PortNumberIsLegal)
            {
                TimeInformation();
                ui->messageBox->append("端口号非法，使用默认端口号："+QString::number(defaultPortNumber));
                portNumber = defaultPortNumber;
            }
        }

        //判断从机地址是否为空
        if(ui->SlaveAddressNumber->text().isEmpty())
        {
            SlaveAddress = defaultSlaveAddress;
            TimeInformation();
            ui->messageBox->append("从机地址为空，使用默认从机地址："+QString::number(SlaveAddress));
        }
        else
        {
            SlaveAddress = ui->SlaveAddressNumber->text().toInt();
        }

        //监听
        isListenTcpServer = tcpServer->listen(QHostAddress(ipAddress),portNumber);
        if(!isListenTcpServer)
        {
            QMessageBox::warning(this,"错误",tcpServer->errorString());
            tcpServer->close();
            return;
        }

        ui->ipAddressData->setEnabled(false);
        ui->portNumberData->setEnabled(false);
        ui->SlaveAddressNumber->setEnabled(false);
        ui->FlushIPAddressButton->setEnabled(false);

        TimeInformation();
        ui->messageBox->append("开始监听："+ipAddress+":"+QString::number(portNumber));
        ui->messageBox->append("从机地址："+QString::number(SlaveAddress));
        ui->connectButton->setText("停止监听");
    }
    else if(ui->connectButton->text() == "停止监听")
    {
        tcpServer->close();
        isListenTcpServer = false;
        TimeInformation();
        ui->messageBox->append("停止监听："+ipAddress+":"+QString::number(portNumber));
        ui->connectButton->setText("开始监听");
        ui->ipAddressData->setEnabled(true);
        ui->portNumberData->setEnabled(true);
        ui->SlaveAddressNumber->setEnabled(true);
        ui->FlushIPAddressButton->setEnabled(true);

        //停止监听端口时，关闭所有连接
        if(1 == TcpServerConnectState)
        {
            //关闭连接
            tcpReceiveSocket->close();
            TcpServerConnectState = false;
            TimeInformation();
            ui->messageBox->append("断开连接："+MasterIpAddress+":"+QString::number(MasterPortNumber));
        }
    }
    else
    {
        isListenTcpServer = false;
        TimeInformation();
        ui->messageBox->append("监听失败，请重试！");
        ui->messageBox->append("无法监听："+ipAddress+":"+QString::number(portNumber));
        ui->connectButton->setText("连接");
    }
}
/***********************************连接相关函数*************************************/
//建立新连接
void Widget::CreateNewConnect()
{
    TcpServerConnectState = true;
    //获取套接字及其标识符
    tcpReceiveSocket = tcpServer->nextPendingConnection();
    tcpReceiveSocket->setSocketOption(QAbstractSocket::LowDelayOption,0);

    tcpReceiveSocketDescriptor = tcpReceiveSocket->socketDescriptor();
    //获取客户端IP
    MasterIpAddress = tcpReceiveSocket->peerAddress().toString();
    //获取客户端接口
    MasterPortNumber = tcpReceiveSocket->peerPort();
    //显示客户端连接信息
    ShowTcpServerNewConnect();
}
//新建连接信息提示
void Widget::ShowTcpServerNewConnect()
{
    TimeInformation();
    ui->messageBox->append("新建连接："+MasterIpAddress+":"+QString::number(MasterPortNumber));
}
//连接被动断开信息提示
void Widget::ShowTcpServerDisconnect(QAbstractSocket::SocketError)
{
    TcpServerConnectState = false;
    TimeInformation();
    ui->messageBox->append("断开连接："+MasterIpAddress+":"+QString::number(MasterPortNumber));
}
/************************************报文相关函数***************************************/
//显示请求报文
void Widget::ShowRequestMessage()
{
    //接收字节数组并转化
    QString res;
    TcpRequestMessage =  tcpReceiveSocket->readAll();
    res = HexByteArrayToHexString(TcpRequestMessage,TcpRequestMessage.size(),1);
    //显示收到的报文
    TimeInformation();
    ui->messageBox->append("请求报文地址："+MasterIpAddress + ":"+QString::number(MasterPortNumber));
    ui->messageBox->append("请求报文内容："+res);
}
//显示请求报文
void Widget::ShowResponseMessage(QByteArray MessageArray)
{
    QString res;
    res = HexByteArrayToHexString(MessageArray,MessageArray.size(),1);
    //显示收到的报文
    //TimeInformation();
    //ui->messageBox->append("请求报文地址："+MasterIpAddress + ":"+QString::number(MasterPortNumber));
    ui->messageBox->append("响应报文内容："+res);
}

//解析请求报文
bool Widget::TcpRequestMessageAnalysis(QByteArray MessageArray)
{

    bool AnalysisResult=false;

    //异常判断
    //长度判断：最大长度、最短长度
    if(MessageArray.size() > TCP_MAX_LENGTH)
    {
        ui->messageBox->append("报文长度错误，报文长度超过最大报文长度！");
        return false;
    }
    if(MessageArray.size() < TCP_MIN_LENGTH)
    {
        ui->messageBox->append("报文长度错误，报文长度小于最小报文长度！");
        return false;
    }
    //MBAP报文头
    //事务标识符(指定为 00 01)
    quint16 transactionIdentifier;
    transactionIdentifier = BondTwoUint8ToUint16((quint8)MessageArray[0],(quint8)MessageArray[1]);
    if(transactionIdentifier != 1)
    {
        ui->messageBox->append("事务标识符错误，事务标识符与本机不一致！");
        return false;
    }
    //协议标识符判断
    quint16 protocolNumber;
    protocolNumber = ((quint8)MessageArray[2] << 8) | (quint8)MessageArray[3];
    if(protocolNumber != 0)
    {
        ui->messageBox->append("报文协议错误，请求报文中报文协议错误！");
        return false;
    }
    //应用数据单元ADU长度判断
    quint16 ADULength;
    ADULength = ((quint8)MessageArray[4] << 8) | (quint8)MessageArray[5];
    if(ADULength != (MessageArray.size()- TCP_MBAP_HEADER_LENGTH))
    {
        ui->messageBox->append("字节长度错误，请求报文中字节长度与实际应用数据单元长度不一致！");
        return false;
    }
    //从机地址
    quint8 MessageSlaveAddress;
    MessageSlaveAddress = (quint8)MessageArray[6];
    if(SlaveAddress != MessageSlaveAddress)
    {
        ui->messageBox->append("从机地址错误，请求报文中从机地址与本机从机地址不一致！");
        return false;
    }

    //从机地址(未指定，不判断)
    //功能码判断
    quint8 AbnormalFunctionCode;
    QByteArray AbnormalResponseMessage;
    quint8 FunctionCode;
    FunctionCode = (quint8)MessageArray[7];
    if(FunctionCode != 1 && FunctionCode != 3 && FunctionCode != 15 && FunctionCode != 16)
    {
        //异常报文响应 01
        AbnormalFunctionCode = 0x01;
        AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
        AbnormalMessageSend(AbnormalResponseMessage);
        //异常提示
        ui->messageBox->append("非法功能码！");
        ShowResponseMessage(AbnormalResponseMessage);
        return false;
    }

    switch (TcpRequestMessage.at(7)) {
    case 1:
        //0x01功能码报文处理函数
        AnalysisResult = AnalysisMessage0X010X03(TcpRequestMessage);
        break;
    case 3:
        //0x03功能码报文处理函数
        AnalysisResult = AnalysisMessage0X010X03(TcpRequestMessage);
        break;
    case 15:
        //0x0f功能码报文处理函数
        AnalysisResult = AnalysisMessage0X0f0X10(TcpRequestMessage);
        break;
    case 16:
        //0x10功能码报文处理函数
        AnalysisResult = AnalysisMessage0X0f0X10(TcpRequestMessage);
        break;        
    }

    if(true == AnalysisResult)
    {
        TcpRequestMessage.clear();
    }
    return AnalysisResult;
}


//0x01 0x03 生成正常响应报文 并调用报文发送函数
bool Widget::AnalysisMessage0X010X03(QByteArray MessageArray)
{
    //异常分析
    //异常码、异常响应报文
    quint8 AbnormalFunctionCode;
    QByteArray AbnormalResponseMessage;
    //判断顺序：
    //查询报文长度是否非法
    if(MessageArray.size() != REQUEST_MESSAGE_LENGTH_0X01_0X03)
    {
        ui->messageBox->append("查询报文长度非法！");
        return false;
    }
    //获取数据起始地址和数量
    quint16 BeginAddress;
    BeginAddress = ((quint8)MessageArray[8] << 8) | (quint8)MessageArray[9];
    quint16 DataNumber;
    DataNumber = ((quint8)MessageArray[10] << 8) | (quint8)MessageArray[11];
    //查询报文数量是否合法
    switch(MessageArray.at(7))
    {
    case 1:
        if(DataNumber < READ_COIL_MINNUM || DataNumber > READ_COIL_MAXNUM)
        {
            //发送异常报文，异常码03
            AbnormalFunctionCode = 0x03;
            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
            AbnormalMessageSend(AbnormalResponseMessage);
            //异常提示
            ui->messageBox->append("线圈查询数量非法,请求报文中数据查询数量超出查询范围！");
            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        if((BeginAddress+DataNumber-1) > ADDRESS_MAX)
        {
            //发送异常报文，异常码02
            AbnormalFunctionCode = 0x02;
            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("线圈查询非法,请求报文中起始地址后可读取的线圈数量小于查询数量！");
            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }

        break;
    case 3:
        if(DataNumber < READ_REGISTER_MINNUM || DataNumber > READ_REGISTER_MAXNUM)
        {
            //发送异常报文，异常码03
            AbnormalFunctionCode = 0x03;
            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("查询数量非法,请求报文中数据查询数量超出查询范围！");
            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        if((BeginAddress+DataNumber-1) > ADDRESS_MAX)
        {
            //发送异常报文，异常02
            AbnormalFunctionCode = 0x02;
            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("线圈查询非法,请求报文中起始地址后可读取的线圈数量小于查询数量！");
            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        break;
    }

    //正常响应
    //获取查询数据
    QByteArray data;
    if(MessageArray.at(7) == 1)
    {
        data = GetData0X01(BeginAddress,DataNumber);
    }
    else if( MessageArray.at(7) == 3)
    {
        data = GetData0X03(BeginAddress,DataNumber);
    }
    //生成正常响应报文
    QByteArray res = NormalResponseMessageBuild0X010X03(MessageArray,data);
    //发送响应报文
    NormalResponseMessageSend(res);
    return true;

}
//0x0f 0x10 生成正常响应报文 并调用报文发送函数
bool Widget::AnalysisMessage0X0f0X10(QByteArray MessageArray)
{
    //异常报文响应
    //0x0f
    //字节数
    //数据项长度和字节字段
    //0x10
    //字节数
    //数据项和字节字段
    if(MessageArray.size() < TCP_MIN_LENGTH)
    {
        ui->messageBox->append("请求报文长度错误！");
        return false;
    }
    quint8 AbnormalFunctionCode;
    QByteArray AbnormalResponseMessage;
    //判断顺序：
    //获取数据起始地址和数量
    quint16 BeginAddress;
    BeginAddress = ((quint8)MessageArray[8] << 8) | (quint8)MessageArray[9];
    quint16 DataNumber;
    DataNumber = ((quint8)MessageArray[10] << 8) | (quint8)MessageArray[11];
    //报文数量是否合法
    switch(MessageArray.at(7))
    {
    case 15:
        //写入数量
        if(DataNumber < WRITE_COIL_MINNUM || DataNumber > WRITE_COIL_MAXNUM)
        {
            //发送异常报文，异常码03
            AbnormalFunctionCode = 0x03;
            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
            AbnormalMessageSend(AbnormalResponseMessage);
            //异常提示
            ui->messageBox->append("线圈写入数量非法,请求报文中数据写入数量超出写入范围！");
            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        //起始地址+写入数量
        if((BeginAddress+DataNumber-1) > ADDRESS_MAX)
        {
            //发送异常报文，异常码02
            AbnormalFunctionCode = 0x02;
            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("线圈写入非法,请求报文中起始地址后可写入的线圈数量小于写入数量！");
            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        //字节字段 写入数量
        quint8 DataByteNumber;
        DataByteNumber = (quint8)MessageArray.at(12);
        if(DataByteNumber != (DataNumber+7)/8)
        {
//            AbnormalFunctionCode = 0x03;
//            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
//            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("线圈写入非法,请求报文中字节字段与写入数量所需要的字节不一致！");
           // ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        //数据项长度 字节字段
        if(DataByteNumber != (MessageArray.size() - 13))
        {
//            AbnormalFunctionCode = 0x03;
//            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
//            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("线圈写入非法,请求报文中数据字节字段与数据项实际字节长度不一致！");
            //ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        break;
    case 16:
        //写入数量
        if(DataNumber < WRITE_REGISTER_MINNUM || DataNumber > WRITE_REGISTER_MAXNUM)
        {
            //发送异常报文，异常码03
            AbnormalFunctionCode = 0x03;
            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("寄存器写入数量非法,请求报文中数据写入数量超出写入范围！");
            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        //起始地址 + 写入数量
        if((BeginAddress+DataNumber-1) > ADDRESS_MAX)
        {
            //发送异常报文，异常02
            AbnormalFunctionCode = 0x02;
            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("寄存器写入非法,请求报文中起始地址后可写入的寄存器数量小于写入数量！");
            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        //字节字段  写入数量
        quint16 ByteNumber;
        ByteNumber = (quint8)MessageArray[12];

        if((2*DataNumber) != ByteNumber)
        {
//            AbnormalFunctionCode = 0x03;
//            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
//            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("字节字段错误,请求报文中数据字节数与写入数量对应的字节数不一致！");
//            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        //数据项长度 字节字段是否匹配
        quint8 RegistersByteNumber = MessageArray.size() - 13;
        if(RegistersByteNumber != (quint8)MessageArray[12])
        {
//            AbnormalFunctionCode = 0x03;
//            AbnormalResponseMessage = AbnormalMessageBuild(MessageArray,AbnormalFunctionCode);
//            AbnormalMessageSend(AbnormalResponseMessage);
            ui->messageBox->append("数据项字节错误,请求报文中数据项字节数与数据字节字段不一致！");
//            ShowResponseMessage(AbnormalResponseMessage);
            return false;
        }
        break;
    }

    //正常报文响应
    //初始化响应报文
    QByteArray ResponseMessage;
    ResponseMessage.resize(REQUEST_MESSAGE_LENGTH_0X01_0X03); //正常报文长度
    for(int i=0;i<REQUEST_MESSAGE_LENGTH_0X01_0X03;i++)
    {
        ResponseMessage[i]=MessageArray[i];
    }
    ResponseMessage[4]=(quint8)0;
    ResponseMessage[5]=(quint8)6;

    //获取修改数据的地址
    quint16 ReceiveDataAddress;
    ReceiveDataAddress = ((quint8)MessageArray[8]<<8) | (quint8)MessageArray[9];
    //获取修改数据的数量
    quint16 ReceiveDataNumber;
    ReceiveDataNumber =((quint8)MessageArray[10]<<8) | (quint8)MessageArray[11];
    //获取修改数据的值
    QByteArray ReceiveData;
    ReceiveData.resize(MessageArray.size() - REQUEST_MESSAGE_LENGTH_0X01_0X03-1);
    for(int i =0;i<ReceiveData.size();i++ )
    {
        ReceiveData[i]=MessageArray[i+REQUEST_MESSAGE_LENGTH_0X01_0X03+1];
    }

    //数据写入
    QString res;
    switch(MessageArray.at(7))
    {
    case 15:
        //0x0f
        //显示写入的线圈值
        ui->messageBox->append("----------------------写入线圈----------------------");
        ui->messageBox->append("线圈起始地址："+QString::number(BeginAddress)+"    "+"写入数量："+QString::number(ReceiveDataNumber));
        ShowCoilsData(ReceiveData,ReceiveDataNumber);
        ui->messageBox->append("-----------------------—----------------------------");
        //线圈写入
        res = HexByteArrayToBinString(ReceiveData);
        UpdateCoilsData(ReceiveDataAddress,ReceiveDataNumber,res);
        break;
    case 16:
        //0x10 写多个寄存器
        //显示写入的寄存器值
        ui->messageBox->append("----------------------写入寄存器----------------------");
        ui->messageBox->append("寄存器起始地址："+QString::number(BeginAddress)+"    "+"写入数量："+QString::number(ReceiveDataNumber));
        ShowRegisterData(ReceiveData);
        ui->messageBox->append("-----------------------------------------------------------");

        //寄存器写入
        res = HexByteArrayToDecString(ReceiveData);
        UpdateRegistersData(ReceiveDataAddress,ReceiveDataNumber,res);
        break;
    }
    NormalResponseMessageSend(ResponseMessage);
    return true;
}

void Widget::ShowCoilsData(QByteArray CoilsDataArray,quint16 ReceiveDataNumber)
{
    //取出需要写入的线圈值，并显示
    QString dataObtained;
    for(int i = 0; i < CoilsDataArray.size(); i++)
    {
        //先转化为2进制字符串
        QString str = QString::number((quint8)CoilsDataArray.at(i),2);
        //再转化为2进制整形，由二进制整形转化为8位2进制字符串前面自动补0，从而保证8位
        str = QString("%1").arg((quint8)str.toInt(NULL,2),8,2,QChar('0'));
        //8bit字节倒转
        byteReverse(str);
        //添加到数据中
        dataObtained += str;
    }
    //去除填充的0位，读出请求报文请求的线圈数
    dataObtained = dataObtained.left(ReceiveDataNumber);

    //每个线圈用空格隔开
    QString res;
    for(int i=0;i<dataObtained.size();i++)
    {
        res += dataObtained[i];
        res += " ";
    }

    ui->messageBox->append("线圈写入："+res);
}

void Widget::ShowRegisterData(QByteArray RegistersDataArray)
{

    //显示需要写入寄存器的值
    QString dataObtained;
    for(int i = 0; i < RegistersDataArray.size(); i += 2)
    {
        dataObtained += QString::number(BondTwoUint8ToUint16((quint8)RegistersDataArray.at(i),(quint8)RegistersDataArray.at(i+1)));
        dataObtained += " ";
    }
    ui->messageBox->append("寄存器写入："+dataObtained);
}
//0x01功能码 获取线圈数据
QByteArray Widget::GetData0X01(quint16 BeginAddress,quint16 Number)
{
    //声明读取的数据字符串
    QString getDataString;
    quint8 responseMessageByteNum;
    //求响应报文字节数
    responseMessageByteNum = (quint8)((Number + 7) / 8);

    //从数据表中读取需要数量的线圈数据,形成二进制形式字符串
    for(int i = BeginAddress; i < (BeginAddress + Number); i++)
    {
        QString buffer = ui->coilsTable->item(1,i)->text();
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
    for(int i = 1; i <= (8*responseMessageByteNum - Number); i++)
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
//0x03功能码 获取寄存器数据
QByteArray Widget::GetData0X03(quint16 BeginAddress,quint16 Number)
{
    //声明读取的数据字符串
    QString getDataString;
    //声明响应报文字节数项
    quint8 responseMessageByteNum;

    //求响应报文字节数项，为请求报文数量项的两倍，一个寄存器两个字节
    responseMessageByteNum = Number*2;

    //声明线圈数据数组
    QByteArray registersDataArr;
    registersDataArr.resize(responseMessageByteNum);

    //从数据表中读取需要数量的寄存器数据,形成二进制形式字符串
    for(int i = 0; i < Number; i++)
    {
        //取出10进制字符串
        getDataString = ui->registersTable->item(1,(i + BeginAddress))->text();
        //转化为2进制字符串，不足补0，凑足16位
        getDataString  = QString("%1").arg((quint16)getDataString.toInt(NULL,10),16,2,QLatin1Char('0'));
        //前8位为一个字节
        registersDataArr[2*i] = getDataString.mid(0,8).toInt(NULL,2);
        //后8位为一个字节
        registersDataArr[2*i + 1] = getDataString.mid(8,8).toInt(NULL,2);
    }

    return registersDataArr;
}
//0x0f功能码 写入线圈数据  单个线圈
void Widget::WriteData0X0F(int Column,QString CoilData)
{
    //锁住写入线圈数据信号，进行阻塞
    ui->coilsTable->blockSignals(true);

    //更新ini文件数据
    settings->setValue("Section" + QString::number(Column + 1) + "/coil",CoilData);
    //qDebug() << settings->value("Section" + QString::number(Column + 1) + "/coil").toString() << endl;

    //更新线圈数据表中数据
    if(CoilData == "1")
    {
        CoilData = "ON";
    }
    else
    {
        CoilData = "OFF";
    }
    ui->coilsTable->setItem(1,Column,new QTableWidgetItem(CoilData));
    //设置表格内文字水平+垂直对齐
    ui->coilsTable->item(1,Column)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    //解锁写入线圈数据信号
    ui->coilsTable->blockSignals(false);
}
//0x0f功能码 将16进制字节数组转化为 2进制字符串
QString Widget::HexByteArrayToBinString(QByteArray DataArray)
{
    //2进制字符串的长度
    quint16 DataArrayLength;
    DataArrayLength = DataArray.size();

    QString res;
    for(int i = 0; i < DataArrayLength; i++)
    {
        //先转化为2进制字符串
        QString str = QString::number((quint8)DataArray.at(i),2);
        //再转化为2进制整形，由二进制整形转化为8位2进制字符串前面自动补0，从而保证8位
        str = QString("%1").arg((quint8)str.toInt(NULL,2),8,2,QChar('0'));
        //8bit字节倒转
        byteReverse(str);
        res += str;
    }
    return res;
}
//更新线圈数据
void Widget::UpdateCoilsData(quint16 BeginAddress,quint16 DataNumber,QString DataString)
{

    for(int i=0;i<DataNumber;i++)
    {
        int Column = BeginAddress + i;
        QString coilData = DataString.at(i);
        WriteData0X0F(Column,coilData);
    }
}
//0x10功能码 写入寄存器数据
void Widget::WriteData0X10(int Column,QString registerData)
{
    //锁住写入寄存器数据信号，进行阻塞
    ui->registersTable->blockSignals(true);

    //更新ini文件数据
    settings->setValue("Section" + QString::number(Column + 1) + "/regi",registerData);

    //更新线圈数据表中数据
    ui->registersTable->setItem(1,Column,new QTableWidgetItem(registerData));

    //设置表格内文字水平+垂直对齐
    ui->registersTable->item(1,Column)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    //解锁写入寄存器数据信号
    ui->registersTable->blockSignals(false);
}
//0x10功能码 将16进制字节数组转化为 10进制字符串，每个寄存器的10进制字符串用空格分隔
QString Widget::HexByteArrayToDecString(QByteArray DataArray)
{
    QString res;
    quint16 DataArrayLength = DataArray.size();
    for(int i = 0; i < DataArrayLength; i += 2)
    {
        res += QString::number(BondTwoUint8ToUint16((quint8)DataArray.at(i),(quint8)DataArray.at(i+1)));
        res +=" ";
    }
    return res;
}
//0x10 更新寄存器数据
void Widget::UpdateRegistersData(quint16 BeginAddress, quint16 DataNumber, QString DataString)
{
    QString temp;
    int j=0;
    for(int i=0;i<DataNumber;i++)
    {
        while(j< DataString.size() && DataString[j] != ' ')
        {
            temp +=DataString[j];
            j++;
        }
        WriteData0X10(BeginAddress+i,temp);
        temp.clear();
        j++;
    }

}
//数据表转到指定位置
void Widget::Search(int type)
{
    //1为线圈数据表搜索，2为寄存器数据表搜索
    if(type == 1)
    {
        //获取用户输入的搜索地址
        int coilIndex = ui->coilSearchNumber->text().toInt(NULL,10);

        //获取搜索位置的指针
        QTableWidgetItem *coilItem = ui->coilsTable->item(NULL,coilIndex);

        //将数据表的显示设定为指定指针
        ui->coilsTable->setCurrentItem(coilItem);
        //滚动到指向位置，并将指定位置显示在表格顶部
        ui->coilsTable->scrollToItem(coilItem,QAbstractItemView::PositionAtCenter);
    }
    else
    {
        //获取用户输入的搜索地址
        int registerIndex = ui->registerSearchNumber->text().toInt(NULL,10);

        //获取搜索位置的指针
        QTableWidgetItem *registerItem = ui->registersTable->item(NULL,registerIndex);

        //将数据表的显示设定为指定指针
        ui->registersTable->setCurrentItem(registerItem);
        //滚动到指向位置，并将指定位置显示在表格顶部
        ui->registersTable->scrollToItem(registerItem,QAbstractItemView::PositionAtCenter);
    }
}
//0x01 0x03 生成正常响应报文
QByteArray Widget::NormalResponseMessageBuild0X010X03(QByteArray MessageArray,QByteArray DataArray)
{
    //MessageArray 接收到的字节数组
    QByteArray RespondeMessageArr;

    //响应报文总字节数
    quint16 RespondeMessageBytesNum;

    //2+2+2+1+1  即事务元标志符+协议标识符+（后续报文）长度+ 地址 + 功能码
    RespondeMessageBytesNum = 8 + 1 + (quint16)DataArray.size();
    quint16 length = RespondeMessageBytesNum - 6;
    RespondeMessageArr.resize(RespondeMessageBytesNum);

    //事务元标识符
    RespondeMessageArr[0]=MessageArray[0];
    RespondeMessageArr[1]=MessageArray[1];
    //协议地址
    RespondeMessageArr[2]=MessageArray[2];
    RespondeMessageArr[3]=MessageArray[3];
    //后续包长度
    RespondeMessageArr[4]= length>>8;
    RespondeMessageArr[5]= length & 0xff;
    //地址
    RespondeMessageArr[6]= MessageArray[6];
    //功能码
    RespondeMessageArr[7]=MessageArray[7];
    //数据长度
    RespondeMessageArr[8]= (quint8)DataArray.size();
    //数据
    for(int i=0;i < DataArray.size();i++)
    {
        RespondeMessageArr[i+9]=DataArray[i];
    }
    return RespondeMessageArr;
}

//异常报文生成
QByteArray Widget::AbnormalMessageBuild(QByteArray MessageArray,quint8 AbnormalFunctionCode)
{
    //响应报文总字节数
    quint16 RespondeMessageBytesNum;
    //2+2+2+1+1+1  即事务元标志符+协议标识符+（后续报文）长度+ 地址 + 功能码+异常码
    RespondeMessageBytesNum = 8 + 1;

    QByteArray RespondeMessageArr;
    quint16 length = RespondeMessageBytesNum - 6;
    RespondeMessageArr.resize(RespondeMessageBytesNum);

    //事务元标识符
    RespondeMessageArr[0]=MessageArray[0];
    RespondeMessageArr[1]=MessageArray[1];
    //协议地址
    RespondeMessageArr[2]=MessageArray[2];
    RespondeMessageArr[3]=MessageArray[3];
    //后续包长度
    RespondeMessageArr[4]= length>>8;
    RespondeMessageArr[5]= length & 0xff;
    //地址
    RespondeMessageArr[6]= MessageArray[6];
    //功能码
    quint8 FunctionCode;
    FunctionCode = (quint8)MessageArray[7] +0x80;
    RespondeMessageArr[7]=FunctionCode;
    RespondeMessageArr[8]=AbnormalFunctionCode;

    return RespondeMessageArr;
}

//异常报文发送
void Widget::AbnormalMessageSend(QByteArray Message)
{
      if(TcpServerConnectState)
      {
          tcpReceiveSocket->write(Message);
      }
}

//正常报文响应发送
void Widget::NormalResponseMessageSend(QByteArray MessageArray)
{
    if(TcpServerConnectState)
    {
        tcpReceiveSocket->write(MessageArray);
        ShowResponseMessage(MessageArray);
    }

}

//字节翻转函数
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
//将ini文件中的数据放到对应的表格中
void Widget::ReadOutIniData(void)
{
    for(int i = 0; i < (ADDRESS_MAX + 1); i++)
    {
        //地址设置
        QString adr =  "0x" + QString("%1").arg(i,4,16,QLatin1Char('0'));
        ui->coilsTable->setItem(0,i, new QTableWidgetItem(QString(adr)));
        ui->coilsTable->item(0,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->registersTable->setItem(0,i, new QTableWidgetItem(QString(adr)));
        ui->registersTable->item(0,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
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
        ui->coilsTable->setItem(1,i,new QTableWidgetItem(coilData));
        //设置表格内文字水平+垂直对齐
        ui->coilsTable->item(1,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        //在寄存器数据表中显示数据
        ui->registersTable->setItem(1,i,new QTableWidgetItem(registerData));
        //设置表格内文字水平+垂直对齐
        ui->registersTable->item(1,i)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
}

//两个quint8 合并成一个 quint16
quint16 Widget::BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum)
{
    quint16 bondNum = (preNum << 8) | afterNum;
    return bondNum;
}

//16进制字节数组转化为16进制字符串
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

//将消息写入到日志文件
void Widget::WriteHistoricalMessage()
{
    //将历史记录写入文件，使用追加方式写入文件
    QFile file(RECORD_PATH);
    file.open(QFileDevice::Append);
    file.write(ui->messageBox->toPlainText().toUtf8().data());
    //消息分块
    file.write("\n\n");
    //清除消息框中的内容
    ui->messageBox->clear();
    file.close();
}

void Widget::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton close;
    close = QMessageBox::question(this,"提示","确认退出程序？",QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

    if(close == QMessageBox::Yes)
    {
        //关闭界面，保存日志
        //消息框内显示清除的时间，和文件夹路径
        QFileInfo info(RECORD_PATH);
        //时间
        TimeInformation();
        //消息窗口显示信息
        ui->messageBox->append("保存至路径：" + info.filePath() + "\n文件名称：" + info.fileName()
                                + "\n文件大小：" + QString::number(info.size()) + "\n创建日期：" + info.created().toString("yyyy-MM-dd hh:mm:ss")
                                + "\n最后保存日期：" + info.lastModified().toString("yyyy-MM-dd hh:mm:ss") + "\n");
        WriteHistoricalMessage();
        event->accept();
    }
    else
    {
        event->ignore();
    }

}

Widget::~Widget()
{
    delete ui;
}
