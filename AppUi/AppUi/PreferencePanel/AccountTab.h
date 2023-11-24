#ifndef ACCOUNTTAB_H
#define ACCOUNTTAB_H

#include <QWidget>

class AccountTab : public QWidget {
    Q_OBJECT
public:
    AccountTab(QWidget *parent);
    ~AccountTab();

private:
    void constructUi();
};

#endif // ACCOUNTTAB_H