#include "historymessagedialog.h"
#include "ui_historymessagedialog.h"

HistoryMessageDialog::HistoryMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryMessageDialog)
{
    ui->setupUi(this);
}
//声明设置路径函数
void HistoryMessageDialog::ShowHistoricalMessage(QString path)
{
    filePath = path;
    //打开文件，使用只读方式读取文件
    QFile file(filePath);
    file.open(QFileDevice::ReadOnly);

    //读取文件
    QByteArray array;
    array = file.readAll();
    ui->historyMessageBrowser->setText(array);
    ui->historyMessageBrowser->moveCursor(QTextCursor::End);
    //显示模态对话框
    exec();
    file.close();
}

HistoryMessageDialog::~HistoryMessageDialog()
{
    delete ui;
}
