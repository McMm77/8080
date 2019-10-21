CC=gcc
FLAGS=-g -I/usr/include/lua5.3/
DEASM_FLAGS=-g -Ddgconfig_DEASSEMBLER
DEASM_OBJ=deassembler_main.o deassembler.o
EMMU_FLAGS=-g
EMMU_OBJ=main_file.o cpu.o cpu_common.o deassembler_emu.o cli_parser.o simple_assembler.o

emulator: $(EMMU_OBJ)
	$(CC) -o emulator $(EMMU_OBJ)

deassembler: $(DEASM_OBJ)
	$(CC) -o deassembler $(DEASM_OBJ)

main_file.o: main_file.c
	$(CC) -c $(EMMU_FLAGS) main_file.c

cpu_common.o: cpu_common.c
	$(CC) -c $(EMMU_FLAGS) cpu_common.c

cli_parser.o: cli_parser.c
	$(CC) -c $(EMMU_FLAGS) cli_parser.c

cpu.o: cpu.c
	$(CC) -c $(EMMU_FLAGS) cpu.c

simple_assembler.o: simple_assembler.c
	$(CC) -c $(EMMU_FLAGS) simple_assembler.c

deassembler_emu.o: deassembler.c
	$(CC) -c $(EMMU_FLAGS) deassembler.c -o deassembler_emu.o

deassembler.o: deassembler.c
	$(CC) -c $(DEASM_FLAGS) deassembler.c

deassembler_main.o: deassembler_main.c
	$(CC) -c $(DEASM_FLAGS) deassembler_main.c

clean:
	rm -rfv *.o
	rm -f deassembler
	rm -f emulator

