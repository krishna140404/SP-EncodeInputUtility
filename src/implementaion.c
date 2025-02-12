#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIo.h"
#include "binary_to_srec.h"
#include "binary_to_asm.h"
#include "command_parser.h"
#include "encode.h"

  int main (int argc, char *argv[]){
    // parsing the command line argument to the encoded file 
    int result = handleArguments(argc, argv);

    // if the arguments are not handling 
    if(result ==1){
        printf("help requested. exiting the program.\n");
        return EXIT_SUCCESS;
    }
    else if (result != 0){
        fprintf(stderr, "error : failed to proceess arguments.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
  }