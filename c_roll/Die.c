//
//  Die.c
//  c_roll
//
//  Created by Paul Malone on 10/19/19.
//  Copyright © 2019 Paul Malone. All rights reserved.
//

// TODO - implement roll function here

#include "Die.h"
#include "NCArray.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

// Prototypes for helpers
static int getRandomInt(int upperLimit);
void filwht(char *rollString);

// Parses a die struct from a given string
Die init_die(char *rollString) {
    Die die;
    
    printf("before filling whitespace: %s\n", rollString);
    filwht(rollString);
    printf("filled white space: %s\n", rollString);
    
//    const char d[2] = "d";
//    const char plus[2] = "+";
//    char *token;
    char *end;
    intArray a;
    init_intArray(&a, 0);
//
    for (long i = strtol(rollString, &end, 10); rollString != end; i = strtol(rollString, &end, 10)) {
//        printf("'%.*s' -> ", (int)(end-rollString), rollString);
        rollString = end;
        if (errno == ERANGE){
            printf("range error, got ");
            errno = 0;
        } else {
            insert_intArray(&a, (int)i);
        }
//        printf("%ld\n", i);
    }

//    // Parse amount
//    token = strtok(rollString, d);
//    die.amount = (int)strtol(token, NULL, 10);
//
//    // Parse sides
//    token = strtok(NULL, d);
//    token = strtok(token, plus);
//    die.sides = (int)strtol(token, NULL, 10);
//
//    // Parse modifier
//    token = strtok(NULL, plus);
//    die.modifier = (int)strtol(token, NULL, 10);
    
    // Initialize die with values from  strtol array
    die.amount = a.array[0];
    die.sides = a.array[1];
    die.modifier = a.array[2];
    
    return die;
}

int roll(Die die) {
    int i = die.amount;
    int rollValue = 0;

    while (i > 0) {
        rollValue += getRandomInt(die.sides);
        i -= 1;
    }
    return rollValue + 1 + die.modifier;
}

/* Private functions */

// Use arc4random_uniform to return random int within a limit
static int getRandomInt(int upperLimit) {
    uint32_t u32upperLimit = (uint32_t) upperLimit;
    return (int) arc4random_uniform(u32upperLimit);
}

// Fills in all non-digit characters with whitespace to make it easier for strtol to find digits
void filwht(char *rollString) {
    int length = (int)strlen(rollString);
    for (int i = 0; i < length; ++i) {
        if (!isdigit(rollString[i])) {
            *(rollString + i) = ' ';
        }
    }
}

