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
        ui.scrollArea->setWidgetResizable(true);
        ui.scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui.scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        while(databaseQuery->next()){
            QCheckBox *checkbox_done = new QCheckBox("Done");
            QWidget *widget_assignment = new QWidget;
            QHBoxLayout* h_layout = new QHBoxLayout(widget_assignment);
            widget_assignment->setMaximumHeight(150);
            widget_assignment->setMinimumHeight(100);
    //        widget_assignment->setStyleSheet("background-color:#B3B3B3");
            QLabel *sn = new QLabel;
            QLabel *label_title_assignment = new QLabel;
            QLabel *label_description_assignment = new QLabel;
            QLabel *label_deadline_assignment = new QLabel;
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
        }/*
        QPushButton *refresh = new QPushButton("Refresh");
        refresh->setStyleSheet("padding:15px 5px;border-radius:10px;font: 700 7pt;");*/
//        v_layout.addWidget(refresh);
    //    delete checkbox_done;
    //    delete refresh;
        db.close();
}

void add_reminders(QSqlDatabase& db,QString title, QString description, QDate date){
    if(!db.open()){
        qDebug("Unable to connect...");
    }
    else{
        qDebug("Connected Sunccessfully to the Reminders database!!!");
    }
    QSqlQuery *databaseq = new QSqlQuery(db);
    if(!databaseq->exec("CREATE TABLE IF NOT EXISTS Reminders (id int not null primary key, title text, description text, deadline date)")){
        qDebug("Cannot execute the query..");
    }
    else{
        qDebug("Created a table with name Reminders Successfully!!!");
    }
    delete databaseq;
    QSqlQuery *databaseQuery = new QSqlQuery(db);
    //For increasing the unique id key
    databaseQuery->exec("SELECT id FROM Reminders");
    int id; //declaring the id for the last updated id key
    while (databaseQuery->next()) {
           int id_loop = databaseQuery->value(0).toInt();
            qDebug() << id_loop;
            id = id_loop + 1;
        }
    qDebug()<<"New Key: "<<id;
    try{
//        QSqlQuery *databaseQuery = new QSqlQuery(db);
        databaseQuery->prepare("INSERT INTO Reminders(id,title,description,deadline)""VALUES (:id,:title,:description,:deadline)");
        databaseQuery->bindValue(":id",id);
        qDebug()<<title;
        qDebug()<<description;
        qDebug()<<date;
        databaseQuery->bindValue(":title",title);
        databaseQuery->bindValue(":description",description);
        databaseQuery->bindValue(":deadline",date);
        if(!databaseQuery->exec()){
        throw "fas";
        }
        qDebug("Inserted the data into the Reminder table");
    }
    catch(const char* ex){
        qDebug()<<db.lastError();
    }
    databaseQuery->exec("SELECT * FROM Reminders");
    while(databaseQuery->next()){
        int print_id = databaseQuery->value(0).toInt();
        QString title_print = databaseQuery->value(1).toString();
        QDate date = databaseQuery->value(2).toDate();
//        QString date_s = date.toString();
        qDebug()<<"ID of Reminder: "<<print_id;
        qDebug()<<"Reminder Title: "<<title_print;
        qDebug()<<"Reminder deadline: "<<date;
    }
    delete databaseQuery;
    db.close();
}

