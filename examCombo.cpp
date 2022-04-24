#include "examCombo.h"

void fetch_Physics(QComboBox& cb){
    qDebug("Index Physics Fetching!!!");
    for(int index = 0 ; index < 100 ; index ++){
        cb.removeItem(index);
    }
    cb.addItem("PHYS 102");
    cb.addItem("PHYS 101");
    cb.addItem("PHYS 105");
}

void fetch_Chemistry(QComboBox& cb){
    qDebug("Index Chemistry Fetching!!!");
    for(int index = 0 ; index < 20 ; index ++){
        cb.removeItem(index);
    }
    cb.addItem("CHEM 101");
    cb.addItem("CHEM 104");
    cb.addItem("CHEM 203");
}

void fetch_Math(QComboBox& cb){
    qDebug("Index Math Fetching!!!");
    for(int index = 0 ; index < 20 ; index ++){
        cb.removeItem(index);
    }
    cb.addItem("MATH 101");
    cb.addItem("MATH 201");
    cb.addItem("MATH 204");
}

void fetch_Programming(QComboBox& cb){
    qDebug("Index Comp Fetching!!!");
    for(int index = 0 ; index < 20 ; index ++){
        cb.removeItem(index);
    }
    cb.addItem("COMP 102");
    cb.addItem("COMP 116");
    cb.addItem("COMP 203");
}

void fetch_drawing(QComboBox& cb){
    qDebug("Index drawing Fetching!!!");
    for(int index = 0 ; index < 20 ; index ++){
        cb.removeItem(index);
    }
    cb.addItem("EDRG 101");
    cb.addItem("EDRG 102");
}

void fetch_environment(QComboBox& cb){
    qDebug("Index Environment Fetching!!!");
    for(int index = 0 ; index < 20 ; index ++){
        cb.removeItem(index);
    }
    cb.addItem("ENVE 101");
    cb.addItem("ENVE 102");
}

