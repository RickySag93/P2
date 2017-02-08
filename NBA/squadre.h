#ifndef SQUADRE_H
#define SQUADRE_H
#include "infoteam.h"
#include <QWidget>
#include <QListWidgetItem>
#include "controller.h"

namespace Ui {
class Squadre;
}

class Squadre : public QWidget
{
    Q_OBJECT

public:
    explicit Squadre(QWidget *parent = 0, Controller* ctrl=0);
    void showTeam();
    void closeEvent(QCloseEvent* event);
    ~Squadre();

private slots:
    void on_listEast_itemDoubleClicked(QListWidgetItem *item);

    void on_listWest_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::Squadre *ui;
    Controller* ct;
    InfoTeam* info;
};

#endif // SQUADRE_H
