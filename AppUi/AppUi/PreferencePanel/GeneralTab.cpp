#include "GeneralTab.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

GeneralTab::GeneralTab(QWidget *parent) : QWidget(parent) { 
    constructUi();
}

GeneralTab::~GeneralTab() {
    qDebug()<<"General Tab destructed.";
}

QFrame *GeneralTab::getSeparator() {
    QFrame *ret = nullptr;
    
    ret = new QFrame(this);
    ret->setFrameShape(QFrame::HLine);
    ret->setFrameShadow(QFrame::Sunken);

    return ret;
}

void GeneralTab::constructUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // connectivity
    QHBoxLayout *line = new QHBoxLayout();
    QGridLayout *grid = new QGridLayout();
    QLabel *text = new QLabel("Connectivity information", this);
    grid->addWidget(text, 0, 0, 1, 2);
    text = new QLabel("Connection:", this);
    grid->addWidget(text, 1, 0, Qt::AlignRight);
    text = new QLabel("WARP", this);
    grid->addWidget(text, 1, 1, Qt::AlignLeft);
    text = new QLabel("DNS protocol:", this);
    grid->addWidget(text, 2, 0, Qt::AlignRight);
    text = new QLabel("HTTPS", this);
    grid->addWidget(text, 2, 1, Qt::AlignLeft);
    text = new QLabel("Colocation center:", this);
    grid->addWidget(text, 3, 0, Qt::AlignRight);
    text = new QLabel("SEA", this);
    grid->addWidget(text, 3, 1, Qt::AlignLeft);
    
    // add a separator
    QFrame *separator = getSeparator();
    grid->addWidget(separator, 4, 0, 1, 2);

    // your device
    text = new QLabel("Your device", this);
    grid->addWidget(text, 5, 0);

    // connection type
    text = new QLabel("Connection type:", this);
    grid->addWidget(text, 6, 0, Qt::AlignRight);
    text = new QLabel("Ethernet", this);
    grid->addWidget(text, 6, 1, Qt::AlignLeft);

    // public ip
    text = new QLabel("Public IP:", this);
    grid->addWidget(text, 7, 0, Qt::AlignRight);
    text = new QLabel("fe80::985a:ebff:fe4d:9665", this);
    grid->addWidget(text, 7, 1, Qt::AlignLeft);

    // another separator
    separator = getSeparator();
    grid->addWidget(separator, 8, 0, 1, 2);

    text = new QLabel("Device ID:", this);
    grid->addWidget(text, 9, 0, Qt::AlignRight);
    text = new QLabel("02adb949-55b9-41b6-b555-7925c7a51523", this);
    grid->addWidget(text, 9, 1, Qt::AlignLeft);

    line->addLayout(grid);
    line->addStretch();
    mainLayout->addLayout(line);

    // auto login
    QVBoxLayout *col = new QVBoxLayout();
    col->addStretch();
    grid = new QGridLayout();
    QCheckBox *check = new QCheckBox("Launch at login", this);
    grid->addWidget(check, 0, 0, 1, 2);
    text = new QLabel("Automatically start Demo when you login to your Mac.", this);
    grid->addWidget(text, 1, 0);
    col->addLayout(grid);
    mainLayout->addLayout(col);

    // version info
    grid = new QGridLayout();
    text = new QLabel("Version 2023.11.4.0 (20231109.13)", this);
    grid->addWidget(text, 0, 0, Qt::AlignLeft);
    QPushButton *updates = new QPushButton("Check for Updates", this);
    //updates->setDefault(false);
    updates->setAutoDefault(false);
    grid->addWidget(updates, 0, 1, Qt::AlignRight);
    mainLayout->addLayout(grid);
}