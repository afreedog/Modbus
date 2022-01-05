#include "widget.h"
#include "ui_widget.h"
#include "historymessagedialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = startTimer(CLOCK_REFRESH);

    //初始化历史消息窗口对象
    HistoryMessageWindow = new HistoryMessageDialog(this);

    //初始化服务器参数
    ServerInit();
    //初始化请求窗口
    RequestInit();
    //设置消息框为只读类型
    ui->messageEdit->setReadOnly(true);

    //生成套接字tcpSocket
    tcpSocket = NULL;
    tcpSocket = new QTcpSocket(this);
    tcpSocket->setSocketOption(QAbstractSocket::LowDelayOption,0);

    //按下连接控制按钮触发连接或者断开
    connect(ui->connectButton,&QPushButton::clicked,this,&Widget::TcpConnect);
    //Tcp连接成功触发的槽函数
    connect(tcpSocket,&QTcpSocket::connected,this,&Widget::ConnectSuccessPrompt);
    //Tcp断开连接时触发的槽函数
    connect(tcpSocket,&QTcpSocket::disconnected,[=](){
        //TCP断开连接
        TcpDisConnect();
        //提示断开连接
        ConnectBrokensPrompt();
    });

    //功能码改变触发槽函数
    connect(ui->funcCodeBox,SIGNAL(currentIndexChanged(int)),this,SLOT(FuncCodeSetNumLineEdit(int)));

    //按下发送按钮触发TCP主站请求报文函数
    connect(ui->sendButton,&QPushButton::clicked, [=](){
        TCPRequestMessage(ui->funcCodeBox->currentIndex());
    });

    //当有可读数据时触发的槽函数
    connect(tcpSocket,&QTcpSocket::readyRead,[=](){
        //将可读的数据存入数组
        QByteArray bufferArray = tcpSocket->readAll();
        TCPAnalysisMessage(bufferArray);
    });

    //消息框更新显示槽函数
    connect(ui->messageEdit,&QTextEdit::textChanged,[=](){
         ui->messageEdit->moveCursor(QTextCursor::End);
    });

    //历史信息路径重置槽函数
    connect(ui->ResetFilePahtButton,&QPushButton::clicked,[=](){
        ResetFilePath();
    });
    //点击查看历史消息，启动查看历史消息函数
    connect(ui->historyButton,&QPushButton::clicked,[=](){
        ViewHistoricalMessage();
    });

    //点击清除窗口按钮时，启动清除消息窗口函数
    connect(ui->clearButton,&QPushButton::clicked,[=](){
        //清除消息窗口函数
        ClearMessageWin();
    });

    //数据查询
    connect(ui->CoilsSearchButton,&QPushButton::clicked,[=](){
        Search(1);
    });
    connect(ui->RegisterSearchButton,&QPushButton::clicked,[=](){
        Search(2);
    });
    connect(ui->beginAddressLineEdit,&QLineEdit::textChanged,[=](){
        if(ui->beginAddressLineEdit->text().toInt()+ui->numLineEdit->text().toInt() > 65536)
        {
            QMessageBox::warning(this,"提示","请检查起始地址和数量是否合法！",QMessageBox::Ok,QMessageBox::NoButton);
            ui->beginAddressLineEdit->clear();
        }

    });
    connect(ui->numLineEdit,&QLineEdit::textChanged,[=](){
        if(ui->beginAddressLineEdit->text().toInt()+ui->numLineEdit->text().toInt() > 65536)
        {
              QMessageBox::warning(this,"提示","请检查起始地址和数量是否合法！",QMessageBox::Ok,QMessageBox::NoButton);
            ui->numLineEdit->clear();
        }
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
    if(tmp == timer)
    {
        showDateTime();
    }
}

/****************************************************初始化***************************************************/
//1. 初始化服务器参数设置
void Widget::ServerInit()
{
    //初始化设置对象
    settings = new QSettings(DATA_FILE_PATH,QSettings::IniFormat);

    //设置默认地址的背景显示
    ui->ipEdit->setPlaceholderText(defaultIpAddress);
    ui->portEdit->setPlaceholderText(QString::number(defaultPortAddress));
    //设置IP默认值
    IpDefault();
    //设置port默认值
    PortDefault();
    //初始化数据显示
    DataInitialization();
    //设置搜索框默认背景
    ui->CoilSearchNumber->setPlaceholderText("0-65535");
    ui->CoilSearchNumber->setValidator(new QIntValidator(0, 65535, this));

    ui->RegisterSearchNumber->setPlaceholderText("0-65535");
    ui->RegisterSearchNumber->setValidator(new QIntValidator(0, 65535, this));
}

//2. 初始化请求窗口设置
void Widget::RequestInit()
{
    //从机地址选项添加
    for(int i = 0; i < MAXSLAVENUMBER; i++)
    {
        ui->slaveAddressBox->addItem(QString::number(i + 1));
    }
    //功能码选项添加
    QStringList strList;
    strList << "0x01" << "0x03" << "0x0f" << "0x10";
    ui->funcCodeBox->addItems(strList);
    //设置默认地址的背景提示
    ui->beginAddressLineEdit->setPlaceholderText("0 - 0xFFFF");
    //限制线圈和寄存器的地址范围为0-0xFFFF
    ui->beginAddressLineEdit->setValidator(new QIntValidator(ADDRESS_MIN, ADDRESS_MAX, this));
    //设置数量的背景提示
    ui->numLineEdit->setPlaceholderText("1 - 2000");
    ui->numLineEdit->setValidator(new QIntValidator(1,2000,this));

}

//3. 设置ip默认值函数
void Widget::IpDefault()
{
    //IP未设置，设置默认值
    if(ui->ipEdit->text().isEmpty())
    {
        ipAddress = defaultIpAddress;
        ui->ipEdit->setText(ipAddress);
    }
}
//4. 设置port默认值函数
void Widget::PortDefault()
{
    //端口未设置，设置默认值
    if(ui->portEdit->text().isEmpty())
    {
        portAddress = defaultPortAddress;
        ui->portEdit->setText(QString::number(portAddress));
    }
}

//5. 功能码配置函数，设置不同的功能码设置对应的数量范围并限制其取值
void Widget::FuncCodeSetNumLineEdit(int FCBIndex)
{
    if(FCBIndex == 0) //读输出线圈 0x01 看响应报文：数据最多250byte = 2000bit
    {
        ui->numLineEdit->setPlaceholderText("1 - 2000");
        ui->numLineEdit->setValidator(new QIntValidator(READ_COIL_MINNUM, READ_COIL_MAXNUM, this));
    }
    else if(FCBIndex == 1)  //读输出寄存器 0x03 看响应报文：数据最多250byte = 125个寄存器
    {
        ui->numLineEdit->setPlaceholderText("1 - 125");
        ui->numLineEdit->setValidator(new QIntValidator(READ_REGISTER_MINNUM, READ_REGISTER_MAXNUM, this));
    }
    else if(FCBIndex == 2)  //写多个输出线圈 0x0F 看请求报文：数据最多246byte = 1968bit
    {
        ui->numLineEdit->setPlaceholderText("1 - 1968");
        ui->numLineEdit->setValidator(new QIntValidator(WRITE_COIL_MINNUM, WRITE_COIL_MAXNUM, this));
    }
    else  //写多个输出寄存器  0x10 看请求报文：数据最多246byte = 123个寄存器
    {
        ui->numLineEdit->setPlaceholderText("1 - 123");
        ui->numLineEdit->setValidator(new QIntValidator(WRITE_REGISTER_MINNUM, WRITE_REGISTER_MAXNUM, this));
    }
}

/**************************************************提示信息函数**************************************************/
//1. 提示连接成功函数
void Widget::ConnectSuccessPrompt()
{
    QMessageBox::information(this,"提示","连接服务器成功！",QMessageBox::Ok);
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("成功连接至服务器!");
    ui->messageEdit->append("IP地址："+ ipAddress + "    端口号：" + QString::number(portAddress));
}
//2. 提示连接失败函数
void Widget::ConnectFailurePrompt()
{
    QMessageBox::warning(this,"提示","连接服务器超时！",QMessageBox::Ok,QMessageBox::NoButton);
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("连接服务器超时，请重新操作！");
}

//3. 提示连接断开函数
void Widget::ConnectBrokensPrompt()
{
    //时间
    TimeInformation();
    //显示断开连接
    ui->messageEdit->append("与服务器断开连接！");
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
    ui->messageEdit->append("保存至路径：" + info.filePath() + "\n文件名称：" + info.fileName()
                            + "\n文件大小：" + QString::number(info.size()) + "\n创建日期：" + info.created().toString("yyyy-MM-dd hh:mm:ss")
                            + "\n最后保存日期：" + info.lastModified().toString("yyyy-MM-dd hh:mm:ss") + "\n");
}

/******************************************************TCP函数*****************************************************/
//1. TCP连接函数,按下按钮触发连接或断开
void Widget::TcpConnect()
{
    //判断当前是等待连接状态还是已连接状态
    if(ui->connectButton->text() == "连接")
    {
        //若存在连接，则取消原有连接，重置套接字
        tcpSocket->abort();

        //设置IP默认值
        IpDefault();
        //设置port默认值
        PortDefault();

        //获取服务器地址信息
        //获取输入的ip地址
        ipAddress = ui->ipEdit->text();
        //获取输入的端口号,将字符串转换成16位int型
        portAddress = ui->portEdit->text().toInt();

        //进行当前连接，连接至指定从站的指定端口
        tcpSocket->connectToHost(QHostAddress(ipAddress),portAddress);

        //判断连接是否成功，连接成功后进行提示并将按钮设置为断开
        if(!tcpSocket->waitForConnected(WAITE_FOR_CONNECT))
        {
            //提示连接超时
            ConnectFailurePrompt();
        }
        else
        {
            //设置TCP连接状态标识符为连接
            TcpConnectIdentifier = true;
            ui->connectButton->setText("断开");
        }
    }
    else
    {
        //二次确认是否断开连接
        DisConnectConfirm();
    }
}

//2. 二次确认断开连接函数
void Widget::DisConnectConfirm()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"提示","确认与服务器断开连接?",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    //如果选择确认，则断开连接
    if(reply == QMessageBox::Yes)
    {
        TcpDisConnect();
    }
}

