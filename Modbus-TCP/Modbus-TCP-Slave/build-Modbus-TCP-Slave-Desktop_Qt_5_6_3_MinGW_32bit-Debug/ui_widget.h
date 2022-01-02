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
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *horizontalSpacer_21;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *coilSearchNumber;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *coilSearchPushBotton;
    QSpacerItem *horizontalSpacer_22;
    QTableWidget *coilsTable;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *registerSearchNumber;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *registerSearchPushBotton;
    QSpacerItem *horizontalSpacer_23;
    QTableWidget *registersTable;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ipAddressText;
    QLineEdit *ipAddressData;
    QSpacerItem *horizontalSpacer_2;
    QLabel *portNumberText;
    QLineEdit *portNumberData;
    QSpacerItem *horizontalSpacer_3;
    QLabel *LocalAddressLabel;
    QLineEdit *SlaveAddressNumber;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *connectButton;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTextEdit *messageBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_15;
    QLabel *showCurrentTime;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *ShowHistoryMessageButton;
    QPushButton *ClearHistoryButton;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *disconnectButton;
    QPushButton *FlushIPAddressButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1096, 724);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        Widget->setFont(font);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        tabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QFont font2;
        font2.setPointSize(9);
        tab->setFont(font2);
        verticalLayoutWidget_2 = new QWidget(tab);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 651, 251));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_21);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        coilSearchNumber = new QLineEdit(verticalLayoutWidget_2);
        coilSearchNumber->setObjectName(QStringLiteral("coilSearchNumber"));

        horizontalLayout_5->addWidget(coilSearchNumber);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        coilSearchPushBotton = new QPushButton(verticalLayoutWidget_2);
        coilSearchPushBotton->setObjectName(QStringLiteral("coilSearchPushBotton"));

        horizontalLayout_5->addWidget(coilSearchPushBotton);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_22);


        verticalLayout_3->addLayout(horizontalLayout_5);

        coilsTable = new QTableWidget(verticalLayoutWidget_2);
        if (coilsTable->columnCount() < 65536)
            coilsTable->setColumnCount(65536);
        if (coilsTable->rowCount() < 2)
            coilsTable->setRowCount(2);
        coilsTable->setObjectName(QStringLiteral("coilsTable"));
        sizePolicy.setHeightForWidth(coilsTable->sizePolicy().hasHeightForWidth());
        coilsTable->setSizePolicy(sizePolicy);
        coilsTable->setMinimumSize(QSize(0, 0));
        coilsTable->setFont(font1);
        coilsTable->setFrameShape(QFrame::Panel);
        coilsTable->setDragEnabled(true);
        coilsTable->setRowCount(2);
        coilsTable->setColumnCount(65536);

        verticalLayout_3->addWidget(coilsTable);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 651, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_20);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        registerSearchNumber = new QLineEdit(verticalLayoutWidget);
        registerSearchNumber->setObjectName(QStringLiteral("registerSearchNumber"));

        horizontalLayout_4->addWidget(registerSearchNumber);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        registerSearchPushBotton = new QPushButton(verticalLayoutWidget);
        registerSearchPushBotton->setObjectName(QStringLiteral("registerSearchPushBotton"));

        horizontalLayout_4->addWidget(registerSearchPushBotton);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_23);


        verticalLayout->addLayout(horizontalLayout_4);

        registersTable = new QTableWidget(verticalLayoutWidget);
        if (registersTable->columnCount() < 65536)
            registersTable->setColumnCount(65536);
        if (registersTable->rowCount() < 2)
            registersTable->setRowCount(2);
        registersTable->setObjectName(QStringLiteral("registersTable"));
        sizePolicy.setHeightForWidth(registersTable->sizePolicy().hasHeightForWidth());
        registersTable->setSizePolicy(sizePolicy);
        registersTable->setMinimumSize(QSize(600, 0));
        registersTable->setFont(font1);
        registersTable->setFrameShape(QFrame::Box);
        registersTable->setRowCount(2);
        registersTable->setColumnCount(65536);

        verticalLayout->addWidget(registersTable);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);


        gridLayout->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ipAddressText = new QLabel(Widget);
        ipAddressText->setObjectName(QStringLiteral("ipAddressText"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ipAddressText->sizePolicy().hasHeightForWidth());
        ipAddressText->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(ipAddressText);

        ipAddressData = new QLineEdit(Widget);
        ipAddressData->setObjectName(QStringLiteral("ipAddressData"));
        ipAddressData->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(ipAddressData);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        portNumberText = new QLabel(Widget);
        portNumberText->setObjectName(QStringLiteral("portNumberText"));
        sizePolicy1.setHeightForWidth(portNumberText->sizePolicy().hasHeightForWidth());
        portNumberText->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(portNumberText);

        portNumberData = new QLineEdit(Widget);
        portNumberData->setObjectName(QStringLiteral("portNumberData"));
        portNumberData->setMaximumSize(QSize(50, 16777215));
        portNumberData->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(portNumberData);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        LocalAddressLabel = new QLabel(Widget);
        LocalAddressLabel->setObjectName(QStringLiteral("LocalAddressLabel"));

        horizontalLayout_3->addWidget(LocalAddressLabel);

        SlaveAddressNumber = new QLineEdit(Widget);
        SlaveAddressNumber->setObjectName(QStringLiteral("SlaveAddressNumber"));
        SlaveAddressNumber->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(SlaveAddressNumber);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        connectButton = new QPushButton(Widget);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        horizontalLayout_3->addWidget(connectButton);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 4, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(200);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(0, 300));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        messageBox = new QTextEdit(groupBox);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        sizePolicy.setHeightForWidth(messageBox->sizePolicy().hasHeightForWidth());
        messageBox->setSizePolicy(sizePolicy);
        messageBox->setReadOnly(true);

        gridLayout_2->addWidget(messageBox, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);


        gridLayout->addLayout(verticalLayout_2, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_15);

        showCurrentTime = new QLabel(Widget);
        showCurrentTime->setObjectName(QStringLiteral("showCurrentTime"));

        horizontalLayout->addWidget(showCurrentTime);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_16);

        ShowHistoryMessageButton = new QPushButton(Widget);
        ShowHistoryMessageButton->setObjectName(QStringLiteral("ShowHistoryMessageButton"));

        horizontalLayout->addWidget(ShowHistoryMessageButton);

        ClearHistoryButton = new QPushButton(Widget);
        ClearHistoryButton->setObjectName(QStringLiteral("ClearHistoryButton"));

        horizontalLayout->addWidget(ClearHistoryButton);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_17);

        disconnectButton = new QPushButton(Widget);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));

        horizontalLayout->addWidget(disconnectButton);

        FlushIPAddressButton = new QPushButton(Widget);
        FlushIPAddressButton->setObjectName(QStringLiteral("FlushIPAddressButton"));

        horizontalLayout->addWidget(FlushIPAddressButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "TCP-Slave", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\347\272\277\345\234\210\346\225\260\346\215\256", Q_NULLPTR));
        coilSearchPushBotton->setText(QApplication::translate("Widget", "\346\220\234\347\264\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\272\277\345\234\210", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250\346\225\260\346\215\256", Q_NULLPTR));
        registerSearchPushBotton->setText(QApplication::translate("Widget", "\346\220\234\347\264\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
        ipAddressText->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        portNumberText->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        LocalAddressLabel->setText(QApplication::translate("Widget", "\344\273\216\346\234\272\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        connectButton->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));
        showCurrentTime->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        ShowHistoryMessageButton->setText(QApplication::translate("Widget", "\346\266\210\346\201\257\346\237\245\347\234\213", Q_NULLPTR));
        ClearHistoryButton->setText(QApplication::translate("Widget", "\346\266\210\346\201\257\346\270\205\351\231\244 ", Q_NULLPTR));
        disconnectButton->setText(QApplication::translate("Widget", "\346\226\255\345\274\200\350\277\236\346\216\245", Q_NULLPTR));
        FlushIPAddressButton->setText(QApplication::translate("Widget", "\345\210\267\346\226\260IP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
