#include "DnsTab.h"
#include <QCheckBox>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QDebug>

DnsTab::DnsTab(QWidget *parent) : QWidget(parent) { 
    constructUi();
}

DnsTab::~DnsTab() {
    qDebug()<<"DNS Tab destructed.";
}

void DnsTab::constructUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QCheckBox *logDns = new QCheckBox("Log DNS queries", this);
    mainLayout->addWidget(logDns);

    // query table
    QTableWidget *queryList = new QTableWidget(this);
    queryList->setRowCount(10);
    queryList->setColumnCount(5);
    QStringList headerLabels;
    headerLabels << "Time" << "Questions" << "Answers" << "Resolver" << "Resolving time";
    queryList->setHorizontalHeaderLabels(headerLabels);
    queryList->verticalHeader()->setVisible(false);
    mainLayout->addWidget(queryList);
}