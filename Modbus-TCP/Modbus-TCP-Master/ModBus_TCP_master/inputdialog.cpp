#include "inputdialog.h"
#include "ui_inputdialog.h"

inputDialog::inputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputDialog)
{
    ui->setupUi(this);
    this->setFixedSize(500,200);
    connect(ui->inputDialogLineEdit,&QLineEdit::textChanged,[=](){
         quint16 number = ui->inputDialogLineEdit->text().count();
         ui->Number->setText("当前输入字符个数为："+QString::number(number));
    });
}


QString inputDialog::getText(QString title, QString writeGui)
{
    setWindowTitle(title);
    ui->inputDialogLabel->setText(writeGui);
     ui->Number->setText("当前输入字符个数为："+QString::number(0));
    exec();
    return this->ui->inputDialogLineEdit->text();

}

inputDialog::~inputDialog()
{
    delete ui;
}
