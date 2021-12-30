/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *dateTimeEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *historyButton;
    QSpacerItem *verticalSpacer;
    QPushButton *clearButton;
    QGroupBox *messageBox;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *messageEdit;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *addressBox;
    QGridLayout *gridLayout;
    QLineEdit *portEdit;
    QLineEdit *ipEdit;
    QLabel *ipAddressLabel;
    QLabel *portAddressLabel;
    QGroupBox *tcpBox;
    QVBoxLayout *verticalLayout;
    QPushButton *connectButton;
    QGroupBox *requestBox;
    QGridLayout *gridLayout_2;
    QLabel *beginAddressLabel;
    QLabel *slaveAddressLabel;
    QComboBox *slaveAddressBox;
    QLabel *funcLabel;
    QComboBox *funcCodeBox;
    QLabel *numLabel;
    QLineEdit *numLineEdit;
    QLineEdit *beginAddressLineEdit;
    QPushButton *sendButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(805, 857);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setBaseSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setBold(false);
        font.setWeight(50);
        Widget->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/xinje.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        verticalLayout_4 = new QVBoxLayout(Widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        dateTimeEdit = new QLabel(Widget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(dateTimeEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        historyButton = new QPushButton(Widget);
        historyButton->setObjectName(QStringLiteral("historyButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(historyButton->sizePolicy().hasHeightForWidth());
        historyButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        historyButton->setFont(font1);

        horizontalLayout_3->addWidget(historyButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        clearButton = new QPushButton(Widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        sizePolicy1.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy1);
        clearButton->setFont(font1);

        horizontalLayout_3->addWidget(clearButton);

        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(5, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        messageBox = new QGroupBox(Widget);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(messageBox->sizePolicy().hasHeightForWidth());
        messageBox->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        messageBox->setFont(font2);
        messageBox->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_4 = new QHBoxLayout(messageBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        messageEdit = new QTextEdit(messageBox);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));
        sizePolicy.setHeightForWidth(messageEdit->sizePolicy().hasHeightForWidth());
        messageEdit->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        messageEdit->setFont(font3);
        messageEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(messageEdit);


        verticalLayout_3->addWidget(messageBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addressBox = new QGroupBox(Widget);
        addressBox->setObjectName(QStringLiteral("addressBox"));
        addressBox->setFont(font1);
        gridLayout = new QGridLayout(addressBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        portEdit = new QLineEdit(addressBox);
        portEdit->setObjectName(QStringLiteral("portEdit"));
        portEdit->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(portEdit, 1, 1, 1, 1);

        ipEdit = new QLineEdit(addressBox);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));
        ipEdit->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(ipEdit, 0, 1, 1, 1);

        ipAddressLabel = new QLabel(addressBox);
        ipAddressLabel->setObjectName(QStringLiteral("ipAddressLabel"));
        ipAddressLabel->setFont(font1);

        gridLayout->addWidget(ipAddressLabel, 0, 0, 1, 1);

        portAddressLabel = new QLabel(addressBox);
        portAddressLabel->setObjectName(QStringLiteral("portAddressLabel"));
        portAddressLabel->setFont(font1);

        gridLayout->addWidget(portAddressLabel, 1, 0, 1, 1);


        horizontalLayout->addWidget(addressBox);

        tcpBox = new QGroupBox(Widget);
        tcpBox->setObjectName(QStringLiteral("tcpBox"));
        tcpBox->setFont(font1);
        verticalLayout = new QVBoxLayout(tcpBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        connectButton = new QPushButton(tcpBox);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        sizePolicy.setHeightForWidth(connectButton->sizePolicy().hasHeightForWidth());
        connectButton->setSizePolicy(sizePolicy);
        connectButton->setFont(font1);

        verticalLayout->addWidget(connectButton);


        horizontalLayout->addWidget(tcpBox);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        requestBox = new QGroupBox(Widget);
        requestBox->setObjectName(QStringLiteral("requestBox"));
        sizePolicy2.setHeightForWidth(requestBox->sizePolicy().hasHeightForWidth());
        requestBox->setSizePolicy(sizePolicy2);
        requestBox->setFont(font1);
        gridLayout_2 = new QGridLayout(requestBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        beginAddressLabel = new QLabel(requestBox);
        beginAddressLabel->setObjectName(QStringLiteral("beginAddressLabel"));

        gridLayout_2->addWidget(beginAddressLabel, 1, 0, 1, 1);

        slaveAddressLabel = new QLabel(requestBox);
        slaveAddressLabel->setObjectName(QStringLiteral("slaveAddressLabel"));

        gridLayout_2->addWidget(slaveAddressLabel, 0, 0, 1, 1);

        slaveAddressBox = new QComboBox(requestBox);
        slaveAddressBox->setObjectName(QStringLiteral("slaveAddressBox"));
        slaveAddressBox->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(slaveAddressBox, 0, 1, 1, 1);

        funcLabel = new QLabel(requestBox);
        funcLabel->setObjectName(QStringLiteral("funcLabel"));

        gridLayout_2->addWidget(funcLabel, 0, 2, 1, 1);

        funcCodeBox = new QComboBox(requestBox);
        funcCodeBox->setObjectName(QStringLiteral("funcCodeBox"));
        funcCodeBox->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(funcCodeBox, 0, 3, 1, 1);

        numLabel = new QLabel(requestBox);
        numLabel->setObjectName(QStringLiteral("numLabel"));

        gridLayout_2->addWidget(numLabel, 1, 2, 1, 1);

        numLineEdit = new QLineEdit(requestBox);
        numLineEdit->setObjectName(QStringLiteral("numLineEdit"));
        numLineEdit->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(numLineEdit, 1, 3, 1, 1);

        beginAddressLineEdit = new QLineEdit(requestBox);
        beginAddressLineEdit->setObjectName(QStringLiteral("beginAddressLineEdit"));
        beginAddressLineEdit->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(beginAddressLineEdit, 1, 1, 1, 1);


        verticalLayout_2->addWidget(requestBox);


        horizontalLayout_2->addLayout(verticalLayout_2);

        sendButton = new QPushButton(Widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy3);
        sendButton->setFont(font1);

        horizontalLayout_2->addWidget(sendButton);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 15);
        verticalLayout_3->setStretch(2, 3);

        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Modbus_TCP", Q_NULLPTR));
        dateTimeEdit->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        historyButton->setText(QApplication::translate("Widget", "\345\216\206\345\217\262\346\266\210\346\201\257", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\347\252\227\345\217\243", Q_NULLPTR));
        messageBox->setTitle(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));
        addressBox->setTitle(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        ipAddressLabel->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        portAddressLabel->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        tcpBox->setTitle(QApplication::translate("Widget", "TCP", Q_NULLPTR));
        connectButton->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", Q_NULLPTR));
        requestBox->setTitle(QApplication::translate("Widget", "\350\257\267\346\261\202", Q_NULLPTR));
        beginAddressLabel->setText(QApplication::translate("Widget", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        slaveAddressLabel->setText(QApplication::translate("Widget", "\344\273\216\346\234\272\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        funcLabel->setText(QApplication::translate("Widget", "\345\212\237\350\203\275\347\240\201\357\274\232", Q_NULLPTR));
        numLabel->setText(QApplication::translate("Widget", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        sendButton->setText(QApplication::translate("Widget", "\345\217\221\n"
"\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
