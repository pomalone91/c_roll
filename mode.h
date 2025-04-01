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
void mode_batch(char *path);
void mode_static(int argc, char **arg);
int mode_interactive(void);
void mode_help();

#endif /* mode_h */