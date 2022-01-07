#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "../../Modbus-TCP-Slave/Modbus-TCP-Slave/historymessagedialog.h"
#include "../../Modbus-TCP-Slave/Modbus-TCP-Slave/widget.h"

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
    //TCP从站
    //TCP请求报文解析
    void test_TcpRequestMessageAnalysis_data();
    void test_TcpRequestMessageAnalysis();
    //TCP 0x01 0x03报文解析

    void test_AnalysisMessage0X010X03_data();
    void test_AnalysisMessage0X010X03();
    //TCP 0x0f 0x10报文解析
    void test_AnalysisMessage0X0f0X10_data();
    void test_AnalysisMessage0X0f0X10();

    //0x01 0x03响应报文生成
    void test_NormalResponseMessageBuild0X010X03_data();
    void test_NormalResponseMessageBuild0X010X03();

    //异常代码
    void test_AbnormalMessageBuild_data();
    void test_AbnormalMessageBuild();

    //16进制字节数组转2进制字符串
    //已测试

    //16进制字节数组转10进制字符串
    //已测试

};

TCPtestTest::TCPtestTest()
{
}
//请求报文解析测试
void TCPtestTest::test_TcpRequestMessageAnalysis_data()
{
    //创建测试表
    QTest::addColumn<QByteArray>("ReponseMessage");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/test_TcpRequestMessageAnalysis_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();
    //qDebug() << QString::number(testCount) << endl;
    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString reponseMessageString = settings.value("section" + QString::number(i + 1) + "/reqMes").toString();
        int expectedValue= settings.value("section" + QString::number(i + 1) + "/except").toString().toInt();

        //去除字符串空格
        reponseMessageString.remove(QRegExp("\\s"));
        //获得字符数组大小
        int reponseMessageSize = (reponseMessageString.size()/2);
        bool expect;
        if(expectedValue == 0)
        {
            expect = true;
        }
        else
        {
            expect = false;
        }
        QByteArray ReponseMessageArray;
        //转为字节数组
        for(int j = 0; j < reponseMessageSize; j++)
        {
            ReponseMessageArray.append((quint8)(reponseMessageString.mid(2*j,2).toInt(NULL,16)));
        }
        QString rowNameStr = QString::number(i);
        //qDebug() << widget.HexByteArrayToHexString(ReponseMessageArray,ReponseMessageArray.size(),0);
        //qDebug() << QString::number(ReponseMessageArray.size()) << endl;

        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << ReponseMessageArray
                                 << expect;
    }
}
void TCPtestTest::test_TcpRequestMessageAnalysis()
{
    QFETCH(QByteArray,ReponseMessage);
    QFETCH(bool,expected);

    bool res = widget.TcpRequestMessageAnalysis(ReponseMessage);
    QCOMPARE(res,expected);

}

//0x01 0x03
void TCPtestTest::test_AnalysisMessage0X010X03_data()
{
    //创建测试表
    QTest::addColumn<QByteArray>("ReponseMessage");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/AnalysisMessage0X010X03_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();
    //qDebug() << QString::number(testCount) << endl;
    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString reponseMessageString = settings.value("section" + QString::number(i + 1) + "/reqMes").toString();
        int expectedValue= settings.value("section" + QString::number(i + 1) + "/except").toString().toInt();

        //去除字符串空格
        reponseMessageString.remove(QRegExp("\\s"));
        //获得字符数组大小
        int reponseMessageSize = (reponseMessageString.size()/2);
        bool expect;
        if(expectedValue == 0)
        {
            expect = true;
        }
        else
        {
            expect = false;
        }
        QByteArray ReponseMessageArray;
        //转为字节数组
        for(int j = 0; j < reponseMessageSize; j++)
        {
            ReponseMessageArray.append((quint8)(reponseMessageString.mid(2*j,2).toInt(NULL,16)));
        }
        QString rowNameStr = QString::number(i);
        //qDebug() << widget.HexByteArrayToHexString(ReponseMessageArray,ReponseMessageArray.size(),0);
        //qDebug() << QString::number(ReponseMessageArray.size()) << endl;

        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << ReponseMessageArray
                                 << expect;
    }
}
void TCPtestTest::test_AnalysisMessage0X010X03()
{
    QFETCH(QByteArray,ReponseMessage);
    QFETCH(bool,expected);

    bool res = widget.AnalysisMessage0X010X03(ReponseMessage);
    QCOMPARE(res,expected);

}

