/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionQuit;
    QAction *actionPort0;
    QAction *actionPort1;
    QAction *actionPort2;
    QAction *actionTempReader;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabAcquire;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonAcquire;
    QPushButton *pushButtonClear;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QLCDNumber *lcdNumber;
    QWidget *tabPlot;
    QPushButton *pushButtonPlot;
    QCustomPlot *widgetPlot;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuConnect;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(479, 377);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionPort0 = new QAction(MainWindow);
        actionPort0->setObjectName(QStringLiteral("actionPort0"));
        actionPort0->setCheckable(true);
        actionPort1 = new QAction(MainWindow);
        actionPort1->setObjectName(QStringLiteral("actionPort1"));
        actionPort1->setCheckable(true);
        actionPort2 = new QAction(MainWindow);
        actionPort2->setObjectName(QStringLiteral("actionPort2"));
        actionPort2->setCheckable(true);
        actionTempReader = new QAction(MainWindow);
        actionTempReader->setObjectName(QStringLiteral("actionTempReader"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 20, 421, 281));
        tabWidget->setTabPosition(QTabWidget::North);
        tabAcquire = new QWidget();
        tabAcquire->setObjectName(QStringLiteral("tabAcquire"));
        layoutWidget = new QWidget(tabAcquire);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 40, 97, 124));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonAcquire = new QPushButton(layoutWidget);
        pushButtonAcquire->setObjectName(QStringLiteral("pushButtonAcquire"));

        verticalLayout_3->addWidget(pushButtonAcquire);

        pushButtonClear = new QPushButton(layoutWidget);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));

        verticalLayout_3->addWidget(pushButtonClear);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        textBrowser = new QTextBrowser(tabAcquire);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(150, 50, 111, 121));
        lcdNumber = new QLCDNumber(tabAcquire);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(270, 50, 121, 121));
        tabWidget->addTab(tabAcquire, QString());
        tabPlot = new QWidget();
        tabPlot->setObjectName(QStringLiteral("tabPlot"));
        pushButtonPlot = new QPushButton(tabPlot);
        pushButtonPlot->setObjectName(QStringLiteral("pushButtonPlot"));
        pushButtonPlot->setGeometry(QRect(30, 10, 89, 25));
        widgetPlot = new QCustomPlot(tabPlot);
        widgetPlot->setObjectName(QStringLiteral("widgetPlot"));
        widgetPlot->setGeometry(QRect(30, 50, 351, 181));
        tabWidget->addTab(tabPlot, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 479, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuConnect = new QMenu(menuBar);
        menuConnect->setObjectName(QStringLiteral("menuConnect"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font;
        font.setPointSize(8);
        statusBar->setFont(font);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConnect->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionQuit);
        menuConnect->addAction(actionPort0);
        menuConnect->addAction(actionPort1);
        menuConnect->addAction(actionPort2);
        menuAbout->addAction(actionTempReader);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSave_As);
        mainToolBar->addAction(actionQuit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Qt Arduino Input Output", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Alt+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Alt+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Alt+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionPort0->setText(QApplication::translate("MainWindow", "/dev/ACM0", nullptr));
        actionPort1->setText(QApplication::translate("MainWindow", "/dev/ACM1", nullptr));
        actionPort2->setText(QApplication::translate("MainWindow", "/dev/ACM2", nullptr));
        actionTempReader->setText(QApplication::translate("MainWindow", "AboutTempReader", nullptr));
        pushButtonAcquire->setText(QApplication::translate("MainWindow", "Acquire", nullptr));
        pushButtonClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "ON LED", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAcquire), QApplication::translate("MainWindow", "Acquire", nullptr));
        pushButtonPlot->setText(QApplication::translate("MainWindow", "Plot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPlot), QApplication::translate("MainWindow", "Plot", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuConnect->setTitle(QApplication::translate("MainWindow", "Connect", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
