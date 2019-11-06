#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "cpu_core.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleEmulationTrigger();
    void updateScreen();

private:
    invaders invader;
    Ui::MainWindow *ui;
    QPushButton *trigger_button;
    QTimer *update_screen_timer;
};

#endif // MAINWINDOW_H
