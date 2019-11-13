#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_screen_timer = new QTimer(this);
    graphic = new QGraphicsScene(this);

    ass_cmd_pre = ui->ass_label_pre;
    ass_cmd_post = ui->ass_label_post;

    trigger_button = ui->emulation_trigger;
    step_button = ui->step_button;
    step_debug_button = ui->step_to_button;

    step_count = ui->ass_step_count;
    debug_pc = ui->debug_pc;
    step_x_button = ui->step_x_button;

    rst_button0 = ui->reset_button_0;
    rst_button1 = ui->reset_button_1;
    rst_button2 = ui->reset_button_2;
    rst_button3 = ui->reset_button_3;
    rst_button4 = ui->reset_button_4;
    rst_button5 = ui->reset_button_5;
    rst_button6 = ui->reset_button_6;
    rst_button7 = ui->reset_button_8;

    reg_b_edit = ui->reg_b_edit;
    reg_c_edit = ui->reg_c_edit;
    reg_d_edit = ui->reg_d_edit;
    reg_e_edit = ui->reg_e_edit;
    reg_h_edit = ui->reg_h_edit;
    reg_l_edit = ui->reg_l_edit;
    reg_a_edit = ui->reg_a_edit;
    flag_ac = ui->ac_flag;
    flag_c = ui->c_flag;
    flag_p = ui->p_flag;
    flag_s = ui->s_flag;
    flag_z = ui->z_flag;
    stack_pointer = ui->stack;
    program_counter = ui->pc;

    connect(trigger_button, SIGNAL (released()), this, SLOT (handleEmulationTrigger()));
    connect(step_button, SIGNAL (released()), this, SLOT (handleStepButton()));
    connect(step_x_button, SIGNAL (released()), this, SLOT (handleXStepButton()));
    connect(step_debug_button, SIGNAL (released()), this, SLOT (handleDebugStepButton()));

    connect(update_screen_timer, SIGNAL (timeout()), this, SLOT(updateScreen()));

    connect(rst_button0, SIGNAL (released()), this, SLOT (handleResetButton_0()));
    connect(rst_button1, SIGNAL (released()), this, SLOT (handleResetButton_1()));
    connect(rst_button2, SIGNAL (released()), this, SLOT (handleResetButton_2()));
    connect(rst_button3, SIGNAL (released()), this, SLOT (handleResetButton_3()));
    connect(rst_button4, SIGNAL (released()), this, SLOT (handleResetButton_4()));
    connect(rst_button5, SIGNAL (released()), this, SLOT (handleResetButton_5()));
    connect(rst_button6, SIGNAL (released()), this, SLOT (handleResetButton_6()));
    connect(rst_button7, SIGNAL (released()), this, SLOT (handleResetButton_7()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleEmulationTrigger()
{
    invader.start();
    update_screen_timer->start(17);
}

void MainWindow::handleDebugStepButton() {
    bool ok;
    cpu_debug debug_info;
    QString pc_str = debug_pc->text();
    uint16_t pc = pc_str.toUInt(&ok, 16);

    invader.step_to(debug_info, pc);

    update_cpu_core_data(debug_info);
    draw_screen();
}
void MainWindow::handleXStepButton() {

    cpu_debug debug_info;
    invader.step(debug_info, 100);

    update_cpu_core_data(debug_info);
    draw_screen();
}

void MainWindow::handleStepButton() {
    cpu_debug debug_info;
    invader.step(debug_info, 1);

    update_cpu_core_data(debug_info);
    draw_screen();
}

void MainWindow::handleResetButton_0()
{
    invader.rst_interrupt(0);
}

void MainWindow::handleResetButton_1()
{
    invader.rst_interrupt(1);
}

void MainWindow::handleResetButton_2()
{
    invader.rst_interrupt(2);
}

void MainWindow::handleResetButton_3()
{
    invader.rst_interrupt(3);
}

void MainWindow::handleResetButton_4()
{
    invader.rst_interrupt(4);
}

void MainWindow::handleResetButton_5()
{
    invader.rst_interrupt(5);
}

void MainWindow::handleResetButton_6()
{
    invader.rst_interrupt(6);
}

void MainWindow::handleResetButton_7()
{
    invader.rst_interrupt(7);
}

QString MainWindow::convert_u16_to_hexstr(uint16_t reg_val)
{
    QString number;

    number.sprintf("0x%04x", reg_val);
    return number;
}

QString MainWindow::convert_u8_to_str(uint8_t reg_val)
{
    QString number = QString::number(reg_val);

    return number;
}

QString MainWindow::convert_u8_to_hexstr(uint8_t reg_val)
{
    QString number;

    number.sprintf("0x%02x", reg_val);
    return number;
}

void MainWindow::update_cpu_core_data(cpu_debug &debug)
{
    this->reg_b_edit->setText(convert_u8_to_hexstr(debug.curr_core.get_reg_b()));
    this->reg_c_edit->setText(convert_u8_to_hexstr(debug.curr_core.get_reg_c()));

    this->reg_d_edit->setText(convert_u8_to_hexstr(debug.curr_core.get_reg_d()));
    this->reg_e_edit->setText(convert_u8_to_hexstr(debug.curr_core.get_reg_e()));

    this->reg_h_edit->setText(convert_u8_to_hexstr(debug.curr_core.get_reg_h()));
    this->reg_l_edit->setText(convert_u8_to_hexstr(debug.curr_core.get_reg_l()));

    this->reg_a_edit->setText(convert_u8_to_hexstr(debug.curr_core.get_reg_a()));

    this->flag_ac->setText(convert_u8_to_str(debug.curr_core_flags.get_ac_flag()));
    this->flag_c->setText((convert_u8_to_str(debug.curr_core_flags.get_c_flag())));
    this->flag_p->setText(convert_u8_to_str(debug.curr_core_flags.get_p_flag()));
    this->flag_s->setText(convert_u8_to_str(debug.curr_core_flags.get_s_flag()));
    this->flag_z->setText(convert_u8_to_str(debug.curr_core_flags.get_z_flag()));

    this->stack_pointer->setText(convert_u16_to_hexstr(debug.curr_core.get_sp()));
    this->program_counter->setText((convert_u16_to_hexstr(debug.curr_core.get_pc())));

    this->ass_cmd_pre->setText(debug.curr_opcode_cmd);
    this->ass_cmd_post->setText(debug.post_opcode_cmd);
}

void MainWindow::draw_screen() {
    int screen_x = 224; int screen_y = 256; int counter = 0;

//    QByteArray  screen_buffer = invader.get_screen_buffer();
    QImage image = QImage(screen_x, screen_y, QImage::Format_RGB32);

    for( int x = 0 ; x < screen_x ; x++) {
        for(int y = 0 ; y < screen_y ; y+=8) {
            for (int i = 0 ; i < 8 ; i++) {
                uint8_t pixel = invader.get_pixel(counter);

                if( pixel & (0x1 << i)) {
                    image.setPixel(x, (y+i), qRgb(128, 128, 128));
                }
/*
                if (screen_buffer[counter] & (0x1 << i)) {
                    image.setPixel(x, (y+i), qRgb(128, 128, 128));
                }
*/
            }

            counter++;
        }
    }

    graphic->addPixmap(QPixmap::fromImage(image));
    ui->play_screen->setScene((graphic));
}

void MainWindow::updateScreen() {
    invader.screen_interrupt();
    draw_screen();
}
