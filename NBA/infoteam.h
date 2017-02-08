#ifndef INFOTEAM_H
#define INFOTEAM_H
#include "team.h"
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QLabel>
#include <QPixmap>
#include "record.h"
namespace Ui {
class InfoTeam;
}

class InfoTeam : public QWidget
{
    Q_OBJECT

public:
    explicit InfoTeam(QWidget *parent = 0,  Team* t=0);
    void load( Team* t);
    ~InfoTeam();

private slots:

private:
    Ui::InfoTeam *ui;
    Team* team;
};

#endif // INFOTEAM_H
