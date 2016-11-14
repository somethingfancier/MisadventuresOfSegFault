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
    msg.setText("Highscore: " + QString::number(highScore));
    msg.exec();
}

void MainWindow::on_pbExit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_storyButton_clicked()
{
    QMessageBox msg(mw);
    msg.setText("Story: YOU ARE SEGFAULT. YOU HAVE BEEN BANISHED TO A FORSAKEN REALM AND MUST COLLECT THE MISSING HEADER FILES TO ESCAPE BACK TO REALITY. GOOD LUCK.");
    msg.exec();
}
