//
//  Die.c
//  c_roll
//
//  Created by Paul Malone on 10/19/19.
//  Copyright © 2019 Paul Malone. All rights reserved.
//

// TODO - implement roll function here

#include "Die.h"
#include <stdlib.h>
#include <string.h>

// Generate random number given a dice
static int getRandomInt(int upperLimit);

int roll(Die die) {
    int i = die.amount;
    int rollValue = 0;

    while (i > 0) {
        rollValue += getRandomInt(die.sides);
        i -= 1;
    }
    return rollValue + 1 + die.modifier;
}

// Parses a die struct from a given string
void parseRoll(char *rollString) {
//    const char d[2] = "d";
//    char *token;

//    printf("parsing rollString %s\n", rollString);
//    token = strtok(rollString, d);
//
//    /* get the first token */
//    token = strtok(rollString, d);
//
//    /* walk through other tokens */
//    while( token != NULL ) {
//       printf( " %s\n", token );
//
//       token = strtok(NULL, d);
//    }
    
    printf("str = %s\n", rollString);
    const char d[2] = "d";
    char *token;

    /* get the first token */
    token = strtok(rollString, d);

    /* walk through other tokens */
    while( token != NULL ) {
       printf( " %s\n", token );

       token = strtok(NULL, d);
    }
}

// Private functions
// TODO - implement a function to help me generate random numbers using arc4random

// Use arc4random_uniform to return random int within a limit
static int getRandomInt(int upperLimit) {
    uint32_t u32upperLimit = (uint32_t) upperLimit;
    return (int) arc4random_uniform(u32upperLimit);
}
