//
//  roll.h
//  c_roll
//
//  Created by Paul Malone on 3/21/2025.

#ifndef roll_h
#define roll_h

#include <stdio.h>

// Roll structure
typedef struct roll {
    int sides;
    int amount;
    int target; // The target value a roll is trying to beat to be considered a success
    int modifier; // If there is a +/- affecting the roll
    char *type;
} roll;

// Public interface
roll init_roll(const char *roll_string);
int make_roll(roll die);

#endif /* roll_h */
