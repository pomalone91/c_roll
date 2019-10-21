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

// Parses a die struct from a given string
Die init_die(char *rollString) {
    Die die;
    const char d[2] = "d";
    const char plus[2] = "+";
    char *token;

    // Parse amount
    token = strtok(rollString, d);
    die.amount = (int)strtol(token, NULL, 10);
    
    // Parse sides
    token = strtok(NULL, d);
    token = strtok(token, plus);
    die.sides = (int)strtol(token, NULL, 10);
    
    // Parse modifier
    token = strtok(NULL, plus);
    die.modifier = (int)strtol(token, NULL, 10);
    
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

// Returns an array of the tokens parsed from a string given a delimiter
int parseAmount(char *rollString) {
    return 0;
}

