/********************************************************************************
** Form generated from reading UI file 'utilitymanager.ui'
**
** Created: Sun Apr 17 12:15:26 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTILITYMANAGER_H
#define UI_UTILITYMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UtilityManager
{
public:
    QWidget *centralWidget;
    QPushButton *taskManager;
    QPushButton *troubleShootDisk;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UtilityManager)
    {
        if (UtilityManager->objectName().isEmpty())
            UtilityManager->setObjectName(QString::fromUtf8("UtilityManager"));
        UtilityManager->resize(400, 400);
        centralWidget = new QWidget(UtilityManager);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        taskManager = new QPushButton(centralWidget);
        taskManager->setObjectName(QString::fromUtf8("taskManager"));
        taskManager->setGeometry(QRect(20, 130, 101, 81));
        troubleShootDisk = new QPushButton(centralWidget);
        troubleShootDisk->setObjectName(QString::fromUtf8("troubleShootDisk"));
        troubleShootDisk->setGeometry(QRect(222, 136, 131, 71));
        UtilityManager->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UtilityManager);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        UtilityManager->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UtilityManager);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UtilityManager->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UtilityManager);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UtilityManager->setStatusBar(statusBar);

        retranslateUi(UtilityManager);

        QMetaObject::connectSlotsByName(UtilityManager);
    } // setupUi

    void retranslateUi(QMainWindow *UtilityManager)
    {
        UtilityManager->setWindowTitle(QApplication::translate("UtilityManager", "Utility Manager", 0, QApplication::UnicodeUTF8));
        taskManager->setText(QApplication::translate("UtilityManager", "Task Manager", 0, QApplication::UnicodeUTF8));
        troubleShootDisk->setText(QApplication::translate("UtilityManager", "TroubleShoot Disks", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UtilityManager: public Ui_UtilityManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTILITYMANAGER_H
