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
Die parseRoll(char *rollString) {
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
    const char p[2] = "+";
    const char m[2] = "-";
    char *token;
    // Array to hold the values we parse to build the struct
    int values[3] = {0, 0, 0};
    int i = 0;

    /* get the first token */
    token = strtok(rollString, d);

    /* walk through other tokens */
    while( token != NULL ) {
       printf( " %s\n", token );
        // Convert token to int then store it in values
        values[i] = (int)strtol(token, NULL, 10);
        i++;

       token = strtok(NULL, d);
    }
    
    Die die;
    die.amount = values[0];
    die.sides = values[1];
    die.modifier = values[2];
    
    return die;
}

/* Private functions */

// Use arc4random_uniform to return random int within a limit
static int getRandomInt(int upperLimit) {
    uint32_t u32upperLimit = (uint32_t) upperLimit;
    return (int) arc4random_uniform(u32upperLimit);
}

// Returns an array of the tokens parsed from a string given a delimiter
int parseAmount(char *rollString) {
    return 0;
}

