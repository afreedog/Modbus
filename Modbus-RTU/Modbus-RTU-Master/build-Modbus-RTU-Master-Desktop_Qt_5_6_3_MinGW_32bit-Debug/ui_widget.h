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
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *SerialSwitchSetting;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ShowCurrentTime;
    QSpacerItem *horizontalSpacer_6;
    QLabel *SerialPortLabel;
    QComboBox *SerialPortName;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *SerialSwitchSettingButton;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *RefreshSerialPortButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *HistoryMessageButton;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *ClearHistoryMessageButton;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *SerialSetting;
    QHBoxLayout *horizontalLayout;
    QLabel *BaudRateNumberLabel;
    QComboBox *BaudRateNumber;
    QSpacerItem *horizontalSpacer_2;
    QLabel *DataBitsNumberLabel;
    QComboBox *DataBitsNumber;
    QSpacerItem *horizontalSpacer_3;
    QLabel *ParityNameLabel;
    QComboBox *ParityName;
    QSpacerItem *horizontalSpacer_4;
    QLabel *StopBitsNameLabel;
    QComboBox *StopBitsName;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *ShowCurrentMessage;
    QVBoxLayout *verticalLayout;
    QTextEdit *messageBox;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *MessageSetting;
    QGridLayout *gridLayout;
    QLabel *SlaveAddressLabel;
    QLabel *DataNumberLabel;
    QComboBox *FunctionCodeNumber;
    QLabel *FunctionCodeLabel;
    QLabel *BeginAddressLabel;
    QLineEdit *DataNumber;
    QLineEdit *BeginAddressNumber;
    QSpacerItem *horizontalSpacer;
    QLineEdit *SlaveAddressNumber;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *SendMessageButton;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(784, 1127);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        Widget->setFont(font);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
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
        ShowCurrentTime = new QLabel(SerialSwitchSetting);
        ShowCurrentTime->setObjectName(QStringLiteral("ShowCurrentTime"));
        sizePolicy.setHeightForWidth(ShowCurrentTime->sizePolicy().hasHeightForWidth());
        ShowCurrentTime->setSizePolicy(sizePolicy);
        ShowCurrentTime->setMinimumSize(QSize(200, 0));
        ShowCurrentTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(ShowCurrentTime);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        SerialPortLabel = new QLabel(SerialSwitchSetting);
        SerialPortLabel->setObjectName(QStringLiteral("SerialPortLabel"));
        sizePolicy.setHeightForWidth(SerialPortLabel->sizePolicy().hasHeightForWidth());
        SerialPortLabel->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(SerialPortLabel);

        SerialPortName = new QComboBox(SerialSwitchSetting);
        SerialPortName->setObjectName(QStringLiteral("SerialPortName"));
        SerialPortName->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(SerialPortName);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        SerialSwitchSettingButton = new QPushButton(SerialSwitchSetting);
        SerialSwitchSettingButton->setObjectName(QStringLiteral("SerialSwitchSettingButton"));

        horizontalLayout_2->addWidget(SerialSwitchSettingButton);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_15);

        RefreshSerialPortButton = new QPushButton(SerialSwitchSetting);
        RefreshSerialPortButton->setObjectName(QStringLiteral("RefreshSerialPortButton"));

        horizontalLayout_2->addWidget(RefreshSerialPortButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        HistoryMessageButton = new QPushButton(SerialSwitchSetting);
        HistoryMessageButton->setObjectName(QStringLiteral("HistoryMessageButton"));

        horizontalLayout_2->addWidget(HistoryMessageButton);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_16);

        ClearHistoryMessageButton = new QPushButton(SerialSwitchSetting);
        ClearHistoryMessageButton->setObjectName(QStringLiteral("ClearHistoryMessageButton"));

        horizontalLayout_2->addWidget(ClearHistoryMessageButton);


        horizontalLayout_5->addWidget(SerialSwitchSetting);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_12);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        SerialSetting = new QGroupBox(Widget);
        SerialSetting->setObjectName(QStringLiteral("SerialSetting"));
        sizePolicy.setHeightForWidth(SerialSetting->sizePolicy().hasHeightForWidth());
        SerialSetting->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(SerialSetting);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BaudRateNumberLabel = new QLabel(SerialSetting);
        BaudRateNumberLabel->setObjectName(QStringLiteral("BaudRateNumberLabel"));

        horizontalLayout->addWidget(BaudRateNumberLabel);

        BaudRateNumber = new QComboBox(SerialSetting);
        BaudRateNumber->setObjectName(QStringLiteral("BaudRateNumber"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(BaudRateNumber->sizePolicy().hasHeightForWidth());
        BaudRateNumber->setSizePolicy(sizePolicy2);
        BaudRateNumber->setMinimumSize(QSize(10, 0));

        horizontalLayout->addWidget(BaudRateNumber);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        DataBitsNumberLabel = new QLabel(SerialSetting);
        DataBitsNumberLabel->setObjectName(QStringLiteral("DataBitsNumberLabel"));

        horizontalLayout->addWidget(DataBitsNumberLabel);

        DataBitsNumber = new QComboBox(SerialSetting);
        DataBitsNumber->setObjectName(QStringLiteral("DataBitsNumber"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(DataBitsNumber->sizePolicy().hasHeightForWidth());
        DataBitsNumber->setSizePolicy(sizePolicy3);
        DataBitsNumber->setMinimumSize(QSize(0, 0));
        DataBitsNumber->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(DataBitsNumber);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        ParityNameLabel = new QLabel(SerialSetting);
        ParityNameLabel->setObjectName(QStringLiteral("ParityNameLabel"));

        horizontalLayout->addWidget(ParityNameLabel);

        ParityName = new QComboBox(SerialSetting);
        ParityName->setObjectName(QStringLiteral("ParityName"));
        ParityName->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(ParityName);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        StopBitsNameLabel = new QLabel(SerialSetting);
        StopBitsNameLabel->setObjectName(QStringLiteral("StopBitsNameLabel"));

        horizontalLayout->addWidget(StopBitsNameLabel);

        StopBitsName = new QComboBox(SerialSetting);
        StopBitsName->setObjectName(QStringLiteral("StopBitsName"));
        StopBitsName->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(StopBitsName);


        horizontalLayout_4->addWidget(SerialSetting);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_13);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        ShowCurrentMessage = new QGroupBox(Widget);
        ShowCurrentMessage->setObjectName(QStringLiteral("ShowCurrentMessage"));
        verticalLayout = new QVBoxLayout(ShowCurrentMessage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        messageBox = new QTextEdit(ShowCurrentMessage);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(messageBox->sizePolicy().hasHeightForWidth());
        messageBox->setSizePolicy(sizePolicy4);
        messageBox->setMinimumSize(QSize(0, 450));

        verticalLayout->addWidget(messageBox);


        verticalLayout_2->addWidget(ShowCurrentMessage);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_14);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        MessageSetting = new QGroupBox(Widget);
        MessageSetting->setObjectName(QStringLiteral("MessageSetting"));
        sizePolicy4.setHeightForWidth(MessageSetting->sizePolicy().hasHeightForWidth());
        MessageSetting->setSizePolicy(sizePolicy4);
        gridLayout = new QGridLayout(MessageSetting);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        SlaveAddressLabel = new QLabel(MessageSetting);
        SlaveAddressLabel->setObjectName(QStringLiteral("SlaveAddressLabel"));
        sizePolicy1.setHeightForWidth(SlaveAddressLabel->sizePolicy().hasHeightForWidth());
        SlaveAddressLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(SlaveAddressLabel, 0, 0, 1, 1);

        DataNumberLabel = new QLabel(MessageSetting);
        DataNumberLabel->setObjectName(QStringLiteral("DataNumberLabel"));
        sizePolicy1.setHeightForWidth(DataNumberLabel->sizePolicy().hasHeightForWidth());
        DataNumberLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(DataNumberLabel, 2, 3, 1, 1);

        FunctionCodeNumber = new QComboBox(MessageSetting);
        FunctionCodeNumber->setObjectName(QStringLiteral("FunctionCodeNumber"));
        sizePolicy4.setHeightForWidth(FunctionCodeNumber->sizePolicy().hasHeightForWidth());
        FunctionCodeNumber->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(FunctionCodeNumber, 0, 4, 1, 1);

        FunctionCodeLabel = new QLabel(MessageSetting);
        FunctionCodeLabel->setObjectName(QStringLiteral("FunctionCodeLabel"));
        sizePolicy1.setHeightForWidth(FunctionCodeLabel->sizePolicy().hasHeightForWidth());
        FunctionCodeLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(FunctionCodeLabel, 0, 3, 1, 1);

        BeginAddressLabel = new QLabel(MessageSetting);
        BeginAddressLabel->setObjectName(QStringLiteral("BeginAddressLabel"));
        sizePolicy1.setHeightForWidth(BeginAddressLabel->sizePolicy().hasHeightForWidth());
        BeginAddressLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(BeginAddressLabel, 2, 0, 1, 1);

        DataNumber = new QLineEdit(MessageSetting);
        DataNumber->setObjectName(QStringLiteral("DataNumber"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(DataNumber->sizePolicy().hasHeightForWidth());
        DataNumber->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(DataNumber, 2, 4, 1, 1);

        BeginAddressNumber = new QLineEdit(MessageSetting);
        BeginAddressNumber->setObjectName(QStringLiteral("BeginAddressNumber"));
        sizePolicy5.setHeightForWidth(BeginAddressNumber->sizePolicy().hasHeightForWidth());
        BeginAddressNumber->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(BeginAddressNumber, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        SlaveAddressNumber = new QLineEdit(MessageSetting);
        SlaveAddressNumber->setObjectName(QStringLiteral("SlaveAddressNumber"));
        sizePolicy5.setHeightForWidth(SlaveAddressNumber->sizePolicy().hasHeightForWidth());
        SlaveAddressNumber->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(SlaveAddressNumber, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 2, 1, 1);


        horizontalLayout_3->addWidget(MessageSetting);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        SendMessageButton = new QPushButton(Widget);
        SendMessageButton->setObjectName(QStringLiteral("SendMessageButton"));
        sizePolicy1.setHeightForWidth(SendMessageButton->sizePolicy().hasHeightForWidth());
        SendMessageButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(SendMessageButton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        SerialSwitchSetting->setTitle(QString());
        ShowCurrentTime->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\346\227\266\351\227\264\344\277\241\346\201\257", Q_NULLPTR));
        SerialPortLabel->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        SerialSwitchSettingButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        RefreshSerialPortButton->setText(QApplication::translate("Widget", "\345\210\267\346\226\260\344\270\262\345\217\243", Q_NULLPTR));
        HistoryMessageButton->setText(QApplication::translate("Widget", "\345\216\206\345\217\262\344\277\241\346\201\257", Q_NULLPTR));
        ClearHistoryMessageButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\347\252\227\345\217\243", Q_NULLPTR));
        SerialSetting->setTitle(QString());
        BaudRateNumberLabel->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        BaudRateNumber->clear();
        BaudRateNumber->insertItems(0, QStringList()
         << QApplication::translate("Widget", "9600", Q_NULLPTR)
         << QApplication::translate("Widget", "19200", Q_NULLPTR)
         << QApplication::translate("Widget", "115200", Q_NULLPTR)
        );
        DataBitsNumberLabel->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        DataBitsNumber->clear();
        DataBitsNumber->insertItems(0, QStringList()
         << QApplication::translate("Widget", "8", Q_NULLPTR)
         << QApplication::translate("Widget", "7", Q_NULLPTR)
         << QApplication::translate("Widget", "6", Q_NULLPTR)
         << QApplication::translate("Widget", "5", Q_NULLPTR)
        );
        ParityNameLabel->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        ParityName->clear();
        ParityName->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\346\227\240\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("Widget", "\345\245\207\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("Widget", "\345\201\266\346\240\241\351\252\214", Q_NULLPTR)
        );
        StopBitsNameLabel->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        StopBitsName->clear();
        StopBitsName->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", Q_NULLPTR)
         << QApplication::translate("Widget", "2", Q_NULLPTR)
        );
        ShowCurrentMessage->setTitle(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));
        MessageSetting->setTitle(QApplication::translate("Widget", "\346\212\245\346\226\207", Q_NULLPTR));
        SlaveAddressLabel->setText(QApplication::translate("Widget", "\344\273\216\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
        DataNumberLabel->setText(QApplication::translate("Widget", "\346\225\260\351\207\217", Q_NULLPTR));
        FunctionCodeNumber->clear();
        FunctionCodeNumber->insertItems(0, QStringList()
         << QApplication::translate("Widget", "0x01", Q_NULLPTR)
         << QApplication::translate("Widget", "0x03", Q_NULLPTR)
         << QApplication::translate("Widget", "0x0f", Q_NULLPTR)
         << QApplication::translate("Widget", "0x10", Q_NULLPTR)
        );
        FunctionCodeLabel->setText(QApplication::translate("Widget", "\345\212\237\350\203\275\347\240\201", Q_NULLPTR));
        BeginAddressLabel->setText(QApplication::translate("Widget", "\350\265\267\345\247\213\345\234\260\345\235\200", Q_NULLPTR));
        SendMessageButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
