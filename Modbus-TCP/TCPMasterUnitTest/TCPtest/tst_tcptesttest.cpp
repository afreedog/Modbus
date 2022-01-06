#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "../../Modbus-TCP-Master/ModBus_TCP_master/historymessagedialog.h"
#include "../../Modbus-TCP-Master/ModBus_TCP_master/inputdialog.h"
#include "../../Modbus-TCP-Master/ModBus_TCP_master/widget.h"

#include <QWidget>
//Basic
#include <QDebug>
#include <QEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QByteArray>
#include <QTimer>
#include <QCloseEvent>
#include <QInputDialog>


//NetWork
#include <QtNetwork>
#include <QTcpSocket>
#include <QHostAddress>

class TCPtestTest : public QObject
{
    Q_OBJECT

public:
    TCPtestTest();
    Widget widget;

private Q_SLOTS:
    //TCP主站
    //多线圈字符串合法性判断函数测试
    void test_coilsLegality_data();
    void test_coilsLegality();

    //字节反转函数测试
    void test_byteReverse_data();
    void test_byteReverse();

    //连接两个quint8数据为一个quint16数据函数测试
    void test_BondTwoUint8ToUint16_data();
    void test_BondTwoUint8ToUint16();

    //数组转十六进制字符串函数测试
    void test_HexByteArrayToHexString_data();
    void test_HexByteArrayToHexString();

    //读输出线圈0x01和读输出寄存器0x03请求报文构建函数测试
    void test_RequestMessage0x010x03Build_data();
    void test_RequestMessage0x010x03Build();

    //写多个输出线圈0x0F和写多个输出寄存器0x10请求报构建函数测试
    void test_RequestMessage0x0F0x10Build_data();
    void test_RequestMessage0x0F0x10Build();

    //报文合法性判断函数测试
    void test_MessageLegalJudge_data();
    void test_MessageLegalJudge();

    //功能码合法性判断函数测试
    void test_FuncCodeLegalJudge_data();
    void test_FuncCodeLegalJudge();

    //异常码报文处理函数测试
    void test_TCPExceptionCodeProcess_data();
    void test_TCPExceptionCodeProcess();

    //0X01功能码报文处理函数测试
    void test_TCP0X01FuncCodeProcess_data();
    void test_TCP0X01FuncCodeProcess();

    //0X03功能码报文处理函数测试
    void test_TCP0X03FuncCodeProcess_data();
    void test_TCP0X03FuncCodeProcess();

    //0X0f功能码报文处理函数测试
    void test_TCP0X0fFuncCodeProcess_data();
    void test_TCP0X0fFuncCodeProcess();

    //0X010功能码报文处理函数测试数据
    void test_TCP0X10FuncCodeProcess_data();
    void test_TCP0X10FuncCodeProcess();

};

TCPtestTest::TCPtestTest()
{
}

