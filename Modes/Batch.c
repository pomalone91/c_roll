//
//  Batch.c
//  c_roll
//
//  Created by Paul Malone on 3/29/20.
//  Copyright © 2020 Paul Malone. All rights reserved.
//

#include "Batch.h"
#include "../Structures/roll.h"
#include <string.h>
#include <stdlib.h>

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
