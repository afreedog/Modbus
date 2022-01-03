#ifndef INPUTDATADIALOG_H
#define INPUTDATADIALOG_H

#include <QDialog>

namespace Ui {
class InputDataDialog;
}

class InputDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDataDialog(QWidget *parent = 0);
    ~InputDataDialog();

    QString getText(QString title,QString WriteGui);

private:
    Ui::InputDataDialog *ui;
};

#endif // INPUTDATADIALOG_H
