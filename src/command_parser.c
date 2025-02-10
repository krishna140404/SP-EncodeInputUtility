#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/command_parser.h" 

int parse_command_line(int argc, char** argv, int* mode, char* input_file, char* output_file) {
    if (argc < 2) {  // If no arguments are provided, print usage and return failure
        printf("Usage: encodeInput [-i inputfile] [-o outputfile] [-srec] [-h]\n");
        return -1;
    }

    // Default values
    *mode = 0;  // 0 = Assembly mode (default), 1 = S-Record mode
    input_file[0] = '\0';
    output_file[0] = '\0';
}
