//
//  mode.c
//  c_roll
//
//  Created by Paul Malone on 3/31/25.
//

#include "mode.h"
#include "roll.h"
#include <string.h>
#include <stdlib.h>

// Batch mode
void mode_batch(char *path) {
    FILE *inputFile;
    inputFile = fopen(path, "r");
    char buffer[64];
    char *s;
    
    if (inputFile == NULL) {
        printf("Could not read file at %s\n", path);
    } else {
        // File found, make the rolls...
        printf("Rolling dice in %s\n", path);
        while ((s = fgets(buffer, 64, inputFile)) != NULL) {
            // Remove \n from string because they are obnoxious...
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len-1] == '\n') {
              buffer[--len] = '\0';
            }
            // Parse strings into dice
            printf("%s: ", s);
            Roll d = roll_init(s);
            printf("%i\n ", roll_throw(d));
        }
        printf("\n");
    }
    if (s != NULL)
    {
        free(s);
    }
    if (inputFile != NULL) {
        free(inputFile);
    }
}

// Static mode
void mode_static(int argc, char **argv) {
    Roll r;
    int i = 1;
    while (i < argc) {
        r = roll_init((char *)argv[i]);
        printf("%i ", roll_throw(r));
        printf("\n");
        ++i;
    }
}

// Interactive Mode
int mode_interactive(void) {
    Roll d;
    char input[40];
    const char exit[5] = "exit\n";
    printf("Enter a roll: \n");
    do {
        if (fgets(input, 40, stdin)) {
            if (strncmp(input, exit, 5) != 0) {
                d = roll_init(input);
                printf("%i\n", roll_throw(d));
            } else {
                break;
            }
        }
//            printf("%i\n", strcmp(input, exit));
    } while (strncmp(input, exit, 5) != 0);
    
    return 0;
}

// Help mode
void mode_help() {
    printf("Options\n-h: Show this help message.\n-b: Roll all the rolls in a plaintext file. Example: roll -b \"/path/to/file.txt\"\n\nFormat examples\n1d6: Rolls 1 six-sided dice.\n1d6+1: Rolls 1 six-sided dice and adds 1 to the result.\n10d6h4+1: Rolls 10 six-sided die hitting on 4 and adds 1 to the result of each individual dice to determine if they hit. The result is the number of dice that were equal to or higher than 4.\n");

}