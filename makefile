CC=gcc
FLAGS=-g -I/usr/include/lua5.3/
DEASM_FLAGS=-g
DEASM_OBJ=deassembler_main.o deassembler.o

deassembler: $(DEASM_OBJ)
	$(CC) -o deassembler $(DEASM_OBJ)

deassembler.o: deassembler.c
	$(CC) -c $(DEASM_FLAGS) deassembler.c

deassembler_main.o: deassembler_main.c
	$(CC) -c $(DEASM_FLAGS) deassembler_main.c

clean:
	rm -rfv *.o
	rm deassembler


