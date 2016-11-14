/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QPushButton *storyButton;
    QPushButton *pbExit;
    QPushButton *pbHighscore;
    QPushButton *pbLoad;
    QPushButton *pbStart;
    QPushButton *pbControls;
    QWidget *widget_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 602);
        MainWindow->setWindowOpacity(1);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 800, 600));
        widget->setStyleSheet(QStringLiteral(""));
        storyButton = new QPushButton(widget);
        storyButton->setObjectName(QStringLiteral("storyButton"));
        storyButton->setGeometry(QRect(50, 10, 701, 151));
        storyButton->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/misadv.png"), QSize(), QIcon::Normal, QIcon::Off);
        storyButton->setIcon(icon);
        storyButton->setIconSize(QSize(650, 400));
        pbExit = new QPushButton(widget);
        pbExit->setObjectName(QStringLiteral("pbExit"));
        pbExit->setGeometry(QRect(310, 480, 191, 61));
        pbExit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbExit->setIcon(icon1);
        pbExit->setIconSize(QSize(160, 40));
        pbHighscore = new QPushButton(widget);
        pbHighscore->setObjectName(QStringLiteral("pbHighscore"));
        pbHighscore->setGeometry(QRect(270, 410, 271, 61));
        pbHighscore->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/Highscores.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbHighscore->setIcon(icon2);
        pbHighscore->setIconSize(QSize(250, 70));
        pbLoad = new QPushButton(widget);
        pbLoad->setObjectName(QStringLiteral("pbLoad"));
        pbLoad->setGeometry(QRect(310, 250, 191, 61));
        pbLoad->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/Load.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbLoad->setIcon(icon3);
        pbLoad->setIconSize(QSize(160, 40));
        pbStart = new QPushButton(widget);
        pbStart->setObjectName(QStringLiteral("pbStart"));
        pbStart->setGeometry(QRect(310, 170, 191, 61));
        pbStart->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/Start.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbStart->setIcon(icon4);
        pbStart->setIconSize(QSize(160, 40));
        pbControls = new QPushButton(widget);
        pbControls->setObjectName(QStringLiteral("pbControls"));
        pbControls->setGeometry(QRect(310, 340, 191, 61));
        pbControls->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/Help.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbControls->setIcon(icon5);
        pbControls->setIconSize(QSize(180, 50));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 800, 600));
        widget_2->setStyleSheet(QStringLiteral("image: url(:/images/images/landscape.png);"));
        pbControls->raise();
        pbHighscore->raise();
        widget_2->raise();
        storyButton->raise();
        pbExit->raise();
        pbHighscore->raise();
        pbLoad->raise();
        pbStart->raise();
        pbControls->raise();
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        storyButton->setText(QString());
        pbExit->setText(QString());
        pbHighscore->setText(QString());
        pbLoad->setText(QString());
        pbStart->setText(QString());
        pbControls->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
