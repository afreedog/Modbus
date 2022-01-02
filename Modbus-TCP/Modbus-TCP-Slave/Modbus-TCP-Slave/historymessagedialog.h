#ifndef HISTORYMESSAGEDIALOG_H
#define HISTORYMESSAGEDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>

namespace Ui {
class HistoryMessageDialog;
}

class HistoryMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryMessageDialog(QWidget *parent = 0);
    ~HistoryMessageDialog();

    void ShowHistoryMessage(QString path);

private:
    Ui::HistoryMessageDialog *ui;
    QString FilePath = "";
};

#endif // HISTORYMESSAGEDIALOG_H
