#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "../Modbus-RTU-Master/Modbus-RTU-Master/historymessagedialog.h"
#include "../Modbus-RTU-Master/Modbus-RTU-Master/widget.h"
#include "../Modbus-RTU-Master/Modbus-RTU-Master/inputdatadialog.h"

#include <QWidget>
//Basic
#include <QDebug>
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
#include <QSettings>
#include <QTableWidgetItem>
#include <QAbstractItemView>

//PORT
#include <QtSerialPort/QSerialPort>        //提供访问串口的功能
#include <QtSerialPort/QSerialPortInfo>    //提供系统中存在的串口的信息

class RTUtestTest : public QObject
{
    Q_OBJECT

public:
    RTUtestTest();
    Widget widget;

private Q_SLOTS:
    //RTU主站
    //0x01 0x03请求报文生成测试
    void test_RequestMessageBuild0x010x03_data();
    void test_RequestMessageBuild0x010x03();

    //0x0f 0x10请求报文生成测试
    void test_RequestMessageBuild0x0f0x10_data();
    void test_RequestMessageBuild0x0f0x10();

    //解析响应报文测试
    void test_ParseResponseMessage_data();
    void test_ParseResponseMessage();

    //线圈16进制字节数组转2进制字符串
    void test_CoilsByteArrayToQString_data();
    void test_CoilsByteArrayToQString();

    //寄存器16进制字节数组转10进制字符串
    void test_RegistersByteArrayToQString_data();
    void test_RegistersByteArrayToQString();

};

RTUtestTest::RTUtestTest()
{
}

//0x01 0x03请求报文生成测试
void RTUtestTest::test_RequestMessageBuild0x010x03_data()
{
    //创建配置对象
    QSettings settings("./RTUtest/config/RequestMessageBuild0x010x03_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();
    //创建测试表
    QTest::addColumn<quint8>("SlaveAddress");
    QTest::addColumn<quint8>("FuncCode");
    QTest::addColumn<quint16>("BeginAddress");
    QTest::addColumn<quint16>("Number");
    QTest::addColumn<QByteArray>("expected");
    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        quint8 SlaveAddress = settings.value("Section" + QString::number(i + 1) + "/SlaveAddress").toInt();
        quint8 FuncCode = settings.value("Section" + QString::number(i + 1) + "/FuncCode").toInt();
        quint16 BeginAddress = settings.value("Section" + QString::number(i + 1) + "/BeginAddress").toInt();
        quint16 Number = settings.value("Section" + QString::number(i + 1) + "/Number").toInt();
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

        QTest::newRow(rowNameCh) << SlaveAddress
                                 << FuncCode
                                 << BeginAddress
                                 << Number
                                 << expected;
    }

}
void RTUtestTest::test_RequestMessageBuild0x010x03()
{
    QFETCH(quint8, SlaveAddress);
    QFETCH(quint8, FuncCode);
    QFETCH(quint16, BeginAddress);
    QFETCH(quint16, Number);
    QFETCH(QByteArray, expected);

    //初始化结构体
    Widget::RequestMessageStruct MessBasicInfo;
    MessBasicInfo.SlaveAddress = SlaveAddress;
    MessBasicInfo.FunctionCode = FuncCode;
    MessBasicInfo.BeginAddress = BeginAddress;
    MessBasicInfo.DataNumber = Number;
    QByteArray result = widget.RequestMessageBuild0X010X03(&MessBasicInfo);
    QCOMPARE(result, expected);

}

