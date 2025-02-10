#include "../inc/binary_to_asm.h"

void convert_binary_to_asm(FILE *input, FILE *output) {
    if (!input || !output) {  // Check for valid file pointers
        fprintf(stderr, "Error: Invalid file pointers provided.\n");
        return;
    }

    unsigned char byte;
    
    // Read each byte from the binary file and convert to assembly DB directive
    while (fread(&byte, 1, 1, input)) {
        if(fprintf(output, "DB 0x%02X\n", byte) < 0) {  // Write to output file
            fprintf(stderr, "Error: Writing to output file failed.\n");
            return;
        }  
    }

    if (ferror(input)) {  // Check if file reading had an error
        fprintf(stderr, "Error: Reading from input file failed.\n");
    }    
}