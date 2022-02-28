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
//    Dialog secdialog;
//    secdialog.setModal(true);
//    secdialog.exec();
    hide();
//    secdialog = new Dialog(this);
//    secdialog -> show();
    dashboard = new Dashboard(this);
    dashboard->showMaximized();
}

