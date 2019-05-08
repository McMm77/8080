CC=gcc
FLAGS=-g -I/usr/include/lua5.3/
DEASM_FLAGS=-g -Ddgconfig_DEASSEMBLER
OBJ=main_file.o cpu.o deassembler_str.o
DEASM_OBJ=deassembler_main.o deassembler.o

all: $(OBJ)
	mv deassembler.o deassembler_str.o
	$(CC) -o emulator $(OBJ) 

deassembler: $(DEASM_OBJ)
	$(CC) -o deassembler $(DEASM_OBJ)

main_file.o: main_file.c
	$(CC) -c $(FLAGS) main_file.c

cpu.o: cpu.c cpu.h
	$(CC) -c $(FLAGS) cpu.c

deassembler_str.o: deassembler.c
	$(CC) -c $(FLAGS) deassembler.c

deassembler.o: deassembler.c
	$(CC) -c $(DEASM_FLAGS) deassembler.c

deassembler_main.o: deassembler_main.c
	$(CC) -c $(DEASM_FLAGS) deassembler_main.c


clean:
	rm -rfv *.o
	rm emulator
	rm deassembler


