#ifndef INFOPLAYER_H
#define INFOPLAYER_H

#include <QDialog>
#include "player.h"
#include <QPixmap>

namespace Ui {
class InfoPlayer;
}

class InfoPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit InfoPlayer(QWidget *parent = 0,Player* p=0);
    void load(Player*);
    ~InfoPlayer();

private:
    Ui::InfoPlayer *ui;
    Player* player;
};

#endif // INFOPLAYER_H
