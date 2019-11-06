#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    trigger_button = ui->emulation_trigger;
    update_screen_timer = new QTimer(this);

    connect(trigger_button, SIGNAL (released()), this, SLOT (handleEmulationTrigger()));
    connect(update_screen_timer, SIGNAL (timeout()), this, SLOT(updateScreen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleEmulationTrigger()
{
//    cpu_8080.start();
    update_screen_timer->start(1000);
}

void MainWindow::updateScreen() {
    invader.screen_interrupt();
}
