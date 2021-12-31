#ifndef SHOWRESPONSEDATAORREQUESTDATA_H
#define SHOWRESPONSEDATAORREQUESTDATA_H

#include <QWidget>

namespace Ui {
class ShowResponseDataOrRequestData;
}

class ShowResponseDataOrRequestData : public QWidget
{
    Q_OBJECT

public:
    explicit ShowResponseDataOrRequestData(QWidget *parent = 0);
    ~ShowResponseDataOrRequestData();

private:
    Ui::ShowResponseDataOrRequestData *ui;
};

#endif // SHOWRESPONSEDATAORREQUESTDATA_H
