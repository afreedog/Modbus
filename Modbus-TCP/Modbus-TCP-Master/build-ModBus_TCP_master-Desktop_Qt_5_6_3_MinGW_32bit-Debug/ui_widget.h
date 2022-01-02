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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *dateTimeEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *historyButton;
    QPushButton *ResetFilePahtButton;
    QSpacerItem *verticalSpacer;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_13;
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
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *tcpBox;
    QVBoxLayout *verticalLayout;
    QPushButton *connectButton;
    QGroupBox *requestBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *beginAddressLabel;
    QComboBox *funcCodeBox;
    QLabel *funcLabel;
    QComboBox *slaveAddressBox;
    QLabel *slaveAddressLabel;
    QLabel *numLabel;
    QLineEdit *beginAddressLineEdit;
    QLineEdit *numLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_7;
    QPushButton *sendButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *CoilSearchNumber;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *CoilsSearchButton;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *CoilsDataTable;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *RegisterSearchNumber;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *RegisterSearchButton;
    QSpacerItem *horizontalSpacer_11;
    QTableWidget *RegistersDataTable;
    QSpacerItem *horizontalSpacer_12;

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
        gridLayout_3 = new QGridLayout(Widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
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

        ResetFilePahtButton = new QPushButton(Widget);
        ResetFilePahtButton->setObjectName(QStringLiteral("ResetFilePahtButton"));

        horizontalLayout_3->addWidget(ResetFilePahtButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        clearButton = new QPushButton(Widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        sizePolicy1.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy1);
        clearButton->setFont(font1);

        horizontalLayout_3->addWidget(clearButton);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);

        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(6, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        messageBox = new QGroupBox(Widget);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(messageBox->sizePolicy().hasHeightForWidth());
        messageBox->setSizePolicy(sizePolicy2);
        messageBox->setFont(font1);
        messageBox->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_4 = new QHBoxLayout(messageBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        messageEdit = new QTextEdit(messageBox);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(messageEdit->sizePolicy().hasHeightForWidth());
        messageEdit->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        messageEdit->setFont(font2);
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

        gridLayout->addWidget(portEdit, 1, 2, 1, 1);

        ipEdit = new QLineEdit(addressBox);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));
        ipEdit->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(ipEdit, 0, 2, 1, 1);

        ipAddressLabel = new QLabel(addressBox);
        ipAddressLabel->setObjectName(QStringLiteral("ipAddressLabel"));
        ipAddressLabel->setFont(font1);

        gridLayout->addWidget(ipAddressLabel, 0, 1, 1, 1);

        portAddressLabel = new QLabel(addressBox);
        portAddressLabel->setObjectName(QStringLiteral("portAddressLabel"));
        portAddressLabel->setFont(font1);

        gridLayout->addWidget(portAddressLabel, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 0, 1, 1);


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
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 0, 3, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 0, 6, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 0, 1, 1);

        beginAddressLabel = new QLabel(requestBox);
        beginAddressLabel->setObjectName(QStringLiteral("beginAddressLabel"));

        gridLayout_2->addWidget(beginAddressLabel, 2, 1, 1, 1);

        funcCodeBox = new QComboBox(requestBox);
        funcCodeBox->setObjectName(QStringLiteral("funcCodeBox"));
        funcCodeBox->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(funcCodeBox, 0, 5, 1, 1);

        funcLabel = new QLabel(requestBox);
        funcLabel->setObjectName(QStringLiteral("funcLabel"));

        gridLayout_2->addWidget(funcLabel, 0, 4, 1, 1);

        slaveAddressBox = new QComboBox(requestBox);
        slaveAddressBox->setObjectName(QStringLiteral("slaveAddressBox"));
        slaveAddressBox->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(slaveAddressBox, 0, 2, 1, 1);

        slaveAddressLabel = new QLabel(requestBox);
        slaveAddressLabel->setObjectName(QStringLiteral("slaveAddressLabel"));

        gridLayout_2->addWidget(slaveAddressLabel, 0, 1, 1, 1);

        numLabel = new QLabel(requestBox);
        numLabel->setObjectName(QStringLiteral("numLabel"));

        gridLayout_2->addWidget(numLabel, 2, 4, 1, 1);

        beginAddressLineEdit = new QLineEdit(requestBox);
        beginAddressLineEdit->setObjectName(QStringLiteral("beginAddressLineEdit"));
        beginAddressLineEdit->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(beginAddressLineEdit, 2, 2, 1, 1);

        numLineEdit = new QLineEdit(requestBox);
        numLineEdit->setObjectName(QStringLiteral("numLineEdit"));
        numLineEdit->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(numLineEdit, 2, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        verticalLayout_2->addWidget(requestBox);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_7);

        sendButton = new QPushButton(Widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy4);
        sendButton->setFont(font1);

        horizontalLayout_2->addWidget(sendButton);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 15);
        verticalLayout_3->setStretch(2, 3);

        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy5);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy6);

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        CoilSearchNumber = new QLineEdit(tab);
        CoilSearchNumber->setObjectName(QStringLiteral("CoilSearchNumber"));
        CoilSearchNumber->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(CoilSearchNumber);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        CoilsSearchButton = new QPushButton(tab);
        CoilsSearchButton->setObjectName(QStringLiteral("CoilsSearchButton"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(CoilsSearchButton->sizePolicy().hasHeightForWidth());
        CoilsSearchButton->setSizePolicy(sizePolicy7);

        horizontalLayout_5->addWidget(CoilsSearchButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_5);

        CoilsDataTable = new QTableWidget(tab);
        if (CoilsDataTable->columnCount() < 65536)
            CoilsDataTable->setColumnCount(65536);
        if (CoilsDataTable->rowCount() < 2)
            CoilsDataTable->setRowCount(2);
        CoilsDataTable->setObjectName(QStringLiteral("CoilsDataTable"));
        CoilsDataTable->setRowCount(2);
        CoilsDataTable->setColumnCount(65536);

        verticalLayout_4->addWidget(CoilsDataTable);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy6.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy6);

        horizontalLayout_6->addWidget(label_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        RegisterSearchNumber = new QLineEdit(tab_2);
        RegisterSearchNumber->setObjectName(QStringLiteral("RegisterSearchNumber"));
        RegisterSearchNumber->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(RegisterSearchNumber);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        RegisterSearchButton = new QPushButton(tab_2);
        RegisterSearchButton->setObjectName(QStringLiteral("RegisterSearchButton"));
        sizePolicy7.setHeightForWidth(RegisterSearchButton->sizePolicy().hasHeightForWidth());
        RegisterSearchButton->setSizePolicy(sizePolicy7);

        horizontalLayout_6->addWidget(RegisterSearchButton);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);


        verticalLayout_5->addLayout(horizontalLayout_6);

        RegistersDataTable = new QTableWidget(tab_2);
        if (RegistersDataTable->columnCount() < 65536)
            RegistersDataTable->setColumnCount(65536);
        if (RegistersDataTable->rowCount() < 2)
            RegistersDataTable->setRowCount(2);
        RegistersDataTable->setObjectName(QStringLiteral("RegistersDataTable"));
        RegistersDataTable->setRowCount(2);
        RegistersDataTable->setColumnCount(65536);

        verticalLayout_5->addWidget(RegistersDataTable);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 2, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 1, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Modbus_TCP", Q_NULLPTR));
        dateTimeEdit->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        historyButton->setText(QApplication::translate("Widget", "\345\216\206\345\217\262\346\266\210\346\201\257", Q_NULLPTR));
        ResetFilePahtButton->setText(QApplication::translate("Widget", "\350\267\257\345\276\204\351\207\215\347\275\256", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\347\252\227\345\217\243", Q_NULLPTR));
        messageBox->setTitle(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));
        addressBox->setTitle(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        ipAddressLabel->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        portAddressLabel->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        tcpBox->setTitle(QApplication::translate("Widget", "TCP", Q_NULLPTR));
        connectButton->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", Q_NULLPTR));
        requestBox->setTitle(QApplication::translate("Widget", "\350\257\267\346\261\202", Q_NULLPTR));
        beginAddressLabel->setText(QApplication::translate("Widget", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        funcLabel->setText(QApplication::translate("Widget", "\345\212\237\350\203\275\347\240\201\357\274\232", Q_NULLPTR));
        slaveAddressLabel->setText(QApplication::translate("Widget", "\344\273\216\346\234\272\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        numLabel->setText(QApplication::translate("Widget", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        sendButton->setText(QApplication::translate("Widget", "\345\217\221\n"
"\351\200\201", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\347\272\277\345\234\210", Q_NULLPTR));
        CoilsSearchButton->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\272\277\345\234\210", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
        RegisterSearchButton->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
