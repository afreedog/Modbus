#ifndef WIDGET_H
#define WIDGET_H

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
#include <QSettings>
#include <QInputDialog>
#include <QIODevice>
#include <QDebug>
//Network
#include<QtNetwork>
#include<QTcpServer>
#include<QHostAddress>

#include "historymessagedialog.h"

#define INIFILE_PATH "../Data/Data.ini"  //数据文件路径
#define RECORD_PATH  "../Log/record.txt"

#define MAXSLAVENUMBER 247  //从机地址最大数
#define CLOCK_REFRESH 500   //时钟刷新时间
#define CLOCK_FORMAT "yyyy-MM-dd hh:mm:ss" //时间显示格式
#define WAITE_FOR_CONNECT 3000  //等待连接
#define RESENDNUMBER 3  //超时重发次数
#define ADDRESS_MIN 0  //线圈和寄存器的地址最小值
#define ADDRESS_MAX 65535 //线圈和寄存器的地址最大值
#define READ_COIL_MINNUM  1 //请求报文读取线圈最小值
#define READ_COIL_MAXNUM 2000  //请求报文读取线圈最大值
#define READ_REGISTER_MINNUM 1  //请求报文读取寄存器个数的最小值
#define READ_REGISTER_MAXNUM 125  //请求报文读取寄存器个数的最大值
#define WRITE_COIL_MINNUM 1  //请求报文写入线圈个数的最小值
#define WRITE_COIL_MAXNUM 1968 //请求报人写入线圈个数的最大值
#define WRITE_REGISTER_MINNUM 1  //请求报文写入寄存器个数最小值
#define WRITE_REGISTER_MAXNUM 123 //请求报文写入寄存器个数最大值
#define WRITE_REGISTER_VALUE_MINNUM 0 //请求报文写入寄存器中的数值最小值
#define WRITE_REGISTER_VALUE_MAXNUM 65535  //请求报文写入寄存器的数值最大值
#define REQUEST_MESSAGE_LENGTH_0X01_0X03  12   //0X01或0X03请求报文长度
#define TCP_MBAP_HEADER_LENGTH 6     //TCP 中MBAP的字节长度
#define TCP_MAX_LENGTH  259
#define TCP_MIN_LENGTH  12

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //默认的服务器ip地址、端口号、从机地址
    QString defaultIpAddress = "127.0.0.1";
    quint16 defaultPortNumber = 502;
    quint8 defaultSlaveAddress = 1;
    //从机地址
    quint8 SlaveAddress;

    //存放客户端Ip地址和端口
    QString MasterIpAddress;
    quint16 MasterPortNumber;

    //设置默认ip
    void IpDefault();
    //刷新IP
    QString getLocalIp();

    //设置默认端口
    void PortDefault();
    void SlaveAddressDefault();
    //tcpServer初始化
    void TcpServerInit();

    int timer;
    QTimer *RecordTimer=nullptr;
    void timerEvent(QTimerEvent *event);

    //结束计时函数
    void endTimer();
    void WriteHistoricalMessage();

    //声明设置对象
    QSettings *settings;

    //设置端口监听
    bool isListenTcpServer = false;
    //对指定ip指定端口进行监听
    void ListenTcpServer();

    bool TcpServerConnectState = false;

    //当前时间信息函数
    void TimeInformation();
    //时钟函数
    void ShowDateTime();

    //显示请求报文
    void ShowRequestMessage();
    //显示回应报文
    void ShowResponseMessage(QByteArray MessageArray);
    //异常报文判断
    bool AbnormalMessageJudgment(QByteArray MessageArray,quint8 &AbnormalFunctionCode);
    //异常报文生成
    QByteArray AbnormalMessageBuild(QByteArray MessageArray,quint8 AbnormalFunctionCode);
    //异常报文发送
    void AbnormalMessageSend(QByteArray Message);

    //建立新连接
    void CreateNewConnect();
    //显示新建连接
    void ShowTcpServerNewConnect();

    //请求报文字节数组
    QByteArray TcpRequestMessage;
    //解析请求报文
    bool TcpRequestMessageAnalysis(QByteArray MessageArray);
    void Search(int type);

    //0x01 0x03报文解析
    bool AnalysisMessage0X010X03(QByteArray MessageArray);
    //0x0f
    bool AnalysisMessage0X0f0X10(QByteArray MessageArray);
    void ShowCoilsData(QByteArray CoilsDataArray,quint16 ReceiveDataNumber);
    void ShowRegisterData(QByteArray RegistersDataArray);

    //0x01 获取线圈数据
    QByteArray GetData0X01(quint16 BeginAddress,quint16 Number);
    //0x03 获取寄存器数据
    QByteArray GetData0X03(quint16 BeginAddress,quint16 Number);
    //0x0f 写入线圈 单个线圈
    void WriteData0X0F(int Column,QString CoilData);
    //16进制字节数组转化为2进制字符串
    QString HexByteArrayToBinString(QByteArray DataArray);
    //0x10 写入寄存器 单个寄存器
    void WriteData0X10(int Column,QString registerData);
    //0X01正常报文生成
    QByteArray NormalResponseMessageBuild0X010X03(QByteArray MessageArray,QByteArray DataArray);

    //正常报文发送
    void NormalResponseMessageSend(QByteArray MessageArray);
    //16进制字节数组转化为16进制字符串
    QString HexByteArrayToHexString(QByteArray HexByteArr,int ConvertLen, int pattern);
    //更新线圈数据
    void UpdateCoilsData(quint16 BeginAddress,quint16 DataNumber,QString DataString);
    //更新寄存器数据
    void UpdateRegistersData(quint16 BeginAddress,quint16 DataNumber,QString DataString);
    //16进制字节数组 转化为 10进制字符数组，每个寄存器的值用空格分开
    QString HexByteArrayToDecString(QByteArray DataArray);
    //两个quint8 合并为 quint16
    quint16 BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum);
    void byteReverse(QString &coils);
    //ini文件 -> 数据表
    void ReadOutIniData();

    qintptr tcpReceiveSocketDescriptor;
    void closeEvent(QCloseEvent *event);
    HistoryMessageDialog *HistoryMessageWindow;

private:
    Ui::Widget *ui;

    QTcpServer *tcpServer;
    QTcpSocket *tcpReceiveSocket;

    //存放输入框中IP地址和端口
    QString ipAddress;
    quint16 portNumber;


    //显示断开连接
    void ShowTcpServerDisconnect(QAbstractSocket::SocketError);//
};

#endif // WIDGET_H
