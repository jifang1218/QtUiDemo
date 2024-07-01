#include "AdvancedTab.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QDebug>

AdvancedTab::AdvancedTab(QWidget *parent) : QWidget(parent) { 
    constructUi();
}

AdvancedTab::~AdvancedTab() {
    qDebug()<<"Advanced Tab destructed.";
}

void AdvancedTab::constructUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *line = new QHBoxLayout();
    // grid
    // statistics
    QGridLayout *grid = new QGridLayout();
    QLabel *text = new QLabel("Statistics", this);
    grid->addWidget(text, 0, 0, 1, 2);
    
    // data received
    text = new QLabel("Data received: ", this);
    grid->addWidget(text, 1, 0, Qt::AlignRight);
    text = new QLabel("888 KB", this);
    grid->addWidget(text, 1, 1, Qt::AlignLeft);
    
    // data sent
    text = new QLabel("Data sent: ", this);
    grid->addWidget(text, 2, 0, Qt::AlignRight);
    text = new QLabel("888 KB", this);
    grid->addWidget(text, 2, 1, Qt::AlignLeft);

    // latest handshake
    text = new QLabel("Latest handshake: ", this);
    grid->addWidget(text, 3, 0, Qt::AlignRight);
    text = new QLabel("2023-11-20, 16:52:33", this);
    grid->addWidget(text, 3, 1, Qt::AlignLeft);

    // latency
    text = new QLabel("Estimated latency: ", this);
    grid->addWidget(text, 4, 0, Qt::AlignRight);
    text = new QLabel("20 ms", this);
    grid->addWidget(text, 4, 1, Qt::AlignLeft);

    // loss
    text = new QLabel("Estimated loss: ", this);
    grid->addWidget(text, 5, 0, Qt::AlignRight);
    text = new QLabel("0.00%", this);
    grid->addWidget(text, 5, 1, Qt::AlignLeft);

    line->addLayout(grid);
    line->addStretch();
    mainLayout->addLayout(line);

    // split tunnel
    line = new QHBoxLayout();
    QPlainTextEdit *edit = new QPlainTextEdit("Exclude an IP address, or range of IP addresses, or domain from Demo tunnel. This is useful for apps that do not work well with tunneled network connections.", this);
    edit->setReadOnly(true);
    line->addWidget(edit);
    QPushButton *button = new QPushButton("Split Tunnel", this);
    button->setAutoDefault(false);
    line->addWidget(button);
    mainLayout->addLayout(line);

    // local domain fallback
    line = new QHBoxLayout();
    edit = new QPlainTextEdit("Use Local Domain Fallback to instruct WARP Client to ignore DNS requests to a given list of domain suffixes. These DNS requests will be passed back to DNS servers configured on existing network interfaces on the device.", this);
    edit->setReadOnly(true);
    line->addWidget(edit);
    button = new QPushButton("Local Domain Fallback", this);
    button->setAutoDefault(false);
    line->addWidget(button);
    mainLayout->addLayout(line);

    // configure proxy
    line = new QHBoxLayout();
    edit = new QPlainTextEdit("Proxy mode enables a local proxy server on your device. All traffic directed through localhost:{port} is encrypted using secure WARP tunnel connection. This is useful to securely tunnel traffic from a particular application on your device by simply configuring SOCKS or HTTPS proxy settings for the application or OS.", this);
    edit->setReadOnly(true);
    line->addWidget(edit);
    button = new QPushButton("Configure Proxy", this);
    button->setAutoDefault(false);
    line->addWidget(button);
    mainLayout->addLayout(line);

    mainLayout->addStretch();

    // checkbox
    QCheckBox *check = new QCheckBox("Yes, I want to participate in the beta program", this);
    mainLayout->addWidget(check);
    edit = new QPlainTextEdit("Participate in the beta and help shape the future of the Demo application. \nPlease note, to stop participating in the beta please uninstall this application manually and re-download from our website. ", this);
    edit->setReadOnly(true);
    mainLayout->addWidget(edit);
}