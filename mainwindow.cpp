#include "mainwindow.h"
#include "sqlite.h"
#include<iostream>
using namespace std;

#include "ui_mainwindow.h"
#include "eventsdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getStarted_clicked()
{
//    ui->label_3->setText(day);
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_addTask_clicked()
{
    ui->groupBox->show();
    ui->errorAdd->setText("");
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
    QSqlDatabase *db = new  QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
    db->setDatabaseName("assignment.sqlite");
    QWidget *central = new QWidget;
    QVBoxLayout* vertical_layout = new QVBoxLayout(central);
    ui->scrollArea->setWidget(central);
    ui->scrollArea->setWidgetResizable(true);
    fetch_assignment(*db,*ui,*vertical_layout);
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

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    eventdialog = new eventsdialog(this);
    eventdialog->show();
    eventdialog->setWindowTitle(date.toString());
}


void MainWindow::on_submitButton_clicked()
{
     QString title;
     QString description,dd1;
     QDateTime deadline;
    QSqlDatabase *db = new  QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
    db->setDatabaseName("assignment.sqlite");
    try{
    title = ui->lineEdit->text();
    qDebug()<<title;
    description = ui->lineEdit_2->text();
    qDebug()<<description;
    deadline = ui->dateTimeEdit->dateTime();
    qDebug()<<deadline.toString();
    dd1 = deadline.toString();
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->errorAdd->setText("Success: Added The Assignment...");
    if(title == "" || description == "") throw invalid_argument("Cannot Perform the tasks");
    }
    catch(invalid_argument& ex){
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->errorAdd->setText("Error: Cannot add the Tasks... ");
    }
    run_assignment_database(*db);
    assignment_database(*db,title,description,dd1);
}