void add_exams(QSqlDatabase& db,QString sub, QString code, QDate date){
    if(!db.open()){
        qDebug("Unable to connect...");
    }
    else{
        qDebug("Connected Sunccessfully to the Exams database!!!");
    }
    QSqlQuery *databaseq = new QSqlQuery(db);
    if(!databaseq->exec("CREATE TABLE IF NOT EXISTS Exams (id int not null primary key, sub text, code text, date_ date)")){
        qDebug("Cannot execute the query..");
    }
    else{
        qDebug("Created a table with name Exams Successfully!!!");
    }
    delete databaseq;
    QSqlQuery *databaseQuery = new QSqlQuery(db);
    //For increasing the unique id key
    databaseQuery->exec("SELECT id FROM Exams");
    int id; //declaring the id for the last updated id key
    while (databaseQuery->next()) {
           int id_loop = databaseQuery->value(0).toInt();
            qDebug() << id_loop;
            id = id_loop + 1;
        }
    qDebug()<<"New Key: "<<id;
    try{
//        QSqlQuery *databaseQuery = new QSqlQuery(db);
        databaseQuery->prepare("INSERT INTO Exams(id,sub,code,date_)""VALUES (:id,:sub,:code,:date_)");
        databaseQuery->bindValue(":id",id);
        qDebug()<<sub;
        qDebug()<<code;
        qDebug()<<date;
        databaseQuery->bindValue(":sub",sub);
        databaseQuery->bindValue(":code",code);
        databaseQuery->bindValue(":date_",date);
        if(!databaseQuery->exec()){
        throw "fas";
        }
        qDebug("Inserted the data into the Exams table");
    }
    catch(const char* ex){
        qDebug()<<db.lastError();
    }
    databaseQuery->exec("SELECT * FROM Exams");
    while(databaseQuery->next()){
        int print_id = databaseQuery->value(0).toInt();
        QString title_print = databaseQuery->value(1).toString();
        QDate date = databaseQuery->value(2).toDate();
//        QString date_s = date.toString();
        qDebug()<<"ID of Exam: "<<print_id;
        qDebug()<<"Exam Title: "<<title_print;
        qDebug()<<"Exam deadline: "<<date;
    }
    delete databaseQuery;
    db.close();
}

void write_exams(QSqlDatabase& db,Ui::MainWindow& ui,QVBoxLayout& v_layout){
    if(!db.open()){
            qDebug("Unable to connect...");
        }
        else{
            qDebug("Connected Sunccessfully to the exams database!!!");
            qDebug("Fetching the exams Data...");
        }
        QSqlQuery *databaseQuery = new QSqlQuery(db);
        databaseQuery->exec("SELECT * FROM Exams");
        int sn_assignment = 1;
        ui.scrollArea_2->setWidgetResizable(true);
        ui.scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui.scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        while(databaseQuery->next()){
            QCheckBox *done = new QCheckBox("Completed");
            QWidget *widget_assignment = new QWidget;
            QHBoxLayout* h_layout = new QHBoxLayout(widget_assignment);
            widget_assignment->setMaximumHeight(150);
            widget_assignment->setMinimumHeight(100);
    //        widget_assignment->setStyleSheet("background-color:#B3B3B3");
            QLabel *sn = new QLabel;
            QLabel *label_title_assignment = new QLabel;
            QLabel *label_description_assignment = new QLabel;
            QLabel *label_deadline_assignment = new QLabel;
            QString  sn_str = QString::number(sn_assignment) + ".";
            sn->setText(sn_str);
            label_title_assignment->setText(databaseQuery->value(1).toString());
            label_description_assignment->setText(databaseQuery->value(2).toString());
            label_deadline_assignment->setText(databaseQuery->value(3).toString());
            h_layout->addWidget(sn);
            h_layout->addWidget(label_title_assignment);
            h_layout->addWidget(label_description_assignment);
            h_layout->addWidget(label_deadline_assignment);
            h_layout->addWidget(done);
            v_layout.addWidget(widget_assignment);
            int print_id = databaseQuery->value(0).toInt();
            QString title_print = databaseQuery->value(1).toString();
            qDebug()<<"ID of Exam: "<<print_id;
            qDebug()<<"Exam Subject: "<<title_print;
            sn_assignment +=1;
        }
        QPushButton *refresh = new QPushButton("Refresh");
        refresh->setStyleSheet("padding:15px 5px;border-radius:10px;font: 700 12pt;");
        v_layout.addWidget(refresh);
    //    delete checkbox_done;
    //    delete refresh;
        db.close();
}
