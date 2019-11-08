#ifndef CPU_H
#define CPU_H

#include <QThread>
#include <QFile>
#include <QByteArray>
#include <QTimer>

class Cpu : public QThread
{
public:
    Cpu();

public:
    void Execute(QByteArray&);

    void run() override {
        QByteArray arr= rom_file.readAll();
        display_timer->start(1000);
//        Execute(arr);
    }

public slots:
    void refresh_screen();

private:
    QFile   rom_file;
    QTimer  *display_timer;
};

#endif // CPU_H
