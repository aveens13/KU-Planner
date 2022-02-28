#include "dashboard.h"
#include "ui_dashboard.h"
//#include "mainwindow.h"

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_addButton_clicked()
{
    qDebug()<<"hello i am clicked";
}


void Dashboard::on_assignments_clicked()
{
    hide();
    assignment = new Assignment(this);
    assignment->showMaximized();
}

