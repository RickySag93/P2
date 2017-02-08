#ifndef INFOGAME_H
#define INFOGAME_H

#include <QDialog>
#include <QPixmap>
#include <QDebug>
#include <QUrl>
#include <QDesktopServices>
#include "game.h"

namespace Ui {
class InfoGame;
}

class InfoGame : public QDialog
{
    Q_OBJECT

public:
    explicit InfoGame(QWidget *parent = 0, Game* g=0,QString Hlogo="",QString Alogo="");
    void load();
    void closeEvent(QCloseEvent* event);
    ~InfoGame();

private slots:
    void on_highlights_clicked();

private:
    Ui::InfoGame *ui;
    Game* game;
    QString hlogo,alogo;
};

#endif // INFOGAME_H
