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
    QString convert_u8_to_hexstr(uint8_t);
    QString convert_u16_to_hexstr(uint16_t reg_val);
    void update_cpu_core_data(cpu_debug&);

private slots:
    void handleEmulationTrigger();
    void handleStepButton();
    void handleXStepButton();
    void handleDebugStepButton();
    void handleResetButton_0();
    void handleResetButton_1();
    void handleResetButton_2();
    void handleResetButton_3();
    void handleResetButton_4();
    void handleResetButton_5();
    void handleResetButton_6();
    void handleResetButton_7();
    void handleCoinButton();
    void handleStartButton();
    void handleStartPressed();
    void updateScreen();

private:
    invaders invader;
    Ui::MainWindow *ui;

    QLabel      *ass_cmd_pre;
    QLabel      *ass_cmd_post;
    QPushButton *trigger_button;
    QPushButton *step_button;
    QPushButton *step_x_button;
    QPushButton *step_debug_button;

    QLineEdit   *step_count;
    QLineEdit   *debug_pc;

    QLineEdit   *reg_b_edit;
    QLineEdit   *reg_c_edit;
    QLineEdit   *reg_d_edit;
    QLineEdit   *reg_e_edit;
    QLineEdit   *reg_h_edit;
    QLineEdit   *reg_l_edit;
    QLineEdit   *reg_a_edit;

    QLineEdit   *flag_z;
    QLineEdit   *flag_p;
    QLineEdit   *flag_s;
    QLineEdit   *flag_ac;
    QLineEdit   *flag_c;

    QLineEdit   *stack_pointer;
    QLineEdit   *program_counter;

    QPushButton *rst_button0;
    QPushButton *rst_button1;
    QPushButton *rst_button2;
    QPushButton *rst_button3;
    QPushButton *rst_button4;
    QPushButton *rst_button5;
    QPushButton *rst_button6;
    QPushButton *rst_button7;

    QPushButton *start_button;
    QPushButton *coin_button;

    QTimer *update_screen_timer;
    QGraphicsScene *graphic;
};

#endif // MAINWINDOW_H