//3. TCP断开函数，按下断开按钮并确认后触发函数
void Widget::TcpDisConnect()
{
    //设置TCP连接状态标识符为断开
    TcpConnectIdentifier = false;
    //断开与服务器的连接
    tcpSocket->disconnectFromHost();
    //关闭套接字
    tcpSocket->close();
    //设置连接按钮为等待连接状态
    ui->connectButton->setText("连接");
    //设置TCP请求报文发送状态为离线
    TCPSendIdentifier = false;
    //清空请求报文数组
    requestMessage.clear();
    return;
}

/****************************************************消息处理函数***************************************************/
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
    //当前路径为空
    //设置自定义路径
    if(path == NULL)
    {
         path = QFileDialog::getOpenFileName(this,"打开文件","../ModBus_TCP_master","TEXT(*.txt)");
         ui->messageEdit->append("自定义路径设置成功！");
         FileInformation();
    }

    //自定义路径为空
    if(path == NULL)
    {
        //提示没有文件路径
        NoFilePathPrompt();
        //提示文件打开失败
        FailedOpenFilePrompt();
        //设置默认路径
        path = RECORD_FILE_PATH;
        ui->messageEdit->append("使用默认路径！");
        FileInformation();
    }

    //打开显示窗口显示历史记录内容，传入路径参数
    HistoryMessageWindow->ShowHistoricalMessage(path);
}

