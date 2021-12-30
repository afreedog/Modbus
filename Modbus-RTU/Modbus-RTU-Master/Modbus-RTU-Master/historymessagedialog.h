#ifndef HISTORYMESSAGEDIALOG_H
#define HISTORYMESSAGEDIALOG_H

#include <QDebug>
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

    //显示历史信息
    void ShowHistoryMessage(QString path);

private:
    Ui::HistoryMessageDialog *ui;
    QString FilePath = "";
};

#endif // HISTORYMESSAGEDIALOG_H
