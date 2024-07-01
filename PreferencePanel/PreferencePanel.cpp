#include "PreferencePanel.h"
#include "GeneralTab.h"
#include "ConnectionTab.h"
#include "AccountTab.h"
#include "DnsTab.h"
#include "FeedbackTab.h"
#include "AdvancedTab.h"
#include <QTabWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

PreferencePanel::PreferencePanel(int activeTabIndex, QWidget *parent) : QDialog(parent) {
    constructUi(activeTabIndex);
}

PreferencePanel::~PreferencePanel() {
    qDebug()<<"Preference Panel destructed.";
}

void PreferencePanel::constructUi(int activeTabIndex) {
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addStretch();

    QVBoxLayout *contentLayout = new QVBoxLayout();
    QTabWidget *tabWidget = new QTabWidget(this);

    // General
    QWidget *generalTabbar = new QWidget(tabWidget);
    tabWidget->addTab(generalTabbar, "General");
    GeneralTab *general = new GeneralTab(tabWidget);
    QVBoxLayout *generalLayout = new QVBoxLayout(generalTabbar);
    generalLayout->addWidget(general);
    

    // Connection
    QWidget *connectionTabbar = new QWidget(tabWidget);
    tabWidget->addTab(connectionTabbar, "Connection");
    ConnectionTab *connection = new ConnectionTab(tabWidget);
    QVBoxLayout *connectionLayout = new QVBoxLayout(connectionTabbar);
    connectionLayout->addWidget(connection);

    // Account
    QWidget *accountTabbar = new QWidget(tabWidget);
    tabWidget->addTab(accountTabbar, "Account");
    AccountTab *account = new AccountTab(tabWidget);
    QVBoxLayout *accountLayout = new QVBoxLayout(accountTabbar);
    accountLayout->addWidget(account);

    // DNS Logs
    QWidget *dnsTabbar = new QWidget(tabWidget);
    tabWidget->addTab(dnsTabbar, "DNS Logs");
    DnsTab *dns = new DnsTab(tabWidget);
    QVBoxLayout *dnsLayout = new QVBoxLayout(dnsTabbar);
    dnsLayout->addWidget(dns);

    // Feedback
    QWidget *feedbackTabbar = new QWidget(tabWidget);
    tabWidget->addTab(feedbackTabbar, "Feedback");
    FeedbackTab *feedback = new FeedbackTab(tabWidget);
    QVBoxLayout *feedbackLayout = new QVBoxLayout(feedbackTabbar);
    feedbackLayout->addWidget(feedback);
    
    // Advanced
    QWidget *advancedTabbar = new QWidget(tabWidget);
    tabWidget->addTab(advancedTabbar, "Advanced");
    AdvancedTab *advanced = new AdvancedTab(tabWidget);
    QVBoxLayout *advancedLayout = new QVBoxLayout(advancedTabbar);
    advancedLayout->addWidget(advanced);

    contentLayout->addWidget(tabWidget);

    // set active tab
    tabWidget->setCurrentIndex(activeTabIndex);
    mainLayout->addLayout(contentLayout);

    mainLayout->addStretch();
/*
    QGridLayout


    QLabel *label1 = new QLabel("Content of Tab 1", tab1);
    QPushButton *button1 = new QPushButton("Click Me", tab1);

    QVBoxLayout *layout1 = new QVBoxLayout(tab1);
    layout1->addWidget(label1);
    layout1->addWidget(button1);

    QWidget *tab2 = new QWidget();
    QLabel *label2 = new QLabel("Content of Tab 2", tab2);
    QPushButton *button2 = new QPushButton("Press Me", tab2);

    QVBoxLayout *layout2 = new QVBoxLayout(tab2);
    layout2->addWidget(label2);
    layout2->addWidget(button2);

    

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(tabWidget);

    setWindowTitle("QDialog with QTabWidget");
    */
}