//TCP主站单元测试
//读输出线圈0x01和读输出寄存器0x03请求报文构建函数测试数据
void TCPtestTest::test_RequestMessage0x010x03Build_data()
{
    //创建测试表
    QTest::addColumn<quint16>("transactionIdenti");
    QTest::addColumn<quint16>("protocolIdenti");
    QTest::addColumn<quint16>("length");
    QTest::addColumn<quint8>("unitIdenti");
    QTest::addColumn<quint8>("funcCode");
    QTest::addColumn<quint16>("beginAddr");
    QTest::addColumn<quint16>("num");
    QTest::addColumn<QByteArray>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/RequestMessage0x010x03Build_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        quint16 transactionIdenti = settings.value("Section" + QString::number(i + 1) + "/transactionIdenti").toInt();
        quint16 protocolIdenti = settings.value("Section" + QString::number(i + 1) + "/protocolIdenti").toInt();
        quint16 length = settings.value("Section" + QString::number(i + 1) + "/length").toInt();
        quint8 unitIdenti = settings.value("Section" + QString::number(i + 1) + "/unitIdenti").toInt();
        quint8 funcCode = settings.value("Section" + QString::number(i + 1) + "/funcCode").toInt();
        quint16 beginAddr = settings.value("Section" + QString::number(i + 1) + "/beginAddr").toInt();
        quint16 num = settings.value("Section" + QString::number(i + 1) + "/num").toInt();
        QString expectedString = settings.value("Section" + QString::number(i + 1) + "/expected").toString();

        //去除字符串空格
        expectedString.remove(QRegExp("\\s"));

        //获得字符数组大小
        int expectedSize = (expectedString.size()/2);

        QByteArray expected;
        //转为字节数组
        for(int j = 0; j < expectedSize; j++)
        {
            expected.append((quint8)(expectedString.mid(2*j,2).toInt(NULL,16)));
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << transactionIdenti
                                 << protocolIdenti
                                 << length
                                 << unitIdenti
                                 << funcCode
                                 << beginAddr
                                 << num
                                 << expected;
    }
}
//读输出线圈0x01和读输出寄存器0x03请求报文构建函数测试
void TCPtestTest::test_RequestMessage0x010x03Build()
{
    QFETCH(quint16, transactionIdenti);
    QFETCH(quint16, protocolIdenti);
    QFETCH(quint16, length);
    QFETCH(quint8, unitIdenti);
    QFETCH(quint8, funcCode);
    QFETCH(quint16, beginAddr);
    QFETCH(quint16, num);
    QFETCH(QByteArray, expected);

    Widget::MessageBasicInformation MessBasicInfo;
    MessBasicInfo.transactionIdenti = transactionIdenti;
    MessBasicInfo.protocolIdenti = protocolIdenti;
    MessBasicInfo.length = length;
    MessBasicInfo.unitIdenti = unitIdenti;
    MessBasicInfo.funcCode = funcCode;
    MessBasicInfo.beginAddr = beginAddr;
    MessBasicInfo.num = num;

    QByteArray result = widget.RequestMessage0x010x03Build(&MessBasicInfo);

    QCOMPARE(result, expected);
}

//写多个输出线圈0x0F和写多个输出寄存器0x10请求报构建函数测试数据
void TCPtestTest::test_RequestMessage0x0F0x10Build_data()
{
    //创建测试表
    QTest::addColumn<quint16>("transactionIdenti");
    QTest::addColumn<quint16>("protocolIdenti");
    QTest::addColumn<quint16>("length");
    QTest::addColumn<quint8>("unitIdenti");
    QTest::addColumn<quint8>("funcCode");
    QTest::addColumn<quint16>("beginAddr");
    QTest::addColumn<quint16>("num");
    QTest::addColumn<QByteArray>("byteArr");
    QTest::addColumn<QByteArray>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/RequestMessage0x0F0x10Build_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        quint16 transactionIdenti = settings.value("Section" + QString::number(i + 1) + "/transactionIdenti").toInt();
        quint16 protocolIdenti = settings.value("Section" + QString::number(i + 1) + "/protocolIdenti").toInt();
        quint16 length = settings.value("Section" + QString::number(i + 1) + "/length").toInt();
        quint8 unitIdenti = settings.value("Section" + QString::number(i + 1) + "/unitIdenti").toInt();
        quint8 funcCode = settings.value("Section" + QString::number(i + 1) + "/funcCode").toInt();
        quint16 beginAddr = settings.value("Section" + QString::number(i + 1) + "/beginAddr").toInt();
        quint16 num = settings.value("Section" + QString::number(i + 1) + "/num").toInt();
        QString byteString = settings.value("Section" + QString::number(i + 1) + "/byteArr").toString();
        QString expectedString = settings.value("Section" + QString::number(i + 1) + "/expected").toString();

        //去除字符串空格
        byteString.remove(QRegExp("\\s"));
        expectedString.remove(QRegExp("\\s"));

        //获得字符数组大小
        int byteSize = (byteString.size()/2);
        int expectedSize = (expectedString.size()/2);

        QByteArray byteArr, expected;
        //转为字节数组
        for(int j = 0; j < byteSize; j++)
        {
            byteArr.append((quint8)(byteString.mid(2*j,2).toInt(NULL,16)));
        }
        for(int j = 0; j < expectedSize; j++)
        {
            expected.append((quint8)(expectedString.mid(2*j,2).toInt(NULL,16)));
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << transactionIdenti
                                 << protocolIdenti
                                 << length
                                 << unitIdenti
                                 << funcCode
                                 << beginAddr
                                 << num
                                 << byteArr
                                 << expected;
    }
}
//写多个输出线圈0x0F和写多个输出寄存器0x10请求报构建函数测试
void TCPtestTest::test_RequestMessage0x0F0x10Build()
{
    QFETCH(quint16, transactionIdenti);
    QFETCH(quint16, protocolIdenti);
    QFETCH(quint16, length);
    QFETCH(quint8, unitIdenti);
    QFETCH(quint8, funcCode);
    QFETCH(quint16, beginAddr);
    QFETCH(quint16, num);
    QFETCH(QByteArray, byteArr);
    QFETCH(QByteArray, expected);

    Widget::MessageBasicInformation MessBasicInfo;
    MessBasicInfo.transactionIdenti = transactionIdenti;
    MessBasicInfo.protocolIdenti = protocolIdenti;
    MessBasicInfo.length = length;
    MessBasicInfo.unitIdenti = unitIdenti;
    MessBasicInfo.funcCode = funcCode;
    MessBasicInfo.beginAddr = beginAddr;
    MessBasicInfo.num = num;

    QByteArray result = widget.RequestMessage0x0F0x10Build(&MessBasicInfo, byteArr);

    QCOMPARE(result, expected);
}

