//
//  whroll.h
//  c_roll
//
//  Created by Paul Malone on 3/13/2025.

#ifndef whroll_h
#define whroll_h

#include <stdio.h>

// Die structure
typedef struct whroll {
    int sides;
    int amount;
    int target; // The target value a roll is trying to beat to be considered a success
    int modifier; // If there is a +/- affecting the roll
} whroll;

// Public interface
whroll init_whroll(char *rollString);
int make_whroll(whroll die);

#endif /* whroll_h */
