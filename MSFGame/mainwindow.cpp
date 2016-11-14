#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mw = this->window();
    mw->setWindowTitle("Misadventures of SegFault");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbStart_clicked()
{
    Game *game = new Game();
    game->show();
    
    QMainWindow::close();
}

void MainWindow::on_pbLoad_clicked()
{
    Game *game = new Game();
    Universe::instance().Load();
    game->getPlayer()->updatePos();
    Universe::instance().getPlayer()->getScore()->Load();
    game->initialize(Universe::instance().getPlayer()->getCurrentWorld());
    game->player->getScore()->setScore(Universe::instance().getPlayer()->getScore());
    game->player->getScore()->updateScore();
    game->show();

    QMainWindow::close();
}

void MainWindow::on_pbControls_clicked()
{
    QMessageBox msg(mw);
    msg.setText("Controls: \n\n*Move - Arrow Keys \n*Melee Attack - Spacebar \n*Ranged Attack - Alt Key \n*Pause - Esc Key");
    msg.exec();
}

void MainWindow::on_pbHighscore_clicked()
{
    QMessageBox msg(mw);
    msg.setWindowTitle("HIGHSCORE");
    int highScore = Universe::instance().getPlayer()->getScore()->HighscoreLoad();
    msg.setText("\nYour All-Time Highscore: " + QString::number(highScore) + "\n");
    msg.exec();
}

void MainWindow::on_pbExit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_storyButton_clicked()
{
    QMessageBox msg(mw);
    msg.setText("STORY\n\n\nYou are SEGFAULT.\nYou have mysteriously found yourself on an island\nand you have no idea why.\nSomething drew you here… literally. It was probably a QtGraphics command.\nBut that’s beside the point.\n\nYou can tell there’s something evil in this map,\npartly because it’s a game and there has to be a protagonist.\nBut also because there’s annoying slimes trying to attack you.\nAnd the last time you checked\nmost of your jelly was not sentient.\n\nYou probably have several questions you want answered,\nlike “Why am I here?” and “What is my purpose?”\nand “Why do my fireballs look like tomatoes?” and “Wait, I have fireballs?!?”\nAdventure through this realm and find the answers you seek.\n\nBut beware…\n\n\nAll is not as it seems.\n\nDon’t worry though, It’s probably just a bug Mr J. put in.\nWait, who’s Mr. J??");
    msg.exec();
}