//报文合法性判断函数测试数据
void TCPtestTest::test_MessageLegalJudge_data()
{
    QTest::addColumn<QByteArray>("MessageArr");
    QTest::addColumn<QByteArray>("RequestMessageArr");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/MessageLegalJudge_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString Message = settings.value("Section" + QString::number(i + 1) + "/Message").toString();
        QString RequestMessage = settings.value("Section" + QString::number(i + 1) + "/RequestMessage").toString();
        int expectedValue = settings.value("Section" + QString::number(i + 1) + "/expected").toInt();

        //去除空格
        Message.remove(QRegExp("\\s"));
        RequestMessage.remove(QRegExp("\\s"));

        int MessageSize = (Message.size()/2);
        int RequestMessageSize = (RequestMessage.size()/2);
        bool expected;

        if(expectedValue == 1)
        {
            expected = true;
        }
        else
        {
            expected = false;
        }

        QByteArray MessageArr,RequestMessageArr;
        //转为字节数组
        for(int j = 0; j < MessageSize; j++)
        {
            MessageArr.append((quint8)(Message.mid(2*j,2).toInt(NULL,16)));
        }

        for(int j = 0; j < RequestMessageSize; j++)
        {
            RequestMessageArr.append((quint8)(RequestMessage.mid(2*j,2).toInt(NULL,16)));
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << MessageArr << RequestMessageArr << expected;
    }
}
//报文合法性判断函数测试
void TCPtestTest::test_MessageLegalJudge()
{
    QFETCH(QByteArray, MessageArr);
    QFETCH(QByteArray, RequestMessageArr);
    QFETCH(bool, expected);

    bool result = widget.MessageLegalJudge(MessageArr, RequestMessageArr);

    QCOMPARE(result, expected);
}

//功能码合法性判断函数测试数据
void TCPtestTest::test_FuncCodeLegalJudge_data()
{
    QTest::addColumn<QByteArray>("MessageArr");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/FuncCodeLegalJudge_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString Message = settings.value("Section" + QString::number(i + 1) + "/Message").toString();
        int expectedValue = settings.value("Section" + QString::number(i + 1) + "/expected").toInt();

        //去除空格
        Message.remove(QRegExp("\\s"));
        int MessageSize = (Message.size()/2);
        bool expected;

        if(expectedValue == 1)
        {
            expected = true;
        }
        else
        {
            expected = false;
        }

        QByteArray MessageArr;
        //转为字节数组
        for(int j = 0; j < MessageSize; j++)
        {
            MessageArr.append((quint8)(Message.mid(2*j,2).toInt(NULL,16)));
        }
        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << MessageArr << expected;
    }

}
//功能码合法性判断函数测试
void TCPtestTest::test_FuncCodeLegalJudge()
{
    QFETCH(QByteArray, MessageArr);
    QFETCH(bool, expected);

    bool result = widget.FuncCodeLegalJudge(MessageArr);

    QCOMPARE(result, expected);
}

