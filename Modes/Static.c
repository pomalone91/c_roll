//
//  Static.c
//  c_roll
//
//  Created by Paul Malone on 3/29/20.
//  Copyright © 2020 Paul Malone. All rights reserved.
//

#include "Static.h"
#include "../Structures/Die.h"

void staticmode(int argc, char **argv) {
    Die staticd;
    int i = 1;
    
    while (i < argc) {
        staticd = init_die((char *)argv[i]);
        printf("%i ", roll(staticd));
        ++i;
    }
    printf("\n");
}
