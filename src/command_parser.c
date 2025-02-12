/*
 * FILE: command_parser.c
 * PROJECT: encodeInput Utility
 * PROGRAMMER: MANREET THIND (STUDENT ID: 8982315)
 * FIRST VERSION: 01/26/2025
 * DESCRIPTION:
 * This file contains the implementation of the function to parse command-line arguments.
 * It processes user input, determines the operation mode (Assembly/S-Record), 
 * extracts file names, and ensures correct program execution.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/command_parser.h" 

/*
 * Name    : parse_command_line
 * Purpose : Parses command-line arguments to determine the operation mode and input/output filenames.
 * Input   : argc        - int    - Argument count
 *           argv        - char** - Argument vector (array of strings)
 * Outputs : mode        - int*   - Pointer to store the operation mode (assembly/S-Record)
 *           input_file  - char*  - Buffer to store the input file name
 *           output_file - char*  - Buffer to store the output file name
 * Returns : int - 0 on success, -1 on failure
 */
int parse_command_line(int argc, char** argv, int* mode, char* input_file, char* output_file) {

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
        else {  // Invalid argument
            fprintf(stderr, "Error: Invalid option '%s'\n", argv[i]);
            printf("Usage: encodeInput [-i inputfile] [-o outputfile] [-srec] [-h]\n");
            return -1;
        }
    }

    return 0;
}