//异常码报文处理函数测试数据
void TCPtestTest::test_TCPExceptionCodeProcess_data()
{
    QTest::addColumn<QByteArray>("MessageArr");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/TCPExceptionCodeProcess_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString Message = settings.value("Section" + QString::number(i + 1) + "/Message").toString();
        int expectedValue = settings.value("Section" + QString::number(i + 1) + "/expected").toInt();

        //去除空格
        Message.remove(QRegExp("\\s"));
        int MessageSize = (Message.size()/2);
        bool expected;

        if(expectedValue == 1)
        {
            expected = true;
        }
        else
        {
            expected = false;
        }

        QByteArray MessageArr;
        //转为字节数组
        for(int j = 0; j < MessageSize; j++)
        {
            MessageArr.append((quint8)(Message.mid(2*j,2).toInt(NULL,16)));
        }
        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << MessageArr << expected;
    }

}
//异常码报文处理函数测试
void TCPtestTest::test_TCPExceptionCodeProcess()
{
    QFETCH(QByteArray, MessageArr);
    QFETCH(bool, expected);

    bool result = widget.TCPExceptionCodeProcess(MessageArr);

    QCOMPARE(result, expected);
}

//0X01功能码报文处理函数测试数据
void TCPtestTest::test_TCP0X01FuncCodeProcess_data()
{
    QTest::addColumn<QByteArray>("MessageArr");
    QTest::addColumn<QByteArray>("RequestMessageArr");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/TCP0X01FuncCodeProcess_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString Message = settings.value("Section" + QString::number(i + 1) + "/Message").toString();
        QString RequestMessage = settings.value("Section" + QString::number(i + 1) + "/RequestMessage").toString();
        int expectedValue = settings.value("Section" + QString::number(i + 1) + "/expected").toInt();

        //去除空格
        Message.remove(QRegExp("\\s"));
        RequestMessage.remove(QRegExp("\\s"));

        int MessageSize = (Message.size()/2);
        int RequestMessageSize = (RequestMessage.size()/2);
        bool expected;

        if(expectedValue == 1)
        {
            expected = true;
        }
        else
        {
            expected = false;
        }

        QByteArray MessageArr,RequestMessageArr;
        //转为字节数组
        for(int j = 0; j < MessageSize; j++)
        {
            MessageArr.append((quint8)(Message.mid(2*j,2).toInt(NULL,16)));
        }

        for(int j = 0; j < RequestMessageSize; j++)
        {
            RequestMessageArr.append((quint8)(RequestMessage.mid(2*j,2).toInt(NULL,16)));
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << MessageArr << RequestMessageArr << expected;
    }
}
//0X01功能码报文处理函数测试
void TCPtestTest::test_TCP0X01FuncCodeProcess()
{
    QFETCH(QByteArray, MessageArr);
    QFETCH(QByteArray, RequestMessageArr);
    QFETCH(bool, expected);

    bool result = widget.TCP0X01FuncCodeProcess(MessageArr, RequestMessageArr);

    QCOMPARE(result, expected);
}

//0X03功能码报文处理函数测试数据
void TCPtestTest::test_TCP0X03FuncCodeProcess_data()
{
    QTest::addColumn<QByteArray>("MessageArr");
    QTest::addColumn<QByteArray>("RequestMessageArr");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/TCP0X03FuncCodeProcess_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString Message = settings.value("Section" + QString::number(i + 1) + "/Message").toString();
        QString RequestMessage = settings.value("Section" + QString::number(i + 1) + "/RequestMessage").toString();
        int expectedValue = settings.value("Section" + QString::number(i + 1) + "/expected").toInt();

        //去除空格
        Message.remove(QRegExp("\\s"));
        RequestMessage.remove(QRegExp("\\s"));

        int MessageSize = (Message.size()/2);
        int RequestMessageSize = (RequestMessage.size()/2);
        bool expected;

        if(expectedValue == 1)
        {
            expected = true;
        }
        else
        {
            expected = false;
        }

        QByteArray MessageArr,RequestMessageArr;
        //转为字节数组
        for(int j = 0; j < MessageSize; j++)
        {
            MessageArr.append((quint8)(Message.mid(2*j,2).toInt(NULL,16)));
        }

        for(int j = 0; j < RequestMessageSize; j++)
        {
            RequestMessageArr.append((quint8)(RequestMessage.mid(2*j,2).toInt(NULL,16)));
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << MessageArr << RequestMessageArr << expected;
    }
}
//0X03功能码报文处理函数测试
void TCPtestTest::test_TCP0X03FuncCodeProcess()
{
    QFETCH(QByteArray, MessageArr);
    QFETCH(QByteArray, RequestMessageArr);
    QFETCH(bool, expected);

    bool result = widget.TCP0X03FuncCodeProcess(MessageArr, RequestMessageArr);

    QCOMPARE(result, expected);
}

