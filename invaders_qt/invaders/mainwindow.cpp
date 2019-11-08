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

    ass_cmd = ui->ass_label;
    trigger_button = ui->emulation_trigger;
    step_button = ui->step_button;
    reset_button = ui->reset_button;

    reg_b_edit = ui->reg_b_edit;
    reg_c_edit = ui->reg_c_edit;
    reg_d_edit = ui->reg_d_edit;
    reg_e_edit = ui->reg_e_edit;
    reg_h_edit = ui->reg_h_edit;
    reg_l_edit = ui->reg_l_edit;
    reg_a_edit = ui->reg_a_edit;

    connect(trigger_button, SIGNAL (released()), this, SLOT (handleEmulationTrigger()));
    connect(step_button, SIGNAL (released()), this, SLOT (handleStepButton()));
    connect(reset_button, SIGNAL (released()), this, SLOT (handleResetButton()));
    connect(update_screen_timer, SIGNAL (timeout()), this, SLOT(updateScreen()));


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

void MainWindow::handleStepButton() {
    cpu_debug debug_info;
    invader.step(debug_info);

    update_cpu_core_data(debug_info);
    draw_screen();
}

void MainWindow::handleResetButton()
{
    invader.screen_interrupt();
}

QString MainWindow::convert_u8_to_str(uint8_t reg_val)
{
    QString number = QString::number(reg_val);

    return number;
}

void MainWindow::update_cpu_core_data(cpu_debug &debug)
{
    this->reg_b_edit->setText(convert_u8_to_str(debug.curr_core.get_reg_b()));
    this->reg_c_edit->setText(convert_u8_to_str(debug.curr_core.get_reg_c()));

    this->reg_d_edit->setText(convert_u8_to_str(debug.curr_core.get_reg_d()));
    this->reg_e_edit->setText(convert_u8_to_str(debug.curr_core.get_reg_e()));

    this->reg_h_edit->setText(convert_u8_to_str(debug.curr_core.get_reg_h()));
    this->reg_l_edit->setText(convert_u8_to_str(debug.curr_core.get_reg_l()));

    this->ass_cmd->setText(debug.post_opcode_cmd);
}

void MainWindow::draw_screen() {
    int screen_x = 224; int screen_y = 256; int counter = 0;

    QByteArray  screen_buffer = invader.get_screen_buffer();
    QImage image = QImage(screen_x, screen_y, QImage::Format_RGB32);

    for( int x = 0 ; x < screen_x ; x++) {
        for(int y = 0 ; y < screen_y ; y+=8) {
            for (int i = 0 ; i < 8 ; i++) {
                if (screen_buffer[counter] & (0x1 << i)) {
                    image.setPixel(x, (y+i), qRgb(128, 128, 128));
                }
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
