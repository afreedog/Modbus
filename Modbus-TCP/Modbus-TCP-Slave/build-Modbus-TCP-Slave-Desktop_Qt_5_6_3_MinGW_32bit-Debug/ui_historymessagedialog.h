/********************************************************************************
** Form generated from reading UI file 'historymessagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYMESSAGEDIALOG_H
#define UI_HISTORYMESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_HistoryMessageDialog
{
public:
    QGridLayout *gridLayout;
    QTextEdit *HistoryMessageBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *HistoryMessageDialog)
    {
        if (HistoryMessageDialog->objectName().isEmpty())
            HistoryMessageDialog->setObjectName(QStringLiteral("HistoryMessageDialog"));
        HistoryMessageDialog->resize(400, 300);
        gridLayout = new QGridLayout(HistoryMessageDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        HistoryMessageBox = new QTextEdit(HistoryMessageDialog);
        HistoryMessageBox->setObjectName(QStringLiteral("HistoryMessageBox"));

        gridLayout->addWidget(HistoryMessageBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(HistoryMessageDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(HistoryMessageDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HistoryMessageDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HistoryMessageDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HistoryMessageDialog);
    } // setupUi

    void retranslateUi(QDialog *HistoryMessageDialog)
    {
        HistoryMessageDialog->setWindowTitle(QApplication::translate("HistoryMessageDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HistoryMessageDialog: public Ui_HistoryMessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYMESSAGEDIALOG_H
