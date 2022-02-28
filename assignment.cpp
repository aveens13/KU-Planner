#include "assignment.h"
#include "ui_assignment.h"

Assignment::Assignment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Assignment)
{
    ui->setupUi(this);
}

Assignment::~Assignment()
{
    delete ui;
}
