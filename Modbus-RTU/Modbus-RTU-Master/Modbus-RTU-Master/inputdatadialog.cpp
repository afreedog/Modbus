#include "inputdatadialog.h"
#include "ui_inputdatadialog.h"

InputDataDialog::InputDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDataDialog)
{
    ui->setupUi(this);
    this->setFixedSize(500,200);
}

QString InputDataDialog::getText(QString title, QString writeGui)
{
    setWindowTitle(title);
    ui->inputDialogLabel->setText(writeGui);

    exec();

    return this->ui->inputDialogLineEdit->text();
}
InputDataDialog::~InputDataDialog()
{
    delete ui;
}
