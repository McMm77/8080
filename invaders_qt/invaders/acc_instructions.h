#ifndef ACC_INSTRUCTIONS_H
#define ACC_INSTRUCTIONS_H

#include <QByteArray>
#include <QString>

class cpu;

class add_instr
{
protected:
    void add(cpu&, uint8_t);
};

class adc_instr
{
public:
    void adc(cpu&, uint8_t);
};

class sub_instr
{
public:
    void sub(cpu&, uint8_t);
};

class sbb_instr
{
public:
    void sbb(cpu&, uint8_t);
};

class ana_instr
{
public:
    void ana(cpu&, uint8_t);
};

class xra_instr
{
public:
    void xra(cpu&, uint8_t);
};

class ora_instr
{
public:
    void ora(cpu&, uint8_t);
};

class cmp_instr
{
public:
    void cmp(cpu&, uint8_t);
};

#endif // ACC_INSTRUCTIONS_H
