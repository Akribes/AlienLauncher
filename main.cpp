#include "mainwindow.h"

#include <QApplication>
#include <QUuid>

int main(int argc, char *argv[])
{
    QApplication a (argc, argv);
    QApplication::setOrganizationName("AlienLauncher");
    QApplication::setOrganizationDomain("");
    QApplication::setApplicationName("AlienLauncher");

    // Cliend id sent to auth servers must be identical for each request, so use a random UUID (like the official launcher)
    QSettings s;
    if (!s.contains("auth/clientToken")) {
        s.setValue("auth/clientToken", QUuid::createUuid().toString(QUuid::Id128));
    }

    MainWindow w;
    w.show();
    return a.exec();
}
