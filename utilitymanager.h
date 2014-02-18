#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H
#define TASKMANAGER_H
#define SAFE_REMOVE_H
#define UNMOUNTDISK_H
#include <QMainWindow>
#include <QTime>
#include <Qt>
#include <QTabBar>
#include <QLabel>
#include <QTabWidget>
#include <QWidget>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
    class UtilityManager;
    class TaskManager;
    class safe_Remove;
    class UnmountDisk;
}

class UtilityManager : public QMainWindow {
    Q_OBJECT
public:
    UtilityManager(QWidget *parent = 0);
    ~UtilityManager();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::UtilityManager *ui;

private slots:
    void on_troubleShootDisk_clicked();
    void on_taskManager_clicked();
    void on_checkSafeRemove_clicked();
    void on_unmount_clicked();
};


class TaskManager : public QMainWindow {
    Q_OBJECT
public:
    TaskManager(QWidget *parent = 0);
    ~TaskManager();

    QTableWidgetItem Pid;
    QTableWidgetItem Process;
    QTableWidgetItem Status;
    QTableWidgetItem Memory;
    void showMemInfo();
    void showBatteryInfo();
    void showBasicInfo();
    void showProcessInfo();
    void showOsVersion();
    void showNetworkInfo();

public slots:

    void showTime();



protected:
    void changeEvent(QEvent *e);

private:
    Ui::TaskManager *task;
};




class safe_Remove : public QMainWindow {
    Q_OBJECT
public:
    safe_Remove(QWidget *parent = 0);
    ~safe_Remove();

    void mountInfo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::safe_Remove *safeRemove;

private slots:

private slots:
};

class UnmountDisk : public QMainWindow {
    Q_OBJECT
public:
    UnmountDisk(QWidget *parent = 0);
    ~UnmountDisk();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::UnmountDisk *unmount;

private slots:
};

#endif // UTILITYMANAGER_H
