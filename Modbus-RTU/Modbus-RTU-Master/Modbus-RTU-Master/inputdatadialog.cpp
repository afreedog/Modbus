#include "inputdatadialog.h"
#include "ui_inputdatadialog.h"

InputDataDialog::InputDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDataDialog)
{
    ui->setupUi(this);
    this->setFixedSize(500,200);
    connect(ui->inputDialogLineEdit,&QLineEdit::textChanged,[=](){
         quint16 number = ui->inputDialogLineEdit->text().count();
         ui->number->setText("当前输入字符个数为："+QString::number(number));
    });
}

QString InputDataDialog::getText(QString title, QString writeGui)
{
    setWindowTitle(title);
    ui->inputDialogLabel->setText(writeGui);
    ui->number->setText("当前输入字符个数为："+QString::number(0));
    exec();

    return this->ui->inputDialogLineEdit->text();
}
InputDataDialog::~InputDataDialog()
{
    delete ui;
}
