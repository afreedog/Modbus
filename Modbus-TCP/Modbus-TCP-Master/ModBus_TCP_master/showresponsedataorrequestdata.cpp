#include "showresponsedataorrequestdata.h"
#include "ui_showresponsedataorrequestdata.h"

ShowResponseDataOrRequestData::ShowResponseDataOrRequestData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowResponseDataOrRequestData)
{
    ui->setupUi(this);
}

ShowResponseDataOrRequestData::~ShowResponseDataOrRequestData()
{
    delete ui;
}
