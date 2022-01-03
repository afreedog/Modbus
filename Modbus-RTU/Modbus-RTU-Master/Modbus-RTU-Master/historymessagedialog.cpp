#include "historymessagedialog.h"
#include "ui_historymessagedialog.h"

HistoryMessageDialog::HistoryMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryMessageDialog)
{
    ui->setupUi(this);
    this->setFixedSize(750,650);
    ui->HistoryMessageBox->setReadOnly(true);
}

void HistoryMessageDialog::ShowHistoryMessage(QString path)
{
    FilePath = path;
    //打开文件
    QFile file(FilePath);
    file.open(QFileDevice::ReadOnly);

    //只读，读取文件
    QByteArray DataArray;
    DataArray = file.readAll();

    ui->HistoryMessageBox->setText(DataArray);
    ui->HistoryMessageBox->moveCursor(QTextCursor::End);

    //显示模态对话框
    exec();
    file.close();
}

HistoryMessageDialog::~HistoryMessageDialog()
{
    delete ui;
}
