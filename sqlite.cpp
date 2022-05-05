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

void assignment_database(QSqlDatabase& db,QString title, QString desc, QDate deadline){

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
        QDate Date = QDate::fromString(deadline.toString(),"yyyy-MM-dd");
        qDebug()<<title;
        qDebug()<<desc;
        qDebug()<<Date;
        databaseQuery->bindValue(":title",title);
        databaseQuery->bindValue(":description",desc);
        databaseQuery->bindValue(":deadline",deadline.toString());
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
            QDate Date = QDate::fromString(databaseQuery->value(3).toString(),"yyyy-MM-dd");
            qDebug()<<Date;
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
    if(!databaseq->exec("CREATE TABLE IF NOT EXISTS Reminders (id int not null primary key, title text, description text, deadline text)")){
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
        databaseQuery->bindValue(":deadline",date.toString());
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
        QDate date = QDate::fromString(databaseQuery->value(3).toString(),"yyyy-MM-dd");
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
    if(!databaseq->exec("CREATE TABLE IF NOT EXISTS Exams (id int not null primary key, sub text, code text, deadline text)")){
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
        databaseQuery->prepare("INSERT INTO Exams(id,sub,code,deadline)""VALUES (:id,:sub,:code,:deadline)");
        databaseQuery->bindValue(":id",id);
        qDebug()<<sub;
        qDebug()<<code;
        qDebug()<<date;
        databaseQuery->bindValue(":sub",sub);
        databaseQuery->bindValue(":code",code);
        databaseQuery->bindValue(":deadline",date.toString());
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
            QDate Date = QDate::fromString(databaseQuery->value(3).toString(),"yyyy-MM-dd");
            qDebug()<<Date;
            int print_id = databaseQuery->value(0).toInt();
            QString title_print = databaseQuery->value(1).toString();
            qDebug()<<"ID of Exam: "<<print_id;
            qDebug()<<"Exam Subject: "<<title_print;
            sn_assignment +=1;
        }
    //    delete checkbox_done;
    //    delete refresh;
        db.close();
}

void fetch_reminders(QSqlDatabase& db,Ui::MainWindow& ui, QVBoxLayout& v_layout){
    if(!db.open()){
            qDebug("Unable to connect...");
        }
    else{
            qDebug("Connected Sunccessfully to the reminders database!!!");
            qDebug("Fetching the reminders Data...");
        }
    QSqlQuery *databaseQuery = new QSqlQuery(db);
    databaseQuery->exec("SELECT * FROM Reminders");
    ui.scrollArea_3->setWidgetResizable(true);
    ui.scrollArea_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    while(databaseQuery->next()){
        QWidget* widget = new QWidget();
        widget->setMaximumHeight(150);
        widget->setMinimumHeight(100);
        QVBoxLayout* vertical_l = new QVBoxLayout(widget);
        QLabel* title = new QLabel();
        QLabel* description = new QLabel();
//        QPushButton* delete_rem = new QPushButton("Delete");
//        delete_rem->setMaximumWidth(50);
//        delete_rem->setMinimumHeight(20);
//        delete_rem->setStyleSheet("background-color:#ff7e61;border-radius:10px;hover:{background-color:#ff513a}");
        title->setText(databaseQuery->value(1).toString());
        title->setStyleSheet("font:12pt");
        description->setText(databaseQuery->value(2).toString());
        vertical_l->addWidget(title);
        vertical_l->addWidget(description);
//        vertical_l->addWidget(delete_rem);
        v_layout.addWidget(widget);
        widget->setStyleSheet("background-color:#cfbbd4;border-radius:10px;");
        int print_id = databaseQuery->value(0).toInt();
        QString title_print = databaseQuery->value(1).toString();
        qDebug()<<"ID of reminder: "<<print_id;
        qDebug()<<"Reminder Title: "<<title_print;
    }
}


struct DayEvents {
    std::vector<QString> assignments;
    std::vector<QString> reminders;
    std::vector<QString> exams;
};

DayEvents selectedDay;
int totalAssignments = 0;

void return_assignment(QSqlDatabase& db,QDate date){
    selectedDay.assignments.clear();

    if(!db.open()){
            qDebug("Unable to connect...");
        }
    else{
            qDebug("Connected Sunccessfully");
        }
    QSqlQuery *databaseQuery = new QSqlQuery(db);
    try{
        qDebug()<<date.toString();
        if(!databaseQuery->exec("SELECT title FROM Assignment WHERE deadline='"+date.toString()+"'")) throw "Cannot Execute";
    }
    catch(const char* ex){
        qDebug()<<ex;
        return;
    }
    while(databaseQuery->next()){
        qDebug()<<databaseQuery->value(0).toString();
        selectedDay.assignments.push_back(databaseQuery->value(0).toString());
    }
    QSqlQuery *databaseQuery1 = new QSqlQuery(db);
    try{
        if(!databaseQuery1->exec("SELECT * FROM Assignment")) throw "Cannot Execute";
    }
    catch(const char* ex){
        qDebug()<<ex;
        return;
    }
    while(databaseQuery1->next()){
        totalAssignments +=1;
    }
}

void return_reminders(QSqlDatabase& db,QDate date){
    selectedDay.reminders.clear();

    if(!db.open()){
            qDebug("Unable to connect...");
        }
    else{
            qDebug("Connected Sunccessfully");
        }
    QSqlQuery *databaseQuery = new QSqlQuery(db);
    try{
        qDebug()<<date.toString();
        if(!databaseQuery->exec("SELECT title FROM Reminders WHERE deadline='"+date.toString()+"'")) throw "Cannot Execute";
    }
    catch(const char* ex){
        qDebug()<<ex;
        return;
    }
    while(databaseQuery->next()){
        qDebug()<<databaseQuery->value(0).toString();
        selectedDay.reminders.push_back(databaseQuery->value(0).toString());
    }
}

void return_exams(QSqlDatabase& db,QDate date){
    selectedDay.exams.clear();

    if(!db.open()){
            qDebug("Unable to connect...");
        }
    else{
            qDebug("Connected Sunccessfully");
        }
    QSqlQuery *databaseQuery = new QSqlQuery(db);
    try{
        qDebug()<<date.toString();
        if(!databaseQuery->exec("SELECT sub FROM Exams WHERE deadline='"+date.toString()+"'")) throw "Cannot Execute";
    }
    catch(const char* ex){
        qDebug()<<ex;
        return;
    }
    while(databaseQuery->next()){
        qDebug()<<databaseQuery->value(0).toString();
        selectedDay.exams.push_back(databaseQuery->value(0).toString());
    }
}

//void setText(Ui::eventsdialog& ui){
//    qDebug()<<assignment_title[0];
//    ui.eventlabel->setText(assignment_title[0]);
//}
