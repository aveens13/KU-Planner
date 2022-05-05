#ifndef SQLITE_H
#define SQLITE_H
#include <QtSql>
#include <QSqlDatabase>
#include <stdexcept>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eventsdialog.h"
#include "ui_eventsdialog.h"
void run_assignment_database(QSqlDatabase&);
void assignment_database(QSqlDatabase&,QString, QString, QDate);
void fetch_assignment(QSqlDatabase&,Ui::MainWindow&,QVBoxLayout&);
void add_reminders(QSqlDatabase&,QString, QString, QDate);
void add_exams(QSqlDatabase&,QString, QString, QDate);
void write_exams(QSqlDatabase&,Ui::MainWindow&,QVBoxLayout&);
void fetch_reminders(QSqlDatabase&,Ui::MainWindow&, QVBoxLayout&);
void return_assignment(QSqlDatabase&,QDate);
void return_exams(QSqlDatabase&,QDate);
void return_reminders(QSqlDatabase&,QDate);
//void setText(Ui::eventsdialog&);
#endif // SQLITE_H
