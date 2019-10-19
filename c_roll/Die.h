//
//  Die.h
//  c_roll
//
//  Created by Paul Malone on 10/19/19.
//  Copyright © 2019 Paul Malone. All rights reserved.
//

// TODO - func prototypes for public functions
// TODO - implement Die struct here

#ifndef Die_h
#define Die_h

#include <stdio.h>

// Die structure
typedef struct Die {
    int sides;
    int amount;
    int modifier;
} Die;

// Public functions
int roll(Die die);

#endif /* Die_h */
