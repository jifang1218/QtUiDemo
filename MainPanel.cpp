#include "MainPanel.h"
#include "widgets/SwitchButton.h"
#include "widgets/SettingsMenu.h"
#include "PreferencePanel/PreferencePanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QCloseEvent>
#include <QGuiApplication>
#include <QScreen>

MainPanel::MainPanel(QWidget *parent)
    : QWidget(parent)
{
    // setAttribute(Qt::WA_TranslucentBackground);
    constructUi();
}

MainPanel::~MainPanel() {
    
}

QSize MainPanel::sizeHint() const {
    return QSize(300, 400);
}

void MainPanel::constructUi() {
    // the overall layout
    QVBoxLayout *vbox = new QVBoxLayout(this);

    // 1st row
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setSizeConstraint(QLayout::SetMinimumSize);
    QLabel *label = new QLabel("Demo\nby Fang", this);
    hbox->addWidget(label);
    hbox->addStretch();

    QIcon feedbackIcon = QIcon(":1.png");
    QPushButton *feedbackBtn = new QPushButton(feedbackIcon, "", this);
    connect(feedbackBtn, &QPushButton::pressed, this, &MainPanel::sendFeedback);
    hbox->addWidget(feedbackBtn);

    QIcon settingsIcon = QIcon(":1.png");
    QPushButton *settingsBtn = new QPushButton(settingsIcon, "", this);
    connect(settingsBtn, &QPushButton::pressed, this, &MainPanel::showMenu);
    hbox->addWidget(settingsBtn);

    vbox->addLayout(hbox);

    // 2nd row
    QVBoxLayout *innerVBox = new QVBoxLayout();
    innerVBox->setAlignment(Qt::AlignHCenter);

    // demo
    innerVBox->addStretch();
    QLabel *lbl = new QLabel("DEMO", this);
    lbl->setAlignment(Qt::AlignHCenter);
    innerVBox->addWidget(lbl);
    
    // switch button
    SwitchButton *connectBtn = new SwitchButton(this);
    connectBtn->setValue(isConnected);
    connect(connectBtn, &SwitchButton::valueChanged, this, &MainPanel::ConnectButtonChanged);
    innerVBox->addWidget(connectBtn, 1, Qt::AlignHCenter);

    // connected/disconnected.
    connStatus = new QLabel("Disconnected", this);
    connStatus->setAlignment(Qt::AlignHCenter);
    innerVBox->addWidget(connStatus);

    // status bar
    connDesc = new QLabel("Your Internet is unsecured.");
    connDesc->setAlignment(Qt::AlignHCenter);
    innerVBox->addWidget(connDesc);
    innerVBox->addStretch();
    vbox->addLayout(innerVBox);

    this->setLayout(vbox);

    // remove min, max, close
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
}

void MainPanel::sendFeedback() {
    PreferencePanel pref(4); // feedback tab
    pref.exec();
}

void MainPanel::showMenu() {
    if (menu == nullptr) {
        menu = new SettingsMenu(this);
    }

    QPushButton *settingsBtn = static_cast<QPushButton *>(sender());
    QRect rect = settingsBtn->geometry();
    QPoint pos = mapToGlobal(rect.topLeft());

    menu->move(pos.x(), pos.y() + rect.height());
    menu->show();
}

void MainPanel::closeEvent(QCloseEvent *event) {
    if (this->isVisible()) {
        this->hide();
        event->ignore();
    } else {
        event->accept();
    }
}

void MainPanel::ConnectButtonChanged(bool newValue) {
    if (newValue) {
        connStatus->setText("Connected.");
        connDesc->setText("Your Internet is secured.");
    } else {
        connStatus->setText("Disconnected.");
        connDesc->setText("Your Internet is unsecured.");
    }
}