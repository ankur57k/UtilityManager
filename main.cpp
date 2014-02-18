#include <QtGui/QApplication>
#include "utilitymanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UtilityManager w;
    w.show();
    return a.exec();
}
