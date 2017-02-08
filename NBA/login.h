#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QMenu>
#include "controller.h"


namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0,QMenu* main=0, Controller* ctr=0);
    void closeEvent(QCloseEvent* event);
    ~Login();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();


private:
    Ui::Login *ui;
    Controller* ct;
    QMenu* mainw;
};

#endif // LOGIN_H
