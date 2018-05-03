/********************************************************************************
** Form generated from reading UI file 'aspAction.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASPACTION_H
#define UI_ASPACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aspAction
{
public:
    QPushButton *pushButtonInitial;

    void setupUi(QDialog *aspAction)
    {
        if (aspAction->objectName().isEmpty())
            aspAction->setObjectName(QStringLiteral("aspAction"));
        aspAction->resize(400, 300);
        pushButtonInitial = new QPushButton(aspAction);
        pushButtonInitial->setObjectName(QStringLiteral("pushButtonInitial"));
        pushButtonInitial->setGeometry(QRect(90, 100, 93, 28));

        retranslateUi(aspAction);

        QMetaObject::connectSlotsByName(aspAction);
    } // setupUi

    void retranslateUi(QDialog *aspAction)
    {
        aspAction->setWindowTitle(QApplication::translate("aspAction", "aspAction", Q_NULLPTR));
        pushButtonInitial->setText(QApplication::translate("aspAction", "Initial", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aspAction: public Ui_aspAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASPACTION_H
