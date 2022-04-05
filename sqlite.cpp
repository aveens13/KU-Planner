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

void assignment_database(QSqlDatabase& db){
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

    try{
        QSqlQuery *databaseQuery = new QSqlQuery(db);
        databaseQuery->prepare("INSERT INTO Assignment(id,title,description,deadline)""VALUES (3,'Physics Assignment 1','Assignment 1 Complete','Tuesday March 31')");
        if(!databaseQuery->exec()){
        throw "Cannot Insert into the table..";
        }
        qDebug("Inserted the data into the assignment table");
    }
    catch(const char* ex){
        qDebug()<<db.lastError();
    }
}
