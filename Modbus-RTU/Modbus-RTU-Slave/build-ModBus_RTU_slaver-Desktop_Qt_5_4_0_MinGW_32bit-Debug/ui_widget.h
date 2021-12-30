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
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *dateTimeEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *historyButton;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QGroupBox *rtuBox;
    QGridLayout *gridLayout;
    QLineEdit *localAddressEdit;
    QComboBox *portNumberBox;
    QLabel *localAddressLabel;
    QLabel *portNumberLabel;
    QLabel *dataBitsLabel;
    QLabel *stopBitsLabel;
    QComboBox *baudBox;
    QComboBox *parityBox;
    QLabel *parityLabel;
    QComboBox *stopBitsBox;
    QComboBox *dataBitsBox;
    QLabel *baudLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *portButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *messageBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *messageEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *coilTableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *coilLabel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *coilLineEdit;
    QPushButton *coilSearchPushButton;
    QWidget *tab_2;
    QTableWidget *registerTableWidget;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *registerLabel;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *regisetLineEdit;
    QPushButton *registerSearchPushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(626, 850);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setBaseSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(10);
        Widget->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/xinje.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        dateTimeEdit = new QLabel(Widget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        horizontalLayout_2->addWidget(dateTimeEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        historyButton = new QPushButton(Widget);
        historyButton->setObjectName(QStringLiteral("historyButton"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        historyButton->setFont(font1);

        horizontalLayout_2->addWidget(historyButton);

        clearButton = new QPushButton(Widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setFont(font1);

        horizontalLayout_2->addWidget(clearButton);

        horizontalLayout_2->setStretch(2, 8);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rtuBox = new QGroupBox(Widget);
        rtuBox->setObjectName(QStringLiteral("rtuBox"));
        rtuBox->setFont(font1);
        gridLayout = new QGridLayout(rtuBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        localAddressEdit = new QLineEdit(rtuBox);
        localAddressEdit->setObjectName(QStringLiteral("localAddressEdit"));
        localAddressEdit->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(localAddressEdit->sizePolicy().hasHeightForWidth());
        localAddressEdit->setSizePolicy(sizePolicy1);
        localAddressEdit->setMinimumSize(QSize(0, 0));
        localAddressEdit->setBaseSize(QSize(0, 0));
        localAddressEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(localAddressEdit, 2, 1, 1, 1);

        portNumberBox = new QComboBox(rtuBox);
        portNumberBox->setObjectName(QStringLiteral("portNumberBox"));
        sizePolicy1.setHeightForWidth(portNumberBox->sizePolicy().hasHeightForWidth());
        portNumberBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(portNumberBox, 1, 1, 1, 1);

        localAddressLabel = new QLabel(rtuBox);
        localAddressLabel->setObjectName(QStringLiteral("localAddressLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(localAddressLabel->sizePolicy().hasHeightForWidth());
        localAddressLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(localAddressLabel, 2, 0, 1, 1);

        portNumberLabel = new QLabel(rtuBox);
        portNumberLabel->setObjectName(QStringLiteral("portNumberLabel"));
        sizePolicy2.setHeightForWidth(portNumberLabel->sizePolicy().hasHeightForWidth());
        portNumberLabel->setSizePolicy(sizePolicy2);
        portNumberLabel->setFont(font1);

        gridLayout->addWidget(portNumberLabel, 1, 0, 1, 1);

        dataBitsLabel = new QLabel(rtuBox);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));
        sizePolicy2.setHeightForWidth(dataBitsLabel->sizePolicy().hasHeightForWidth());
        dataBitsLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(dataBitsLabel, 1, 7, 1, 1);

        stopBitsLabel = new QLabel(rtuBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));
        sizePolicy2.setHeightForWidth(stopBitsLabel->sizePolicy().hasHeightForWidth());
        stopBitsLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(stopBitsLabel, 2, 3, 1, 1);

        baudBox = new QComboBox(rtuBox);
        baudBox->setObjectName(QStringLiteral("baudBox"));
        sizePolicy1.setHeightForWidth(baudBox->sizePolicy().hasHeightForWidth());
        baudBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(baudBox, 1, 5, 1, 1);

        parityBox = new QComboBox(rtuBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));
        sizePolicy1.setHeightForWidth(parityBox->sizePolicy().hasHeightForWidth());
        parityBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(parityBox, 2, 8, 1, 1);

        parityLabel = new QLabel(rtuBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));
        sizePolicy2.setHeightForWidth(parityLabel->sizePolicy().hasHeightForWidth());
        parityLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(parityLabel, 2, 7, 1, 1);

        stopBitsBox = new QComboBox(rtuBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));
        sizePolicy1.setHeightForWidth(stopBitsBox->sizePolicy().hasHeightForWidth());
        stopBitsBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(stopBitsBox, 2, 5, 1, 1);

        dataBitsBox = new QComboBox(rtuBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));
        sizePolicy1.setHeightForWidth(dataBitsBox->sizePolicy().hasHeightForWidth());
        dataBitsBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(dataBitsBox, 1, 8, 1, 1);

        baudLabel = new QLabel(rtuBox);
        baudLabel->setObjectName(QStringLiteral("baudLabel"));
        sizePolicy2.setHeightForWidth(baudLabel->sizePolicy().hasHeightForWidth());
        baudLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(baudLabel, 1, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 6, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 2, 1, 1);


        horizontalLayout->addWidget(rtuBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        portButton = new QPushButton(Widget);
        portButton->setObjectName(QStringLiteral("portButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(portButton->sizePolicy().hasHeightForWidth());
        portButton->setSizePolicy(sizePolicy3);
        portButton->setFont(font1);

        horizontalLayout->addWidget(portButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_6);

        messageBox = new QGroupBox(Widget);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        messageBox->setFont(font1);
        messageBox->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(messageBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        messageEdit = new QTextEdit(messageBox);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(messageEdit->sizePolicy().hasHeightForWidth());
        messageEdit->setSizePolicy(sizePolicy4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(9);
        messageEdit->setFont(font2);
        messageEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        messageEdit->setReadOnly(true);

        verticalLayout->addWidget(messageEdit);


        verticalLayout_2->addWidget(messageBox);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(2, 2);

        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        coilTableWidget = new QTableWidget(tab);
        if (coilTableWidget->columnCount() < 65536)
            coilTableWidget->setColumnCount(65536);
        if (coilTableWidget->rowCount() < 2)
            coilTableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        coilTableWidget->setItem(0, 0, __qtablewidgetitem);
        coilTableWidget->setObjectName(QStringLiteral("coilTableWidget"));
        coilTableWidget->setGeometry(QRect(0, 60, 761, 161));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(coilTableWidget->sizePolicy().hasHeightForWidth());
        coilTableWidget->setSizePolicy(sizePolicy5);
        coilTableWidget->setMinimumSize(QSize(280, 0));
        coilTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        coilTableWidget->setRowCount(2);
        coilTableWidget->setColumnCount(65536);
        coilTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        coilTableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        coilTableWidget->verticalHeader()->setStretchLastSection(false);
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 10, 631, 41));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        coilLabel = new QLabel(widget);
        coilLabel->setObjectName(QStringLiteral("coilLabel"));
        coilLabel->setFont(font1);

        horizontalLayout_4->addWidget(coilLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        coilLineEdit = new QLineEdit(widget);
        coilLineEdit->setObjectName(QStringLiteral("coilLineEdit"));
        coilLineEdit->setEnabled(true);
        sizePolicy1.setHeightForWidth(coilLineEdit->sizePolicy().hasHeightForWidth());
        coilLineEdit->setSizePolicy(sizePolicy1);
        coilLineEdit->setMinimumSize(QSize(80, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        coilLineEdit->setFont(font3);

        horizontalLayout_3->addWidget(coilLineEdit);

        coilSearchPushButton = new QPushButton(widget);
        coilSearchPushButton->setObjectName(QStringLiteral("coilSearchPushButton"));
        coilSearchPushButton->setMinimumSize(QSize(80, 0));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        coilSearchPushButton->setFont(font4);

        horizontalLayout_3->addWidget(coilSearchPushButton);

        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 1);

        horizontalLayout_4->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab, QString());
        coilTableWidget->raise();
        coilTableWidget->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        registerTableWidget = new QTableWidget(tab_2);
        if (registerTableWidget->columnCount() < 65536)
            registerTableWidget->setColumnCount(65536);
        if (registerTableWidget->rowCount() < 2)
            registerTableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        registerTableWidget->setItem(0, 0, __qtablewidgetitem1);
        registerTableWidget->setObjectName(QStringLiteral("registerTableWidget"));
        registerTableWidget->setGeometry(QRect(0, 60, 821, 161));
        sizePolicy5.setHeightForWidth(registerTableWidget->sizePolicy().hasHeightForWidth());
        registerTableWidget->setSizePolicy(sizePolicy5);
        registerTableWidget->setMinimumSize(QSize(280, 0));
        registerTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        registerTableWidget->setRowCount(2);
        registerTableWidget->setColumnCount(65536);
        registerTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        registerTableWidget->verticalHeader()->setStretchLastSection(false);
        widget1 = new QWidget(tab_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(70, 10, 611, 41));
        horizontalLayout_6 = new QHBoxLayout(widget1);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        registerLabel = new QLabel(widget1);
        registerLabel->setObjectName(QStringLiteral("registerLabel"));
        registerLabel->setFont(font1);

        horizontalLayout_6->addWidget(registerLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        regisetLineEdit = new QLineEdit(widget1);
        regisetLineEdit->setObjectName(QStringLiteral("regisetLineEdit"));
        sizePolicy1.setHeightForWidth(regisetLineEdit->sizePolicy().hasHeightForWidth());
        regisetLineEdit->setSizePolicy(sizePolicy1);
        regisetLineEdit->setMinimumSize(QSize(80, 0));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        regisetLineEdit->setFont(font5);

        horizontalLayout_5->addWidget(regisetLineEdit);

        registerSearchPushButton = new QPushButton(widget1);
        registerSearchPushButton->setObjectName(QStringLiteral("registerSearchPushButton"));
        registerSearchPushButton->setMinimumSize(QSize(80, 0));
        registerSearchPushButton->setFont(font4);

        horizontalLayout_5->addWidget(registerSearchPushButton);

        horizontalLayout_5->setStretch(1, 2);
        horizontalLayout_5->setStretch(2, 1);

        horizontalLayout_6->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Modbus_RTU", Q_NULLPTR));
        dateTimeEdit->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        historyButton->setText(QApplication::translate("Widget", "\345\216\206\345\217\262\346\266\210\346\201\257", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\347\252\227\345\217\243", Q_NULLPTR));
        rtuBox->setTitle(QApplication::translate("Widget", "RTU", Q_NULLPTR));
        localAddressLabel->setText(QApplication::translate("Widget", "\345\234\260\345\235\200", Q_NULLPTR));
        portNumberLabel->setText(QApplication::translate("Widget", "\344\270\262\345\217\243", Q_NULLPTR));
        dataBitsLabel->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        stopBitsLabel->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        parityLabel->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        baudLabel->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        portButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        messageBox->setTitle(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));

        const bool __sortingEnabled = coilTableWidget->isSortingEnabled();
        coilTableWidget->setSortingEnabled(false);
        coilTableWidget->setSortingEnabled(__sortingEnabled);

        coilLabel->setText(QApplication::translate("Widget", "\347\272\277\345\234\210\346\225\260\346\215\256", Q_NULLPTR));
        coilSearchPushButton->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\272\277\345\234\210", Q_NULLPTR));

        const bool __sortingEnabled1 = registerTableWidget->isSortingEnabled();
        registerTableWidget->setSortingEnabled(false);
        registerTableWidget->setSortingEnabled(__sortingEnabled1);

        registerLabel->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250\346\225\260\346\215\256", Q_NULLPTR));
        registerSearchPushButton->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
