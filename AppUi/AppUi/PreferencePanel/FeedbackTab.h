#ifndef FEEDBACKTAB_H
#define FEEDBACKTAB_H

#include <QWidget>

class FeedbackTab : public QWidget {
    Q_OBJECT
public:
    FeedbackTab(QWidget *parent);
    ~FeedbackTab();

private:
    void constructUi();
};

#endif // FEEDBACKTAB_H