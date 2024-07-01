#include "SettingsMenu.h"
#include "../PreferencePanel/PreferencePanel.h"
#include <QActionGroup>
#include <QApplication>
#include <QAction>
#include <QDebug>

SettingsMenu::SettingsMenu(QWidget *parent) : QMenu(parent) {
    constructUi();
}

void SettingsMenu::constructUi() {
    QActionGroup *actionGroup = new QActionGroup(this);

    // set addr menu item
    if (addrMenuItem == nullptr) {
        addrMenuItem = new QAction("1.1.1.1", this);
    } else {
        addrMenuItem->setText("1.1.1.1");
    }
    addrMenuItem->setCheckable(true);
    addrMenuItem->setChecked(true);
    connect(addrMenuItem, &QAction::triggered, this, &SettingsMenu::addressSelected);
    actionGroup->addAction(addrMenuItem);

    // set addrWithWARP menu item
    if (addrWithWARPMenuItem == nullptr) {
        addrWithWARPMenuItem = new QAction("1.1.1.1 with WARP", this);
    } else {
        addrWithWARPMenuItem->setText("1.1.1.1 with WARP");
    }
    addrWithWARPMenuItem->setCheckable(true);
    connect(addrWithWARPMenuItem, &QAction::triggered, this, &SettingsMenu::addressWithWARPSelected);
    actionGroup->addAction(addrWithWARPMenuItem);
    addActions(actionGroup->actions());

    addSeparator();

    // preferences
    if (preferenceMenuItem == nullptr) {
        preferenceMenuItem = new QAction("Preferences", this);
    } 
    connect(preferenceMenuItem, &QAction::triggered, this, &SettingsMenu::showPreference);
    addAction(preferenceMenuItem);

    // send feedback
    if (sendFeedbackMenuItem == nullptr) {
        sendFeedbackMenuItem = new QAction("Send Feedback", this);
    }
    connect(sendFeedbackMenuItem, &QAction::triggered, this, &SettingsMenu::sendFeedback);
    addAction(sendFeedbackMenuItem);

    // about
    if (aboutMenuItem == nullptr) {
        aboutMenuItem = new QAction("About WARP", this);
    }
    connect(aboutMenuItem, &QAction::triggered, this, &SettingsMenu::showAbout);
    addAction(aboutMenuItem);

    addSeparator();

    // quit
    if (quitMenuItem == nullptr) {
        quitMenuItem = new QAction("Quit", this);
    }
    connect(quitMenuItem, &QAction::triggered, this, &SettingsMenu::doQuit);
    addAction(quitMenuItem);

    move(100, 100);
}

void SettingsMenu::addressSelected() {
    qDebug()<<"address selected.";
}

void SettingsMenu::addressWithWARPSelected() {
    qDebug()<<"address with WARP selected.";
}

void SettingsMenu::showPreference() {
    PreferencePanel pref(0); // first tab
    pref.exec();
}

void SettingsMenu::sendFeedback() {
    PreferencePanel pref(4); // feedback tab
    pref.exec();
}

void SettingsMenu::showAbout() {
    qDebug()<<"show about.";
}

void SettingsMenu::doQuit() {
    QApplication::quit();
}