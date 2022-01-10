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
#include <QInputDialog>
#include <QSettings>

//NetWork
#include <QtNetwork>
#include <QTcpSocket>
#include <QHostAddress>
#include "historymessagedialog.h"
#include "inputdialog.h"

//Macro
#define RECORD_FILE_PATH  "../Log/record.txt"  //日志记录路径
#define DATA_FILE_PATH "../Data/Data.ini"  //数据文件路径

#define MAXSLAVENUMBER 247    //从机地址个数最大为247
#define CLOCK_REFRESH 500  //时钟刷新时间
#define CLOCK_FORMAT "yyyy-MM-dd hh:mm:ss dddd"  //时钟显示格式
#define WAITE_FOR_CONNECT 3000  //设置等待连接时间
#define WAITE_FOR_RESPONSE 3000 //设置响应报文超时时长5000ms
#define RESENDNUMBER 3        //设置超时重发次数为3次
#define ADDRESS_MIN 0  //线圈和寄存器的地址最小值
#define ADDRESS_MAX 65535  //线圈和寄存器的地址最大值
#define READ_COIL_MINNUM 1  //请求报文读取线圈个数的最小值
#define READ_COIL_MAXNUM 2000  //请求报文读取线圈个数的最大值
#define READ_REGISTER_MINNUM 1 //请求报文读取寄存器个数的最小值
#define READ_REGISTER_MAXNUM 125 //请求报文读取寄存器个数的最大值
#define WRITE_COIL_MINNUM 1  //请求报文写入线圈个数的最小值
#define WRITE_COIL_MAXNUM 1968  //请求报文写入线圈个数的最大值
#define WRITE_REGISTER_MINNUM 1 //请求报文写入寄存器个数的最小值
#define WRITE_REGISTER_MAXNUM 123 //请求报文写入寄存器个数的最大值
#define WRITE_REGISTER_VALUE_MINNUM 0 //请求报文写入寄存器数值的最小值
#define WRITE_REGISTER_VALUE_MAXNUM 65535 //请求报文写入寄存器数值的最大值
#define REQUEST_MESSAGE_LENGTH_0X01_0X03 12 //0X01或0X03请求报文长度
#define TCP_MINIMUM_MESSAGE_LENGTH 9      //TCP 最小报文长度
#define TCP_MAXIMUM_MESSAGE_LENGTH 259    //TCP 最大报文长度

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //设置默认服务器IP地址和端口号
    QString defaultIpAddress = "127.0.0.1";
    qint16 defaultPortAddress = 502;

    //设置TCP连接状态标识符，默认为断开状态
    bool TcpConnectIdentifier = false;
    //设置TCP请求报文发送状态，设置在线请求报文只能有一个，默认为未发送状态
    bool TCPSendIdentifier = false;
    //初始化超时重传次数
    int resendNumber;
    //初始化请求报文数组
    QByteArray requestMessage;
    //MBAP事务元标识符
    quint16 transactionIdentifier = 0;

    //声明设置对象
    QSettings  *settings;
    //本地数据显示初始化
    void DataInitialization();
    //数据搜索定位
    void Search(int type);

    //写入单个线圈或寄存器
    void WriteCoilsData(int Column,QString CoilData);
     void WriteRegistersData(int Column,QString registerData);
    //查询数据写入到文件
    void UpdateCoilsData(quint16 BeginAddress,quint16 DataNumber,QString DataString);
    void UpdateRegistersData(quint16 BeginAddress,quint16 DataNumber,QString DataString);
    //16进制字节数组转化为2进制字符串
    QString HexByteArrayToBinString(QByteArray DataArray);
    //16进制字节数组 转化为 10进制字符数组，每个寄存器的值用空格分开
    QString HexByteArrayToDecString(QByteArray DataArray);

    //多线圈字符串合法性判断函数
    bool coilsLegality(QString &coils);

    //字节反转函数
    void byteReverse(QString &coils);
    //数组转十六进制字符串
    QString HexByteArrayToHexString(QByteArray HexByteArr,int ConvertLen, int pattern);
    //请求报文公共信息结构体
    typedef struct MessageBasicInformation
    {
        //事务元标识符
        quint16 transactionIdenti;
        //协议标识符
        quint16 protocolIdenti;
        //基础长度(6)
        quint16 length;
        //单元标识符
        quint8 unitIdenti;
        //功能码
        quint8 funcCode;
        //起始地址
        quint16 beginAddr;
        //数量
        quint16 num;
    }MessageBasicInformation;

    //TCP主站发送请求报文函数
    void TCPRequestMessage(int funcCodeIndex);
    //结构体初始化函数
    void structInitialize(MessageBasicInformation *structPt);
    //读输出线圈0x01和读输出寄存器0x03请求报文处理函数
    void RequestMessage0x010x03();
    //读输出线圈0x01和读输出寄存器0x03请求报文构建函数
    QByteArray RequestMessage0x010x03Build(MessageBasicInformation *structPt);

    //处理用户线圈输入函数，返回字节数组
    QByteArray userCoilsInputProcess();
    //处理用户寄存器输入函数，返回字节数组
    QByteArray userRegistersInputProcess();
    //写多个输出线圈0x0F和写多个输出寄存器0x10请求报处理函数
    void RequestMessage0x0F0x10();
    //写多个输出线圈0x0F和写多个输出寄存器0x10请求报构建函数
    QByteArray RequestMessage0x0F0x10Build(MessageBasicInformation *structPt, QByteArray byteArr);
    //TCP主站请求报文发送函数
    void TCPRequestMessageSend();


    //显示响应报文函数
    void ShowResponseMessage(QString Message);
    //解析响应报文
    bool TCPAnalysisMessage(QByteArray MessageArray);
    //报文合法性判断函数
    bool MessageLegalJudge(QByteArray MessageArr, QByteArray requestMessageArr);
    //功能码合法性判断函数
    bool FuncCodeLegalJudge(QByteArray MessageArr);
    //异常码报文处理函数
    bool TCPExceptionCodeProcess(QByteArray MessageArr);
    //异常码判断函数
    void TCPExceptionCodeJudge(quint8 excCode);
    //0X01功能码报文处理函数
    bool TCP0X01FuncCodeProcess(QByteArray MessageArr, QByteArray requestMessageArr);
    //0X03功能码报文处理函数
    bool TCP0X03FuncCodeProcess(QByteArray MessageArr, QByteArray requestMessageArr);
    //0X0f功能码报文处理函数
    bool TCP0X0fFuncCodeProcess(QByteArray MessageArr, QByteArray requestMessageArr);
    //0X10功能码报文处理函数
    bool TCP0X10FuncCodeProcess(QByteArray MessageArr, QByteArray requestMessageArr);
    //连接两个quint8数据为一个quint16数据
    quint16 BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum);

    //重置文件保存路径
    void ResetFilePath();
    //程序关闭事件处理函数
    void closeEvent(QCloseEvent *event);

