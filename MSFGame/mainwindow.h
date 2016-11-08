#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

static QWidget* mw;

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_pbStart_clicked();

    void on_pbLoad_clicked();

    void on_pbControls_clicked();

    void on_pbHighscore_clicked();

    void on_pbExit_clicked();

    void on_storyButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
