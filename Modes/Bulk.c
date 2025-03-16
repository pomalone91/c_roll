//
//  Bulk.c
//  c_roll
//
//  Created by Paul Malone on 3/29/20.
//  Copyright © 2020 Paul Malone. All rights reserved.
//

#include "Bulk.h"
#include "../Structures/whroll.h"

void bulk(char *roll) {
    // printf("%s\n", roll);
    whroll r;
    r = init_whroll(roll);
    make_whroll(r);
}
