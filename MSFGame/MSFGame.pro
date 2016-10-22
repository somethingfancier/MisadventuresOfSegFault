#-------------------------------------------------
#
# Project created by QtCreator 2016-10-19T14:38:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MSFGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    player.cpp \
    universe.cpp \
    world.cpp \
    item.cpp \
    worldchar.cpp \
    score.cpp \
    enemy.cpp \
    npc.cpp

HEADERS  += mainwindow.h \
    game.h \
    player.h \
    universe.h \
    world.h \
    item.h \
    worldchar.h \
    score.h \
    enemy.h \
    npc.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