//3. 写历史消息函数
void Widget::WriteHistoricalMessage()
{
    //路径为空时，设置为默认路径
    if(path == NULL)
    {
        path = RECORD_FILE_PATH;
    }
    //将历史记录写入文件，使用追加方式写入文件
    QFile file(path);
    file.open(QFileDevice::Append);
    file.write(ui->messageEdit->toPlainText().toUtf8().data());
    //消息分块
    file.write("\n\n");
    //清除消息框中的内容
    ui->messageEdit->clear();
    //消息框内显示清除的时间，和文件夹路径
    file.close();
}

/****************************************************请求报文函数***************************************************/
//1. TCP主站请求报文函数
void Widget::TCPRequestMessage(int funcCodeIndex)
{
    //判断功能码
    switch(funcCodeIndex)
    {
    case 0:
    {
        //读输出线圈0x01和读输出寄存器0x03请求报文处理函数
        RequestMessage0x010x03();
        break;
    }
    case 1:
    {
        //读输出线圈0x01和读输出寄存器0x03请求报文处理函数
        RequestMessage0x010x03();
        break;
    }
    case 2:
    {
        //写多个输出线圈0x0F和写多个输出寄存器0x10请求报处理函数
        RequestMessage0x0F0x10();
        break;
    }
    case 3:
    {
        //写多个输出线圈0x0F和写多个输出寄存器0x10请求报处理函数
        RequestMessage0x0F0x10();
        break;
    }
    }

    for(resendNumber = 0; resendNumber < RESENDNUMBER; resendNumber++)
    {
        //使主线程先处理主界面刷新，避免假死
        QApplication::processEvents();
        if(!tcpSocket->waitForReadyRead(WAITE_FOR_RESPONSE))
        {
            //使用TCP向目标从站重新传输请求报文
            tcpSocket->write(requestMessage);
            ui->messageEdit->append("从站无响应！");
            ui->messageEdit->append("已向目标从站第"
                                    + QString::number(resendNumber + 1)
                                    + "次重新发送报文");
        }
        else
        {
            //设置TCP请求报文发送状态为离线
            TCPSendIdentifier = false;
            return;
        }
    }

    //重传次数费完
    //显示错误
    TimeInformation();
    ui->messageEdit->append("重传无效！无法收到目标从站的响应！");
    //设置TCP请求报文发送状态为离线
    TCPSendIdentifier = false;
    //清空请求报文数组
    requestMessage.clear();

    return;
}

//2. 结构体初始化函数
void Widget::structInitialize(MessageBasicInformation *structPt)
{
    //事务元标识符赋值
    //structPt->transactionIdenti = transactionIdentifier++;
    structPt->transactionIdenti = (quint16)1;
    //协议标识符，ModBus协议标识符为0
    structPt->protocolIdenti = (quint16)0;
    //单元标识符赋值
    structPt->unitIdenti = ui->slaveAddressBox->currentText().toUShort();
    //起始地址赋值
    structPt->beginAddr = ui->beginAddressLineEdit->text().toUShort();
    //数量赋值
    structPt->num = ui->numLineEdit->text().toUShort();
    //长度
    structPt->length = 6;

    //功能码赋值
    switch(ui->funcCodeBox->currentIndex())
    {
    //读输出线圈0x01
    case 0:
    {
        structPt->funcCode = (quint8)1;
        break;
    }
    //读输出寄存器0x03
    case 1:
    {
        structPt->funcCode = (quint8)3;
        break;
    }
    //读输出寄存器0x0F
    case 2:
    {
        structPt->funcCode = (quint8)15;
        break;
    }
    //读输出寄存器0x10
    case 3:
    {
        structPt->funcCode = (quint8)16;
        break;
    }
    }
}

//3. 读输出线圈0x01和读输出寄存器0x03请求报文处理函数
void Widget::RequestMessage0x010x03()
{
    //初始化结构体
    MessageBasicInformation  MessageBasicInfo;
    structInitialize(&MessageBasicInfo);
    //读输出线圈0x01和读输出寄存器0x03请求报文构建函数
    requestMessage = RequestMessage0x010x03Build(&MessageBasicInfo);
    //发送请求报文
    TCPRequestMessageSend();
}

//4. 读输出线圈0x01和读输出寄存器0x03请求报文构建函数
QByteArray Widget::RequestMessage0x010x03Build(MessageBasicInformation *structPt)
{
    QByteArray requestMess;
    //设置请求报文数组大小为12，即该报文长度为12字节
    requestMess.resize(REQUEST_MESSAGE_LENGTH_0X01_0X03);

    /***********************************将数据放入报文数组***********************************/
    //事务元标识符：2字节
    requestMess[0] = structPt->transactionIdenti >> 8;
    requestMess[1] = structPt->transactionIdenti & 0xff;
    //协议标识符：2字节
    requestMess[2] = structPt->protocolIdenti >> 8;
    requestMess[3] = structPt->protocolIdenti & 0x0ff;
    //长度标识符：2字节
    requestMess[4] = structPt->length >> 8;
    requestMess[5] = structPt->length & 0x0ff;
    //单元标识符：1字节
    requestMess[6] = structPt->unitIdenti;
    //功能码：1字节
    requestMess[7] = structPt->funcCode;
    //起始地址：2字节
    requestMess[8] = structPt->beginAddr >> 8;
    requestMess[9] = structPt->beginAddr & 0x0ff;
    //数量：2字节
    requestMess[10] = structPt->num >> 8;
    requestMess[11] = structPt->num & 0x0ff;

    return requestMess;
}

