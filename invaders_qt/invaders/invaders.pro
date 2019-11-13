#-------------------------------------------------
#
# Project created by QtCreator 2019-10-31T10:52:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = invaders
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cpu_core.cpp \
    opcodes.cpp \
    cpu_core_flags.cpp \
    invaders.cpp \
    cpu.cpp \
    nop_opcode.cpp \
    register_pair_opcodes.cpp \
    rotate_acc_opcodes.cpp \
    jmp_opcode.cpp \
    call_opcode.cpp \
    ret_opcode.cpp \
    direct_addr_opcode.cpp \
    interrupt_flipflop_opcode.cpp \
    immediate_opcode.cpp \
    reg_or_mem_to_acc_opcode.cpp \
    acc_instructions.cpp \
    data_transfer_opcodes.cpp \
    rst_opcode.cpp \
    io_opcode.cpp \
    single_register_opcodes.cpp \
    carry_bit_opcode.cpp \
    hlt_opcode.cpp

HEADERS += \
        mainwindow.h \
    cpu_core.h \
    opcodes.h \
    register_pair_opcodes.h \
    rotate_acc_opcodes.h \
    jmp_opcode.h \
    call_opcode.h \
    ret_opcode.h \
    direct_addr_opcode.h \
    interrupt_flipflop_opcode.h \
    immediate_opcode.h \
    reg_or_mem_to_acc_opcode.h \
    acc_instructions.h \
    data_transfer_opcodes.h \
    rst_opcode.h \
    io_opcode.h \
    single_register_opcodes.h \
    carry_bit_opcode.h \
    hlt_opcode.h \
    nop_opcode.h

FORMS += \
        mainwindow.ui
