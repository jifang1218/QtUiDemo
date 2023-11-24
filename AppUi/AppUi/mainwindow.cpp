#include "mainwindow.h"
#include "MainPanel.h"
#include <QApplication>
#include <QCloseEvent>
#include <QDebug>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) 
{
    QIcon icon(":1.png");
    sysIcon = new QSystemTrayIcon(this);
    sysIcon->setIcon(icon);
    sysIcon->setToolTip("Qt systray");
    
    /*
    min = new QAction("minimize", this);
    connect(min, &QAction::triggered, this, &MainWindow::hide);
    max = new QAction("maximize", this);
    connect(max, &QAction::triggered, this, &MainWindow::showMaximized);
    restore = new QAction("restore", this);
    connect(restore, &QAction::triggered, this, &MainWindow::showNormal);
    quit = new QAction("quit", this);
    connect(quit, &QAction::triggered, this, &QApplication::quit);*/

    connect(sysIcon, &QSystemTrayIcon::activated, this, &MainWindow::on_activatedSysTrayIcon);

    /*menu = new QMenu(this);
    menu->addAction(min);
    menu->addAction(max);
    menu->addAction(restore);
    menu->addSeparator();
    menu->addAction(quit);
    sysIcon->setContextMenu(menu);*/
    sysIcon->show();

    // hide itself
    hide();
    showMainPanel();
}

MainWindow::~MainWindow()
{
}

void MainWindow::toggleMainPanel() {
    if (mainPanel == nullptr || !mainPanel->isVisible()) {
        showMainPanel();
    } else {
        hideMainPanel();
    }
}

void MainWindow::showMainPanel() {
    if (mainPanel == nullptr) {
        mainPanel = new MainPanel();
    } 
    
    if (!mainPanel->isVisible()) {
        // QRect bound = sysIcon->geometry();
        // QPoint pos = mapToGlobal(bound.bottomLeft());
        // mainPanel->move(pos.x() - mainPanel->size().width()/2, pos.y());
        mainPanel->show();
    }
}

void MainWindow::hideMainPanel() {
    if (mainPanel != nullptr && mainPanel->isVisible()) {
        mainPanel->hide();
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (this->isVisible()) {
        this->hide();
        sysIcon->showMessage("qt systray", "close window");
        qDebug()<<"close main window";
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason) {
    switch (reason) {
        case QSystemTrayIcon::Trigger: {
            qDebug()<<"reason: trigger";
            toggleMainPanel();
        } break;
        case QSystemTrayIcon::DoubleClick: {
            qDebug()<<"reason: double click";
        } break;
        default: {
            qDebug()<<"reason: "<<reason;
        }
    }
}