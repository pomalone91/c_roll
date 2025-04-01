//
//  mode.h
//  c_roll
//
//  Created by Paul Malone on 3/29/20.
//  Copyright © 2020 Paul Malone. All rights reserved.
//

#ifndef mode_h
#define mode_h

#include <stdio.h>
#include "roll.h"

// Usage modes
void batch(char *path);
void staticmode(int argc, char **arg);
int interactive(void);

#endif /* mode_h */