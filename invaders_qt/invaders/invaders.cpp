#include "cpu_core.h"

invaders::invaders()
    : rom_image("invaders.full")
{
}

void invaders::screen_interrupt() {
    static int flag = 0;

    cpu_8080->interrupt(flag);

    flag = (flag == 0) ? 1 : 0;
}

void invaders::run() {

       if( rom_image.open(QIODevice::ReadOnly | QIODevice::Unbuffered) == true) {

           QByteArray arr = rom_image.readAll();
           memory = new cpu_memory(arr);
           cpu *cpu_8080 = new cpu(*memory);

           cpu_8080->execute();
       }
}
