#include "AccountTab.h"
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

AccountTab::AccountTab(QWidget *parent) : QWidget(parent) { 
    constructUi();
}

AccountTab::~AccountTab() {
    qDebug()<<"Account Tab destructed.";
}

void AccountTab::constructUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // license
    QHBoxLayout *line = new QHBoxLayout();
    QLabel *text = new QLabel("License Key: ", this);
    line->addWidget(text);
    text = new QLabel("Kr6D2P91-6cw0IT27-n621qOG0", this);
    line->addWidget(text);
    line->addStretch();
    QPushButton *key = new QPushButton("Use Different Key", this);
    key->setAutoDefault(false);
    line->addWidget(key);
    mainLayout->addLayout(line);

    // devices
    QTableWidget *deviceList = new QTableWidget(this);
    deviceList->setRowCount(10);
    deviceList->setColumnCount(1);
    deviceList->setHorizontalHeaderLabels({"Devices using your license key"});
    for (int row = 0; row < 10; ++row) {
        text = new QLabel("\nmacOS\nMacmini7,1", this);
        deviceList->setCellWidget(row, 0, text);
        deviceList->setRowHeight(row, text->geometry().height());
    }
    deviceList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    deviceList->verticalHeader()->setVisible(false);
    mainLayout->addWidget(deviceList);

    // login button
    line = new QHBoxLayout();
    QPushButton *login = new QPushButton("Login to Demo", this);
    login->setAutoDefault(false);
    line->addStretch();
    line->addWidget(login);
    mainLayout->addLayout(line);
}