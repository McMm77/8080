#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>

#include "cpu.h"

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
    void handle_exec_cpu_button();

private:
    Ui::MainWindow *ui;
    QPushButton *exec_cpu_button;

    cpu_model_t  cpu;
    memory_t     rom;

};

#endif // MAINWINDOW_H