//0x0f 0x10
void TCPtestTest::test_AnalysisMessage0X0f0X10_data()
{
    //创建测试表
    QTest::addColumn<QByteArray>("ReponseMessage");
    QTest::addColumn<bool>("expected");

    //创建配置对象
    QSettings settings("./TCPtest/config/AnalysisMessage0X0F0X10_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();
    //qDebug() << QString::number(testCount) << endl;
    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString reponseMessageString = settings.value("section" + QString::number(i + 1) + "/reqMes").toString();
        int expectedValue= settings.value("section" + QString::number(i + 1) + "/except").toString().toInt();

        //去除字符串空格
        reponseMessageString.remove(QRegExp("\\s"));
        //获得字符数组大小
        int reponseMessageSize = (reponseMessageString.size()/2);
        bool expect;
        if(expectedValue == 0)
        {
            expect = true;
        }
        else
        {
            expect = false;
        }
        QByteArray ReponseMessageArray;
        //转为字节数组
        for(int j = 0; j < reponseMessageSize; j++)
        {
            ReponseMessageArray.append((quint8)(reponseMessageString.mid(2*j,2).toInt(NULL,16)));
        }
        QString rowNameStr = QString::number(i);
        //qDebug() << widget.HexByteArrayToHexString(ReponseMessageArray,ReponseMessageArray.size(),0);
        //qDebug() << QString::number(ReponseMessageArray.size()) << endl;

        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << ReponseMessageArray
                                 << expect;
    }
}
void TCPtestTest::test_AnalysisMessage0X0f0X10()
{
    QFETCH(QByteArray,ReponseMessage);
    QFETCH(bool,expected);

    bool res = widget.AnalysisMessage0X0f0X10(ReponseMessage);
    QCOMPARE(res,expected);
}

//0x01 0x03响应报文生成测试
void TCPtestTest::test_NormalResponseMessageBuild0X010X03_data()
{
    QTest::addColumn<QByteArray>("RequestMessage");
    QTest::addColumn<QByteArray>("Data");
    QTest::addColumn<QByteArray>("ReponseMessage");

    //创建配置对象
    QSettings settings("./TCPtest/config/NormalResponseMessageBuild0X010X03_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    //qDebug() << QString::number(testCount) << endl;
    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString ReponseMessageString = settings.value("section" + QString::number(i + 1) + "/reponse").toString();
        QString DataString = settings.value("section" + QString::number(i + 1) + "/data").toString();
        QString ExpectString = settings.value("section" + QString::number(i + 1) + "/expect").toString();

        //去除字符串空格
        ReponseMessageString.remove(QRegExp("\\s"));
        DataString.remove(QRegExp("\\s"));
        ExpectString.remove(QRegExp("\\s"));

        //获得字符数组大小
        int ReponseMessageSize = (ReponseMessageString.size()/2);
        int DataSize = (DataString.size()/2);
        int ExpectedSize = (ExpectString.size()/2);

        QByteArray ReponseMessageArray;
        QByteArray DataArray;
        QByteArray ExpectArray;

        //转为字节数组
        for(int j = 0; j < ReponseMessageSize; j++)
        {
            ReponseMessageArray.append((quint8)(ReponseMessageString.mid(2*j,2).toInt(NULL,16)));
        }
        for(int j = 0; j < DataSize;j++)
        {
            DataArray.append((quint8)(DataString.mid(2*j,2).toInt(NULL,16)));
        }
        for(int j = 0; j < ExpectedSize;j++)
        {
            ExpectArray.append((quint8)(ExpectString.mid(2*j,2).toInt(NULL,16)));
        }
        //qDebug() << widget.HexByteArrayToHexString(ReponseMessageArray,ReponseMessageArray.size(),0);
        //qDebug() << widget.HexByteArrayToHexString(DataArray,DataArray.size(),0);
        //qDebug() << widget.HexByteArrayToHexString(ExpectArray,ExpectArray.size(),0);
        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << ReponseMessageArray
                                 << DataArray
                                 << ExpectArray;
    }

}
void TCPtestTest::test_NormalResponseMessageBuild0X010X03()
{
    QFETCH(QByteArray,RequestMessage);
    QFETCH(QByteArray,Data);
    QFETCH(QByteArray,ReponseMessage);

    QByteArray res = widget.NormalResponseMessageBuild0X010X03(RequestMessage,Data);
    QCOMPARE(res,ReponseMessage);

}