//0X0f功能码报文处理函数测试数据
void TCPtestTest::test_TCP0X0fFuncCodeProcess_data()
{
    QTest::addColumn<QByteArray>("MessageArr");
    QTest::addColumn<QByteArray>("RequestMessageArr");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/TCP0X0fFuncCodeProcess_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString Message = settings.value("Section" + QString::number(i + 1) + "/Message").toString();
        QString RequestMessage = settings.value("Section" + QString::number(i + 1) + "/RequestMessage").toString();
        int expectedValue = settings.value("Section" + QString::number(i + 1) + "/expected").toInt();

        //去除空格
        Message.remove(QRegExp("\\s"));
        RequestMessage.remove(QRegExp("\\s"));

        int MessageSize = (Message.size()/2);
        int RequestMessageSize = (RequestMessage.size()/2);
        bool expected;

        if(expectedValue == 1)
        {
            expected = true;
        }
        else
        {
            expected = false;
        }

        QByteArray MessageArr,RequestMessageArr;
        //转为字节数组
        for(int j = 0; j < MessageSize; j++)
        {
            MessageArr.append((quint8)(Message.mid(2*j,2).toInt(NULL,16)));
        }

        for(int j = 0; j < RequestMessageSize; j++)
        {
            RequestMessageArr.append((quint8)(RequestMessage.mid(2*j,2).toInt(NULL,16)));
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << MessageArr << RequestMessageArr << expected;
    }
}
//0X0f功能码报文处理函数测试
void TCPtestTest::test_TCP0X0fFuncCodeProcess()
{
    QFETCH(QByteArray, MessageArr);
    QFETCH(QByteArray, RequestMessageArr);
    QFETCH(bool, expected);

    bool result = widget.TCP0X0fFuncCodeProcess(MessageArr, RequestMessageArr);

    QCOMPARE(result, expected);
}

//0X010功能码报文处理函数测试数据
void TCPtestTest::test_TCP0X10FuncCodeProcess_data()
{
    QTest::addColumn<QByteArray>("MessageArr");
    QTest::addColumn<QByteArray>("RequestMessageArr");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/TCP0X10FuncCodeProcess_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString Message = settings.value("Section" + QString::number(i + 1) + "/Message").toString();
        QString RequestMessage = settings.value("Section" + QString::number(i + 1) + "/RequestMessage").toString();
        int expectedValue = settings.value("Section" + QString::number(i + 1) + "/expected").toInt();

        //去除空格
        Message.remove(QRegExp("\\s"));
        RequestMessage.remove(QRegExp("\\s"));

        int MessageSize = (Message.size()/2);
        int RequestMessageSize = (RequestMessage.size()/2);
        bool expected;

        if(expectedValue == 1)
        {
            expected = true;
        }
        else
        {
            expected = false;
        }

        QByteArray MessageArr,RequestMessageArr;
        //转为字节数组
        for(int j = 0; j < MessageSize; j++)
        {
            MessageArr.append((quint8)(Message.mid(2*j,2).toInt(NULL,16)));
        }

        for(int j = 0; j < RequestMessageSize; j++)
        {
            RequestMessageArr.append((quint8)(RequestMessage.mid(2*j,2).toInt(NULL,16)));
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << MessageArr << RequestMessageArr << expected;
    }
}
//0X10功能码报文处理函数测试
void TCPtestTest::test_TCP0X10FuncCodeProcess()
{
    QFETCH(QByteArray, MessageArr);
    QFETCH(QByteArray, RequestMessageArr);
    QFETCH(bool, expected);

    bool result = widget.TCP0X10FuncCodeProcess(MessageArr, RequestMessageArr);

    QCOMPARE(result, expected);
}
//多线圈字符串合法性判断函数测试数据
void TCPtestTest::test_coilsLegality_data()
{
    QTest::addColumn<QString>("coils");
    QTest::addColumn<bool>("expected");

    QTest::newRow("0") << "0" << true;
    QTest::newRow("1") << "1" << true;
    QTest::newRow("2") << "00000" << true;
    QTest::newRow("3") << "11111" << true;
    QTest::newRow("4") << "0011" << true;
    QTest::newRow("5") << "1100" << true;
    QTest::newRow("6") << "3" << false;
    QTest::newRow("7") << "333" << false;
    QTest::newRow("8") << "02000" << false;
    QTest::newRow("9") << "12000" << false;
    QTest::newRow("10") << "0211" << false;
    QTest::newRow("117") << "1211" << false;
}
//多线圈字符串合法性判断函数测试
void TCPtestTest::test_coilsLegality()
{
    QFETCH(QString, coils);
    QFETCH(bool, expected);

    bool result = widget.coilsLegality(coils);
    QCOMPARE(result, expected);
}

