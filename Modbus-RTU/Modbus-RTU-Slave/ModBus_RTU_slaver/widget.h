#ifndef WIDGET_H
#define WIDGET_H

//Macro
#define INIFILE_PATH "../Data/Data.ini"  //数据文件路径
#define RECORD_PATH  "../Log/record.txt" //操作日志文件

#define CLOCK_REFRESH 500  //时钟刷新时间
#define CLOCK_FORMAT "yyyy-MM-dd hh:mm:ss dddd"  //时钟显示格式
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
#define READ_MESSAGE_TIME_LENGTH 300  //接收请求报文的时间为300ms
#define RTU_MESSAGE_MAX_BYTE 255 //RTU报文最大长度
#define MINIMUM_MESSAGE_LENGTH 8 //接收到的请求报文最小长度
#define REQUEST_MESSAGE_LENGTH_0X01_0X03 8 //接收到的0X01或0X03请求报文长度
#define ABNORMAL_RESPONSE_LENGTH 5  //异常响应报文长度
#define WRITE_RESPONSE_LENGTH 8 //正常写入响应报文长度
#include "historymessagedialog.h"

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

    //初始化波特率存储
    int *baudRate;
    //程序关闭事件处理函数
    void closeEvent(QCloseEvent *event);

    /**************************************************结构体和枚举*********************************************/
    //界面串口配置参数结构体
    typedef struct portParameters
    {
        //本机地址
        QString localAddress;
        //串口号
        QString portNumber;
        //波特率序号
        qint32 baudRate;
        //数据位序号
        QSerialPort::DataBits dataBits;
        //停止位序号
        QSerialPort::StopBits stopBits;
        //校验位序号
        QSerialPort::Parity parity;
    }portParameters;
    //串口配置参数结构体初始化函数
    void portStructInitialize(portParameters *structPt);

    //请求报文基础信息结构体
    typedef struct MessageBasicInformation
    {
        //请求报文长度
        int Size;
        //目的地址
        quint8 SlaveAddress;
        //功能码
        quint8 FuncCode;
        //起始地址
        quint16 BeginAddress;
        //数量项
        quint16 Number;
        //报文的CRC校验码
        QString CrcCheck;
    }MessageBasicInformation;
    //请求报文结构体初始化函数
    void messStructInitialize(MessageBasicInformation *structPt, QByteArray messageArr);

    /****************************************************报文处理*********************************************/
    //解析请求报文
    bool RTUAnalysisMessage(QByteArray MessageArray);
    //功能码0X01和0X03请求报文解析函数
    bool AnalysisMessage0X010X03(MessageBasicInformation *structPt, int errorMark);
    //功能码0X0F请求报文解析函数
    bool AnalysisMessage0X0F(MessageBasicInformation *structPt, QByteArray messageArr);
    //功能码0X10请求报文解析函数
    bool AnalysisMessage0X10(MessageBasicInformation *structPt, QByteArray messageArr);
    //异常响应报文构建函数
    QByteArray AbnormalResponseMessage(quint8 localAddr, quint8 funcCode,int abnorCode);
    //异常响应报文发送和显示函数
    void AbnorResMessSendAndPrompt(quint8 localAddr, quint8 funcCode, int abnorCode, int errorMark);

    //0x01正常响应报文线圈数据获取函数
    QByteArray NorResseMessBuild0x01data(MessageBasicInformation *structPt);
    //0x03正常响应报文寄存器数据获取函数
    QByteArray NorResseMessBuild0x03data(MessageBasicInformation *structPt);
    //0x01和0x03正常响应报文构建函数
    QByteArray NorResseMessBuild0x010x03(MessageBasicInformation *structPt, QByteArray byteArr);
    //0x0f和0x10正常响应报文构建函数
    QByteArray NorResseMessBuild0x0f0x10(MessageBasicInformation *structPt);
    //正常响应报文发送和显示函数
    void NorResMessSendAndPrompt(MessageBasicInformation *structPt);

    /****************************************************功能函数*********************************************/
    //十六进制数组转十六进制字符串（加空格）
    QString HexByteArrayToHexString(QByteArray HexByteArr, int ConvertLen, int pattern);
    //CRC校验码计算函数
    QString CRCCheck(QString &checkStr);
    //判断报文CRC正确性函数
    bool JudgeCRC(MessageBasicInformation *structPt, QByteArray messageArr);
    //连接两个quint8数据为一个quint16数据
    quint16 BondTwoUint8ToUint16(quint8 preNum, quint8 afterNum);
    //字节反转函数
    void byteReverse(QString &coils);


private:
    Ui::Widget *ui;

    //默认本机地址
    quint8 localAddress = 1;

    //初始化接收报文缓冲区
    QByteArray bufferArray;

    QSerialPort *serialPort;
    int *serialPortStatus;

    HistoryMessageDialog *HistoryMessageWindow;

    //时间事件
    int clock;
    int ReadMessageTime;
    QTimer *RecordTimer = nullptr;

    void timerEvent(QTimerEvent *event);
    //声明设置对象
    QSettings *settings;

    //初始化文件路径
    QString path = "";

    //时钟函数
    void showDateTime();

    //指针分配内存与删除函数
    void PointerManagement(int pattern);
    //初始化界面设置
    void InterfaceInit();
    //串口按钮函数
    void PortButton();
    //串口连接函数
    bool PortConnect(portParameters *structPt);
    //串口断开函数
    void PortDisConnect();
    //串口断开检测函数
    void handleSerialError(QSerialPort::SerialPortError error);
    //输入框关闭，发送按钮打开函数
    void boxConnect();
    //输入框开启，发送按钮关闭函数
    void boxDisconnect();

    //提示连接成功函数
    void OpenSuccessPrompt();
    //提示连接失败函数
    void OpenFailurePrompt();
    //提示串口关闭函数
    void ClosePortPrompt();

    //读出ini数据函数
    void ReadOutIniData(void);
    //写入线圈数据函数
    void WriteCoilData(int row,QString coilData);
    //写入寄存器数据函数
    void WriteRegistData(int row,QString registerData);
    //转到指定位置数据函数
    void Search(int type);

    //报文接收时间函数
    int ReceivingTime();
    //报文缓存区
    void RTUReadMessage();

    /****************************************************信息函数*********************************************/
    //清除消息窗口函数
    void ClearMessageWin();
    //查看历史消息函数
    void ViewHistoricalMessage();
    //显示历史消息函数
    void ShowHistoricalMessage();
    //写历史消息函数
    void WriteHistoricalMessage();
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
    //显示请求报文函数
    void ShowRequstMessage(QString Message);
};

#endif // WIDGET_H
