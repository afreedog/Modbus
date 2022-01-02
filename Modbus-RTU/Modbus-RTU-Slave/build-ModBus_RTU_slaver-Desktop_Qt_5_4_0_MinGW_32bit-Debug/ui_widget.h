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
    QSpacerItem *horizontalSpacer_4;
    QLabel *dateTimeEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *historyButton;
    QPushButton *clearButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *messageEdit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QGroupBox *rtuBox;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_10;
    QLabel *localAddressLabel;
    QLineEdit *localAddressEdit;
    QComboBox *portNumberBox;
    QLabel *portNumberLabel;
    QLabel *dataBitsLabel;
    QLabel *stopBitsLabel;
    QComboBox *parityBox;
    QLabel *parityLabel;
    QLabel *baudLabel;
    QComboBox *dataBitsBox;
    QComboBox *stopBitsBox;
    QComboBox *baudBox;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *portButton;
    QSpacerItem *horizontalSpacer_8;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *coilLabel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *coilLineEdit;
    QPushButton *coilSearchPushButton;
    QTableWidget *coilTableWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *registerLabel;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *regisetLineEdit;
    QPushButton *registerSearchPushButton;
    QTableWidget *registerTableWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(626, 748);
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
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
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

        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(0, 300));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        messageEdit = new QTextEdit(groupBox);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));
        sizePolicy1.setHeightForWidth(messageEdit->sizePolicy().hasHeightForWidth());
        messageEdit->setSizePolicy(sizePolicy1);
        messageEdit->setMinimumSize(QSize(0, 300));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(9);
        messageEdit->setFont(font2);
        messageEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        messageEdit->setReadOnly(true);

        verticalLayout->addWidget(messageEdit);


        verticalLayout_2->addWidget(groupBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rtuBox = new QGroupBox(Widget);
        rtuBox->setObjectName(QStringLiteral("rtuBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rtuBox->sizePolicy().hasHeightForWidth());
        rtuBox->setSizePolicy(sizePolicy2);
        rtuBox->setFont(font1);
        gridLayout = new QGridLayout(rtuBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 2, 0, 1, 1);

        localAddressLabel = new QLabel(rtuBox);
        localAddressLabel->setObjectName(QStringLiteral("localAddressLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(localAddressLabel->sizePolicy().hasHeightForWidth());
        localAddressLabel->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(localAddressLabel, 3, 0, 1, 1);

        localAddressEdit = new QLineEdit(rtuBox);
        localAddressEdit->setObjectName(QStringLiteral("localAddressEdit"));
        localAddressEdit->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(localAddressEdit->sizePolicy().hasHeightForWidth());
        localAddressEdit->setSizePolicy(sizePolicy4);
        localAddressEdit->setMinimumSize(QSize(0, 0));
        localAddressEdit->setBaseSize(QSize(0, 0));
        localAddressEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(localAddressEdit, 3, 1, 1, 1);

        portNumberBox = new QComboBox(rtuBox);
        portNumberBox->setObjectName(QStringLiteral("portNumberBox"));
        sizePolicy4.setHeightForWidth(portNumberBox->sizePolicy().hasHeightForWidth());
        portNumberBox->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(portNumberBox, 1, 1, 1, 1);

        portNumberLabel = new QLabel(rtuBox);
        portNumberLabel->setObjectName(QStringLiteral("portNumberLabel"));
        sizePolicy3.setHeightForWidth(portNumberLabel->sizePolicy().hasHeightForWidth());
        portNumberLabel->setSizePolicy(sizePolicy3);
        portNumberLabel->setFont(font1);

        gridLayout->addWidget(portNumberLabel, 1, 0, 1, 1);

        dataBitsLabel = new QLabel(rtuBox);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));
        sizePolicy3.setHeightForWidth(dataBitsLabel->sizePolicy().hasHeightForWidth());
        dataBitsLabel->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(dataBitsLabel, 1, 5, 1, 1);

        stopBitsLabel = new QLabel(rtuBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));
        sizePolicy3.setHeightForWidth(stopBitsLabel->sizePolicy().hasHeightForWidth());
        stopBitsLabel->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(stopBitsLabel, 3, 2, 1, 1);

        parityBox = new QComboBox(rtuBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));
        sizePolicy4.setHeightForWidth(parityBox->sizePolicy().hasHeightForWidth());
        parityBox->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(parityBox, 3, 6, 1, 1);

        parityLabel = new QLabel(rtuBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));
        sizePolicy3.setHeightForWidth(parityLabel->sizePolicy().hasHeightForWidth());
        parityLabel->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(parityLabel, 3, 5, 1, 1);

        baudLabel = new QLabel(rtuBox);
        baudLabel->setObjectName(QStringLiteral("baudLabel"));
        sizePolicy3.setHeightForWidth(baudLabel->sizePolicy().hasHeightForWidth());
        baudLabel->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(baudLabel, 1, 2, 1, 1);

        dataBitsBox = new QComboBox(rtuBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));
        sizePolicy4.setHeightForWidth(dataBitsBox->sizePolicy().hasHeightForWidth());
        dataBitsBox->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(dataBitsBox, 1, 6, 1, 1);

        stopBitsBox = new QComboBox(rtuBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));
        sizePolicy4.setHeightForWidth(stopBitsBox->sizePolicy().hasHeightForWidth());
        stopBitsBox->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(stopBitsBox, 3, 4, 1, 1);

        baudBox = new QComboBox(rtuBox);
        baudBox->setObjectName(QStringLiteral("baudBox"));
        sizePolicy4.setHeightForWidth(baudBox->sizePolicy().hasHeightForWidth());
        baudBox->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(baudBox, 1, 4, 1, 1);


        horizontalLayout->addWidget(rtuBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        portButton = new QPushButton(Widget);
        portButton->setObjectName(QStringLiteral("portButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(portButton->sizePolicy().hasHeightForWidth());
        portButton->setSizePolicy(sizePolicy5);
        portButton->setFont(font1);

        horizontalLayout->addWidget(portButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy6);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        sizePolicy3.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy3);
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        coilLabel = new QLabel(tab);
        coilLabel->setObjectName(QStringLiteral("coilLabel"));
        sizePolicy2.setHeightForWidth(coilLabel->sizePolicy().hasHeightForWidth());
        coilLabel->setSizePolicy(sizePolicy2);
        coilLabel->setFont(font1);

        horizontalLayout_4->addWidget(coilLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        coilLineEdit = new QLineEdit(tab);
        coilLineEdit->setObjectName(QStringLiteral("coilLineEdit"));
        coilLineEdit->setEnabled(true);
        sizePolicy4.setHeightForWidth(coilLineEdit->sizePolicy().hasHeightForWidth());
        coilLineEdit->setSizePolicy(sizePolicy4);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        coilLineEdit->setFont(font3);
        coilLineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(coilLineEdit);

        coilSearchPushButton = new QPushButton(tab);
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


        verticalLayout_4->addLayout(horizontalLayout_4);

        coilTableWidget = new QTableWidget(tab);
        if (coilTableWidget->columnCount() < 65536)
            coilTableWidget->setColumnCount(65536);
        if (coilTableWidget->rowCount() < 2)
            coilTableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        coilTableWidget->setItem(0, 0, __qtablewidgetitem);
        coilTableWidget->setObjectName(QStringLiteral("coilTableWidget"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(coilTableWidget->sizePolicy().hasHeightForWidth());
        coilTableWidget->setSizePolicy(sizePolicy7);
        coilTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        coilTableWidget->setRowCount(2);
        coilTableWidget->setColumnCount(65536);
        coilTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        coilTableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        coilTableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout_4->addWidget(coilTableWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        registerLabel = new QLabel(tab_2);
        registerLabel->setObjectName(QStringLiteral("registerLabel"));
        sizePolicy2.setHeightForWidth(registerLabel->sizePolicy().hasHeightForWidth());
        registerLabel->setSizePolicy(sizePolicy2);
        registerLabel->setFont(font1);

        horizontalLayout_6->addWidget(registerLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        regisetLineEdit = new QLineEdit(tab_2);
        regisetLineEdit->setObjectName(QStringLiteral("regisetLineEdit"));
        sizePolicy4.setHeightForWidth(regisetLineEdit->sizePolicy().hasHeightForWidth());
        regisetLineEdit->setSizePolicy(sizePolicy4);
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        regisetLineEdit->setFont(font5);
        regisetLineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(regisetLineEdit);

        registerSearchPushButton = new QPushButton(tab_2);
        registerSearchPushButton->setObjectName(QStringLiteral("registerSearchPushButton"));
        registerSearchPushButton->setMinimumSize(QSize(80, 0));
        registerSearchPushButton->setFont(font4);

        horizontalLayout_5->addWidget(registerSearchPushButton);

        horizontalLayout_5->setStretch(1, 2);
        horizontalLayout_5->setStretch(2, 1);

        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_6);

        registerTableWidget = new QTableWidget(tab_2);
        if (registerTableWidget->columnCount() < 65536)
            registerTableWidget->setColumnCount(65536);
        if (registerTableWidget->rowCount() < 2)
            registerTableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        registerTableWidget->setItem(0, 0, __qtablewidgetitem1);
        registerTableWidget->setObjectName(QStringLiteral("registerTableWidget"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(registerTableWidget->sizePolicy().hasHeightForWidth());
        registerTableWidget->setSizePolicy(sizePolicy8);
        registerTableWidget->setMinimumSize(QSize(280, 0));
        registerTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        registerTableWidget->setRowCount(2);
        registerTableWidget->setColumnCount(65536);
        registerTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        registerTableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(registerTableWidget);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Modbus_RTU", Q_NULLPTR));
        dateTimeEdit->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        historyButton->setText(QApplication::translate("Widget", "\345\216\206\345\217\262\346\266\210\346\201\257", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\347\252\227\345\217\243", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "\346\266\210\346\201\257", Q_NULLPTR));
        rtuBox->setTitle(QApplication::translate("Widget", "RTU", Q_NULLPTR));
        localAddressLabel->setText(QApplication::translate("Widget", "\345\234\260\345\235\200", Q_NULLPTR));
        portNumberLabel->setText(QApplication::translate("Widget", "\344\270\262\345\217\243", Q_NULLPTR));
        dataBitsLabel->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        stopBitsLabel->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        parityLabel->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        baudLabel->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        portButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        coilLabel->setText(QApplication::translate("Widget", "\347\272\277\345\234\210\346\225\260\346\215\256", Q_NULLPTR));
        coilSearchPushButton->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));

        const bool __sortingEnabled = coilTableWidget->isSortingEnabled();
        coilTableWidget->setSortingEnabled(false);
        coilTableWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\272\277\345\234\210", Q_NULLPTR));
        registerLabel->setText(QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250\346\225\260\346\215\256", Q_NULLPTR));
        registerSearchPushButton->setText(QApplication::translate("Widget", "Search", Q_NULLPTR));

        const bool __sortingEnabled1 = registerTableWidget->isSortingEnabled();
        registerTableWidget->setSortingEnabled(false);
        registerTableWidget->setSortingEnabled(__sortingEnabled1);

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\345\257\204\345\255\230\345\231\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