//字节反转函数测试数据
void TCPtestTest::test_byteReverse_data()
{
    QTest::addColumn<QString>("targetString");
    QTest::addColumn<QString>("resultString");

    QTest::newRow("全0") << "00000000" << "00000000";
    QTest::newRow("01混杂") << "01110110" << "01101110";
    QTest::newRow("全1") << "11111111" << "11111111";
}
//字节反转函数测试
void TCPtestTest::test_byteReverse()
{
    QFETCH(QString, targetString);
    QFETCH(QString, resultString);

    QString resultStr = targetString;
    widget.byteReverse(resultStr);

    QCOMPARE(resultStr, resultString);
}

//连接两个quint8数据为一个quint16数据函数测试数据
void TCPtestTest::test_BondTwoUint8ToUint16_data()
{
    QTest::addColumn<quint8>("preNum");
    QTest::addColumn<quint8>("afterNum");
    QTest::addColumn<quint16>("bondNum");

    QTest::newRow("前0后1") << quint8(0) << quint8(255) << quint16(255);
    QTest::newRow("前1后0") << quint8(255) << quint8(0) << quint16(65280);
    QTest::newRow("全1") << quint8(255) << quint8(255) << quint16(65535);
    QTest::newRow("混杂") << quint8(215) << quint8(190) << quint16(55230);
}
//连接两个quint8数据为一个quint16数据函数测试
void TCPtestTest::test_BondTwoUint8ToUint16()
{
    QFETCH(quint8, preNum);
    QFETCH(quint8, afterNum);
    QFETCH(quint16, bondNum);

    quint16 resultNum = widget.BondTwoUint8ToUint16(preNum, afterNum);
    QCOMPARE(resultNum, bondNum);
}

//数组转十六进制字符串函数测试数据
void TCPtestTest::test_HexByteArrayToHexString_data()
{
    QTest::addColumn<QByteArray>("HexByteArr");
    QTest::addColumn<int>("ConvertLen");
    QTest::addColumn<int>("pattern");
    QTest::addColumn<QString>("expected");

    QByteArray arr1;
    arr1.resize(1);
    arr1[0] = quint8(0);
    QTest::newRow("0") << arr1 << 1 << 0 << "00";

    QByteArray arr2;
    arr2.resize(1);
    arr2[0] = quint8(255);
    QTest::newRow("1") << arr2 << 1 << 0 << "ff";

    QByteArray arr3;
    arr3.resize(2);
    arr3[0] = quint8(0);
    arr3[1] = quint8(255);
    QTest::newRow("2") << arr3 << 2 << 0 << "00ff";

    QByteArray arr4;
    arr4.resize(2);
    arr4[0] = quint8(255);
    arr4[1] = quint8(0);
    QTest::newRow("3") << arr4 << 2 << 0 << "ff00";

    QByteArray arr5;
    arr5.resize(2);
    arr5[0] = quint8(0);
    arr5[1] = quint8(255);
    QTest::newRow("4") << arr5 << 2 << 1 << "00 ff ";

    QByteArray arr6;
    arr6.resize(2);
    arr6[0] = quint8(255);
    arr6[1] = quint8(0);
    QTest::newRow("5") << arr6 << 2 << 1 << "ff 00 ";
}
//数组转十六进制字符串函数测试
void TCPtestTest::test_HexByteArrayToHexString()
{
    QFETCH(QByteArray, HexByteArr);
    QFETCH(int, ConvertLen);
    QFETCH(int, pattern);
    QFETCH(QString, expected);

    QString resultStr = widget.HexByteArrayToHexString(HexByteArr, ConvertLen, pattern);
    QCOMPARE(resultStr, expected);
}

QTEST_MAIN(TCPtestTest)

#include "tst_tcptesttest.moc"
