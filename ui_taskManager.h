/********************************************************************************
** Form generated from reading UI file 'taskManager.ui'
**
** Created: Sun Apr 17 23:48:04 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManager
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *sysInfoCPU;
    QLabel *sysInfoRAM;
    QLabel *sysInfoOSV;
    QLabel *label_4;
    QLabel *sysInfoCache;
    QLabel *label_6;
    QLabel *sysInfoCores;
    QWidget *tab_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *SysInfoFreeMemory;
    QLabel *SysInfoBuffers;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *SysInfoCached;
    QLabel *SysInfoSwapCached;
    QLabel *SysInfoTotalMemory;
    QWidget *tab_6;
    QLabel *label_22;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *sysInfoBatteryInfoLabelSerialNumber;
    QLabel *sysInfoBatteryInfoLabelBatteryModelNo;
    QLabel *sysInfoBatteryInfoLabelAcAdapter;
    QLabel *sysInfoBatteryInfoLabelBatteryType;
    QLabel *sysInfoBatteryInfoLabelBatteryState;
    QLabel *sysInfoBatteryInfoLabelBatteryTechnology;
    QWidget *tab_2;
    QTableWidget *TableWidgetProcess;
    QWidget *tab_3;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *packetsSent;
    QLabel *bytesSent;
    QLabel *packetsReceived;
    QLabel *bytesReceived;

    void setupUi(QMainWindow *TaskManager)
    {
        if (TaskManager->objectName().isEmpty())
            TaskManager->setObjectName(QString::fromUtf8("TaskManager"));
        TaskManager->resize(1150, 550);
        centralWidget = new QWidget(TaskManager);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1130, 550));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 1110, 550));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 62, 17));
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 62, 17));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 100, 90, 17));
        sysInfoCPU = new QLabel(tab_4);
        sysInfoCPU->setObjectName(QString::fromUtf8("sysInfoCPU"));
        sysInfoCPU->setGeometry(QRect(130, 40, 441, 17));
        sysInfoRAM = new QLabel(tab_4);
        sysInfoRAM->setObjectName(QString::fromUtf8("sysInfoRAM"));
        sysInfoRAM->setGeometry(QRect(130, 70, 441, 17));
        sysInfoOSV = new QLabel(tab_4);
        sysInfoOSV->setObjectName(QString::fromUtf8("sysInfoOSV"));
        sysInfoOSV->setGeometry(QRect(130, 100, 850, 17));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 130, 90, 17));
        sysInfoCache = new QLabel(tab_4);
        sysInfoCache->setObjectName(QString::fromUtf8("sysInfoCache"));
        sysInfoCache->setGeometry(QRect(130, 130, 441, 17));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 160, 90, 17));
        sysInfoCores = new QLabel(tab_4);
        sysInfoCores->setObjectName(QString::fromUtf8("sysInfoCores"));
        sysInfoCores->setGeometry(QRect(130, 160, 441, 17));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label_7 = new QLabel(tab_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 50, 101, 17));
        label_8 = new QLabel(tab_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 80, 91, 17));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 110, 62, 17));
        SysInfoFreeMemory = new QLabel(tab_5);
        SysInfoFreeMemory->setObjectName(QString::fromUtf8("SysInfoFreeMemory"));
        SysInfoFreeMemory->setGeometry(QRect(150, 80, 301, 17));
        SysInfoBuffers = new QLabel(tab_5);
        SysInfoBuffers->setObjectName(QString::fromUtf8("SysInfoBuffers"));
        SysInfoBuffers->setGeometry(QRect(150, 110, 441, 17));
        label_13 = new QLabel(tab_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(40, 140, 62, 17));
        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(40, 170, 111, 17));
        SysInfoCached = new QLabel(tab_5);
        SysInfoCached->setObjectName(QString::fromUtf8("SysInfoCached"));
        SysInfoCached->setGeometry(QRect(150, 140, 441, 17));
        SysInfoSwapCached = new QLabel(tab_5);
        SysInfoSwapCached->setObjectName(QString::fromUtf8("SysInfoSwapCached"));
        SysInfoSwapCached->setGeometry(QRect(150, 170, 441, 17));
        SysInfoTotalMemory = new QLabel(tab_5);
        SysInfoTotalMemory->setObjectName(QString::fromUtf8("SysInfoTotalMemory"));
        SysInfoTotalMemory->setGeometry(QRect(150, 50, 400, 17));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        label_22 = new QLabel(tab_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(50, 160, 111, 17));
        label_21 = new QLabel(tab_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(50, 130, 101, 17));
        label_19 = new QLabel(tab_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(50, 70, 141, 17));
        label_20 = new QLabel(tab_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(50, 100, 131, 17));
        label_23 = new QLabel(tab_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(50, 190, 141, 17));
        label_24 = new QLabel(tab_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(50, 40, 181, 17));
        sysInfoBatteryInfoLabelSerialNumber = new QLabel(tab_6);
        sysInfoBatteryInfoLabelSerialNumber->setObjectName(QString::fromUtf8("sysInfoBatteryInfoLabelSerialNumber"));
        sysInfoBatteryInfoLabelSerialNumber->setGeometry(QRect(200, 160, 351, 17));
        sysInfoBatteryInfoLabelBatteryModelNo = new QLabel(tab_6);
        sysInfoBatteryInfoLabelBatteryModelNo->setObjectName(QString::fromUtf8("sysInfoBatteryInfoLabelBatteryModelNo"));
        sysInfoBatteryInfoLabelBatteryModelNo->setGeometry(QRect(200, 100, 341, 17));
        sysInfoBatteryInfoLabelAcAdapter = new QLabel(tab_6);
        sysInfoBatteryInfoLabelAcAdapter->setObjectName(QString::fromUtf8("sysInfoBatteryInfoLabelAcAdapter"));
        sysInfoBatteryInfoLabelAcAdapter->setGeometry(QRect(200, 70, 341, 17));
        sysInfoBatteryInfoLabelBatteryType = new QLabel(tab_6);
        sysInfoBatteryInfoLabelBatteryType->setObjectName(QString::fromUtf8("sysInfoBatteryInfoLabelBatteryType"));
        sysInfoBatteryInfoLabelBatteryType->setGeometry(QRect(200, 130, 341, 17));
        sysInfoBatteryInfoLabelBatteryState = new QLabel(tab_6);
        sysInfoBatteryInfoLabelBatteryState->setObjectName(QString::fromUtf8("sysInfoBatteryInfoLabelBatteryState"));
        sysInfoBatteryInfoLabelBatteryState->setGeometry(QRect(200, 40, 341, 17));
        sysInfoBatteryInfoLabelBatteryTechnology = new QLabel(tab_6);
        sysInfoBatteryInfoLabelBatteryTechnology->setObjectName(QString::fromUtf8("sysInfoBatteryInfoLabelBatteryTechnology"));
        sysInfoBatteryInfoLabelBatteryTechnology->setGeometry(QRect(200, 190, 351, 17));
        tabWidget_2->addTab(tab_6, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        TableWidgetProcess = new QTableWidget(tab_2);
        if (TableWidgetProcess->columnCount() < 4)
            TableWidgetProcess->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableWidgetProcess->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font;
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferDefault);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        TableWidgetProcess->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TableWidgetProcess->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TableWidgetProcess->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        TableWidgetProcess->setObjectName(QString::fromUtf8("TableWidgetProcess"));
        TableWidgetProcess->setGeometry(QRect(-1, 10, 611, 441));
        TableWidgetProcess->setMinimumSize(QSize(561, 441));
        TableWidgetProcess->setSizeIncrement(QSize(0, 0));
        TableWidgetProcess->horizontalHeader()->setCascadingSectionResizes(true);
        TableWidgetProcess->horizontalHeader()->setDefaultSectionSize(150);
        TableWidgetProcess->horizontalHeader()->setMinimumSectionSize(100);
        TableWidgetProcess->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 40, 150, 17));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 80, 150, 17));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 120, 150, 17));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 160, 150, 17));
        packetsSent = new QLabel(tab_3);
        packetsSent->setObjectName(QString::fromUtf8("packetsSent"));
        packetsSent->setGeometry(QRect(220, 160, 300, 17));
        bytesSent = new QLabel(tab_3);
        bytesSent->setObjectName(QString::fromUtf8("bytesSent"));
        bytesSent->setGeometry(QRect(220, 120, 300, 17));
        packetsReceived = new QLabel(tab_3);
        packetsReceived->setObjectName(QString::fromUtf8("packetsReceived"));
        packetsReceived->setGeometry(QRect(220, 80, 300, 17));
        bytesReceived = new QLabel(tab_3);
        bytesReceived->setObjectName(QString::fromUtf8("bytesReceived"));
        bytesReceived->setGeometry(QRect(220, 40, 300, 17));
        tabWidget->addTab(tab_3, QString());
        TaskManager->setCentralWidget(centralWidget);

        retranslateUi(TaskManager);

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TaskManager);
    } // setupUi

    void retranslateUi(QMainWindow *TaskManager)
    {
        TaskManager->setWindowTitle(QApplication::translate("TaskManager", "Task Manager", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TaskManager", "CPU :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TaskManager", "RAM :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TaskManager", "OS Version :", 0, QApplication::UnicodeUTF8));
        sysInfoCPU->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        sysInfoRAM->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        sysInfoOSV->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TaskManager", "Cache Size :", 0, QApplication::UnicodeUTF8));
        sysInfoCache->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TaskManager", "No Of Cores :", 0, QApplication::UnicodeUTF8));
        sysInfoCores->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("TaskManager", "Basic Info", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TaskManager", "Total Memory", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TaskManager", "Free Memory", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("TaskManager", "Buffers", 0, QApplication::UnicodeUTF8));
        SysInfoFreeMemory->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        SysInfoBuffers->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("TaskManager", "Cached", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("TaskManager", "Swapped Cache", 0, QApplication::UnicodeUTF8));
        SysInfoCached->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        SysInfoSwapCached->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        SysInfoTotalMemory->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("TaskManager", "Memory", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("TaskManager", "Serial Number :", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("TaskManager", "Battery Type :", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("TaskManager", "AC Adapter Status :", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("TaskManager", "Battery Model :", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("TaskManager", "Battery Technology :", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("TaskManager", "Battery Available :", 0, QApplication::UnicodeUTF8));
        sysInfoBatteryInfoLabelSerialNumber->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        sysInfoBatteryInfoLabelBatteryModelNo->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        sysInfoBatteryInfoLabelAcAdapter->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        sysInfoBatteryInfoLabelBatteryType->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        sysInfoBatteryInfoLabelBatteryState->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        sysInfoBatteryInfoLabelBatteryTechnology->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("TaskManager", "Battery", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TaskManager", "System Info", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = TableWidgetProcess->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TaskManager", "Pid", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = TableWidgetProcess->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TaskManager", "Process Name ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = TableWidgetProcess->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TaskManager", "Status", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = TableWidgetProcess->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TaskManager", "Memory Used", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TaskManager", "Processes", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TaskManager", "Bytes Received :", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("TaskManager", "Packets Received :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("TaskManager", "Bytes Sent :", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("TaskManager", "Packets Sent :", 0, QApplication::UnicodeUTF8));
        packetsSent->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        bytesSent->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        packetsReceived->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        bytesReceived->setText(QApplication::translate("TaskManager", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("TaskManager", "Network Info", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskManager: public Ui_TaskManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
