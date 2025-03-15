//
//  Bulk.c
//  c_roll
//
//  Created by Paul Malone on 3/29/20.
//  Copyright © 2020 Paul Malone. All rights reserved.
//

#include "Bulk.h"
#include "../Structures/whroll.h"

void bulk(void) {
    // TODO - implement warhammer bulk mode
    printf("Warhammer bulk mode\n");
    char *roll = "100d6h4";
    whroll r = init_whroll(roll);

    make_whroll(r);
}
