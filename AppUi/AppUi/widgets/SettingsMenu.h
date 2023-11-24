#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QMenu>

class PreferencePanel;
class QAction;

class SettingsMenu : public QMenu {
    Q_OBJECT
public:
    SettingsMenu(QWidget *parent);
    ~SettingsMenu() = default;

private:
    void constructUi();
    void addressSelected();
    void addressWithWARPSelected();
    void showPreference();
    void sendFeedback();
    void showAbout();
    void doQuit();

private:
    QAction *addrMenuItem = nullptr;
    QAction *addrWithWARPMenuItem = nullptr;
    QAction *preferenceMenuItem = nullptr;
    QAction *sendFeedbackMenuItem = nullptr;
    QAction *aboutMenuItem = nullptr;
    QAction *quitMenuItem = nullptr;

    PreferencePanel *preferencePanel = nullptr;

};

#endif // SETTINGSMENU_H