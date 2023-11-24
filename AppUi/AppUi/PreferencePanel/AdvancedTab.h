#ifndef ADVANCEDTAB_H
#define ADVANCEDTAB_H

#include <QWidget>

class AdvancedTab : public QWidget {
    Q_OBJECT
public:
    AdvancedTab(QWidget *parent);
    ~AdvancedTab();

private:
    void constructUi();
};

#endif // ADVANCEDTAB_H