#include <QtGui/QApplication>
#include "Languagedlg.h"
#include "Manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Manager manager;
    manager.startWork();
    return a.exec();
}
