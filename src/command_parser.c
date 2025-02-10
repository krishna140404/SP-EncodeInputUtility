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

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i], "-i", 2) == 0) {  // Input file
            if (strlen(argv[i]) > 2) {
                strcpy(input_file, argv[i] + 2);
            } else if (i + 1 < argc) {
                strcpy(input_file, argv[++i]);
            } else {
                fprintf(stderr, "Error: Missing input file name.\n");
                return -1;
            }
        } 
        else if (strncmp(argv[i], "-o", 2) == 0) {  // Output file
            if (strlen(argv[i]) > 2) {
                strcpy(output_file, argv[i] + 2);
            } else if (i + 1 < argc) {
                strcpy(output_file, argv[++i]);
            } else {
                fprintf(stderr, "Error: Missing output file name.\n");
                return -1;
            }
        } 
        else if (strcmp(argv[i], "-srec") == 0) {  // S-Record mode
            *mode = 1;
        } 
        else if (strcmp(argv[i], "-h") == 0) {  // Help
            printf("Usage: encodeInput [-i inputfile] [-o outputfile] [-srec] [-h]\n");
            exit(0);
        } 
}
