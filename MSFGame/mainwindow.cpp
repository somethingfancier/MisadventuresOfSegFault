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
    //game->load();
    game->show();

    QMainWindow::close();
}

void MainWindow::on_pbControls_clicked()
{
    QMessageBox msg(mw);
    msg.setText("Controls: \n\n*Move - Arrow Keys \n*Melee Attack - Spacebar \n*Ranged Attack - Alt Key \n*Pause - Esc Key");
    msg.exec();
}

void MainWindow::on_pbExit_clicked()
{
    QApplication::quit();
}
