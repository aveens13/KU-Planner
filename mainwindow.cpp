#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_dashBoard_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_calendar_2_clicked()
{
    ui->groupBox->show();
    ui->stackedWidget->setCurrentIndex(2);
}

