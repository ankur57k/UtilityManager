/********************************************************************************
** Form generated from reading UI file 'unmountdisk.ui'
**
** Created: Sun Apr 17 20:46:25 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNMOUNTDISK_H
#define UI_UNMOUNTDISK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UnmountDisk
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UnmountDisk)
    {
        if (UnmountDisk->objectName().isEmpty())
            UnmountDisk->setObjectName(QString::fromUtf8("UnmountDisk"));
        UnmountDisk->resize(300, 500);
        centralWidget = new QWidget(UnmountDisk);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        UnmountDisk->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UnmountDisk);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 300, 23));
        UnmountDisk->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UnmountDisk);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UnmountDisk->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UnmountDisk);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UnmountDisk->setStatusBar(statusBar);

        retranslateUi(UnmountDisk);

        QMetaObject::connectSlotsByName(UnmountDisk);
    } // setupUi

    void retranslateUi(QMainWindow *UnmountDisk)
    {
        UnmountDisk->setWindowTitle(QApplication::translate("UnmountDisk", "Unmount Disk", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UnmountDisk: public Ui_UnmountDisk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNMOUNTDISK_H
