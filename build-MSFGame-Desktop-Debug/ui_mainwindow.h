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
    QPushButton *pbLoad;
    QPushButton *pbControls;
    QPushButton *pbStart;
    QPushButton *pbExit;
    QWidget *widget;

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
        pbLoad = new QPushButton(centralWidget);
        pbLoad->setObjectName(QStringLiteral("pbLoad"));
        pbLoad->setGeometry(QRect(310, 210, 191, 61));
        pbLoad->setStyleSheet(QStringLiteral("background-color: rgb(15, 5, 5);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/Load.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbLoad->setIcon(icon);
        pbLoad->setIconSize(QSize(160, 40));
        pbControls = new QPushButton(centralWidget);
        pbControls->setObjectName(QStringLiteral("pbControls"));
        pbControls->setGeometry(QRect(310, 300, 191, 61));
        pbControls->setStyleSheet(QStringLiteral("background-color: rgb(6, 6, 6);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/Controls.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbControls->setIcon(icon1);
        pbControls->setIconSize(QSize(160, 50));
        pbStart = new QPushButton(centralWidget);
        pbStart->setObjectName(QStringLiteral("pbStart"));
        pbStart->setGeometry(QRect(310, 120, 191, 61));
        pbStart->setStyleSheet(QStringLiteral("background-color: rgb(5, 2, 2);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/Start.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbStart->setIcon(icon2);
        pbStart->setIconSize(QSize(160, 40));
        pbExit = new QPushButton(centralWidget);
        pbExit->setObjectName(QStringLiteral("pbExit"));
        pbExit->setGeometry(QRect(310, 390, 191, 61));
        pbExit->setStyleSheet(QStringLiteral("background-color: rgb(6, 6, 6);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbExit->setIcon(icon3);
        pbExit->setIconSize(QSize(160, 40));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 800, 600));
        widget->setStyleSheet(QStringLiteral("image: url(:/images/images/color.jpg);"));
        MainWindow->setCentralWidget(centralWidget);
        widget->raise();
        pbLoad->raise();
        pbControls->raise();
        pbStart->raise();
        pbExit->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pbLoad->setText(QString());
        pbControls->setText(QString());
        pbStart->setText(QString());
        pbExit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
