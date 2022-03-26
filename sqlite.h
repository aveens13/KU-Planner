#ifndef SQLITE_H
#define SQLITE_H

#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
using namespace std;

class SqlThread{
public:
    SqlThread();
    void run();

private:
    QSqlDatabase db;
    SqlThread *sqlObj;
};


#endif // SQLITE_H
