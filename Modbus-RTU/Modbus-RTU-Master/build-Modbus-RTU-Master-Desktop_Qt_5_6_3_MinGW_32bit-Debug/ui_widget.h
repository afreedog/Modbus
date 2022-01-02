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
    QVBoxLayout *verticalLayout_2;
    QGroupBox *SerialSwitchSetting;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *ShowCurrentTime;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *HistoryMessageButton;
    QPushButton *ClearHistoryMessageButton;
    QGroupBox *ShowCurrentMessage;
    QVBoxLayout *verticalLayout;
    QTextEdit *messageBox;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_15;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *SerialPortName;
    QComboBox *BaudRateNumber;
    QPushButton *RefreshSerialPortButton;
    QLabel *SerialPortLabel;
    QSpacerItem *horizontalSpacer_9;
    QComboBox *ParityName;
    QSpacerItem *verticalSpacer;
    QLabel *DataBitsNumberLabel;
    QComboBox *DataBitsNumber;
    QLabel *BaudRateNumberLabel;
    QLabel *ParityNameLabel;
    QComboBox *StopBitsName;
    QLabel *StopBitsNameLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *SerialSwitchSettingButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_16;
    QGroupBox *MessageSetting;
    QGridLayout *gridLayout;
    QLineEdit *DataNumber;
    QSpacerItem *verticalSpacer_3;
    QLabel *DataNumberLabel;
    QComboBox *FunctionCodeNumber;
    QLabel *FunctionCodeLabel;
    QLabel *SlaveAddressLabel;
    QLineEdit *SlaveAddressNumber;
    QLineEdit *BeginAddressNumber;
    QLabel *BeginAddressLabel;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *SendMessageButton;
    QSpacerItem *horizontalSpacer_8;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *CoilSearchNumber;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *CoilSearchButton;
    QSpacerItem *horizontalSpacer_18;
    QTableWidget *CoilsDataTable;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_12;
    QLineEdit *RegisterSearchNumber;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *RegisterSearchButton;
    QSpacerItem *horizontalSpacer_14;
    QTableWidget *RegisterDataNumber;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(784, 785);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        Widget->setFont(font);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        SerialSwitchSetting = new QGroupBox(Widget);
        SerialSwitchSetting->setObjectName(QStringLiteral("SerialSwitchSetting"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SerialSwitchSetting->sizePolicy().hasHeightForWidth());
        SerialSwitchSetting->setSizePolicy(sizePolicy1);
        SerialSwitchSetting->setMinimumSize(QSize(0, 50));
        horizontalLayout_2 = new QHBoxLayout(SerialSwitchSetting);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        ShowCurrentTime = new QLabel(SerialSwitchSetting);
        ShowCurrentTime->setObjectName(QStringLiteral("ShowCurrentTime"));
        sizePolicy.setHeightForWidth(ShowCurrentTime->sizePolicy().hasHeightForWidth());
        ShowCurrentTime->setSizePolicy(sizePolicy);
        ShowCurrentTime->setMinimumSize(QSize(200, 0));
        ShowCurrentTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(ShowCurrentTime);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        HistoryMessageButton = new QPushButton(SerialSwitchSetting);
        HistoryMessageButton->setObjectName(QStringLiteral("HistoryMessageButton"));

        horizontalLayout_2->addWidget(HistoryMessageButton);

        ClearHistoryMessageButton = new QPushButton(SerialSwitchSetting);
        ClearHistoryMessageButton->setObjectName(QStringLiteral("ClearHistoryMessageButton"));

        horizontalLayout_2->addWidget(ClearHistoryMessageButton);


        verticalLayout_2->addWidget(SerialSwitchSetting);

        ShowCurrentMessage = new QGroupBox(Widget);
        ShowCurrentMessage->setObjectName(QStringLiteral("ShowCurrentMessage"));
        verticalLayout = new QVBoxLayout(ShowCurrentMessage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        messageBox = new QTextEdit(ShowCurrentMessage);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(messageBox->sizePolicy().hasHeightForWidth());
        messageBox->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(messageBox);


        verticalLayout_2->addWidget(ShowCurrentMessage);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_15);

        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        SerialPortName = new QComboBox(groupBox);
        SerialPortName->setObjectName(QStringLiteral("SerialPortName"));

        gridLayout_2->addWidget(SerialPortName, 0, 1, 1, 1);

        BaudRateNumber = new QComboBox(groupBox);
        BaudRateNumber->setObjectName(QStringLiteral("BaudRateNumber"));
        sizePolicy.setHeightForWidth(BaudRateNumber->sizePolicy().hasHeightForWidth());
        BaudRateNumber->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(BaudRateNumber, 0, 7, 1, 1);

        RefreshSerialPortButton = new QPushButton(groupBox);
        RefreshSerialPortButton->setObjectName(QStringLiteral("RefreshSerialPortButton"));
        sizePolicy1.setHeightForWidth(RefreshSerialPortButton->sizePolicy().hasHeightForWidth());
        RefreshSerialPortButton->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(RefreshSerialPortButton, 0, 5, 1, 1);

        SerialPortLabel = new QLabel(groupBox);
        SerialPortLabel->setObjectName(QStringLiteral("SerialPortLabel"));
        sizePolicy.setHeightForWidth(SerialPortLabel->sizePolicy().hasHeightForWidth());
        SerialPortLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(SerialPortLabel, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        ParityName = new QComboBox(groupBox);
        ParityName->setObjectName(QStringLiteral("ParityName"));
        ParityName->setMaximumSize(QSize(90, 16777215));

        gridLayout_2->addWidget(ParityName, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 2, 1, 1);

        DataBitsNumberLabel = new QLabel(groupBox);
        DataBitsNumberLabel->setObjectName(QStringLiteral("DataBitsNumberLabel"));
        sizePolicy.setHeightForWidth(DataBitsNumberLabel->sizePolicy().hasHeightForWidth());
        DataBitsNumberLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(DataBitsNumberLabel, 2, 3, 1, 1);

        DataBitsNumber = new QComboBox(groupBox);
        DataBitsNumber->setObjectName(QStringLiteral("DataBitsNumber"));
        sizePolicy.setHeightForWidth(DataBitsNumber->sizePolicy().hasHeightForWidth());
        DataBitsNumber->setSizePolicy(sizePolicy);
        DataBitsNumber->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(DataBitsNumber, 2, 5, 1, 1);

        BaudRateNumberLabel = new QLabel(groupBox);
        BaudRateNumberLabel->setObjectName(QStringLiteral("BaudRateNumberLabel"));
        sizePolicy.setHeightForWidth(BaudRateNumberLabel->sizePolicy().hasHeightForWidth());
        BaudRateNumberLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(BaudRateNumberLabel, 0, 6, 1, 1);

        ParityNameLabel = new QLabel(groupBox);
        ParityNameLabel->setObjectName(QStringLiteral("ParityNameLabel"));
        sizePolicy.setHeightForWidth(ParityNameLabel->sizePolicy().hasHeightForWidth());
        ParityNameLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(ParityNameLabel, 2, 0, 1, 1);

        StopBitsName = new QComboBox(groupBox);
        StopBitsName->setObjectName(QStringLiteral("StopBitsName"));

        gridLayout_2->addWidget(StopBitsName, 2, 7, 1, 1);

        StopBitsNameLabel = new QLabel(groupBox);
        StopBitsNameLabel->setObjectName(QStringLiteral("StopBitsNameLabel"));
        sizePolicy.setHeightForWidth(StopBitsNameLabel->sizePolicy().hasHeightForWidth());
        StopBitsNameLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(StopBitsNameLabel, 2, 6, 1, 1);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        SerialSwitchSettingButton = new QPushButton(groupBox_2);
        SerialSwitchSettingButton->setObjectName(QStringLiteral("SerialSwitchSettingButton"));
        sizePolicy1.setHeightForWidth(SerialSwitchSettingButton->sizePolicy().hasHeightForWidth());
        SerialSwitchSettingButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(SerialSwitchSettingButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_16);

        MessageSetting = new QGroupBox(groupBox_3);
        MessageSetting->setObjectName(QStringLiteral("MessageSetting"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(MessageSetting->sizePolicy().hasHeightForWidth());
        MessageSetting->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(MessageSetting);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        DataNumber = new QLineEdit(MessageSetting);
        DataNumber->setObjectName(QStringLiteral("DataNumber"));
        sizePolicy.setHeightForWidth(DataNumber->sizePolicy().hasHeightForWidth());
        DataNumber->setSizePolicy(sizePolicy);
        DataNumber->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(DataNumber, 2, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 2, 1, 1);

        DataNumberLabel = new QLabel(MessageSetting);
        DataNumberLabel->setObjectName(QStringLiteral("DataNumberLabel"));
        sizePolicy.setHeightForWidth(DataNumberLabel->sizePolicy().hasHeightForWidth());
        DataNumberLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(DataNumberLabel, 2, 3, 1, 1);

        FunctionCodeNumber = new QComboBox(MessageSetting);
        FunctionCodeNumber->setObjectName(QStringLiteral("FunctionCodeNumber"));
        sizePolicy.setHeightForWidth(FunctionCodeNumber->sizePolicy().hasHeightForWidth());
        FunctionCodeNumber->setSizePolicy(sizePolicy);

        gridLayout->addWidget(FunctionCodeNumber, 0, 4, 1, 1);

        FunctionCodeLabel = new QLabel(MessageSetting);
        FunctionCodeLabel->setObjectName(QStringLiteral("FunctionCodeLabel"));
        sizePolicy.setHeightForWidth(FunctionCodeLabel->sizePolicy().hasHeightForWidth());
        FunctionCodeLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(FunctionCodeLabel, 0, 3, 1, 1);

        SlaveAddressLabel = new QLabel(MessageSetting);
        SlaveAddressLabel->setObjectName(QStringLiteral("SlaveAddressLabel"));
        sizePolicy.setHeightForWidth(SlaveAddressLabel->sizePolicy().hasHeightForWidth());
        SlaveAddressLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(SlaveAddressLabel, 0, 0, 1, 1);

        SlaveAddressNumber = new QLineEdit(MessageSetting);
        SlaveAddressNumber->setObjectName(QStringLiteral("SlaveAddressNumber"));
        sizePolicy.setHeightForWidth(SlaveAddressNumber->sizePolicy().hasHeightForWidth());
        SlaveAddressNumber->setSizePolicy(sizePolicy);
        SlaveAddressNumber->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(SlaveAddressNumber, 0, 1, 1, 1);

        BeginAddressNumber = new QLineEdit(MessageSetting);
        BeginAddressNumber->setObjectName(QStringLiteral("BeginAddressNumber"));
        sizePolicy.setHeightForWidth(BeginAddressNumber->sizePolicy().hasHeightForWidth());
        BeginAddressNumber->setSizePolicy(sizePolicy);
        BeginAddressNumber->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(BeginAddressNumber, 2, 1, 1, 1);

        BeginAddressLabel = new QLabel(MessageSetting);
        BeginAddressLabel->setObjectName(QStringLiteral("BeginAddressLabel"));
        sizePolicy.setHeightForWidth(BeginAddressLabel->sizePolicy().hasHeightForWidth());
        BeginAddressLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(BeginAddressLabel, 2, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 1, 0, 1, 1);


        horizontalLayout_7->addWidget(MessageSetting);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        SendMessageButton = new QPushButton(groupBox_3);
        SendMessageButton->setObjectName(QStringLiteral("SendMessageButton"));
        sizePolicy1.setHeightForWidth(SendMessageButton->sizePolicy().hasHeightForWidth());
        SendMessageButton->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(SendMessageButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        horizontalLayout_4->addWidget(groupBox_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_17);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        CoilSearchNumber = new QLineEdit(tab);
        CoilSearchNumber->setObjectName(QStringLiteral("CoilSearchNumber"));

        horizontalLayout_5->addWidget(CoilSearchNumber);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        CoilSearchButton = new QPushButton(tab);
        CoilSearchButton->setObjectName(QStringLiteral("CoilSearchButton"));

        horizontalLayout_5->addWidget(CoilSearchButton);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_18);


        verticalLayout_3->addLayout(horizontalLayout_5);

        CoilsDataTable = new QTableWidget(tab);
        if (CoilsDataTable->columnCount() < 65536)
            CoilsDataTable->setColumnCount(65536);
        if (CoilsDataTable->rowCount() < 2)
            CoilsDataTable->setRowCount(2);
        CoilsDataTable->setObjectName(QStringLiteral("CoilsDataTable"));
        sizePolicy.setHeightForWidth(CoilsDataTable->sizePolicy().hasHeightForWidth());
        CoilsDataTable->setSizePolicy(sizePolicy);
        CoilsDataTable->setRowCount(2);
        CoilsDataTable->setColumnCount(65536);

        verticalLayout_3->addWidget(CoilsDataTable);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        RegisterSearchNumber = new QLineEdit(tab_2);
        RegisterSearchNumber->setObjectName(QStringLiteral("RegisterSearchNumber"));

        horizontalLayout_6->addWidget(RegisterSearchNumber);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);

        RegisterSearchButton = new QPushButton(tab_2);
        RegisterSearchButton->setObjectName(QStringLiteral("RegisterSearchButton"));

        horizontalLayout_6->addWidget(RegisterSearchButton);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);


        verticalLayout_4->addLayout(horizontalLayout_6);

        RegisterDataNumber = new QTableWidget(tab_2);
        if (RegisterDataNumber->columnCount() < 65536)
            RegisterDataNumber->setColumnCount(65536);
        if (RegisterDataNumber->rowCount() < 2)
            RegisterDataNumber->setRowCount(2);
        RegisterDataNumber->setObjectName(QStringLiteral("RegisterDataNumber"));
        sizePolicy2.setHeightForWidth(RegisterDataNumber->sizePolicy().hasHeightForWidth());
        RegisterDataNumber->setSizePolicy(sizePolicy2);
        RegisterDataNumber->setRowCount(2);
        RegisterDataNumber->setColumnCount(65536);

        verticalLayout_4->addWidget(RegisterDataNumber);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        SerialSwitchSetting->setTitle(QString());
        ShowCurrentTime->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\346\227\266\351\227\264\344\277\241\346\201\257", Q_NULLPTR));
        HistoryMessageButton->setText(QApplication::translate("Widget", "\345\216\206\345\217\262\344\277\241\346\201\257", Q_NULLPTR));
        ClearHistoryMessageButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\347\252\227\345\217\243", Q_NULLPTR));
        ShowCurrentMessage->setTitle(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        groupBox->setTitle(QApplication::translate("Widget", "\344\270\262\345\217\243", Q_NULLPTR));
        BaudRateNumber->clear();
        BaudRateNumber->insertItems(0, QStringList()
         << QApplication::translate("Widget", "9600", Q_NULLPTR)
         << QApplication::translate("Widget", "19200", Q_NULLPTR)
         << QApplication::translate("Widget", "115200", Q_NULLPTR)
        );
        RefreshSerialPortButton->setText(QApplication::translate("Widget", "\345\210\267\346\226\260", Q_NULLPTR));
        SerialPortLabel->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        ParityName->clear();
        ParityName->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\346\227\240\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("Widget", "\345\245\207\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("Widget", "\345\201\266\346\240\241\351\252\214", Q_NULLPTR)
        );
        DataBitsNumberLabel->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        DataBitsNumber->clear();
        DataBitsNumber->insertItems(0, QStringList()
         << QApplication::translate("Widget", "8", Q_NULLPTR)
         << QApplication::translate("Widget", "7", Q_NULLPTR)
         << QApplication::translate("Widget", "6", Q_NULLPTR)
         << QApplication::translate("Widget", "5", Q_NULLPTR)
        );
        BaudRateNumberLabel->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        ParityNameLabel->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        StopBitsName->clear();
        StopBitsName->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", Q_NULLPTR)
         << QApplication::translate("Widget", "2", Q_NULLPTR)
        );
        StopBitsNameLabel->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        SerialSwitchSettingButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        MessageSetting->setTitle(QApplication::translate("Widget", "\346\212\245\346\226\207", Q_NULLPTR));
        DataNumberLabel->setText(QApplication::translate("Widget", "\346\225\260\351\207\217", Q_NULLPTR));
        FunctionCodeNumber->clear();
        FunctionCodeNumber->insertItems(0, QStringList()
         << QApplication::translate("Widget", "0x01", Q_NULLPTR)
         << QApplication::translate("Widget", "0x03", Q_NULLPTR)
         << QApplication::translate("Widget", "0x0f", Q_NULLPTR)
         << QApplication::translate("Widget", "0x10", Q_NULLPTR)
        );
        FunctionCodeLabel->setText(QApplication::translate("Widget", "\345\212\237\350\203\275\347\240\201", Q_NULLPTR));
        SlaveAddressLabel->setText(QApplication::translate("Widget", "\344\273\216\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
        BeginAddressLabel->setText(QApplication::translate("Widget", "\350\265\267\345\247\213\345\234\260\345\235\200", Q_NULLPTR));
        SendMessageButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\347\272\277\345\234\210", Q_NULLPTR));
        CoilSearchButton->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));
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