//5. 处理用户线圈输入函数，返回字节数组
QByteArray Widget::userCoilsInputProcess()
{
    /***********************************获取用户的线圈输入（二进制）*********************************/
    //判断字符串是否合法返回值，默认为false
    bool isLegal = false;

    //获取输入框内的字符串,默认为空
    QString writeCoils = NULL;
    //字符串长度，默认为0
    int writeCoilsLength = 0;
    //初始化对话框
    input = new inputDialog;
    input->setModal(true);
    input->hide();
    //发送按钮暂时关闭
    ui->sendButton->setEnabled(false);

    while((writeCoils.isEmpty())
         || (ui->numLineEdit->text().toInt() != writeCoilsLength)
          || (!isLegal))
    {
        //输入标题
        QString inputDialogTitle = "写多个输出线圈(二进制)";
        //输入提示
        QString writeGuide = "请输入你想写入的" + ui->numLineEdit->text() + "个线圈：";
        //获取字符串
        input->show();
        writeCoils = input->getText(inputDialogTitle,writeGuide);

        //获取字符串长度
        writeCoilsLength = writeCoils.length();
        //判断字符串合法性
        isLegal = coilsLegality(writeCoils);
    }

    delete input;
    //发送按钮打开
    ui->sendButton->setEnabled(true);

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

    QString test = HexByteArrayToHexString(coilsInputArr,coilsInputArr.size(),1);
    return coilsInputArr;
}

//6. 处理用户寄存器输入函数，返回字节数组
QByteArray Widget::userRegistersInputProcess()
{
    //获取输入寄存器数量
    int num = ui->numLineEdit->text().toInt();
    //需要的字节数，一个寄存器需要2字节
    int numOfByte = 2*num;
    //创建寄存器输入数组
    QByteArray RegistersInputArr;
    RegistersInputArr.resize(numOfByte);

    for(int i = 0; i < num; i++)
    {
        /***********************************获取用户的寄存器输入（10进制）*********************************/
        //判断字符串是否合法返回值，默认为false，合法值为0-65535
        bool isLegal = false;

        //获取输入框内的字符串,默认为空
        QString writeRegister = NULL;
        //寄存器
        int Register;
        //初始化模态对话框
        input = new inputDialog;
        input->setModal(true);

        input->hide();
        //发送按钮暂时关闭
        ui->sendButton->setEnabled(false);
        while(writeRegister.isEmpty() || (!isLegal))
        {
            //输入标题
            QString inputDialogTitle = "写十进制寄存器(0-65535)";
            //输入提示
            QString writeGuide = "请输入你想写入的第" + QString::number(i + 1) + "个寄存器：";
            //获取字符串
            input->show();
            writeRegister = input->getText(inputDialogTitle,writeGuide);
            //判断字符串合法性，转换为10进制判断
            Register = writeRegister.toInt(NULL,10);
            if((Register >= WRITE_REGISTER_VALUE_MINNUM) && (Register <= WRITE_REGISTER_VALUE_MAXNUM))
            {
                isLegal = true;
            }
        }

        delete input;
        //发送按钮打开
        ui->sendButton->setEnabled(true);

        //转化为2进制字符串，不足补0，凑足16位
        writeRegister = QString("%1").arg((quint16)writeRegister.toInt(NULL,10),16,2,QLatin1Char('0'));
        //前8位为一个字节
        RegistersInputArr[2*i] = writeRegister.mid(0,8).toInt(NULL,2);
        //后8位为一个字节
        RegistersInputArr[2*i + 1] = writeRegister.mid(8,8).toInt(NULL,2);
    }

    return RegistersInputArr;
}

//7. 写多个输出线圈0x0F和写多个输出寄存器0x10请求报处理函数
void Widget::RequestMessage0x0F0x10()
{
    //初始化结构体
    MessageBasicInformation  MessageBasicInfo;
    structInitialize(&MessageBasicInfo);

    //初始化输入字节数组
    QByteArray byteArray;
    //根据功能码的不同进行不同的用户输入处理
    if(MessageBasicInfo.funcCode == 15)
    {
        //获取用户线圈输入，返回字节数组
        byteArray = userCoilsInputProcess();
    }
    else
    {
        //获取用户寄存器输入，返回字节数组
        byteArray = userRegistersInputProcess();
    }

    //读输出线圈0x01和读输出寄存器0x03请求报文构建函数
    requestMessage = RequestMessage0x0F0x10Build(&MessageBasicInfo, byteArray);
    //发送请求报文
    TCPRequestMessageSend();
}