private:
    Ui::Widget *ui;

    //日志显示界面
    HistoryMessageDialog * HistoryMessageWindow;
    //数据显示

    //数据输入界面
    inputDialog *input;

    int timer;
    void timerEvent(QTimerEvent *event);
    //声明tcp套接字
    QTcpSocket *tcpSocket;
    //声明IP地址，端口号
    QString ipAddress;
    qint16 portAddress;

    //file
    //初始化文件路径
    QString path = "";

    //function
    //时钟函数
    void showDateTime();

    //提示连接成功函数
    void ConnectSuccessPrompt();
    //提示连接失败函数
    void ConnectFailurePrompt();
    //二次确认断开连接函数
    void DisConnectConfirm();
    //提示连接断开函数
    void ConnectBrokensPrompt();
    //提示没有历史记录函数
    void NoFilePathPrompt();
    //提示文件路径设置成功函数
    void PathSettingSuccessPrompt();
    //提示文件打开失败函数
    void FailedOpenFilePrompt();
    //文件信息函数
    void FileInformation();
    //时间信息函数
    void TimeInformation();

    //初始化服务器设置
    void ServerInit();
    //初始化请求窗口设置
    void RequestInit();
    //设置ip默认值函数
    void IpDefault();
    //设置port默认值函数
    void PortDefault();

    //TCP连接函数
    void TcpConnect();
    //TCP断开函数
    void TcpDisConnect();

    //清除消息窗口函数
    void ClearMessageWin();

    //查看历史消息函数
    void ViewHistoricalMessage();
    //显示历史消息函数
    void ShowHistoricalMessage();
    //写历史消息函数
    void WriteHistoricalMessage();

public slots:
    //功能码配置函数，选择不同的功能码设置对应的数量范围
    void FuncCodeSetNumLineEdit(int FCBIndex);
};

#endif // WIDGET_H
