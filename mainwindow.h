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

    void on_getStarted_clicked();

    void on_dashBoard_clicked();

    void on_calendar_2_clicked();

    void on_assignments_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
