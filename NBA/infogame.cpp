#include "infogame.h"
#include "ui_infogame.h"

InfoGame::InfoGame(QWidget *parent, Game *g, QString Hlogo, QString Alogo) :
    QDialog(parent),
    ui(new Ui::InfoGame)
{
    game=g;
    hlogo=Hlogo;
    alogo=Alogo;
    ui->setupUi(this);
    load();
}

void InfoGame::load()
{
    QString titolo=game->getAway()+" - "+game->getHome();
    setWindowTitle(titolo);
    ui->titolo->setText(titolo);
    ui->punteggio->setText(QString::number(game->getApts())+" - "+QString::number(game->getHpts()));
    ui->hreb->setText(QString::number(game->getHreb()));
    ui->areb->setText(QString::number(game->getAreb()));
    ui->hass->setText(QString::number(game->getHass()));
    ui->aass->setText(QString::number(game->getAass()));
    QPixmap hpix(hlogo);int hw=ui->hlogo->width();int hh=ui->hlogo->height();
    QPixmap apix(alogo);int w=ui->alogo->width();int h=ui->alogo->height();
    ui->hlogo->setPixmap(hpix.scaled(hw,hh,Qt::KeepAspectRatio));
    ui->alogo->setPixmap(apix.scaled(w,h,Qt::KeepAspectRatio));
    ui->hfg->setText(QString::number(game->getHfg()));
    ui->afg->setText(QString::number(game->getAfg()));
    ui->h3p->setText(QString::number(game->getH3p()));
    ui->a3p->setText(QString::number(game->getA3p()));
    ui->at1->setText(game->getAtab().at(0));
    ui->at2->setText(game->getAtab().at(1));
    ui->at3->setText(game->getAtab().at(2));
    ui->ht1->setText(game->getHtab().at(0));
    ui->ht2->setText(game->getHtab().at(1));
    ui->ht3->setText(game->getHtab().at(2));
}

void InfoGame::closeEvent(QCloseEvent *event)
{
    QDialog::closeEvent(event);
}

InfoGame::~InfoGame()
{
    delete ui;
}

void InfoGame::on_highlights_clicked()
{
    QUrl url(game->getLink());
    QDesktopServices::openUrl(url);
}
