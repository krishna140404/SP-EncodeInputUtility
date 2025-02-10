#include "../inc/binary_to_asm.h"

void convert_binary_to_asm(FILE *input, FILE *output) {
    unsigned char byte;
    while (fread(&byte, 1, 1, input)) {
        fprintf(output, "DB 0x%02X\n", byte);  // Assembly DB directive for byte storage
    }
}