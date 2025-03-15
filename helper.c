#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Use arc4random_uniform to return random int within a limit
int getRandomInt(int upperLimit) {
    if (upperLimit == 0) {
        return 0;
    }
    // TODO set a lower limit?
    return (int) arc4random_uniform((uint32_t)upperLimit) + 1;
}

// Fills in all non-digit characters with whitespace to make it easier for strtol to find digits
void filwht(char *rollString) {
    int length = (int)strlen(rollString);
    for (int i = 0; i < length; ++i) {
        if (!isdigit(rollString[i])) {
            // Uses pointer arithmetic to iterate through char string
            *(rollString + i) = ' ';
        }
    }
}