#ifndef SQLITE_H
#define SQLITE_H
#include <QtSql>
#include <QSqlDatabase>
#include <stdexcept>
#include "mainwindow.h"
#include "ui_mainwindow.h"
void run_assignment_database(QSqlDatabase&);
void assignment_database(QSqlDatabase&,QString, QString, QString);
void fetch_assignment(QSqlDatabase&,Ui::MainWindow&,QVBoxLayout&);
#endif // SQLITE_H
