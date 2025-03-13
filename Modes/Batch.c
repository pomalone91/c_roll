//
//  Batch.c
//  c_roll
//
//  Created by Paul Malone on 3/29/20.
//  Copyright © 2020 Paul Malone. All rights reserved.
//

#include "Batch.h"
#include "../Structures/Die.h"
#include <string.h>

void batch(char *path) {
    // TODO - implement this bad boy
    // Open file at path
    // Parse rolls into dice?
    // Make the rolls?
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
            Die d = init_die(s);
            printf("%i\n ", roll(d));
        }
        printf("\n");
    }
}
