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
    QPushButton *pbExit;
    QPushButton *pbControls;
    QPushButton *pbLoad;
    QPushButton *pbStart;
    QPushButton *pushButton;
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
        pbExit = new QPushButton(widget);
        pbExit->setObjectName(QStringLiteral("pbExit"));
        pbExit->setGeometry(QRect(310, 490, 191, 61));
        pbExit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbExit->setIcon(icon);
        pbExit->setIconSize(QSize(160, 40));
        pbControls = new QPushButton(widget);
        pbControls->setObjectName(QStringLiteral("pbControls"));
        pbControls->setGeometry(QRect(310, 400, 191, 61));
        pbControls->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/Controls.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbControls->setIcon(icon1);
        pbControls->setIconSize(QSize(160, 50));
        pbLoad = new QPushButton(widget);
        pbLoad->setObjectName(QStringLiteral("pbLoad"));
        pbLoad->setGeometry(QRect(310, 310, 191, 61));
        pbLoad->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/Load.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbLoad->setIcon(icon2);
        pbLoad->setIconSize(QSize(160, 40));
        pbStart = new QPushButton(widget);
        pbStart->setObjectName(QStringLiteral("pbStart"));
        pbStart->setGeometry(QRect(310, 220, 191, 61));
        pbStart->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/Start.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbStart->setIcon(icon3);
        pbStart->setIconSize(QSize(160, 40));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 10, 701, 191));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/misadv.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);
        pushButton->setIconSize(QSize(650, 400));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 800, 600));
        widget_2->setStyleSheet(QStringLiteral("image: url(:/images/images/landscape.png);"));
        widget_2->raise();
        pbExit->raise();
        pbControls->raise();
        pbLoad->raise();
        pbStart->raise();
        pushButton->raise();
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pbExit->setText(QString());
        pbControls->setText(QString());
        pbLoad->setText(QString());
        pbStart->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
