#include <QtSql>
#include <QSqlDatabase>
#include "sqlite.h"

void run_database(QSqlDatabase& db){
    if(!db.open()){
        qDebug("Unable to connect...");
    }
    else{
        qDebug("Connected Sunccessfully!!!");
    }
    QSqlQuery databaseQuery(db);
    databaseQuery.prepare("CREATE TABLE IF NOT EXISTS Assignment (id int not null primary key, title text, description text, deadline text)");
    if(!databaseQuery.exec()){
        qDebug("Cannot execute the query..");
        return;
    }
    else{
        qDebug("Done Successfully!!!");
    }
}
