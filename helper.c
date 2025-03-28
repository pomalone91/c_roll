#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

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

void help() {
    printf("Options\n-h: Show this help message.\n-b: Roll all the rolls in a plaintext file. Example: roll -b \"/path/to/file.txt\"\n\nFormat examples\n1d6: Rolls 1 six-sided dice.\n1d6+1: Rolls 1 six-sided dice and adds 1 to the result.\n10d6h4+1: Rolls 10 six-sided die hitting on 4 and adds 1 to the result of each individual dice to determine if they hit. The result is the number of dice that were equal to or higher than 4.\n");

}