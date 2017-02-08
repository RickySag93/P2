#ifndef MODIFUTENTE_H
#define MODIFUTENTE_H

#include <QDialog>
#include <QListWidgetItem>
#include <QMessageBox>
#include "controller.h"

namespace Ui {
class ModifUtente;
}

class ModifUtente : public QDialog
{
    Q_OBJECT

public:
    explicit ModifUtente(QWidget *parent = 0,Controller* ctrl=0);
    void showUtenti();
    void save(QString);
    void saveWithout(QString,int);
    void closeEvent(QCloseEvent* event);
    ~ModifUtente();

private slots:

    void on_listUtenti_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_elimina_clicked();

private:
    Ui::ModifUtente *ui;
    Controller* ct;
    Utente* utente;
};

#endif // MODIFUTENTE_H
