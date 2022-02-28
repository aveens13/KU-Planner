#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include "assignment.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_addButton_clicked();

    void on_assignments_clicked();


private:
    Ui::Dashboard *ui;
    Assignment *assignment;
};

#endif // DASHBOARD_H