//异常响应报文测试
void TCPtestTest::test_AbnormalMessageBuild_data()
{
    QTest::addColumn<QByteArray>("RequestMessage");
    QTest::addColumn<quint8>("AbnormalFunctionCode");
    QTest::addColumn<QByteArray>("ReponseMessage");

    //创建配置对象
    QSettings settings("./TCPtest/config/AbnormalMessageBuild_data.ini",QSettings::IniFormat);
    //获取样例数
    int testCount = settings.value("Section0/num").toInt();

    //qDebug() << QString::number(testCount) << endl;
    for(int i = 0; i < testCount; i++)
    {
        //取出样例
        QString ReponseMessageString = settings.value("Section" + QString::number(i + 1) + "/request").toString();
        quint8  FuncCode = settings.value("Section" + QString::number(i + 1) + "/abnormalcode").toString().toInt();
        QString ExpectString = settings.value("Section" + QString::number(i + 1) + "/reponse").toString();

        //去除字符串空格
        ReponseMessageString.remove(QRegExp("\\s"));
        ExpectString.remove(QRegExp("\\s"));

        //获得字符数组大小
        int ReponseMessageSize = (ReponseMessageString.size()/2);
        int ExpectedSize = (ExpectString.size()/2);

        QByteArray ReponseMessageArray;
        QByteArray ExpectArray;

        //转为字节数组
        for(int j = 0; j < ReponseMessageSize; j++)
        {
            ReponseMessageArray.append((quint8)(ReponseMessageString.mid(2*j,2).toInt(NULL,16)));
        }
        for(int j = 0; j < ExpectedSize;j++)
        {
            ExpectArray.append((quint8)(ExpectString.mid(2*j,2).toInt(NULL,16)));
        }
        //qDebug() << widget.HexByteArrayToHexString(ReponseMessageArray,ReponseMessageArray.size(),0);
        //qDebug() << widget.HexByteArrayToHexString(ExpectArray,ExpectArray.size(),0);
        QString rowNameStr = QString::number(i);
        char* rowNameCh;
        QByteArray rowNameArr = rowNameStr.toLatin1();
        rowNameCh = rowNameArr.data();
        //新建行存储
        QTest::newRow(rowNameCh) << ReponseMessageArray
                                 << FuncCode
                                 << ExpectArray;
    }
}

void TCPtestTest::test_AbnormalMessageBuild()
{
    QFETCH(QByteArray,RequestMessage);
    QFETCH(quint8,AbnormalFunctionCode);
    QFETCH(QByteArray,ReponseMessage);

    QByteArray res = widget.AbnormalMessageBuild(RequestMessage,AbnormalFunctionCode);
    QCOMPARE(res,ReponseMessage);
}


QTEST_MAIN(TCPtestTest)

#include "tst_tcptesttest.moc"