//0x0f 0x10请求报文生成
void RTUtestTest::test_RequestMessageBuild0x0f0x10_data()
{
    //创建配置对象
    QSettings settings("./RTUtest/config/RequestMessageBuild0x0fx10_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();
    //创建测试表
    QTest::addColumn<quint8>("SlaveAddress");
    QTest::addColumn<quint8>("FuncCode");
    QTest::addColumn<quint16>("BeginAddress");
    QTest::addColumn<quint16>("Number");
    QTest::addColumn<QByteArray>("Data");
    QTest::addColumn<QByteArray>("expected");
    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        quint8 SlaveAddress = settings.value("Section" + QString::number(i + 1) + "/SlaveAddress").toInt();
        quint8 FuncCode = settings.value("Section" + QString::number(i + 1) + "/FuncCode").toInt();
        quint16 BeginAddress = settings.value("Section" + QString::number(i + 1) + "/BeginAddress").toInt();
        quint16 Number = settings.value("Section" + QString::number(i + 1) + "/Number").toInt();
        QString Data= settings.value("Section" + QString::number(i + 1) + "/Data").toString();
        QString expectedString = settings.value("Section" + QString::number(i + 1) + "/expected").toString();

        //去除字符串空格
        expectedString.remove(QRegExp("\\s"));
        Data.remove(QRegExp("\\s"));
        //获得字符数组大小
        int expectedSize = (expectedString.size()/2);
        int DataSize = (Data.size()/2);
        QByteArray data;
        QByteArray expected;
        //转为字节数组
        for(int j = 0; j < DataSize;j++)
        {
             data.append((quint8)(Data.mid(2*j,2).toInt(NULL,16)));
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
        QTest::newRow(rowNameCh) << SlaveAddress
                                 << FuncCode
                                 << BeginAddress
                                 << Number
                                 << data
                                 << expected;
    }

}
void RTUtestTest::test_RequestMessageBuild0x0f0x10()
{
    QFETCH(quint8, SlaveAddress);
    QFETCH(quint8, FuncCode);
    QFETCH(quint16, BeginAddress);
    QFETCH(quint16, Number);
    QFETCH(QByteArray,Data);
    QFETCH(QByteArray, expected);

    //初始化结构体
    Widget::RequestMessageStruct MessBasicInfo;
    MessBasicInfo.SlaveAddress = SlaveAddress;
    MessBasicInfo.FunctionCode = FuncCode;
    MessBasicInfo.BeginAddress = BeginAddress;
    MessBasicInfo.DataNumber = Number;
    QByteArray result = widget.RequestMessageBuild0X0f0X10(&MessBasicInfo,Data);
    QCOMPARE(result, expected);
}

//解析响应报文测试
void RTUtestTest::test_ParseResponseMessage_data()
{
    //创建配置对象
    QSettings settings("./RTUtest/config/ParseResponseMessage.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();
    //创建测试表
    QTest::addColumn<QByteArray>("ReponseMessage");
    QTest::addColumn<QByteArray>("RequestMessage");
    QTest::addColumn<bool>("expected");

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString RequestMessage = settings.value("Section" + QString::number(i + 1) + "/requestMessage").toString();
        QString ReponseMessage = settings.value("Section" + QString::number(i + 1) + "/responseMessage").toString();
        int expectedValue = settings.value("Section" + QString::number(i + 1) + "/expected").toString().toInt();

        //去除字符串空格
        RequestMessage.remove(QRegExp("\\s"));
        ReponseMessage.remove(QRegExp("\\s"));

        //获得字符数组大小
        int RequestMessageSize = (RequestMessage.size()/2);
        int ReponseMessageSize = (ReponseMessage.size()/2);
        QByteArray requestMessage;
        QByteArray reponseMessage;

        //转为字节数组
        for(int j = 0; j < RequestMessageSize; j++)
        {
            requestMessage.append((quint8)(RequestMessage.mid(2*j,2).toInt(NULL,16)));
        }
        for(int j =0; j < ReponseMessageSize;j++)
        {
            reponseMessage.append((quint8)(ReponseMessage.mid(2*j,2).toInt(NULL,16)));
        }

        bool expected;
        if(expectedValue == 1)
        {
            expected = true;
        }
        else
        {
            expected = false;
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << reponseMessage
                                 << requestMessage
                                 << expected;
    }

}
void RTUtestTest::test_ParseResponseMessage()
{
    QFETCH(QByteArray,ReponseMessage);
    QFETCH(QByteArray,RequestMessage);
    QFETCH(bool,expected);

    bool res = widget.ParseResponseMessage(ReponseMessage,RequestMessage);
    QCOMPARE(res,expected);
}

//线圈16进制字节数组转2进制字符串
void RTUtestTest::test_CoilsByteArrayToQString_data()
{
    //创建配置对象
    QSettings settings("./RTUtest/config/CoilsByteArrayToQString_data.ini",QSettings::IniFormat);
    //获取样例数
    int testcount = settings.value("section0/num").toInt();
    //创建测试表
    QTest::addColumn<QByteArray>("Coils");
    QTest::addColumn<quint16>("Number");
    QTest::addColumn<QString>("Result");
    //取出样例
    for(int i=0;i<testcount;i++)
    {
        //取出样例
        QString coil = settings.value("Section" + QString::number(i + 1) + "/coil").toString();
        quint16 number = settings.value("Section"+QString::number(i+1)+"/number").toString().toInt();
        QString Expected= settings.value("Section" + QString::number(i + 1) + "/expected").toString();
        //字节数组大小
        int messageSize = coil.size()/2;
        QByteArray messageArr;
        //转为字节数组
        for(int j = 0; j < messageSize; j++)
        {
            messageArr.append((quint8)(coil.mid(2*j,2).toInt(NULL,16)));
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << messageArr << number << Expected;
    }
}
//线圈16进制字节数组转2进制字符串测试
void RTUtestTest::test_CoilsByteArrayToQString()
{
    QFETCH(QByteArray,Coils);
    QFETCH(quint16,Number);
    QFETCH(QString, Result);
    QString result = widget.HexByteArrayToBinString(Coils,Number);
    QCOMPARE(result, Result);
}
//寄存器16进制字节数组转10进制字符串
void RTUtestTest::test_RegistersByteArrayToQString_data()
{
    //创建配置对象
    QSettings settings("./RTUtest/config/RegistersByteArrayToQString_data.ini",QSettings::IniFormat);
    //获取样例数
    int testcount = settings.value("section0/num").toInt();
    //创建测试表
    QTest::addColumn<QByteArray>("registers");
    QTest::addColumn<QString>("ResultString");
    //取出样例
    for(int i=0;i<testcount;i++)
    {
        //取出样例
        QString Register = settings.value("Section" + QString::number(i + 1) + "/registers").toString();
        QString Expected= settings.value("Section" + QString::number(i + 1) + "/expected").toString();
        //字节数组大小
        int messageSize = Register.size()/2;
        QByteArray messageArr;
        //转为字节数组
        for(int j = 0; j < messageSize; j++)
        {
            messageArr.append((quint8)(Register.mid(2*j,2).toInt(NULL,16)));
        }

        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << messageArr << Expected;
    }
}
//寄存器16进制字节数组转10进制字符串测试
void RTUtestTest::test_RegistersByteArrayToQString()
{
    QFETCH(QByteArray, registers);
    QFETCH(QString, ResultString);
    QString result = widget.HexByteArrayToDecString(registers);
    QCOMPARE(result, ResultString);
}

QTEST_MAIN(RTUtestTest)

#include "tst_rtutesttest.moc"
