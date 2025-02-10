# Target to build the final executable
bin/encodeProject: obj/main.o obj/fileIo.o obj/binary_to_asm.o
	gcc obj/main.o obj/fileIo.o obj/binary_to_asm.o -o bin/encodeProject

# Rule for main.o
obj/main.o: src/main.c inc/encodeInput.h
	gcc -c src/main.c -Iinc -o obj/main.o

# Rule for fileIo.o
obj/fileIo.o: src/fileIo.c inc/encodeInput.h
	gcc -c src/fileIo.c -Iinc -o obj/fileIo.o

# Rule for binary_to_asm.o
obj/binary_to_asm.o: src/binary_to_asm.c inc/binary_to_asm.h
	gcc -c src/binary_to_asm.c -Iinc -o obj/binary_to_asm.
	
# Rule for command_parser.o
obj/command_parser.o: src/command_parser.c inc/command_parser.h
	gcc -c src/command_parser.c -Iinc -o obj/command_parser.o

# Default target to build everything
all: bin/encodeProject

# Clean up generated files
clean:
	rm -f obj/*.o bin/encodeProject
