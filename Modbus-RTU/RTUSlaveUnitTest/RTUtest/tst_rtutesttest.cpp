#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "../../Modbus-RTU-Slave/ModBus_RTU_slaver/historymessagedialog.h"
#include "../../Modbus-RTU-Slave/ModBus_RTU_slaver/widget.h"

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

    //RTU从站
    //解析请求报文测试
    void test_RTUAnalysisMessage_data();
    void test_RTUAnalysisMessage();

    //字节反转函数测试
    void test_byteReverse_data();
    void test_byteReverse();

    //连接两个quint8数据为一个quint16数据函数测试
    void test_BondTwoUint8ToUint16_data();
    void test_BondTwoUint8ToUint16();

    //CRC校验码计算函数测试
    void test_CRCCheck_data();
    void test_CRCCheck();

    //数组转十六进制字符串函数测试
    void test_HexByteArrayToHexString_data();
    void test_HexByteArrayToHexString();

    //异常响应报文数组构建函数测试
    void test_AbnormalResponseMessage_data();
    void test_AbnormalResponseMessage();

    //0x01和0x03正常响应报文构建函数测试
    void test_NorResseMessBuild0x010x03_data();
    void test_NorResseMessBuild0x010x03();

    //0x0f和0x10正常响应报文构建函数测试
    void test_NorResseMessBuild0x0f0x10_data();
    void test_NorResseMessBuild0x0f0x10();
};

RTUtestTest::RTUtestTest()
{
}

//字节反转函数测试数据
void RTUtestTest::test_byteReverse_data()
{
    QTest::addColumn<QString>("targetString");
    QTest::addColumn<QString>("resultString");

    //ini读取
    QTest::newRow("全0") << "00000000" << "00000000";
    QTest::newRow("01混杂") << "01110110" << "01101110";
    QTest::newRow("全1") << "11111111" << "11111111";
    QTest::newRow("正常情况1") << "11011101" << "10111011";
    QTest::newRow("正常情况2") << "10111001" << "10011101";
}

//字节反转函数测试
void RTUtestTest::test_byteReverse()
{
    QFETCH(QString, targetString);
    QFETCH(QString, resultString);

    QString resultStr = targetString;
    widget.byteReverse(resultStr);

    QCOMPARE(resultStr, resultString);
}

//连接两个quint8数据为一个quint16数据函数测试数据
void RTUtestTest::test_BondTwoUint8ToUint16_data()
{
    QTest::addColumn<quint8>("preNum");
    QTest::addColumn<quint8>("afterNum");
    QTest::addColumn<quint16>("bondNum");

    //ini读取
    QTest::newRow("前0后1") << quint8(0) << quint8(255) << quint16(255);
    QTest::newRow("前1后0") << quint8(255) << quint8(0) << quint16(65280);
    QTest::newRow("全1") << quint8(255) << quint8(255) << quint16(65535);
    QTest::newRow("混杂") << quint8(215) << quint8(190) << quint16(55230);
    QTest::newRow("正常情况") << quint8(1) << quint8(1)  << quint16(257);
}
//连接两个quint8数据为一个quint16数据函数测试
void RTUtestTest::test_BondTwoUint8ToUint16()
{
    QFETCH(quint8, preNum);
    QFETCH(quint8, afterNum);
    QFETCH(quint16, bondNum);

    quint16 resultNum = widget.BondTwoUint8ToUint16(preNum, afterNum);
    QCOMPARE(resultNum, bondNum);
}

