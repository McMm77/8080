#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    exec_cpu_button = ui->cpu_exec;
    this->connect(exec_cpu_button, SIGNAL (released()), this, SLOT(handle_exec_cpu_button()));

    int sizeX = 600;
    int sizeY = 600;

    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);

    for( int l = 0 ; l < sizeX ; l++) {
            for(int c = 0 ; c < sizeY ; c++) {
                image.setPixel(l,c, qRgb(100, 140, 200));
            }
       }

    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap( QPixmap::fromImage(image));

    ui->graphicsView->setScene((graphic));
}

void MainWindow::handle_exec_cpu_button()
{
    this->exec_cpu_button->setText("EXECUTING");

}

MainWindow::~MainWindow()
{
    delete ui;
}
