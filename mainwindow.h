#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

class MainPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void toggleMainPanel();

private:
    void showMainPanel();
    void hideMainPanel();

private slots:
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

private:
    QSystemTrayIcon *sysIcon = nullptr;
    QAction *min = nullptr;
    QAction *max = nullptr;
    QAction *restore = nullptr;
    QAction *quit = nullptr;
    QMenu *menu = nullptr;
    MainPanel *mainPanel = nullptr;

private:
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
