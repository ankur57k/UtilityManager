/********************************************************************************
** Form generated from reading UI file 'safe_remove.ui'
**
** Created: Sun Apr 17 20:46:25 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAFE_REMOVE_H
#define UI_SAFE_REMOVE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_safe_Remove
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *safe_Remove)
    {
        if (safe_Remove->objectName().isEmpty())
            safe_Remove->setObjectName(QString::fromUtf8("safe_Remove"));
        safe_Remove->resize(500, 700);
        centralWidget = new QWidget(safe_Remove);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        safe_Remove->setCentralWidget(centralWidget);

        retranslateUi(safe_Remove);

        QMetaObject::connectSlotsByName(safe_Remove);
    } // setupUi

    void retranslateUi(QMainWindow *safe_Remove)
    {
        safe_Remove->setWindowTitle(QApplication::translate("safe_Remove", "Safe Remove", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class safe_Remove: public Ui_safe_Remove {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAFE_REMOVE_H
