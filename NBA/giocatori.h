#ifndef GIOCATORI_H
#define GIOCATORI_H

#include <QDialog>
#include <QListWidgetItem>
#include "controller.h"
#include "player.h"
#include "infoplayer.h"

namespace Ui {
class Giocatori;
}

class Giocatori : public QDialog
{
    Q_OBJECT

public:
    explicit Giocatori(QWidget *parent = 0,Controller* ctrl=0);
    void showPlayers();
    void closeEvent(QCloseEvent *event);
    ~Giocatori();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_listGiocatori_itemDoubleClicked(QListWidgetItem *item);


    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Giocatori *ui;
    Controller* ct;
    InfoPlayer* infopl;
};

#endif // GIOCATORI_H
