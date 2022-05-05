#include "eventsdialog.h"
#include "ui_eventsdialog.h"
#include "sqlite.h"

struct DayEvents {
    std::vector<QString> assignments;
    std::vector<QString> reminders;
    std::vector<QString> exams;
};

extern DayEvents selectedDay;

eventsdialog::eventsdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eventsdialog)
{
    ui->setupUi(this);

//    qDebug() << "ui banyo";

    on_comboBox_currentIndexChanged(0);

//    for (auto str : selectedDay.assignments)
//        qDebug()<<str;
}

eventsdialog::~eventsdialog()
{
    delete ui;
}

void eventsdialog::on_comboBox_currentIndexChanged(int index)
{
    std::vector<QString> *current = &selectedDay.exams;
    QString txt;

    if (index == 0) {
        txt.append("Exams\n\n");
    } else if (index == 1) {
        txt.append("Assigments\n\n");
        current = &selectedDay.assignments;
    } else if (index == 2) {
        txt.append("Reminders\n\n");
        current = &selectedDay.reminders;
    }

    for (auto& str : *current)
        txt.append(str + "\n");

    ui->eventlabel->setText(txt);
}

