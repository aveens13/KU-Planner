#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <stdexcept>
#include "ui_mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Dialog* deleteDialog;
    QSqlDatabase *db = new  QSqlDatabase;
    QString array[6] = {"Math","Physics","Programming","Environmental Engineering","Engineering Drawing","Chemistry"};;
};

#endif // DELETEDIALOG_H
