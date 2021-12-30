#include "widget.h"
#include "historymessagedialog.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Modbus-RTU-Slave");
    w.show();

    return a.exec();
}
