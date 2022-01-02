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
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_15;
    QLabel *showCurrentTime;
    QSpacerItem *horizontalSpacer_16;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTextEdit *messageBox;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *ipAddressText;
    QLineEdit *ipAddressData;
    QLineEdit *portNumberData;
    QLabel *portNumberText;
    QLabel *LocalAddressLabel;
    QLineEdit *SlaveAddressNumber;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *FlushIPAddressButton;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *ClearHistoryButton;
    QPushButton *ShowHistoryMessageButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *registerSearchNumber;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *registerSearchPushBotton;
    QSpacerItem *horizontalSpacer_23;
    QTableWidget *registersTable;

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
        verticalLayout_6 = new QVBoxLayout(Widget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_15);

        showCurrentTime = new QLabel(Widget);
        showCurrentTime->setObjectName(QStringLiteral("showCurrentTime"));
        QFont font1;
        font1.setPointSize(12);
        showCurrentTime->setFont(font1);

        horizontalLayout->addWidget(showCurrentTime);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_16);


        verticalLayout_6->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(200);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
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


        verticalLayout_6->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ipAddressText = new QLabel(groupBox_2);
        ipAddressText->setObjectName(QStringLiteral("ipAddressText"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ipAddressText->sizePolicy().hasHeightForWidth());
        ipAddressText->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(ipAddressText, 0, 0, 1, 1);

        ipAddressData = new QLineEdit(groupBox_2);
        ipAddressData->setObjectName(QStringLiteral("ipAddressData"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ipAddressData->sizePolicy().hasHeightForWidth());
        ipAddressData->setSizePolicy(sizePolicy3);
        ipAddressData->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(ipAddressData, 0, 1, 1, 1);

        portNumberData = new QLineEdit(groupBox_2);
        portNumberData->setObjectName(QStringLiteral("portNumberData"));
        sizePolicy3.setHeightForWidth(portNumberData->sizePolicy().hasHeightForWidth());
        portNumberData->setSizePolicy(sizePolicy3);
        portNumberData->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(portNumberData, 1, 1, 1, 1);

        portNumberText = new QLabel(groupBox_2);
        portNumberText->setObjectName(QStringLiteral("portNumberText"));
        sizePolicy2.setHeightForWidth(portNumberText->sizePolicy().hasHeightForWidth());
        portNumberText->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(portNumberText, 1, 0, 1, 1);

        LocalAddressLabel = new QLabel(groupBox_2);
        LocalAddressLabel->setObjectName(QStringLiteral("LocalAddressLabel"));

        gridLayout->addWidget(LocalAddressLabel, 2, 0, 1, 1);

        SlaveAddressNumber = new QLineEdit(groupBox_2);
        SlaveAddressNumber->setObjectName(QStringLiteral("SlaveAddressNumber"));
        sizePolicy3.setHeightForWidth(SlaveAddressNumber->sizePolicy().hasHeightForWidth());
        SlaveAddressNumber->setSizePolicy(sizePolicy3);
        SlaveAddressNumber->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(SlaveAddressNumber, 2, 1, 1, 1);


        horizontalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        FlushIPAddressButton = new QPushButton(groupBox_3);
        FlushIPAddressButton->setObjectName(QStringLiteral("FlushIPAddressButton"));

        verticalLayout_4->addWidget(FlushIPAddressButton);

        connectButton = new QPushButton(groupBox_3);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        verticalLayout_4->addWidget(connectButton);

        disconnectButton = new QPushButton(groupBox_3);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));

        verticalLayout_4->addWidget(disconnectButton);


        horizontalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        ClearHistoryButton = new QPushButton(groupBox_4);
        ClearHistoryButton->setObjectName(QStringLiteral("ClearHistoryButton"));

        verticalLayout_5->addWidget(ClearHistoryButton);

        ShowHistoryMessageButton = new QPushButton(groupBox_4);
        ShowHistoryMessageButton->setObjectName(QStringLiteral("ShowHistoryMessageButton"));

        verticalLayout_5->addWidget(ShowHistoryMessageButton);


        horizontalLayout_3->addWidget(groupBox_4);


        verticalLayout_6->addLayout(horizontalLayout_3);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        tabWidget->setFont(font2);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QFont font3;
        font3.setPointSize(9);
        tab->setFont(font3);
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        coilSearchNumber = new QLineEdit(tab);
        coilSearchNumber->setObjectName(QStringLiteral("coilSearchNumber"));

        horizontalLayout_5->addWidget(coilSearchNumber);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

        coilSearchPushBotton = new QPushButton(tab);
        coilSearchPushBotton->setObjectName(QStringLiteral("coilSearchPushBotton"));

        horizontalLayout_5->addWidget(coilSearchPushBotton);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_22);


        verticalLayout->addLayout(horizontalLayout_5);

        coilsTable = new QTableWidget(tab);
        if (coilsTable->columnCount() < 65536)
            coilsTable->setColumnCount(65536);
        if (coilsTable->rowCount() < 2)
            coilsTable->setRowCount(2);
        coilsTable->setObjectName(QStringLiteral("coilsTable"));
        sizePolicy.setHeightForWidth(coilsTable->sizePolicy().hasHeightForWidth());
        coilsTable->setSizePolicy(sizePolicy);
        coilsTable->setMinimumSize(QSize(0, 0));
        coilsTable->setFont(font2);
        coilsTable->setFrameShape(QFrame::Panel);
        coilsTable->setDragEnabled(true);
        coilsTable->setRowCount(2);
        coilsTable->setColumnCount(65536);

        verticalLayout->addWidget(coilsTable);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        registerSearchNumber = new QLineEdit(tab_2);
        registerSearchNumber->setObjectName(QStringLiteral("registerSearchNumber"));

        horizontalLayout_4->addWidget(registerSearchNumber);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        registerSearchPushBotton = new QPushButton(tab_2);
        registerSearchPushBotton->setObjectName(QStringLiteral("registerSearchPushBotton"));

        horizontalLayout_4->addWidget(registerSearchPushBotton);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_23);


        verticalLayout_3->addLayout(horizontalLayout_4);

        registersTable = new QTableWidget(tab_2);
        if (registersTable->columnCount() < 65536)
            registersTable->setColumnCount(65536);
        if (registersTable->rowCount() < 2)
            registersTable->setRowCount(2);
        registersTable->setObjectName(QStringLiteral("registersTable"));
        sizePolicy.setHeightForWidth(registersTable->sizePolicy().hasHeightForWidth());
        registersTable->setSizePolicy(sizePolicy);
        registersTable->setMinimumSize(QSize(600, 0));
        registersTable->setFont(font2);
        registersTable->setFrameShape(QFrame::Box);
        registersTable->setRowCount(2);
        registersTable->setColumnCount(65536);

        verticalLayout_3->addWidget(registersTable);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_6->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "TCP-Slave", Q_NULLPTR));
        showCurrentTime->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Widget", "\350\256\276\347\275\256", Q_NULLPTR));
        ipAddressText->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        portNumberText->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        LocalAddressLabel->setText(QApplication::translate("Widget", "\344\273\216\346\234\272\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Widget", "\350\277\236\346\216\245", Q_NULLPTR));
        FlushIPAddressButton->setText(QApplication::translate("Widget", "\345\210\267\346\226\260IP", Q_NULLPTR));
        connectButton->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\347\233\221\345\220\254", Q_NULLPTR));
        disconnectButton->setText(QApplication::translate("Widget", "\346\226\255\345\274\200\350\277\236\346\216\245", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Widget", "\346\227\245\345\277\227", Q_NULLPTR));
        ClearHistoryButton->setText(QApplication::translate("Widget", "\346\266\210\346\201\257\346\270\205\351\231\244 ", Q_NULLPTR));
        ShowHistoryMessageButton->setText(QApplication::translate("Widget", "\346\227\245\345\277\227\346\237\245\347\234\213", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\347\272\277\345\234\210\346\225\260\346\215\256", Q_NULLPTR));
        coilSearchPushBotton->setText(QApplication::translate("Widget", "\346\220\234\347\264\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\272\277\345\234\210", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250\346\225\260\346\215\256", Q_NULLPTR));
        registerSearchPushBotton->setText(QApplication::translate("Widget", "\346\220\234\347\264\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
