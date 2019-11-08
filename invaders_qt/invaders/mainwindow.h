#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTimer>
#include <QLabel>
#include <QString>
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
    QString convert_u8_to_str(uint8_t);
    void update_cpu_core_data(cpu_debug&);

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
    QLineEdit   *reg_b_edit;
    QLineEdit   *reg_c_edit;
    QLineEdit   *reg_d_edit;
    QLineEdit   *reg_e_edit;
    QLineEdit   *reg_h_edit;
    QLineEdit   *reg_l_edit;
    QLineEdit   *reg_a_edit;
    QTimer *update_screen_timer;
    QGraphicsScene *graphic;
};

#endif // MAINWINDOW_H
