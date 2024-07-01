#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QWidget>

class SettingsMenu;
class QPushButton;
class QCloseEvent;
class QLabel;

class MainPanel : public QWidget
{
    Q_OBJECT

public:
    MainPanel(QWidget *parent = nullptr);
    ~MainPanel();

public:
    virtual QSize sizeHint() const;

private slots:

public slots:
    void ConnectButtonChanged(bool newValue);

private:
    void constructUi();
    void showMenu();
    void sendFeedback();
    void closeEvent(QCloseEvent *event);

private:
    SettingsMenu *menu = nullptr;
    bool isConnected = false;
    QLabel *connStatus = nullptr;
    QLabel *connDesc = nullptr;
};
#endif // MAINPANEL_H