//8. 写多个输出线圈0x0F和写多个输出寄存器0x10请求报构建函数
QByteArray Widget::RequestMessage0x0F0x10Build(MessageBasicInformation *structPt, QByteArray byteArr)
{
    /*****************************************获取字节数*************************************/
    quint8 numOfByte = byteArr.size();
    /*****************************************获取长度项*************************************/
    quint16 length = structPt->length + numOfByte + 1;
    /****************************************构建请求报文*************************************/
    QByteArray requestMess;
    //设置请求报文数组大小
    requestMess.resize(REQUEST_MESSAGE_LENGTH_0X01_0X03 + 1 + numOfByte);
    /********************************MBAP报文头部分********************************/
    //事务元标识符：2字节
    requestMess[0] = structPt->transactionIdenti >> 8;
    requestMess[1] = structPt->transactionIdenti & 0xff;
    //协议标识符：2字节
    requestMess[2] = structPt->protocolIdenti >> 8;
    requestMess[3] = structPt->protocolIdenti & 0x0ff;
    //长度标识符：2字节
    requestMess[4] = length >> 8;
    requestMess[5] = length & 0x0ff;
    //单元标识符：1字节
    requestMess[6] = structPt->unitIdenti;
    //功能码：1字节
    requestMess[7] = structPt->funcCode;
    //起始地址：2字节
    requestMess[8] = structPt->beginAddr >> 8;
    requestMess[9] = structPt->beginAddr & 0x0ff;
    //数量：2字节
    requestMess[10] = structPt->num >> 8;
    requestMess[11] = structPt->num & 0x0ff;
    //字节数：1字节
    requestMess[12] = (quint8)numOfByte;
    //字节内容
    for(int i = 0; i < numOfByte; i++)
    {
        requestMess[13 + i] = byteArr[i];
    }

    return requestMess;
}

//9. TCP主站请求报文发送函数
void Widget::TCPRequestMessageSend()
{
    //判断当前TCP连接状态，如果连接则进行发送，如果断开则不发送，进行提示
    if(TcpConnectIdentifier == true)
    {
        //使用TCP向目标从站传输请求报文
        tcpSocket->write(requestMessage);

        //消息框显示发送成功的请求报文
        QString message;
        for(int i = 0; i < requestMessage.size(); i++)
        {
            message += QString("%1").arg((quint8)requestMessage.at(i),2,16,QLatin1Char('0'));
            message += " ";
        }
        //时间
        TimeInformation();
        //消息窗口显示信息
        ui->messageEdit->append("请求报文发送成功！ 报文为：" + message);

        //设置TCP请求报文发送状态为在线
        TCPSendIdentifier = true;
    }
    else
    {
        //连接失败，清空请求报文数组，需要重新操作
        requestMessage.clear();
        //时间
        TimeInformation();
        //消息窗口显示信息
        ui->messageEdit->append("服务器连接断开，请重新操作！");

        //设置TCP请求报文发送状态为离线
        TCPSendIdentifier = false;
    }
}

//10. 多线圈字符串合法性判断函数，如果出现0和1以外的数则为非法
bool Widget::coilsLegality(QString &coils)
{
    QByteArray ba = coils.toLatin1();

    const char *s = ba.data();
    bool bret = true;
    while(*s)
    {
        if(*s != '0' && *s != '1')
        {
            bret = false;
            break;
        }
        s++;
    }

    return bret;
}

//11.字节反转函数
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

/**************************************************解析响应报文函数*************************************************/
//1. 解析响应报文
bool Widget::TCPAnalysisMessage(QByteArray MessageArray)
{
    bool analysisResult;
    /***************************************处理报文*************************************/
    //初始化报文字符串
    QString readMessage;

    //将十六进制数据转化成字符串
    readMessage = HexByteArrayToHexString(MessageArray, MessageArray.size(), 1);

    /***************************************显示报文*************************************/
    //判断当前主站状态，若是等待消息状态则显示消息，否则提示不是需要的消息
    if(TCPSendIdentifier == true)
    {
        //显示响应报文
        ShowResponseMessage(readMessage);
    }
    else
    {
        //时间
        TimeInformation();
        //消息窗口显示信息
        ui->messageEdit->append("当前主站没有需要回复的请求！");
        return false;
    }

    /***************************************解析报文*************************************/
    //报文合法性判断
    analysisResult = MessageLegalJudge(MessageArray, requestMessage);
    if(analysisResult == false)
    {
        return false;
    }

    //处理匹配的正常响应码
    switch(MessageArray.at(7))
    {
    case 1:
    {
        //0X01功能码报文处理函数
        analysisResult = TCP0X01FuncCodeProcess(MessageArray, requestMessage);
        break;
    }

    case 3:
    {
        //0X03功能码报文处理函数
        analysisResult = TCP0X03FuncCodeProcess(MessageArray, requestMessage);
        break;
    }

    case 15:
    {
        //0X0f功能码报文处理函数
        analysisResult = TCP0X0fFuncCodeProcess(MessageArray, requestMessage);
        break;
    }

    case 16:
    {
        //0X10功能码报文处理函数
        analysisResult = TCP0X10FuncCodeProcess(MessageArray, requestMessage);
        break;
    }
    }

    if(analysisResult == true)
    {
        //清空请求报文数组
        requestMessage.clear();
    }

    return analysisResult;
}

//2. 显示响应报文函数
void Widget::ShowResponseMessage(QString Message)
{
    //显示收到的报文
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("收到来自IP地址："
                            + ipAddress
                            + " 端口号："
                            + QString::number(portAddress)
                            + "的消息："
                            + '\n'
                            + Message);
}

