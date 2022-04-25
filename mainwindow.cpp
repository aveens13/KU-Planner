#include "mainwindow.h"
#include "sqlite.h"
#include "examCombo.h"
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
    mResourceDir = "../../Resources";
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
    QSqlDatabase *db = new  QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("reminders1.sqlite");
    QWidget *central = new QWidget;
    QVBoxLayout* vertical_layout = new QVBoxLayout(central);
    ui->scrollArea_3->setWidget(central);
    ui->scrollArea_3->setWidgetResizable(true);
    fetch_reminders(*db,*ui,*vertical_layout);
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
    QSqlDatabase *db = new  QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("reminders1.sqlite");
    QWidget *central = new QWidget;
    QVBoxLayout* vertical_layout = new QVBoxLayout(central);
    ui->scrollArea_3->setWidget(central);
    ui->scrollArea_3->setWidgetResizable(true);
    fetch_reminders(*db,*ui,*vertical_layout);
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
    QSqlDatabase *db = new  QSqlDatabase;
    QWidget *central = new QWidget;
    *db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
    db->setDatabaseName("exams.sqlite");
    QVBoxLayout* v1 = new QVBoxLayout(central);
    ui->scrollArea_2->setWidget(central);
    ui->scrollArea_2->setWidgetResizable(true);
    write_exams(*db,*ui,*v1);
}


void MainWindow::on_routine_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_continueButton_clicked()
{
    if((ui->checkBox->isChecked() && ui->checkBox_2->isChecked()) || (ui->checkBox->isChecked() && ui->checkBox_3->isChecked()) || (ui->checkBox_2->isChecked() && ui->checkBox_3->isChecked()) || (ui->checkBox->isChecked() && ui->checkBox_3->isChecked() && ui->checkBox_2->isChecked())){
        ui->errorAdd->setText("Error: Please check only one");
    }
    else if(ui->checkBox->isChecked()){
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if(ui->checkBox_2->isChecked()){
        ui->stackedWidget_2->setCurrentIndex(2);
    }
    else if(ui->checkBox_3->isChecked()){
        ui->stackedWidget_2->setCurrentIndex(3);
    }
    else if(!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked()){
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

void MainWindow::on_reminders_submit_clicked()
{
    QString title;
    QString description,dd1;
    QDate deadline;
    QSqlDatabase *db = new  QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
    db->setDatabaseName("reminders1.sqlite");
    try{
    title = ui->lineEdit_3->text();
    qDebug()<<title;
    description = ui->textEdit->toPlainText();
    qDebug()<<description;
    deadline = ui->dateEdit->date();
    qDebug()<<deadline;
//    dd1 = deadline.toString();
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->errorAdd->setText("Success: Added The Reminder...");
    if(title == "" || description == "") throw invalid_argument("Cannot Perform the tasks");
    }
    catch(invalid_argument& ex){
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->errorAdd->setText("Error: Cannot add the Reminder... ");
    }
    add_reminders(*db,title,description,deadline);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0){
        try {
            qDebug()<<QDir::currentPath();
            QPixmap img(QDir::currentPath() + "/Resources/cs12.png");
            QGraphicsScene *scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);
            ui->graphicsView->scene()->addPixmap(img);
            if(!ui->graphicsView->scene()) throw "err";
        }  catch (const char* err ) {
            qDebug()<<"Error";
        }
    }
    else if(index == 1){
        try {
//            QString url = QFileDialog::getOpenFileName(this,
//                                                       tr("Load Image"),
//                                                       mResourceDir,
//                                                       tr("Images (*.png *.jpg)"));
//            if (url.isEmpty()) throw "error";
            QPixmap img(QDir::currentPath() + "/Resources/cs11.jpg");
            QGraphicsScene *scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);
            ui->graphicsView->scene()->addPixmap(img);
            if(!ui->graphicsView->scene()) throw "err";
        }  catch (const char* err ) {
            qDebug()<<"Error";
        }
    }
    else if (index == 2){
        try {
            qDebug()<<QDir::currentPath();
            QPixmap img(QDir::currentPath() + "/Resources/ee11.jpg");
            QGraphicsScene *scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);
            ui->graphicsView->scene()->addPixmap(img);
            if(!ui->graphicsView->scene()) throw "err";
        }  catch (const char* err ) {
            qDebug()<<"Error";
        }
    }
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if(index == 1){
        QComboBox* cb = ui->comboBox_3;
        fetch_Physics(*cb);
    }
    else if(index == 2){
        QComboBox* combobox = ui->comboBox_3;
        fetch_Chemistry(*combobox);
    }
    else if(index == 3){
        QComboBox* combobox = ui->comboBox_3;
        fetch_Math(*combobox);
    }
    else if(index == 4){
        QComboBox* combobox = ui->comboBox_3;
        fetch_Programming(*combobox);
    }
    else if(index == 5){
        QComboBox* combobox = ui->comboBox_3;
        fetch_drawing(*combobox);
    }
    else if(index == 6){
        QComboBox* combobox = ui->comboBox_3;
        fetch_environment(*combobox);
    }
}


void MainWindow::on_submitExam_clicked()
{
    QString sub;
    QString code;
    QDate deadline;
    QSqlDatabase *db = new  QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
    db->setDatabaseName("exams.sqlite");
    try{
    sub = ui->comboBox_2->currentText();
    qDebug()<<sub;
    code = ui->comboBox_3->currentText();
    qDebug()<<code;
    deadline = ui->dateEdit->date();
    qDebug()<<deadline;
//    dd1 = deadline.toString();
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->errorAdd->setText("Success: Added The Exam...");
    if(sub == "" || code == "") throw invalid_argument("Cannot Perform the tasks");
    }
    catch(invalid_argument& ex){
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->errorAdd->setText("Error: Cannot add the Reminder... ");
    }
    add_exams(*db,sub,code,deadline);
}


void MainWindow::on_pushButton_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(7);
}

