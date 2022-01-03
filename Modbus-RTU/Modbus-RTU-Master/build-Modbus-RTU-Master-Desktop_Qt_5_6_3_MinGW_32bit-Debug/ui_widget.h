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
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *ShowCurrentTime;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *HistoryMessageButton;
    QPushButton *ClearHistoryMessageButton;
    QGroupBox *ShowCurrentMessage;
    QVBoxLayout *verticalLayout;
    QTextEdit *messageBox;
    QHBoxLayout *horizontalLayout;
    QGroupBox *SerialSetting;
    QGridLayout *gridLayout_2;
    QLabel *SerialPortLabel;
    QLabel *BaudRateNumberLabel;
    QComboBox *BaudRateNumber;
    QLabel *ParityNameLabel;
    QComboBox *ParityName;
    QLabel *DataBitsNumberLabel;
    QComboBox *SerialPortName;
    QPushButton *RefreshSerialPortButton;
    QComboBox *StopBitsName;
    QComboBox *DataBitsNumber;
    QLabel *StopBitsNameLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *SerialSwitchSettingButton;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *MessageSetting;
    QGridLayout *gridLayout;
    QLabel *DataNumberLabel;
    QLabel *SlaveAddressLabel;
    QLineEdit *DataNumber;
    QLabel *BeginAddressLabel;
    QLineEdit *BeginAddressNumber;
    QLabel *FunctionCodeLabel;
    QComboBox *FunctionCodeNumber;
    QLineEdit *SlaveAddressNumber;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *SendMessageButton;
    QSpacerItem *horizontalSpacer_9;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QLabel *CoilSearchNameLabel;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *CoilSearchNumber;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *CoilSearchButton;
    QSpacerItem *horizontalSpacer_18;
    QTableWidget *CoilsDataTable;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_19;
    QLabel *RegisterSearchNameLabel;
    QSpacerItem *horizontalSpacer_20;
    QLineEdit *RegisterSearchNumber;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *RegisterSearchButton;
    QSpacerItem *horizontalSpacer_22;
    QTableWidget *RegistersDataTable;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(627, 736);
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
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        ShowCurrentTime = new QLabel(Widget);
        ShowCurrentTime->setObjectName(QStringLiteral("ShowCurrentTime"));
        sizePolicy.setHeightForWidth(ShowCurrentTime->sizePolicy().hasHeightForWidth());
        ShowCurrentTime->setSizePolicy(sizePolicy);
        ShowCurrentTime->setMinimumSize(QSize(200, 0));
        ShowCurrentTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(ShowCurrentTime);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        HistoryMessageButton = new QPushButton(Widget);
        HistoryMessageButton->setObjectName(QStringLiteral("HistoryMessageButton"));

        horizontalLayout_2->addWidget(HistoryMessageButton);

        ClearHistoryMessageButton = new QPushButton(Widget);
        ClearHistoryMessageButton->setObjectName(QStringLiteral("ClearHistoryMessageButton"));

        horizontalLayout_2->addWidget(ClearHistoryMessageButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        ShowCurrentMessage = new QGroupBox(Widget);
        ShowCurrentMessage->setObjectName(QStringLiteral("ShowCurrentMessage"));
        verticalLayout = new QVBoxLayout(ShowCurrentMessage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        messageBox = new QTextEdit(ShowCurrentMessage);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(messageBox->sizePolicy().hasHeightForWidth());
        messageBox->setSizePolicy(sizePolicy1);
        messageBox->setMinimumSize(QSize(0, 200));

        verticalLayout->addWidget(messageBox);


        verticalLayout_2->addWidget(ShowCurrentMessage);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        SerialSetting = new QGroupBox(Widget);
        SerialSetting->setObjectName(QStringLiteral("SerialSetting"));
        sizePolicy.setHeightForWidth(SerialSetting->sizePolicy().hasHeightForWidth());
        SerialSetting->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(SerialSetting);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        SerialPortLabel = new QLabel(SerialSetting);
        SerialPortLabel->setObjectName(QStringLiteral("SerialPortLabel"));
        sizePolicy.setHeightForWidth(SerialPortLabel->sizePolicy().hasHeightForWidth());
        SerialPortLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(SerialPortLabel, 0, 0, 1, 1);

        BaudRateNumberLabel = new QLabel(SerialSetting);
        BaudRateNumberLabel->setObjectName(QStringLiteral("BaudRateNumberLabel"));

        gridLayout_2->addWidget(BaudRateNumberLabel, 0, 2, 1, 1);

        BaudRateNumber = new QComboBox(SerialSetting);
        BaudRateNumber->setObjectName(QStringLiteral("BaudRateNumber"));
        sizePolicy.setHeightForWidth(BaudRateNumber->sizePolicy().hasHeightForWidth());
        BaudRateNumber->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(BaudRateNumber, 0, 3, 1, 1);

        ParityNameLabel = new QLabel(SerialSetting);
        ParityNameLabel->setObjectName(QStringLiteral("ParityNameLabel"));

        gridLayout_2->addWidget(ParityNameLabel, 1, 0, 1, 1);

        ParityName = new QComboBox(SerialSetting);
        ParityName->setObjectName(QStringLiteral("ParityName"));

        gridLayout_2->addWidget(ParityName, 1, 1, 1, 1);

        DataBitsNumberLabel = new QLabel(SerialSetting);
        DataBitsNumberLabel->setObjectName(QStringLiteral("DataBitsNumberLabel"));

        gridLayout_2->addWidget(DataBitsNumberLabel, 1, 2, 1, 1);

        SerialPortName = new QComboBox(SerialSetting);
        SerialPortName->setObjectName(QStringLiteral("SerialPortName"));

        gridLayout_2->addWidget(SerialPortName, 0, 1, 1, 1);

        RefreshSerialPortButton = new QPushButton(SerialSetting);
        RefreshSerialPortButton->setObjectName(QStringLiteral("RefreshSerialPortButton"));

        gridLayout_2->addWidget(RefreshSerialPortButton, 0, 5, 1, 1);

        StopBitsName = new QComboBox(SerialSetting);
        StopBitsName->setObjectName(QStringLiteral("StopBitsName"));

        gridLayout_2->addWidget(StopBitsName, 1, 5, 1, 1);

        DataBitsNumber = new QComboBox(SerialSetting);
        DataBitsNumber->setObjectName(QStringLiteral("DataBitsNumber"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DataBitsNumber->sizePolicy().hasHeightForWidth());
        DataBitsNumber->setSizePolicy(sizePolicy2);
        DataBitsNumber->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(DataBitsNumber, 1, 3, 1, 1);

        StopBitsNameLabel = new QLabel(SerialSetting);
        StopBitsNameLabel->setObjectName(QStringLiteral("StopBitsNameLabel"));

        gridLayout_2->addWidget(StopBitsNameLabel, 1, 4, 1, 1);


        horizontalLayout->addWidget(SerialSetting);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        SerialSwitchSettingButton = new QPushButton(Widget);
        SerialSwitchSettingButton->setObjectName(QStringLiteral("SerialSwitchSettingButton"));
        sizePolicy1.setHeightForWidth(SerialSwitchSettingButton->sizePolicy().hasHeightForWidth());
        SerialSwitchSettingButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(SerialSwitchSettingButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        MessageSetting = new QGroupBox(Widget);
        MessageSetting->setObjectName(QStringLiteral("MessageSetting"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(MessageSetting->sizePolicy().hasHeightForWidth());
        MessageSetting->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(MessageSetting);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        DataNumberLabel = new QLabel(MessageSetting);
        DataNumberLabel->setObjectName(QStringLiteral("DataNumberLabel"));
        sizePolicy1.setHeightForWidth(DataNumberLabel->sizePolicy().hasHeightForWidth());
        DataNumberLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(DataNumberLabel, 1, 2, 1, 1);

        SlaveAddressLabel = new QLabel(MessageSetting);
        SlaveAddressLabel->setObjectName(QStringLiteral("SlaveAddressLabel"));
        sizePolicy1.setHeightForWidth(SlaveAddressLabel->sizePolicy().hasHeightForWidth());
        SlaveAddressLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(SlaveAddressLabel, 0, 0, 1, 1);

        DataNumber = new QLineEdit(MessageSetting);
        DataNumber->setObjectName(QStringLiteral("DataNumber"));
        sizePolicy3.setHeightForWidth(DataNumber->sizePolicy().hasHeightForWidth());
        DataNumber->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(DataNumber, 1, 3, 1, 1);

        BeginAddressLabel = new QLabel(MessageSetting);
        BeginAddressLabel->setObjectName(QStringLiteral("BeginAddressLabel"));
        sizePolicy1.setHeightForWidth(BeginAddressLabel->sizePolicy().hasHeightForWidth());
        BeginAddressLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(BeginAddressLabel, 1, 0, 1, 1);

        BeginAddressNumber = new QLineEdit(MessageSetting);
        BeginAddressNumber->setObjectName(QStringLiteral("BeginAddressNumber"));
        sizePolicy3.setHeightForWidth(BeginAddressNumber->sizePolicy().hasHeightForWidth());
        BeginAddressNumber->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(BeginAddressNumber, 1, 1, 1, 1);

        FunctionCodeLabel = new QLabel(MessageSetting);
        FunctionCodeLabel->setObjectName(QStringLiteral("FunctionCodeLabel"));
        sizePolicy1.setHeightForWidth(FunctionCodeLabel->sizePolicy().hasHeightForWidth());
        FunctionCodeLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(FunctionCodeLabel, 0, 2, 1, 1);

        FunctionCodeNumber = new QComboBox(MessageSetting);
        FunctionCodeNumber->setObjectName(QStringLiteral("FunctionCodeNumber"));
        sizePolicy3.setHeightForWidth(FunctionCodeNumber->sizePolicy().hasHeightForWidth());
        FunctionCodeNumber->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(FunctionCodeNumber, 0, 3, 1, 1);

        SlaveAddressNumber = new QLineEdit(MessageSetting);
        SlaveAddressNumber->setObjectName(QStringLiteral("SlaveAddressNumber"));
        sizePolicy3.setHeightForWidth(SlaveAddressNumber->sizePolicy().hasHeightForWidth());
        SlaveAddressNumber->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(SlaveAddressNumber, 0, 1, 1, 1);


        horizontalLayout_3->addWidget(MessageSetting);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        SendMessageButton = new QPushButton(Widget);
        SendMessageButton->setObjectName(QStringLiteral("SendMessageButton"));
        sizePolicy1.setHeightForWidth(SendMessageButton->sizePolicy().hasHeightForWidth());
        SendMessageButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(SendMessageButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        CoilSearchNameLabel = new QLabel(tab);
        CoilSearchNameLabel->setObjectName(QStringLiteral("CoilSearchNameLabel"));

        horizontalLayout_6->addWidget(CoilSearchNameLabel);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        CoilSearchNumber = new QLineEdit(tab);
        CoilSearchNumber->setObjectName(QStringLiteral("CoilSearchNumber"));

        horizontalLayout_6->addWidget(CoilSearchNumber);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_17);

        CoilSearchButton = new QPushButton(tab);
        CoilSearchButton->setObjectName(QStringLiteral("CoilSearchButton"));

        horizontalLayout_6->addWidget(CoilSearchButton);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_18);


        verticalLayout_4->addLayout(horizontalLayout_6);

        CoilsDataTable = new QTableWidget(tab);
        if (CoilsDataTable->columnCount() < 65536)
            CoilsDataTable->setColumnCount(65536);
        if (CoilsDataTable->rowCount() < 2)
            CoilsDataTable->setRowCount(2);
        CoilsDataTable->setObjectName(QStringLiteral("CoilsDataTable"));
        sizePolicy3.setHeightForWidth(CoilsDataTable->sizePolicy().hasHeightForWidth());
        CoilsDataTable->setSizePolicy(sizePolicy3);
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
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_19);

        RegisterSearchNameLabel = new QLabel(tab_2);
        RegisterSearchNameLabel->setObjectName(QStringLiteral("RegisterSearchNameLabel"));
        sizePolicy.setHeightForWidth(RegisterSearchNameLabel->sizePolicy().hasHeightForWidth());
        RegisterSearchNameLabel->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(RegisterSearchNameLabel);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_20);

        RegisterSearchNumber = new QLineEdit(tab_2);
        RegisterSearchNumber->setObjectName(QStringLiteral("RegisterSearchNumber"));

        horizontalLayout_7->addWidget(RegisterSearchNumber);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_21);

        RegisterSearchButton = new QPushButton(tab_2);
        RegisterSearchButton->setObjectName(QStringLiteral("RegisterSearchButton"));
        sizePolicy.setHeightForWidth(RegisterSearchButton->sizePolicy().hasHeightForWidth());
        RegisterSearchButton->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(RegisterSearchButton);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_22);


        verticalLayout_5->addLayout(horizontalLayout_7);

        RegistersDataTable = new QTableWidget(tab_2);
        if (RegistersDataTable->columnCount() < 65536)
            RegistersDataTable->setColumnCount(65536);
        if (RegistersDataTable->rowCount() < 2)
            RegistersDataTable->setRowCount(2);
        RegistersDataTable->setObjectName(QStringLiteral("RegistersDataTable"));
        sizePolicy3.setHeightForWidth(RegistersDataTable->sizePolicy().hasHeightForWidth());
        RegistersDataTable->setSizePolicy(sizePolicy3);
        RegistersDataTable->setRowCount(2);
        RegistersDataTable->setColumnCount(65536);

        verticalLayout_5->addWidget(RegistersDataTable);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        ShowCurrentTime->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\346\227\266\351\227\264\344\277\241\346\201\257", Q_NULLPTR));
        HistoryMessageButton->setText(QApplication::translate("Widget", "\345\216\206\345\217\262\344\277\241\346\201\257", Q_NULLPTR));
        ClearHistoryMessageButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\347\252\227\345\217\243", Q_NULLPTR));
        ShowCurrentMessage->setTitle(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));
        SerialSetting->setTitle(QApplication::translate("Widget", "\344\270\262\345\217\243", Q_NULLPTR));
        SerialPortLabel->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        BaudRateNumberLabel->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        BaudRateNumber->clear();
        BaudRateNumber->insertItems(0, QStringList()
         << QApplication::translate("Widget", "9600", Q_NULLPTR)
         << QApplication::translate("Widget", "19200", Q_NULLPTR)
         << QApplication::translate("Widget", "115200", Q_NULLPTR)
        );
        ParityNameLabel->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        ParityName->clear();
        ParityName->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\346\227\240\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("Widget", "\345\245\207\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("Widget", "\345\201\266\346\240\241\351\252\214", Q_NULLPTR)
        );
        DataBitsNumberLabel->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        RefreshSerialPortButton->setText(QApplication::translate("Widget", "\345\210\267\346\226\260\344\270\262\345\217\243", Q_NULLPTR));
        StopBitsName->clear();
        StopBitsName->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", Q_NULLPTR)
         << QApplication::translate("Widget", "2", Q_NULLPTR)
        );
        DataBitsNumber->clear();
        DataBitsNumber->insertItems(0, QStringList()
         << QApplication::translate("Widget", "8", Q_NULLPTR)
         << QApplication::translate("Widget", "7", Q_NULLPTR)
         << QApplication::translate("Widget", "6", Q_NULLPTR)
         << QApplication::translate("Widget", "5", Q_NULLPTR)
        );
        StopBitsNameLabel->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        SerialSwitchSettingButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        MessageSetting->setTitle(QApplication::translate("Widget", "\346\212\245\346\226\207", Q_NULLPTR));
        DataNumberLabel->setText(QApplication::translate("Widget", "\346\225\260\351\207\217", Q_NULLPTR));
        SlaveAddressLabel->setText(QApplication::translate("Widget", "\344\273\216\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
        BeginAddressLabel->setText(QApplication::translate("Widget", "\350\265\267\345\247\213\345\234\260\345\235\200", Q_NULLPTR));
        FunctionCodeLabel->setText(QApplication::translate("Widget", "\345\212\237\350\203\275\347\240\201", Q_NULLPTR));
        FunctionCodeNumber->clear();
        FunctionCodeNumber->insertItems(0, QStringList()
         << QApplication::translate("Widget", "0x01", Q_NULLPTR)
         << QApplication::translate("Widget", "0x03", Q_NULLPTR)
         << QApplication::translate("Widget", "0x0f", Q_NULLPTR)
         << QApplication::translate("Widget", "0x10", Q_NULLPTR)
        );
        SendMessageButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
        CoilSearchNameLabel->setText(QApplication::translate("Widget", "\347\272\277\345\234\210", Q_NULLPTR));
        CoilSearchButton->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\272\277\345\234\210", Q_NULLPTR));
        RegisterSearchNameLabel->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
        RegisterSearchButton->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
