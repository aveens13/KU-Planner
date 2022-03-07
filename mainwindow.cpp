#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getstarted_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_dashboard_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_calendar_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_quiz_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_assignments_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_exams_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_routine_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


