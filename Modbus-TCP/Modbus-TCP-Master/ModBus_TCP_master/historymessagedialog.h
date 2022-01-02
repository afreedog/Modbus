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

    //显示历史消息函数，参数为文件路径path
    void ShowHistoricalMessage(QString path);

private:
    Ui::HistoryMessageDialog *ui;

    //初始化路径为空
    QString filePath = "";

};

#endif // HISTORYMESSAGEDIALOG_H
