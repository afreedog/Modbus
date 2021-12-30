#include "inputdialog.h"
#include "ui_inputdialog.h"

inputDialog::inputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputDialog)
{
    ui->setupUi(this);
    this->setFixedSize(500,200);
}


QString inputDialog::getText(QString title, QString writeGui)
{
    setWindowTitle(title);
    ui->inputDialogLabel->setText(writeGui);

    exec();

    return this->ui->inputDialogLineEdit->text();
}

inputDialog::~inputDialog()
{
    delete ui;
}
