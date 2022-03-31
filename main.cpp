#include "mainwindow.h"
#include "sqlite.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
    db.setDatabaseName("mydb.sqlite");
    run_database(db);
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
