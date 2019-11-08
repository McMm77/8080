#include "cpu_core.h"

invaders::invaders()
    : rom_image("/home/meijemac/invaders.full"),
      is_running(false)
{
}

QByteArray invaders::get_screen_buffer() {
    return memory->copy_video_memory();
}

void invaders::reset()
{
    delete cpu_8080;
    delete memory;

    is_running = false;
}

QString invaders::step()
{
    if(!is_running) {
        if( rom_image.open(QIODevice::ReadOnly | QIODevice::Unbuffered) == true) {

            QByteArray arr = rom_image.readAll();
            memory = new cpu_memory(arr);
            cpu_8080 = new cpu(*memory);

            is_running = true;
        }
    }

    return cpu_8080->single_step();
}

void invaders::screen_interrupt() {
    static int flag = 0;

    if(flag == 0)
        cpu_8080->interrupt(0xCF);
    else
        cpu_8080->interrupt(0xD7);

    flag = (flag == 0) ? 1 : 0;
}

void invaders::run() {

       if( rom_image.open(QIODevice::ReadOnly | QIODevice::Unbuffered) == true) {

           QByteArray arr = rom_image.readAll();
           memory = new cpu_memory(arr);
           cpu_8080 = new cpu(*memory);

           cpu_8080->execute();
       }
}
