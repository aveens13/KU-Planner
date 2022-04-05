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
    db.close();
}
