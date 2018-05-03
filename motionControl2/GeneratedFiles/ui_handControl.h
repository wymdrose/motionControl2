/********************************************************************************
** Form generated from reading UI file 'handControl.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDCONTROL_H
#define UI_HANDCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_handControl
{
public:
    QComboBox *comboBoxAxisNo;
    QPushButton *pushButtonStop;
    QLabel *label_2;
    QPushButton *pushButtonInit;
    QComboBox *comboBoxCardType;
    QLabel *label;
    QPushButton *pushButtonHome;
    QComboBox *comboBoxCardNo;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QDialog *handControl)
    {
        if (handControl->objectName().isEmpty())
            handControl->setObjectName(QStringLiteral("handControl"));
        handControl->resize(803, 690);
        comboBoxAxisNo = new QComboBox(handControl);
        comboBoxAxisNo->setObjectName(QStringLiteral("comboBoxAxisNo"));
        comboBoxAxisNo->setGeometry(QRect(160, 160, 87, 22));
        pushButtonStop = new QPushButton(handControl);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(610, 60, 93, 28));
        label_2 = new QLabel(handControl);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 110, 72, 15));
        pushButtonInit = new QPushButton(handControl);
        pushButtonInit->setObjectName(QStringLiteral("pushButtonInit"));
        pushButtonInit->setGeometry(QRect(400, 60, 93, 28));
        comboBoxCardType = new QComboBox(handControl);
        comboBoxCardType->setObjectName(QStringLiteral("comboBoxCardType"));
        comboBoxCardType->setGeometry(QRect(160, 60, 141, 22));
        label = new QLabel(handControl);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 60, 72, 15));
        pushButtonHome = new QPushButton(handControl);
        pushButtonHome->setObjectName(QStringLiteral("pushButtonHome"));
        pushButtonHome->setGeometry(QRect(610, 240, 93, 28));
        comboBoxCardNo = new QComboBox(handControl);
        comboBoxCardNo->setObjectName(QStringLiteral("comboBoxCardNo"));
        comboBoxCardNo->setGeometry(QRect(160, 110, 87, 22));
        label_3 = new QLabel(handControl);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 160, 72, 15));
        label_4 = new QLabel(handControl);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 250, 72, 15));
        label_5 = new QLabel(handControl);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 290, 72, 15));
        label_6 = new QLabel(handControl);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 330, 72, 15));
        label_7 = new QLabel(handControl);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 370, 72, 15));
        label_8 = new QLabel(handControl);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 410, 72, 15));

        retranslateUi(handControl);

        QMetaObject::connectSlotsByName(handControl);
    } // setupUi

    void retranslateUi(QDialog *handControl)
    {
        handControl->setWindowTitle(QApplication::translate("handControl", "handControl", Q_NULLPTR));
        pushButtonStop->setText(QApplication::translate("handControl", "\345\201\234\346\255\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("handControl", "cardNo.", Q_NULLPTR));
        pushButtonInit->setText(QApplication::translate("handControl", "\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        label->setText(QApplication::translate("handControl", "cardTpye", Q_NULLPTR));
        pushButtonHome->setText(QApplication::translate("handControl", "\345\233\236\351\233\266", Q_NULLPTR));
        label_3->setText(QApplication::translate("handControl", "axisNo.", Q_NULLPTR));
        label_4->setText(QApplication::translate("handControl", "\350\265\267\345\247\213\351\200\237\345\272\246\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("handControl", "\346\234\200\345\244\247\351\200\237\345\272\246\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("handControl", "\345\212\240\351\200\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("handControl", "\345\207\217\351\200\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("handControl", "S\346\256\265\346\227\266\351\227\264s\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class handControl: public Ui_handControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDCONTROL_H
