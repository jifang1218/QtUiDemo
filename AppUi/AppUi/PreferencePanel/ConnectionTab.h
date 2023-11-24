#ifndef CONNECTIONTAB_H
#define CONNECTIONTAB_H

#include <QWidget>

class ConnectionTab : public QWidget {
    Q_OBJECT
public:
    ConnectionTab(QWidget *parent);
    ~ConnectionTab();

private:
    void constructUi();
};

#endif // CONNECTIONTAB_H