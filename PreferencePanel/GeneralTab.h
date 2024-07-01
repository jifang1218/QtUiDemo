#ifndef GENERALTAB_H
#define GENERALTAB_H

#include <QWidget>

class QFrame;

class GeneralTab : public QWidget {
    Q_OBJECT
public:
    GeneralTab(QWidget *parent);
    ~GeneralTab();

private:
    void constructUi();
    QFrame *getSeparator();
};

#endif // GENERALTAB_H