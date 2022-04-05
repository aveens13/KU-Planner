#ifndef SQLITE_H
#define SQLITE_H
#include <QtSql>
#include <QSqlDatabase>
#include <stdexcept>
void run_assignment_database(QSqlDatabase& db);
void assignment_database(QSqlDatabase& db,QString, QString, QString);
#endif // SQLITE_H
