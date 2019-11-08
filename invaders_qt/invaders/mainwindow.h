#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QTimer>
#include <QLabel>
#include "cpu_core.h"

class QGraphicsScene;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void draw_screen();

private slots:
    void handleEmulationTrigger();
    void handleStepButton();
    void handleResetButton();
    void updateScreen();

private:
    invaders invader;
    Ui::MainWindow *ui;

    QLabel      *ass_cmd;
    QPushButton *trigger_button;
    QPushButton *step_button;
    QPushButton *reset_button;
    QTextEdit   *reg_b_edit;
    QTextEdit   *reg_c_edit;
    QTextEdit   *reg_d_edit;
    QTextEdit   *reg_e_edit;
    QTextEdit   *reg_h_edit;
    QTextEdit   *reg_l_edit;
    QTextEdit   *reg_a_edit;
    QTimer *update_screen_timer;
    QGraphicsScene *graphic;
};

#endif // MAINWINDOW_H