//3. 报文合法性判断函数
bool Widget::MessageLegalJudge(QByteArray MessageArr, QByteArray requestMessageArr)
{
    bool Result;
    //1. 判断接收到的报文长度是否合法，合法最小长度为写入请求报文的异常响应报文，为9字节
    if(MessageArr.size() < TCP_MINIMUM_MESSAGE_LENGTH)
    {
        //消息窗口显示信息
        ui->messageEdit->append("报文长度错误,报文长度小于最小报文长度！");
        return false;
    }
    if(MessageArr.size() > TCP_MAXIMUM_MESSAGE_LENGTH)
    {
        ui->messageEdit->append("报文长度错误，报文长度大于最大报文长度");
        return false;
    }
    //2. 判断接收到的报文与请求报文的事务元标识符是否一致
    if((MessageArr.at(0) != requestMessageArr.at(0)) || (MessageArr.at(1) != requestMessageArr.at(1)))
    {
        //消息窗口显示信息
        ui->messageEdit->append("事务标识符错误，响应报文与请求报文的事务标识符不一致！");
        return false;
    }

    //3. 判断接收到的报文的协议标识是否是Modbus协议
    if((MessageArr.at(2) != 0) || (MessageArr.at(3) != 0))
    {
        //消息窗口显示信息
        ui->messageEdit->append("协议标识符错误，收到的报文不是Modbus报文！");
        return false;
    }

    //4. 判断接收到的报文的长度的数据与其后的字节长度是否匹配
    if((MessageArr.size() - 6) != BondTwoUint8ToUint16(MessageArr.at(4),MessageArr.at(5)))
    {
        //消息窗口显示信息
        ui->messageEdit->append("报文头中字节字段错误！");
        return false;
    }

    //5. 判断接收到的报文的单元标识符是否与请求报文一致
    if(MessageArr.at(6) != requestMessageArr.at(6))
    {
        //消息窗口显示信息
        ui->messageEdit->append("该报文的发送从站不是请求的从站！");
        return false;
    }

    //6. 判断接收到的报文的功能码是否合法
    Result = FuncCodeLegalJudge(MessageArr);
    if(Result == false)
    {
        return false;
    }

    //7. 处理匹配的异常响应码信息
    Result = TCPExceptionCodeProcess(MessageArr);
    if(Result == false)
    {
        return false;
    }

    //8. 判断请求与响应的功能码是否一致
    if(MessageArr.at(7) != requestMessageArr.at(7))
    {
        //消息窗口显示信息
        ui->messageEdit->append("收到报文的功能码与请求报文不一致！");
        return false;
    }

    return true;
}

//4. 功能码合法性判断函数
bool Widget::FuncCodeLegalJudge(QByteArray MessageArr)
{
    if(MessageArr.at(7) != 1
            &&MessageArr.at(7) != 3
            &&MessageArr.at(7) != 15
            &&MessageArr.at(7) != 16
            &&(quint8)MessageArr.at(7) != 0x81
            &&(quint8)MessageArr.at(7) != 0x83
            &&(quint8)MessageArr.at(7) != 0x8f
            &&(quint8)MessageArr.at(7) != 0x90)
    {
        //消息窗口显示信息
        ui->messageEdit->append("该报文的功能码无法识别！");
        return false;
    }
    else
    {
        return true;
    }
}

//5. 异常码报文处理函数
bool Widget::TCPExceptionCodeProcess(QByteArray MessageArr)
{
    QString exceptionPrompt;
    //处理匹配的异常响应码信息
    switch ((quint8)MessageArr.at(7))
    {
    case 0x81:
    {
        exceptionPrompt = "读多个线圈的请求报文出现异常！";
        break;
    }
    case 0x83:
    {
        exceptionPrompt = "读多个寄存器的请求报文出现异常！";
        break;
    }
    case 0x8f:
    {
        exceptionPrompt = "写入多个线圈的请求报文出现异常！";
        break;
    }
    case 0x90:
    {
        exceptionPrompt = "写入多个寄存器的请求报文出现异常！";
        break;
    }
    default:
    {
        return true;
    }
    }

    //获取异常码
    quint8 exceptionCode = (quint8)MessageArr.at(8);

    ui->messageEdit->append(exceptionPrompt);

    //异常码判断
    TCPExceptionCodeJudge(exceptionCode);

    return false;
}

//6. 异常码判断函数
void Widget::TCPExceptionCodeJudge(quint8 excCode)
{
    QString exceptionCodePrompt;
    switch (excCode)
    {
    case 0x01:
    {
        exceptionCodePrompt = "异常码为：01 非法功能";
        break;
    }
    case 0x02:
    {
        exceptionCodePrompt = "异常码为：02 非法数据地址";
        break;
    }
    case 0x03:
    {
        exceptionCodePrompt = "异常码为：03 非法数据值";
        break;
    }
    }
    //消息窗口显示信息
    ui->messageEdit->append(exceptionCodePrompt);

    return;
}

