#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T10:15:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NBA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    team.cpp \
    record.cpp \
    game.cpp \
    utente.cpp \
    squadre.cpp \
    data.cpp \
    controller.cpp \
    infoteam.cpp \
    login.cpp \
    registrazione.cpp \
    addgiocatore.cpp \
    giocatori.cpp \
    modifutente.cpp \
    infogame.cpp \
    infoplayer.cpp \
    utenteprem.cpp

HEADERS  += mainwindow.h \
    player.h \
    team.h \
    record.h \
    game.h \
    utente.h \
    squadre.h \
    data.h \
    controller.h \
    infoteam.h \
    login.h \
    registrazione.h \
    addgiocatore.h \
    giocatori.h \
    modifutente.h \
    infogame.h \
    infoplayer.h \
    utenteprem.h

FORMS    += mainwindow.ui \
    squadre.ui \
    infoteam.ui \
    login.ui \
    registrazione.ui \
    addgiocatore.ui \
    giocatori.ui \
    modifutente.ui \
    infogame.ui \
    infoplayer.ui

RESOURCES += \
    risorse.qrc
