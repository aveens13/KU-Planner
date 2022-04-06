#ifndef EVENTSDIALOG_H
#define EVENTSDIALOG_H

#include <QDialog>

namespace Ui {
class eventsdialog;
}

class eventsdialog : public QDialog
{
    Q_OBJECT

public:
    explicit eventsdialog(QWidget *parent = nullptr);
    ~eventsdialog();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::eventsdialog *ui;
};

#endif // EVENTSDIALOG_H
