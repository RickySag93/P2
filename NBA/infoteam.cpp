#include "infoteam.h"
#include "ui_infoteam.h"

InfoTeam::InfoTeam(QWidget *parent, Team *t) :
    QWidget(parent),
    ui(new Ui::InfoTeam)
{
    team=t;
    ui->setupUi(this);
    load(team);
}

void InfoTeam::load(Team *t)
{
    setWindowTitle(t->getCity()+" "+t->getNome());
    ui->nome->setText(t->getCity()+" "+t->getNome());
    QPixmap pix(t->getLogo()); int w=ui->foto->width();int h=ui->foto->height();
    ui->foto->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->arena->setText(t->getArena());
    ui->coach->setText(t->getCoach());
    ui->fondazione->setText(QString::number(t->getFondaz()));
    ui->record->setText(t->getRecord().getWin()+" - "+t->getRecord().getLose());
}

InfoTeam::~InfoTeam()
{
    delete ui;
}

