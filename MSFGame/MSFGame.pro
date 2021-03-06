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
    worldchar.cpp \
    worlditem.cpp \
    worldnpc.cpp \
    worldenemy.cpp \
    worldobject.cpp \
    worldobstacle.cpp \
    worldplayer.cpp \
    enemy.cpp \
    score.cpp \
    highscore.cpp\
    worldscore.cpp\
    magic.cpp \
    item.cpp \
    obstacle.cpp \
    lives.cpp \
    worldlives.cpp \
    health.cpp \
    worldhealth.cpp \
    npc.cpp \
    boss.cpp


HEADERS  += mainwindow.h \
    game.h \
    player.h \
    universe.h \
    world.h \
    worldchar.h \
    score.h \
    worldenemy.h \
    worlditem.h \
    worldnpc.h \
    worldobstacle.h \
    worldobject.h \
    worldplayer.h \
    enemy.h \
    worldscore.h\
    highscore.h\
    magic.h \
    item.h \
    obstacle.h \
    lives.h \
    worldlives.h \
    health.h \
    worldhealth.h \
    npc.h \
    boss.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

QMAKE_CXXFLAGS += -std=c++0x
