//
//  Die.h
//  c_roll
//
//  Created by Paul Malone on 10/19/19.
//  Copyright © 2019 Paul Malone. All rights reserved.
//

// TODO - function to build a Die struct from a string like 1d8+1

#ifndef Die_h
#define Die_h

#include <stdio.h>

// Die structure
typedef struct Die {
    int sides;
    int amount;
    int modifier;
} Die;

// Public interface
int roll(Die die);
Die parseRoll(char *rollString);
#endif /* Die_h */
