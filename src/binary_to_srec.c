#include <stdio.h>
#include <stdlib.h>
#include "../inc/binary_to_srec.h"

unsigned char calculate_checksum(int count, int address, unsigned char* data) {
    int sum = count + ((address >> 8) & 0xFF) + (address & 0xFF);
    for (int i = 0; i < count - 3; i++) {
        sum += data[i];
    }
    return (~sum) & 0xFF;
}
