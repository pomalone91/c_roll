//
//  roll.h
//  c_roll
//
//  Created by Paul Malone on 3/21/2025.

#ifndef roll_h
#define roll_h

#include <stdio.h>

typedef enum {
    D,
    W,
} RollType;

// Roll structure
typedef struct Roll {
    int sides;
    int amount;
    int target; // The target value a roll is trying to beat to be considered a success
    int modifier; // If there is a +/- affecting the roll
    RollType type;
} Roll;

// Public interface
Roll roll_init(const char *roll_string);
int roll_throw(Roll die);

#endif /* roll_h */
