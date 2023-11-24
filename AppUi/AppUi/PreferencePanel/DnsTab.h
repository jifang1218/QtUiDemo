#ifndef DNSTAB_H
#define DNSTAB_H

#include <QWidget>

class DnsTab : public QWidget {
    Q_OBJECT
public:
    DnsTab(QWidget *parent);
    ~DnsTab();

private:
    void constructUi();
};

#endif // DNSTAB_H