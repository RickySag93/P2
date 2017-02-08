#ifndef ADDGIOCATORE_H
#define ADDGIOCATORE_H

#include <QDialog>
#include <QMessageBox>
#include "player.h"
#include "controller.h"

namespace Ui {
class AddGiocatore;
}

class AddGiocatore : public QDialog
{
    Q_OBJECT

public:
    explicit AddGiocatore(QWidget *parent = 0,Controller* ctrl=0);
    void save(QString,Player*);
    void closeEvent(QCloseEvent* event);
    ~AddGiocatore();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::AddGiocatore *ui;
    Controller* ct;
};

#endif // ADDGIOCATORE_H
