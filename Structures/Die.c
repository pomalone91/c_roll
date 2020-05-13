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
static void filwht(char *rollString);

// Parses a die struct from a given string
Die init_die(char *rollString) {
    Die die;
    
    char target = '-';
    char *check_result = rollString;
    // Check if the string has '-', if it does the modifier will need to be negative
    check_result = strchr(check_result, target);
    
    filwht(rollString);
    
    char *end;
    
    intArray a;
    init_intArray(&a, 0);
    
    
//
    for (long i = strtol(rollString, &end, 10); rollString != end; i = strtol(rollString, &end, 10)) {
        rollString = end;
        if (errno == ERANGE){
            printf("range error: ");
            errno = 0;
        } else {
            insert_intArray(&a, (int)i);
        }
//        printf("%ld\n", i);
    }
    
    // Initialize die with values from  strtol array
    die.amount = (a.used >= 1) ? a.array[0] : 0;
    die.sides = (a.used >= 2) ? a.array[1] : 0;
    if (check_result) {
        die.modifier = (a.used >= 3) ? -a.array[2] : 0;
    } else {
        die.modifier = (a.used >= 3) ? a.array[2] : 0;
    }
    
    return die;
}

int roll(Die die) {
    int i = die.amount;
    int rollValue = 0;

    while (i > 0) {
        rollValue += getRandomInt(die.sides);
        i -= 1;
    }
    return rollValue + die.modifier;
}

/* Private functions */

// Use arc4random_uniform to return random int within a limit
static int getRandomInt(int upperLimit) {
    if (upperLimit == 0) {
        return 0;
    }
    // TODO set a lower limit?
    return (int) arc4random_uniform((uint32_t)upperLimit) + 1;
}

// Fills in all non-digit characters with whitespace to make it easier for strtol to find digits
static void filwht(char *rollString) {
    int length = (int)strlen(rollString);
    for (int i = 0; i < length; ++i) {
        if (!isdigit(rollString[i])) {
            // Uses pointer arithmetic to iterate through char string
            *(rollString + i) = ' ';
        }
    }
}

