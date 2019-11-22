#include "cpu_core.h"

invaders::invaders()
    : rom_image("/home/meijemac/invaders.full"),
      is_running(false),
      left_1(0),
      left_2(0),
      right_1(0),
      right_2(0),
      fire_1(0),
      fire_2(0),
      start_p2(0),
      start_b(0)
{}

void invaders::left_p1_pressed()
{
    left_1 = 1;
}

void invaders::left_p1_released()
{
    left_1 = 0;
}

void invaders::right_p1_pressed()
{
    right_1 = 1;
}

void invaders::right_p1_released()
{
    right_1 = 0;
}

void invaders::fire_p1_pressed()
{
    fire_1 = 1;
}

void invaders::fire_p1_released()
{
    fire_1 = 0;
}

void invaders::left_p2_pressed()
{
    left_2 = 1;
}

void invaders::left_p2_released()
{
    left_2 = 0;
}

void invaders::right_p2_pressed()
{
    right_2 = 1;
}

void invaders::right_p2_released()
{
    right_2 = 0;
}

void invaders::fire_p2_pressed()
{
    fire_2 = 1;
}

void invaders::fire_p2_released()
{
    fire_2 = 0;
}

uint8_t invaders::get_pixel(int offset) {
    offset += 0x2400;
    return memory->get_u8(offset);
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
            cpu_8080 = new cpu(*memory, *this);

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
            cpu_8080 = new cpu(*memory, *this);

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
QFile myFile("/home/meijemac/log2.log");
QFile shortFile("/home/meijemac/slog2.log");

void invaders::run() {

       if( rom_image.open(QIODevice::ReadOnly | QIODevice::Unbuffered) == true) {

           bool flag = myFile.open(QIODevice::WriteOnly | QIODevice::Text);
           shortFile.open(QIODevice::WriteOnly | QIODevice::Text);

           QByteArray arr = rom_image.readAll();
           memory = new cpu_memory(arr);
           cpu_8080 = new cpu(*memory, *this);

           cpu_8080->execute(myFile, shortFile);
       }
}

void invaders::coin_inserted(uint8_t val) {
    coin = val;
}

void invaders:: start_p1_pressed() {
    start_b = 1;
}

void invaders::start_p1_released() {
    start_b = 0;
}

void invaders::start_p2_pressed() {
    start_p2 = 1;
}

void invaders::start_pressed() {
    start_b = 1;
}

uint8_t invaders::input_1_handler()
{
    return 0x0E;
}

uint8_t invaders::input_2_handler()
{
    uint8_t ret = 0x04;
    ret |= coin;
    ret |= (start_p2 << 1);
    ret |= (start_b << 2);
    ret |= (fire_1 << 4);
    ret |= (left_1 << 5);
    ret |= (right_1 << 6);
    return ret;
}

uint8_t invaders::input_3_handler()
{
    uint8_t ret = 0x00;

    ret |= (fire_2 << 4);
    ret |= (left_2 << 5);
    ret |= (right_2 << 6);

    return ret;
}
