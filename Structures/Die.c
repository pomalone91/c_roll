//
//  Die.c
//  c_roll
//
//  Created by Paul Malone on 10/19/19.
//  Copyright © 2019 Paul Malone. All rights reserved.
//

#include "Die.h"
#include "NCArray.h"
#include "../helper.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

// Parses a die struct from a given string
Die init_die(char *rollString) {
    Die die;
    
    // Check if the string has '-', if it does the modifier will need to be negative
    char *check_result = strchr(rollString, '-');
    // printf("%s\n", check_result);
    // printf("%s\n", rollString);
    
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
    // printf("%i\n", die.amount);
    // printf("%i\n", die.sides);
    // printf("%i\n", die.modifier);
    int i = die.amount;
    int rollValue = 0;

    while (i > 0) {
        rollValue += getRandomInt(die.sides);
        i -= 1;
    }
    return rollValue + die.modifier;
}