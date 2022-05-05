#include "deleteDialog.h"
#include "ui_deleteDialog.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    *db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
    db->setDatabaseName("exams.sqlite");
    for(int i = 0 ; i < 6 ; i++){
        ui->comboBox->addItem(array[i]);
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_comboBox_currentIndexChanged(int index)
{
    *db = QSqlDatabase::addDatabase("QSQLITE"); // adding the sqlite engine
    db->setDatabaseName("exams.sqlite");
    if(!db->open()){
            qDebug("Unable to connect...(combobox)");
        }
        else{
            qDebug("Connected Sunccessfully to the exams database (combobox)!!!");
            qDebug("Fetching the exams Data...");
        }
    int i = 1;
    QString sub = array[0];

        while(i <= 6){
            if(index == i){
                sub = array[i-1];
            }
            i++;
        }
    QSqlQuery *dbq = new QSqlQuery(*db);
    try{
        if(!dbq->prepare("SELECT id FROM Exams WHERE sub ='"+sub+"'")) throw "Cannot Prepare";
        qDebug()<<sub;
        if(!dbq->exec())  throw "Cannot Execute";
    }
    catch(const char* ex){
        qDebug()<<ex;
        qDebug()<<db->lastError();
    }
    while(dbq->next()){
        qDebug()<<dbq->value(0).toInt();
        ui->comboBox_2->clear();
        ui->comboBox_2->addItem(dbq->value(0).toString());
    }
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
}


void Dialog::on_pushButton_clicked()
{
    QString id = ui->comboBox_2->currentText();
    if(!db->open()){
            qDebug("Unable to connect...(deleting)");
        }
        else{
            qDebug("Connected Sunccessfully to the exams database (deleting)!!!");
            qDebug("Fetching the exams Data...");
        }
    qDebug()<<id;
    QSqlQuery *databaseQuery = new QSqlQuery(*db);
    databaseQuery->exec("DELETE FROM Exams where id ='"+id+"'");
}

