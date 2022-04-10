#include <QtSql>
#include <QSqlDatabase>
#include "sqlite.h"

void run_assignment_database(QSqlDatabase& db){

    if(!db.open()){
        qDebug("Unable to connect...");
    }
    else{
        qDebug("Connected Sunccessfully to the assignment database!!!");
    }
    QSqlQuery *databaseQuery = new QSqlQuery(db);
    if(!databaseQuery->exec("CREATE TABLE IF NOT EXISTS Assignment (id int not null primary key, title text, description text, deadline text)")){
        qDebug("Cannot execute the query..");
    }
    else{
        qDebug("Created a table with name Assignment Successfully!!!");
    }
    delete databaseQuery;
}

void assignment_database(QSqlDatabase& db,QString title, QString desc, QString deadline){

    try {
        bool check = db.isOpen();
        qDebug()<<check;
        if(!check) {
            throw "Error";
            return;
        }
    }  catch (const char* ex) {
        qDebug()<<db.lastError();
        return;
    }
    QSqlQuery *databaseQuery = new QSqlQuery(db);
//    if(db.driver()->hasFeature(QSqlDriver::QuerySize)){
//        int number_of_rows = databaseQuery->size();
//        qDebug()<<number_of_rows;
//    }
    //For increasing the unique id key
    databaseQuery->exec("SELECT id FROM ASSIGNMENT");
    int id; //declaring the id for the last updated id key
    while (databaseQuery->next()) {
           int id_loop = databaseQuery->value(0).toInt();
            qDebug() << id_loop;
            id = id_loop + 1;
        }
    qDebug()<<"New Key: "<<id;
    try{
//        QSqlQuery *databaseQuery = new QSqlQuery(db);
        databaseQuery->prepare("INSERT INTO Assignment(id,title,description,deadline)""VALUES (:id,:title,:description,:deadline)");
        databaseQuery->bindValue(":id",id);
        qDebug()<<title;
        qDebug()<<desc;
        qDebug()<<deadline;
        databaseQuery->bindValue(":title",title);
        databaseQuery->bindValue(":description",desc);
        databaseQuery->bindValue(":deadline",deadline);
        if(!databaseQuery->exec()){
        throw "fas";
        }
        qDebug("Inserted the data into the assignment table");
    }
    catch(const char* ex){
        qDebug()<<db.lastError();
    }
    databaseQuery->exec("SELECT * FROM ASSIGNMENT");
    while(databaseQuery->next()){
        int print_id = databaseQuery->value(0).toInt();
        QString title_print = databaseQuery->value(1).toString();
        qDebug()<<"ID of Assignment: "<<print_id;
        qDebug()<<"Assignment Title: "<<title_print;
    }
    delete databaseQuery;
    db.close();
}

void fetch_assignment(QSqlDatabase& db,Ui::MainWindow& ui,QVBoxLayout& v_layout){
    if(!db.open()){
        qDebug("Unable to connect...");
    }
    else{
        qDebug("Connected Sunccessfully to the assignment database!!!");
        qDebug("Fetching the Assignment Data...");
    }
    QSqlQuery *databaseQuery = new QSqlQuery(db);
    databaseQuery->exec("SELECT * FROM ASSIGNMENT");
    int sn_assignment = 1;
    while(databaseQuery->next()){
        QWidget *widget_assignment = new QWidget;
        QHBoxLayout* h_layout = new QHBoxLayout(widget_assignment);
        QLabel *sn = new QLabel;
        QLabel *label_title_assignment = new QLabel;
        QLabel *label_description_assignment = new QLabel;
        QLabel *label_deadline_assignment = new QLabel;
        QCheckBox *checkbox_done = new QCheckBox("Completed");
        QString  sn_str = QString::number(sn_assignment) + ".";
        sn->setText(sn_str);
        label_title_assignment->setText(databaseQuery->value(1).toString());
        label_description_assignment->setText(databaseQuery->value(2).toString());
        label_deadline_assignment->setText(databaseQuery->value(3).toString());
        h_layout->addWidget(sn);
        h_layout->addWidget(label_title_assignment);
        h_layout->addWidget(label_description_assignment);
        h_layout->addWidget(label_deadline_assignment);
        h_layout->addWidget(checkbox_done);
        v_layout.addWidget(widget_assignment);
        int print_id = databaseQuery->value(0).toInt();
        QString title_print = databaseQuery->value(1).toString();
        qDebug()<<"ID of Assignment: "<<print_id;
        qDebug()<<"Assignment Title: "<<title_print;
        sn_assignment +=1;
    }
    db.close();
}
