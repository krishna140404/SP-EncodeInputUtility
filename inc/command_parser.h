/*
 * FILE: command_parser.h
 * PROJECT: encodeInput Utility
 * PROGRAMMER: MANREET THIND (STUDENT ID: 8982315)
 * FIRST VERSION: 01/26/2025
 * DESCRIPTION:
 * This header file declares the function to parse command-line arguments.
 */
#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

// Function prototype
int parse_command_line(int argc, char** argv, int* mode, char* input_file, char* output_file);

#endif