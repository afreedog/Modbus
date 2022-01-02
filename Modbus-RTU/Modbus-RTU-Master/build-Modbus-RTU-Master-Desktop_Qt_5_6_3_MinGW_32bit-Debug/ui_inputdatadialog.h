/********************************************************************************
** Form generated from reading UI file 'inputdatadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDATADIALOG_H
#define UI_INPUTDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_InputDataDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *inputDialogLabel;
    QLineEdit *inputDialogLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InputDataDialog)
    {
        if (InputDataDialog->objectName().isEmpty())
            InputDataDialog->setObjectName(QStringLiteral("InputDataDialog"));
        InputDataDialog->resize(497, 259);
        gridLayout = new QGridLayout(InputDataDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        inputDialogLabel = new QLabel(InputDataDialog);
        inputDialogLabel->setObjectName(QStringLiteral("inputDialogLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputDialogLabel->sizePolicy().hasHeightForWidth());
        inputDialogLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(inputDialogLabel, 0, 0, 1, 1);

        inputDialogLineEdit = new QLineEdit(InputDataDialog);
        inputDialogLineEdit->setObjectName(QStringLiteral("inputDialogLineEdit"));
        QFont font;
        font.setFamily(QStringLiteral("Bookman Old Style"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        inputDialogLineEdit->setFont(font);
        inputDialogLineEdit->setMaxLength(65536);

        gridLayout->addWidget(inputDialogLineEdit, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(InputDataDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(InputDataDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InputDataDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InputDataDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InputDataDialog);
    } // setupUi

    void retranslateUi(QDialog *InputDataDialog)
    {
        InputDataDialog->setWindowTitle(QApplication::translate("InputDataDialog", "Dialog", Q_NULLPTR));
        inputDialogLabel->setText(QApplication::translate("InputDataDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputDataDialog: public Ui_InputDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDATADIALOG_H
