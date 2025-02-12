#include "../inc/binary_to_asm.h"
#include "../inc/binary_to_srec.h"
#include "../inc/command_parser.h"
#include "../inc/fileIO.h"
#include "../inc/encode.h"
#include "binary_to_asm.c"
#include "binary_to_srec.c"
#include "command_parser.c"
#include "encode.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inputFileValidation(char* inputFilename){
    FILE *inputFile = stdin;
    if (inputFilename) {
        inputFile = fopen(inputFilename, "rb");
        if (!inputFile) {
            fprintf(stderr, "Error: Cannot open input file %s\n", inputFilename);
            return NULL;
        }
    }
    return inputFile;
}

FILE *outputFileValidation(char* outputFilename){
    FILE *outputFile = stdout;
    if (outputFilename){
        outputFile = fopen(outputFilename, "w");
        if (!outputFile) {
            fprintf(stderr, "Error: Cannot open output file %s\n", outputFilename);
            return NULL;
        }
    }
    return outputFile;
}