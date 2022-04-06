#include "eventsdialog.h"
#include "ui_eventsdialog.h"

eventsdialog::eventsdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eventsdialog)
{
    ui->setupUi(this);
}

eventsdialog::~eventsdialog()
{
    delete ui;
}

void eventsdialog::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0){
        ui->eventlabel->setText("Events");
    }
}

