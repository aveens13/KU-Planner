#include "mainwindow.h"
#include "sqlite.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));
//    QSqlDatabase *db = new  QSqlDatabase;
//    *db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
//    db->setDatabaseName("planner.sqlite");
//    run_database(*db);
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