//7. 0X01功能码报文处理函数
bool Widget::TCP0X01FuncCodeProcess(QByteArray MessageArr, QByteArray requestMessageArr)
{
    //处理匹配的正常响应码
    QString dataObtained;
    quint8 numOfByte;
    quint16 length;

    //判断响应报文的长度是否符合最低要求
    if(MessageArr.size() < 10)
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文的长度异常！");
        return false;
    }

    //先判断响应报文的字节数是否和请求报文需要的对应
    //求出请求报文中想读的线圈数量number
    quint16 number = BondTwoUint8ToUint16((quint8)requestMessageArr.at(10),(quint8)requestMessageArr.at(11));

    //判断响应报文的字节数是否和满足number需要的字节数匹配
    //求出字节数
    numOfByte = (number + 7) / 8;

    //如果响应报文的字节数和满足number需要的字节数不匹配，则显示错误信息
    if(numOfByte != (quint8)MessageArr.at(8))
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文的字节数异常！");
        return false;
    }

    //判断自身长度字段是否异常
    length =(quint16)BondTwoUint8ToUint16(MessageArr.at(4),MessageArr.at(5));
    //如果不匹配，则输出错误信息
    if(length != MessageArr.size() - 6)
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文自身的长度字段异常！");
        return false;
    }

    //判断自身字节数字段是否异常
    if((quint8)MessageArr.at(8) != (MessageArr.size() - 9))
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文自身的字节数字段异常！");
        return false;
    }

    //取出所读的多个线圈，并显示，数据从第九位开始
    for(int i = 0; i < (quint8)MessageArr.at(8); i++)
    {
        //先转化为2进制字符串
        QString str = QString::number((quint8)MessageArr.at(9 + i),2);
        //再转化为2进制整形，由二进制整形转化为8位2进制字符串前面自动补0，从而保证8位
        str = QString("%1").arg((quint8)str.toInt(NULL,2),8,2,QChar('0'));
        //8bit字节倒转
        byteReverse(str);
        //添加到数据中
        dataObtained += str;
    }
    //去除填充的0位，读出请求报文请求的线圈数
    dataObtained = dataObtained.left(number);

    quint16 BeginAddress;
    BeginAddress = BondTwoUint8ToUint16((quint8)requestMessageArr[8],(quint8)requestMessageArr[9]);
    quint16 DataNumber;
    DataNumber = BondTwoUint8ToUint16((quint8)requestMessageArr[10],(quint8)requestMessageArr[11]);

    UpdateCoilsData(BeginAddress,DataNumber,dataObtained);

    //提示响应报文解析成功
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("多线圈读取成功!");
    ui->messageEdit->append("成功读取到来自IP地址："
                            + ipAddress
                            + " 端口号："
                            + QString::number(portAddress)
                            + "的"
                            + ui->numLineEdit->text()
                            + "个线圈：");
    ui->messageEdit->append(dataObtained);

    return true;
}

//8. 0X03功能码报文处理函数
bool Widget::TCP0X03FuncCodeProcess(QByteArray MessageArr, QByteArray requestMessageArr)
{
    //处理匹配的正常响应码
    QString dataObtained;
    quint16 length;

    //判断响应报文的长度是否符合最低要求
    if(MessageArr.size() < 10)
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文的长度异常！");
        return false;
    }

    //先判断响应报文的字节数是否和请求报文需要的对应
    //求出请求报文中想读的寄存器数量number
    quint16 number = BondTwoUint8ToUint16((quint8)requestMessageArr.at(10),(quint8)requestMessageArr.at(11));

    //如果响应报文的字节数和满足number需要的字节数不匹配，则显示错误信息
    if(2*number != (quint8)MessageArr.at(8))
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文的字节数异常！");
        return false;
    }

    //判断自身长度字段是否异常
    length =(quint16)BondTwoUint8ToUint16(MessageArr.at(4),MessageArr.at(5));
    //如果不匹配，则输出错误信息
    if(length != MessageArr.size() - 6)
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文自身的长度字段异常！");
        return false;
    }

    //判断自身字节数字段是否异常
    if((quint8)MessageArr.at(8) != (MessageArr.size() - 9))
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文自身的字节数字段异常！");
        return false;
    }

    //取出所读的多个寄存器，并显示，数据从第9个字节开始
    for(int i = 0; i < (quint8)MessageArr.at(8); i += 2)
    {
        dataObtained += QString::number(BondTwoUint8ToUint16((quint8)MessageArr.at(9 + i),(quint8)MessageArr.at(10 + i)));
        dataObtained += " ";
    }

    //写入查询数据
    quint16 BeginAddress;
    BeginAddress = BondTwoUint8ToUint16((quint8)requestMessageArr[8],(quint8)requestMessageArr[9]);
    quint16 DataNumber;
    DataNumber = BondTwoUint8ToUint16((quint8)requestMessageArr[10],(quint8)requestMessageArr[11]);
    UpdateRegistersData(BeginAddress,DataNumber,dataObtained);

    //提示响应报文解析成功
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("多寄存器读取成功!");
    ui->messageEdit->append("成功读取到来自IP地址："
                            + ipAddress
                            + " 端口号："
                            + QString::number(portAddress)
                            + "的"
                            + ui->numLineEdit->text()
                            + "个寄存器：");
    ui->messageEdit->append(dataObtained);

    return true;
}

