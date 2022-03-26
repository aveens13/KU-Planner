#include "mainwindow.h"
#include "sqlite.h"
#include<iostream>
using namespace std;
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
    db.setDatabaseName("C:/Users/bhatt/OneDrive/Desktop/KU-Planner/mydb.sqlite");
    if(!db.open()){
        qDebug("Unable to connect...");
    }
    else{
        qDebug("Connected Sunccessfully!!!");
    }
    QSqlQuery databaseQuery(db);
    databaseQuery.prepare("CREATE TABLE IF NOT EXISTS Assignment (id int not null primary key, title text, description text, deadline text)");
    if(!databaseQuery.exec()){
        qDebug("Cannot execute the query..");
        return;
    }
    else{
        qDebug("Done Successfully!!!");
    }

    ui->setupUi(this);
    ui->groupBox->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getStarted_clicked()
{

    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_addTask_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_dashBoard_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_calendar_2_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_assignments_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_exams_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_routine_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_continueButton_clicked()
{
    if(ui->checkBox->isChecked() && ui->checkBox_2->isChecked()){
        ui->errorAdd->setText("Error: Both are checked, please check only one");
    }
    else if(ui->checkBox->isChecked()){
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if(ui->checkBox_2->isChecked()){
        ui->stackedWidget_2->setCurrentIndex(2);
    }
    else if(!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked()){
        ui->errorAdd->setText("Error: At least check one box");
    }
}

