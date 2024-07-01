#include "ConnectionTab.h"
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

ConnectionTab::ConnectionTab(QWidget *parent) : QWidget(parent) { 
    constructUi();
}

ConnectionTab::~ConnectionTab() {
    qDebug()<<"Connection Tab destructed.";
}

void ConnectionTab::constructUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *text = new QLabel("Demo will pause when connected to one of these Wi-Fi networks.", this);
    mainLayout->addWidget(text);

	// WIFI list
    QTableWidget *wifiList = new QTableWidget(this);
    wifiList->setRowCount(10);
    wifiList->setColumnCount(1);
    wifiList->setHorizontalHeaderLabels({"Network name"});
    for (int row = 0; row < 10; ++row) {
        QTableWidgetItem *item = new QTableWidgetItem(QString("WIFI-%1").arg(row + 1));
        wifiList->setItem(row, 0, item);
    }
    wifiList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    wifiList->verticalHeader()->setVisible(false);
    mainLayout->addWidget(wifiList);

    // + - buttons
    QHBoxLayout *buttons = new QHBoxLayout();
    QPushButton *button = new QPushButton("+", this);
    button->setAutoDefault(false);
    /*button->setStyleSheet("QPushButton {"
                          "    background-color: lightblue;"
                          "    border-top-left-radius: 10px;"
                          "    border-bottom-left-radius: 10px;"
                          "    border-top-right-radius: 0px;"
                          "    border-bottom-right-radius: 0px;"
                          "}"
                          );*/

    buttons->addWidget(button);
    button = new QPushButton("-", this);
    button->setAutoDefault(false);
    buttons->addWidget(button);
    /*button->setStyleSheet("QPushButton {"
                          "    background-color: lightblue;"
                          "    color: white;"
                          "    border-top-left-radius: 0px;"
                          "    border-bottom-left-radius: 0px;"
                          "    border-top-right-radius: 10px;"
                          "    border-bottom-right-radius: 10px;"
                          "}"
                          );*/
    buttons->addStretch();
    mainLayout->addLayout(buttons);

    // checkboxes
    QCheckBox *check = new QCheckBox("Disable for all Wi-Fi networks", this);
    mainLayout->addWidget(check);
    check = new QCheckBox("Disable for all wired networks", this);
    mainLayout->addWidget(check);

    // grid
    // dns
    QHBoxLayout *line = new QHBoxLayout();
    QGridLayout *grid = new QGridLayout();
    text = new QLabel("DNS Protocol:", this);
    grid->addWidget(text, 0, 0, Qt::AlignRight);
    QComboBox *combo = new QComboBox(this);
    combo->addItem("HTTPS");
    combo->addItem("WARP");
    combo->addItem("TLS");
    grid->addWidget(combo, 0, 1, Qt::AlignLeft);

    // 1.1.1.1 for families
    text = new QLabel("1.1.1.1 for Families:", this);
    grid->addWidget(text, 1, 0, Qt::AlignRight);
    combo = new QComboBox(this);
    combo->addItem("None");
    combo->addItem("Block Malware");
    combo->addItem("Block Malware and Adult Content");
    grid->addWidget(combo, 1, 1, Qt::AlignLeft);

    // subdomain
    text = new QLabel("Gateway DoH subdomain:", this);
    grid->addWidget(text, 2, 0, Qt::AlignRight);
    QHBoxLayout *subdomain = new QHBoxLayout();
    text = new QLabel("None", this);
    subdomain->addWidget(text);
    subdomain->addStretch();
    button = new QPushButton("Change", this);
    button->setAutoDefault(false);
    subdomain->addWidget(button);
    grid->addLayout(subdomain, 2, 1, Qt::AlignLeft);

    // reset buttons
    button = new QPushButton("Reset Encryption Keys", this);
    button->setAutoDefault(false);
    grid->addWidget(button, 3, 0, Qt::AlignLeft);
    button = new QPushButton("Reset All Settings", this);
    button->setAutoDefault(false);
    grid->addWidget(button, 3, 1, Qt::AlignLeft);

    line->addLayout(grid);
    line->addStretch();
    mainLayout->addLayout(line);
}