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
void batch(char *path) {
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
            roll d = init_roll(s);
            printf("%i\n ", make_roll(d));
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
void staticmode(int argc, char **argv) {
    roll r;
    int i = 1;
    while (i < argc) {
        r = init_roll((char *)argv[i]);
        printf("%i ", make_roll(r));
        printf("\n");
        ++i;
    }
}

// Interactive Mode
int interactive(void) {
    roll d;
    char input[40];
    const char exit[5] = "exit\n";
    printf("Enter a roll: \n");
    do {
        if (fgets(input, 40, stdin)) {
            if (strncmp(input, exit, 5) != 0) {
                d = init_roll(input);
                printf("%i\n", make_roll(d));
            } else {
                break;
            }
        }
//            printf("%i\n", strcmp(input, exit));
    } while (strncmp(input, exit, 5) != 0);
    
    return 0;
}