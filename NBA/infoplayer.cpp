#include "infoplayer.h"
#include "ui_infoplayer.h"


InfoPlayer::InfoPlayer(QWidget *parent, Player *p) :
    QDialog(parent),
    ui(new Ui::InfoPlayer)
{
    player=p;
    ui->setupUi(this);
    load(player);
}

void InfoPlayer::load(Player *player)
{
    setWindowTitle(player->getNome()+" "+player->getCognome());
    ui->nome->setText(player->getNome()+" "+player->getCognome());
    QPixmap pix(player->getFoto()); int w=ui->foto->width(); int h=ui->foto->height();
    ui->foto->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->birthday->setText("Data di nascita: "+QString::number(player->getBirthday().day())+"/"+QString::number(player->getBirthday().month())+"/"+QString::number(player->getBirthday().year()));
    ui->maxpts->setText(QString::number(player->getMaxPts()));
    ui->maxreb->setText(QString::number(player->getMaxReb()));
    ui->maxass->setText(QString::number(player->getMaxAss()));
    ui->seaspts->setText(QString::number(player->getSeasPts()));
    ui->seasreb->setText(QString::number(player->getSeasReb()));
    ui->seasass->setText(QString::number(player->getSeasAss()));
}

InfoPlayer::~InfoPlayer()
{
    delete ui;
}
