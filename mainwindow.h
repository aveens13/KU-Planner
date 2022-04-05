#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDateTime>
#include <QDate>
#include <stdexcept>

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

private:
    Ui::MainWindow *ui;
    QDate *date;
    QString day;

};

#endif // MAINWINDOW_H