//9. 0X0f功能码报文处理函数
bool Widget::TCP0X0fFuncCodeProcess(QByteArray MessageArr, QByteArray requestMessageArr)
{
    //处理匹配的正常响应码
    quint16 messageArrayBeginAddress;
    quint16 requestMessageBegainAddress;
    quint16 length;
    quint16 messageArrayByteNum;
    quint16 requestMessageByteNum;

    //判断响应报文的长度是否符合最低要求，写入请求报文的响应报文为固定长度12
    if(MessageArr.size() != 12)
    {
        //时间
        TimeInformation();
        //消息窗口显示信息
        ui->messageEdit->append("响应报文的长度异常！");
        return false;
    }

    //判断自身长度字段是否异常
    length =(quint16)BondTwoUint8ToUint16(MessageArr.at(4),MessageArr.at(5));
    //如果不匹配，则输出错误信息
    if(length != 6)
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文自身的长度字段异常！");
        return false;
    }

    //判断收到的报文的起始地址字段是否与请求报文匹配
    messageArrayBeginAddress = (quint16)BondTwoUint8ToUint16(MessageArr.at(8),MessageArr.at(9));
    requestMessageBegainAddress = (quint16)BondTwoUint8ToUint16(requestMessageArr.at(8),requestMessageArr.at(9));
    if(messageArrayBeginAddress != requestMessageBegainAddress)
    {
        //消息窗口显示信息
        ui->messageEdit->append("收到的报文的起始地址字段与请求报文不匹配！");
        return false;
    }

    //判断收到的报文的数量字段是否与请求报文匹配
    messageArrayByteNum = (quint16)BondTwoUint8ToUint16(MessageArr.at(10),MessageArr.at(11));
    requestMessageByteNum = (quint16)BondTwoUint8ToUint16(requestMessageArr.at(10),requestMessageArr.at(11));
    if(messageArrayByteNum != requestMessageByteNum)
    {
        //消息窗口显示信息
        ui->messageEdit->append("收到的报文的数量字段与请求报文不匹配！");
        return false;
    }

    //提示响应报文解析成功
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("多线圈写入成功!");
    ui->messageEdit->append("成功向IP地址:"
                            + ipAddress
                            + " 端口号："
                            + QString::number(portAddress)
                            + "起始位置："
                            + ui->beginAddressLineEdit->text()
                            + "处写入"
                            + ui->numLineEdit->text()
                            + "个线圈！");

    return true;
}

//10. 0X10功能码报文处理函数
bool Widget::TCP0X10FuncCodeProcess(QByteArray MessageArr, QByteArray requestMessageArr)
{
    //处理匹配的正常响应码
    quint16 messageArrayBeginAddress;
    quint16 requestMessageBegainAddress;
    quint16 length;
    quint16 messageArrayByteNum;
    quint16 requestMessageByteNum;

    //判断响应报文的长度是否符合最低要求，写入请求报文的响应报文为固定长度12
    if(MessageArr.size() != 12)
    {
        //时间
        TimeInformation();
        //消息窗口显示信息
        ui->messageEdit->append("响应报文的长度异常！");
        return false;
    }

    //判断自身长度字段是否异常
    length =(quint16)BondTwoUint8ToUint16(MessageArr.at(4),MessageArr.at(5));
    //如果不匹配，则输出错误信息
    if(length != 6)
    {
        //消息窗口显示信息
        ui->messageEdit->append("响应报文自身的长度字段异常！");
        return false;
    }

    //判断收到的报文的起始地址字段是否与请求报文匹配
    messageArrayBeginAddress = (quint16)BondTwoUint8ToUint16(MessageArr.at(8),MessageArr.at(9));
    requestMessageBegainAddress = (quint16)BondTwoUint8ToUint16(requestMessageArr.at(8),requestMessageArr.at(9));
    if(messageArrayBeginAddress != requestMessageBegainAddress)
    {
        //消息窗口显示信息
        ui->messageEdit->append("收到的报文的起始地址字段与请求报文不匹配！");
        return false;
    }

    //判断收到的报文的数量字段是否与请求报文匹配
    messageArrayByteNum = (quint16)BondTwoUint8ToUint16(MessageArr.at(10),MessageArr.at(11));
    requestMessageByteNum = (quint16)BondTwoUint8ToUint16(requestMessageArr.at(10),requestMessageArr.at(11));
    if(messageArrayByteNum != requestMessageByteNum)
    {
        //消息窗口显示信息
        ui->messageEdit->append("收到的报文的数量字段与请求报文不匹配！");

        return false;
    }

    //提示响应报文解析成功
    //时间
    TimeInformation();
    //消息窗口显示信息
    ui->messageEdit->append("多寄存器写入成功!");
    ui->messageEdit->append("成功向IP地址:"
                            + ipAddress
                            + " 端口号："
                            + QString::number(portAddress)
                            + "起始位置："
                            + ui->beginAddressLineEdit->text()
                            + "处写入"
                            + ui->numLineEdit->text()
                            + "个寄存器！");

    return true;
}

//11. 连接两个quint8数据为一个quint16数据
quint16 Widget::BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum)
{
    quint16 bondNum = (preNum << 8) | afterNum;
    return bondNum;
}

void Widget::ResetFilePath()
{
    //重置日志文件保存路径
    QString filePath = QFileDialog::getOpenFileName(this,"打开文件","../ModBus_TCP_master","TEXT(*.txt)");
    if(filePath != NULL)
    {
        path = filePath;
        FileInformation();
    }

}

//12. 数组转十六进制字符串
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

//显示本地数据
void Widget::DataInitialization()
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
//写线圈
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
//更新线圈
void Widget::UpdateCoilsData(quint16 BeginAddress,quint16 DataNumber,QString DataString)
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
//更新寄存器
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
//数据查询
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




/**************************************************程序关闭处理函数**************************************************/
void Widget::closeEvent(QCloseEvent *event) //系统自带退出确定程序
{
    int choose;
    choose= QMessageBox::question(this, tr("退出程序"),
                                   QString(tr("确认退出程序?")),
                                   QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

    //选择不退出，则程序继续运行，选择退出，则进行保存数据流程
    if (choose== QMessageBox::No)
     {
          event->ignore();
    }
    else if (choose== QMessageBox::Yes)
    {
        //记录关闭程序事件
        //时间
        TimeInformation();
        //消息窗口显示信息
        ui->messageEdit->append("关闭应用程序！");
        //将现有历史记录写入文件
        WriteHistoricalMessage();
        FileInformation();
        //断开连接
        TcpDisConnect();
        //退出程序
        event->accept();
    }
}

/******************************************************析构函数*****************************************************/
Widget::~Widget()
{
    delete ui;
}

