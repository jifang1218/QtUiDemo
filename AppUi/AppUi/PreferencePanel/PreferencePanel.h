#ifndef PREFERENCEPANEL_H
#define PREFERENCEPANEL_H

#include <QDialog>

class QWidget;

class PreferencePanel : public QDialog {
    Q_OBJECT
public:
    PreferencePanel(int activeTabIndex = 0, QWidget *parent = nullptr);
    ~PreferencePanel();

private:
    void constructUi(int activeTabIndex);
};

#endif // PREFERENCEPANEL_H