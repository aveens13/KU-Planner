#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include "dashboard.h"
#include "assignment.h"
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

private:
    Ui::MainWindow *ui;
    Dialog *secdialog;
    Dashboard *dashboard;

};
#endif // MAINWINDOW_H
