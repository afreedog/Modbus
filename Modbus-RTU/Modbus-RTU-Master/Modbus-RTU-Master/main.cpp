#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(790,840);
    w.setWindowTitle("Modbus-RTU-Master");
    w.show();

    return a.exec();
}
