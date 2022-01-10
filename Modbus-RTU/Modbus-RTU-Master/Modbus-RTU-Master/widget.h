#ifndef WIDGET_H
#define WIDGET_H

#include "historymessagedialog.h"
#include "inputdatadialog.h"

#define INI_FILE_PATH "../Data/Data.ini"  //数据文件路径
#define RECORD_PATH "../Log/record.txt" //日志文件路径
#define CLOCK_REFRESH 500  //时钟刷新时间
#define CLOCK_FORMAT "yyyy-MM-dd hh:mm:ss ddd"  //时钟显示格式
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
#define RTU_MESSAGE_MAX_BYTE 255 //RTU报文最大长度
#define MINIMUM_MESSAGE_LENGTH 8 //接收到的请求报文最小长度
#define REQUEST_MESSAGE_LENGTH_0X01_0X03 8 //0X01或0X03请求报文长度
#define ABNORMAL_RESPONSE_LENGTH 5  //异常响应报文长度
#define WRITE_RESPONSE_LENGTH 8 //正常写入响应报文长度
#define RESEND_MESSAGE_MAX_NUMBER 3 //最大重传次数

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

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //界面初始化
    void InterfaceInit();
    //数据显示初始化
    QSettings *settings;
    //数据搜索
    void Search(int type);

    void ShowIniData();
    //最大数量的背景设置函数
    void MaxNumberOfDefaultBackground();
    //时钟计时器标识符
    int timer;
    //报文读取计时器
    int ReadMessageTimer;
    //报文重发计时器
    QTimer *ResendMessageTimer;
    bool isReceiveResponseMessage;
    //报文重发次数
    quint8 ResendNumber;
    //报文重发
    void ResendRequestMessage();

    //事件函数
    void timerEvent(QTimerEvent *event);
    //显示当前时间
    void TimeInformation();
    //时钟函数
    void ShowCurrentTime();

    //串口参数结构体
    typedef struct SerialPortParameters
    {
        //串口名
        QString SerialPortSerialName;
        //波特率
        QSerialPort::BaudRate SerialPortBaudRate;
        //数据位
        QSerialPort::DataBits SerialPortDataBits;
        //校验位
        QSerialPort::StopBits SerailPortStopBits;
        //停止位
        QSerialPort::Parity SerialPortParity;
    }SerialPortParameters;
    //串口波特率
    int SerialPortBaudRate;
    //串口状态
    bool isOpenSerialPort;
    //串口获取串口参数
    void GetSerialPortParameters();
    //串口结构体初始化
    void SerialPortInitialization();
    //串口打开或关闭
    void OpenOrCloseSerialPort();
    //串口刷新
    void RefreshSerialPort();
    //串口参数控件关闭
    void CloseSerialPortParametersBox();
    //串口参数控件开启
    void OpenSerialPortParametersBox();

    //请求报文结构
    typedef struct RequestMessageStruct
    {
        //地址
        quint8 SlaveAddress;
        //功能码
        quint8 FunctionCode;
        //起始地址
        quint16 BeginAddress;
        //数量
        quint16 DataNumber;
    }RequestMessageStruct;
    //报文结构体初始化
    void RequestMessageStructInitialization();
    //获取数据
    QByteArray InputCoils();
    QByteArray InputRegisters();
    //CRC校验码
    quint16 CRC16Modbus(const QByteArray &data,int flag);
    //报文生成
    QByteArray RequestMessageBuild0X010X03(RequestMessageStruct *requestmessage);
    QByteArray RequestMessageBuild0X0f0X10(RequestMessageStruct *requestmessage,QByteArray Data);

    //存放响应报文
    QByteArray RequestMessageArray;
    QString RequestMessageString;
    //报文发送
    void SendRequestMessage();


    //缓存响应报文
    QByteArray ReceiveMessageArray;
    //接收缓存时间
    int ReceivingTime();
    //接收响应报文
    void RTUReadMessage();
    //显示接收报文
    void ShowResponseMessage(QByteArray responseMessage);
    //将16进制线圈数据转换为2进制字符串
    QString HexByteArrayToBinString(QByteArray DataArray,quint16 DataNumber);
    //将16进制寄存器转化为10进制字符串
    QString HexByteArrayToDecString(QByteArray DataArray);

    //写入单个线圈或寄存器
    void WriteCoilsData(int Column,QString CoilData);
     void WriteRegistersData(int Column,QString registerData);
    //更新数据写入到文件
    void UpdateCoilsData(quint16 BeginAddress,quint16 DataNumber,QString DataString);
    void UpdateRegistersData(quint16 BeginAddress,quint16 DataNumber,QString DataString);
    //接收报文解析
    bool ParseResponseMessage(QByteArray responseMessage,QByteArray RequestMessageArray);


    //16进制字节数组转16进制字符串
    QString HexByteArrayToHexString(QByteArray HexByteArr,int ConvertLen, int pattern);
    //两个quint8 合成 quint16
    quint16 BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum);
    //字节翻转
    void byteReverse(QString &coils);

    //历史信息保存路径
    QString HistoryMessagePath;
    //历史信息计时器
    QTimer *HistoryMessageClearTimer;
    //产看历史信息
    void ShowHistoricalMessage();
    //记录历史信息
    void WriteHistoricalMessage(QString path);
    //清除当前窗口的信息
    void ClearCurrentHistoryMessage();
    //界面关闭事件
    void closeEvent(QCloseEvent *event);

private:
    Ui::Widget *ui;

    //历史信息窗口
    HistoryMessageDialog *HistoryMessageWindow;
    //串口
    QSerialPort * RtuSerialPort;
    //串口结构体
    SerialPortParameters *serialport;
    //请求报文结构体
    RequestMessageStruct *requestmessage;
};

#endif // WIDGET_H
