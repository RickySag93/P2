#ifndef REGISTRAZIONE_H
#define REGISTRAZIONE_H

#include <QDialog>
#include "controller.h"
#include <QString>
#include <QMessageBox>

namespace Ui {
class Registrazione;
}

class Registrazione : public QDialog
{
    Q_OBJECT

public:
    explicit Registrazione(QWidget *parent = 0,Controller* ctrl=0);
    void save(QString path, Utente *u);
    void closeEvent(QCloseEvent* event);
    ~Registrazione();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Registrazione *ui;
    Controller* ct;
};

#endif // REGISTRAZIONE_H
