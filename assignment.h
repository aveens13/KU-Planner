#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <QMainWindow>

namespace Ui {
class Assignment;
}

class Assignment : public QMainWindow
{
    Q_OBJECT

public:
    explicit Assignment(QWidget *parent = nullptr);
    ~Assignment();

private:
    Ui::Assignment *ui;
};

#endif // ASSIGNMENT_H