//CRC校验码计算函数测试数据
void RTUtestTest::test_CRCCheck_data()
{
    QTest::addColumn<QString>("checkString");
    QTest::addColumn<QString>("checkStringCrc");

    //ini读取
    QTest::newRow("0") << "0000000000" << "2400";
    QTest::newRow("1") << "1111111111" << "4166";
    QTest::newRow("2") << "AAAAAAAAAA" << "c33f";
    QTest::newRow("3") << "FFFFFFFFFF" << "3180";
    QTest::newRow("4") << "04F5AB6C7E" << "3acc";
    QTest::newRow("5") << "0" << "bf40";
    QTest::newRow("6") << "1" << "7e80";
    QTest::newRow("7") << "A" << "3f47";
    QTest::newRow("8") << "F" << "ff44";
}
//CRC校验码计算函数测试
void RTUtestTest::test_CRCCheck()
{
    QFETCH(QString, checkString);
    QFETCH(QString, checkStringCrc);

    QString resultCrc = widget.CRCCheck(checkString);
    QCOMPARE(resultCrc, checkStringCrc);
}

//数组转十六进制字符串函数测试数据
void RTUtestTest::test_HexByteArrayToHexString_data()
{
    QTest::addColumn<QByteArray>("HexByteArr");
    QTest::addColumn<int>("ConvertLen");
    QTest::addColumn<int>("pattern");
    QTest::addColumn<QString>("expected");

    //ini读取
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
void RTUtestTest::test_HexByteArrayToHexString()
{
    QFETCH(QByteArray, HexByteArr);
    QFETCH(int, ConvertLen);
    QFETCH(int, pattern);
    QFETCH(QString, expected);

    QString resultStr = widget.HexByteArrayToHexString(HexByteArr, ConvertLen, pattern);
    QCOMPARE(resultStr, expected);
}

//异常响应报文数组构建函数测试数据
void RTUtestTest::test_AbnormalResponseMessage_data()
{
    QTest::addColumn<quint8>("localAddr");
    QTest::addColumn<quint8>("funcCode");
    QTest::addColumn<int>("abnorCode");
    QTest::addColumn<QString>("abnormalResponseStr");
    //ini读取
    QTest::newRow("0") << quint8(1) << quint8(0X01) << 1 << "0181018190";
    QTest::newRow("1") << quint8(1) << quint8(0X01) << 2 << "018102c191";
    QTest::newRow("2") << quint8(1) << quint8(0X01) << 3 << "0181030051";
    QTest::newRow("3") << quint8(1) << quint8(0X03) << 1 << "01830180f0";
    QTest::newRow("4") << quint8(1) << quint8(0X03) << 2 << "018302c0f1";
    QTest::newRow("5") << quint8(1) << quint8(0X03) << 3 << "0183030131";
    QTest::newRow("6") << quint8(1) << quint8(0X0F) << 1 << "018f0185f0";
    QTest::newRow("7") << quint8(1) << quint8(0X0F) << 2 << "018f02c5f1";
    QTest::newRow("8") << quint8(1) << quint8(0X0F) << 3 << "018f030431";
    QTest::newRow("9") << quint8(1) << quint8(0X10) << 1 << "0190018dc0";
    QTest::newRow("10") << quint8(1) << quint8(0X10) << 2 << "019002cdc1";
    QTest::newRow("11") << quint8(1) << quint8(0X10) << 3 << "0190030c01";

    QTest::newRow("12") << quint8(247) << quint8(0X01) << 1 << "f7810161a2";
    QTest::newRow("13") << quint8(247) << quint8(0X01) << 2 << "f7810221a3";
    QTest::newRow("14") << quint8(247) << quint8(0X01) << 3 << "f78103e063";
    QTest::newRow("15") << quint8(247) << quint8(0X03) << 1 << "f7830160c2";
    QTest::newRow("16") << quint8(247) << quint8(0X03) << 2 << "f7830220c3";
    QTest::newRow("17") << quint8(247) << quint8(0X03) << 3 << "f78303e103";
    QTest::newRow("18") << quint8(247) << quint8(0X0F) << 1 << "f78f0165c2";
    QTest::newRow("19") << quint8(247) << quint8(0X0F) << 2 << "f78f0225c3";
    QTest::newRow("20") << quint8(247) << quint8(0X0F) << 3 << "f78f03e403";
    QTest::newRow("21") << quint8(247) << quint8(0X10) << 1 << "f790016df2";
    QTest::newRow("22") << quint8(247) << quint8(0X10) << 2 << "f790022df3";
    QTest::newRow("23") << quint8(247) << quint8(0X10) << 3 << "f79003ec33";
}
//异常响应报文数组构建函数测试
void RTUtestTest::test_AbnormalResponseMessage()
{
    QFETCH(quint8, localAddr);
    QFETCH(quint8, funcCode);
    QFETCH(int, abnorCode);
    QFETCH(QString, abnormalResponseStr);

    QByteArray resultArr = widget.AbnormalResponseMessage(localAddr, funcCode, abnorCode);
    QString resultStr = widget.HexByteArrayToHexString(resultArr, resultArr.size(), 0);
    QCOMPARE(resultStr, abnormalResponseStr);
}

//解析请求报文测试数据
void RTUtestTest::test_RTUAnalysisMessage_data()
{
    //创建配置对象
    QSettings settings("./RTUtest/config/RTUAnalysisMessage_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();
    //创建测试表
    QTest::addColumn<QByteArray>("RequestArr");
    QTest::addColumn<bool>("Expected");
    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString message = settings.value("Section" + QString::number(i + 1) + "/Message").toString();

        int expectedValue = settings.value("Section" + QString::number(i + 1) + "/expected").toInt();

        int messageSize = (message.size()/2);
        bool expected;

        if(expectedValue == 1)
        {
            expected = true;
        }
        else
        {
            expected = false;
        }

        QByteArray messageArr;
        //转为字节数组
        for(int j = 0; j < messageSize; j++)
        {
            messageArr.append((quint8)(message.mid(2*j,2).toInt(NULL,16)));
        }
        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << messageArr << expected;
    }
}

//解析请求报文测试
void RTUtestTest::test_RTUAnalysisMessage()
{
    QFETCH(QByteArray, RequestArr);
    QFETCH(bool, Expected);

    bool result = widget.RTUAnalysisMessage(RequestArr);

    QCOMPARE(result, Expected);
}

//0x01和0x03正常响应报文构建函数测试数据
void RTUtestTest::test_NorResseMessBuild0x010x03_data()
{
    //创建配置对象
    QSettings settings("./RTUtest/config/NorResseMessBuild0x010x03_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    //创建测试表
    QTest::addColumn<int>("Size");
    QTest::addColumn<quint8>("SlaveAddress");
    QTest::addColumn<quint8>("FuncCode");
    QTest::addColumn<quint16>("BeginAddress");
    QTest::addColumn<quint16>("Number");
    QTest::addColumn<QString>("CrcCheck");
    QTest::addColumn<QByteArray>("byteArr");
    QTest::addColumn<QByteArray>("expected");

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        int Size = settings.value("Section" + QString::number(i + 1) + "/Size").toInt();
        quint8 SlaveAddress = settings.value("Section" + QString::number(i + 1) + "/SlaveAddress").toInt();
        quint8 FuncCode = settings.value("Section" + QString::number(i + 1) + "/FuncCode").toInt();
        quint16 BeginAddress = settings.value("Section" + QString::number(i + 1) + "/BeginAddress").toInt();
        quint16 Number = settings.value("Section" + QString::number(i + 1) + "/Number").toInt();
        QString CrcCheck = settings.value("Section" + QString::number(i + 1) + "/CrcCheck").toString();
        QString byteString = settings.value("Section" + QString::number(i + 1) + "/byteArr").toString();
        QString expectedString = settings.value("Section" + QString::number(i + 1) + "/expected").toString();

        //去除字符串空格
        CrcCheck.remove(QRegExp("\\s"));
        byteString.remove(QRegExp("\\s"));
        expectedString.remove(QRegExp("\\s"));

        //获得字符数组大小
        int byteArrSize = (byteString.size()/2);
        int expectedSize = (expectedString.size()/2);

        QByteArray byteArr, expected;
        //转为字节数组
        for(int j = 0; j < byteArrSize; j++)
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
        QTest::newRow(rowNameCh) << Size
                                 << SlaveAddress
                                 << FuncCode
                                 << BeginAddress
                                 << Number
                                 << CrcCheck
                                 << byteArr
                                 << expected;
    }
}

//0x01和0x03正常响应报文构建函数测试
void RTUtestTest::test_NorResseMessBuild0x010x03()
{
    QFETCH(int, Size);
    QFETCH(quint8, SlaveAddress);
    QFETCH(quint8, FuncCode);
    QFETCH(quint16, BeginAddress);
    QFETCH(quint16, Number);
    QFETCH(QString, CrcCheck);
    QFETCH(QByteArray, byteArr);
    QFETCH(QByteArray, expected);

    //初始化结构体
    Widget::MessageBasicInformation MessBasicInfo;
    MessBasicInfo.Size = Size;
    MessBasicInfo.SlaveAddress = SlaveAddress;
    MessBasicInfo.FuncCode = FuncCode;
    MessBasicInfo.BeginAddress = BeginAddress;
    MessBasicInfo.Number = Number;
    MessBasicInfo.CrcCheck = CrcCheck;

    QByteArray result = widget.NorResseMessBuild0x010x03(&MessBasicInfo, byteArr);

    QCOMPARE(result, expected);
}

//0x0f和0x10正常响应报文构建函数测试数据
void RTUtestTest::test_NorResseMessBuild0x0f0x10_data()
{
    //创建配置对象
    QSettings settings("./RTUtest/config/NorResseMessBuild0x0f0x10_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    //创建测试表
    QTest::addColumn<int>("Size");
    QTest::addColumn<quint8>("SlaveAddress");
    QTest::addColumn<quint8>("FuncCode");
    QTest::addColumn<quint16>("BeginAddress");
    QTest::addColumn<quint16>("Number");
    QTest::addColumn<QString>("CrcCheck");
    QTest::addColumn<QByteArray>("expected");

    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        int Size = settings.value("Section" + QString::number(i + 1) + "/Size").toInt();
        quint8 SlaveAddress = settings.value("Section" + QString::number(i + 1) + "/SlaveAddress").toInt();
        quint8 FuncCode = settings.value("Section" + QString::number(i + 1) + "/FuncCode").toInt();
        quint16 BeginAddress = settings.value("Section" + QString::number(i + 1) + "/BeginAddress").toInt();
        quint16 Number = settings.value("Section" + QString::number(i + 1) + "/Number").toInt();
        QString CrcCheck = settings.value("Section" + QString::number(i + 1) + "/CrcCheck").toString();
        QString expectedString = settings.value("Section" + QString::number(i + 1) + "/expected").toString();

        //去除字符串空格
        CrcCheck.remove(QRegExp("\\s"));
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
        QTest::newRow(rowNameCh) << Size
                                 << SlaveAddress
                                 << FuncCode
                                 << BeginAddress
                                 << Number
                                 << CrcCheck
                                 << expected;
    }

}

//0x0f和0x10正常响应报文构建函数测试
void RTUtestTest::test_NorResseMessBuild0x0f0x10()
{
    QFETCH(int, Size);
    QFETCH(quint8, SlaveAddress);
    QFETCH(quint8, FuncCode);
    QFETCH(quint16, BeginAddress);
    QFETCH(quint16, Number);
    QFETCH(QString, CrcCheck);
    QFETCH(QByteArray, expected);

    //初始化结构体
    Widget::MessageBasicInformation MessBasicInfo;
    MessBasicInfo.Size = Size;
    MessBasicInfo.SlaveAddress = SlaveAddress;
    MessBasicInfo.FuncCode = FuncCode;
    MessBasicInfo.BeginAddress = BeginAddress;
    MessBasicInfo.Number = Number;
    MessBasicInfo.CrcCheck = CrcCheck;

    QByteArray result = widget.NorResseMessBuild0x0f0x10(&MessBasicInfo);

    QCOMPARE(result, expected);
}


QTEST_MAIN(RTUtestTest)

#include "tst_rtutesttest.moc"
