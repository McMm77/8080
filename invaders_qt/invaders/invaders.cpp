#include "cpu_core.h"

invaders::invaders()
    : rom_image("/home/meijemac/invaders.full"),
      is_running(false)
{
}

uint8_t invaders::get_pixel(int offset) {
    offset += 0x2400;
    return memory->get_u8(offset);
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

void invaders::step_to(cpu_debug &debug_info, uint16_t pc_counter)
{
    if(!is_running) {
        if( rom_image.open(QIODevice::ReadOnly | QIODevice::Unbuffered) == true) {

            QByteArray arr = rom_image.readAll();
            memory = new cpu_memory(arr);
            cpu_8080 = new cpu(*memory);

            is_running = true;
        }
    }

    while(cpu_8080->core_p().get_pc() != pc_counter) {
        cpu_8080->single_step(debug_info);
    }
}

void invaders::step(cpu_debug& debug_info, int nSteps = 1)
{
    if(!is_running) {
        if( rom_image.open(QIODevice::ReadOnly | QIODevice::Unbuffered) == true) {

            QByteArray arr = rom_image.readAll();
            memory = new cpu_memory(arr);
            cpu_8080 = new cpu(*memory);

            is_running = true;
        }
    }

    for(int n = 0 ; n < nSteps ; n++)   {
        cpu_8080->single_step(debug_info);
    }
}

void invaders::rst_interrupt(int reset_number) {
    uint8_t offset = 0xC7;
    uint8_t rst_opcode = offset + (reset_number * 8);

    cpu_8080->interrupt(rst_opcode);
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
           QFile myFile("/home/meijemac/log.log");

           bool flag = myFile.open(QIODevice::WriteOnly | QIODevice::Text);

           QByteArray arr = rom_image.readAll();
           memory = new cpu_memory(arr);
           cpu_8080 = new cpu(*memory);

           cpu_8080->execute(myFile);
       }
}
