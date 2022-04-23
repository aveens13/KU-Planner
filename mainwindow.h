#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDateTime>
#include <QDate>
#include <stdexcept>
#include <QFileDialog>

#include "eventsdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//void assignment_database(QSqlDatabase& db);
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_getStarted_clicked();

    void on_dashBoard_clicked();

    void on_calendar_2_clicked();

    void on_assignments_clicked();

    void on_exams_clicked();

    void on_routine_clicked();

    void on_addTask_clicked();

    void on_continueButton_clicked();

    void on_submitButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_reminders_submit_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    eventsdialog *eventdialog;
    QDate *date;
    QString day;
    QString mResourceDir;

};

#endif // MAINWINDOW_H
