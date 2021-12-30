/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_inputDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *inputDialogLineEdit;
    QLabel *inputDialogLabel;

    void setupUi(QDialog *inputDialog)
    {
        if (inputDialog->objectName().isEmpty())
            inputDialog->setObjectName(QStringLiteral("inputDialog"));
        inputDialog->resize(485, 181);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputDialog->sizePolicy().hasHeightForWidth());
        inputDialog->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(inputDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        inputDialogLineEdit = new QLineEdit(inputDialog);
        inputDialogLineEdit->setObjectName(QStringLiteral("inputDialogLineEdit"));
        inputDialogLineEdit->setGeometry(QRect(50, 50, 391, 61));
        QFont font;
        font.setFamily(QStringLiteral("Bookman Old Style"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        inputDialogLineEdit->setFont(font);
        inputDialogLineEdit->setMaxLength(65536);
        inputDialogLabel = new QLabel(inputDialog);
        inputDialogLabel->setObjectName(QStringLiteral("inputDialogLabel"));
        inputDialogLabel->setGeometry(QRect(30, 10, 221, 21));

        retranslateUi(inputDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), inputDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), inputDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(inputDialog);
    } // setupUi

    void retranslateUi(QDialog *inputDialog)
    {
        inputDialog->setWindowTitle(QApplication::translate("inputDialog", "\350\276\223\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        inputDialogLabel->setText(QApplication::translate("inputDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class inputDialog: public Ui_inputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
