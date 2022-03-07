#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_getstarted_clicked();

    void on_calendar_clicked();

    void on_quiz_clicked();

    void on_assignments_clicked();

    void on_exams_clicked();

    void on_routine_clicked();

    void on_dashboard_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
