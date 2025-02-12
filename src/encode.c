/*
 * FILE: encode.c
 * PROJECT: encodeInput Utility
 * PROGRAMMER: BHAWANJEET KAUR GILL (STUDENT ID: 8958829)
 * FIRST VERSION: 02/11/2025
 * DESCRIPTION:
 * This header file creates all the functions for encoding the functions altogether.
 */
#include "../inc/binary_to_asm.h"
#include "../inc/binary_to_srec.h"
#include "../inc/command_parser.h"
#include "../inc/fileIO.h"
#include "../inc/encode.h"
#include "binary_to_asm.c"
#include "binary_to_srec.c"
#include "command_parser.c"
#include "fileIO.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int handle_arguments(int argc, char *argv[]) {
    char* inputFilename = NULL;
    char* outputFilename = NULL;
    int srec = 0; //The value of srec is 0 by default and this will be directing to the asm conversion.
    int showHelp = 0; //By default is 0 but if asked for the help by the user, then converts to 1.
    int outputFile = 0;//By default 0, indicating that the file is not present in the list of arguments
    int inputFile = 0;//By default 0, indicating that the file is not present in the list of arguments

    for(int i = 1; i < argc; i++){
        if(strncmp(argv[i], "-i", 2) == 0){
            inputFilename = argv[i] + 2;
            inputFile = 1; //Turns to 1, after knowing that the input file is present in the arguments.
        }
        else if(strncmp(argv[i], "-o", 2) == 0){
            outputFilename = argv[i] + 2;
            outputFile = 1; //Turns to 1, after knowing that the output file is present in the arguments.
        }
        else if(strcmp(argv[i], "-srec") == 0){
            srec = 1; //To be converted to srec file.
        }
        else if(strcmp(argv[i], "-h") == 0)
        {
            printf("Usage: encodeInput [-iINPUTFILENAME] [-oOUTPUTFILENAME] [-srec] [-h]\n");
            return 0;
        }
    }
    if(inputFile == 1 && outputFile == 0){
        FILE* inputData = inputFileValidation(char* inputFilename);
        FILE* outputData = outputFileValidation(char* outputFilename);
        if(srec){
            convert_binary_to_srec(inputData, outputData);
        }
        else{
            convert_binary_to_asm(inputData, outputData);
        }
        
    }




    if(srec){
        convert_binary_to_srec(inputFile, outputFile); //If srec, then convert to srec
    }


}