/********************************************************************************
** Form generated from reading UI file 'motioncontrol2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTIONCONTROL2_H
#define UI_MOTIONCONTROL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_motionControl2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *motionControl2Class)
    {
        if (motionControl2Class->objectName().isEmpty())
            motionControl2Class->setObjectName(QStringLiteral("motionControl2Class"));
        motionControl2Class->resize(600, 400);
        menuBar = new QMenuBar(motionControl2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        motionControl2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(motionControl2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        motionControl2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(motionControl2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        motionControl2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(motionControl2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        motionControl2Class->setStatusBar(statusBar);

        retranslateUi(motionControl2Class);

        QMetaObject::connectSlotsByName(motionControl2Class);
    } // setupUi

    void retranslateUi(QMainWindow *motionControl2Class)
    {
        motionControl2Class->setWindowTitle(QApplication::translate("motionControl2Class", "motionControl2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class motionControl2Class: public Ui_motionControl2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTIONCONTROL2_H
