//
//  Die.h
//  c_roll
//
//  Created by Paul Malone on 10/19/19.

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
Die init_die(char *rollString);
int roll_die(Die die);

#endif /* Die_h */
