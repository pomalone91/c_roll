//
//  main.c
//  c_roll
//
//  Created by Paul Malone on 10/19/19.
//  Copyright © 2019 Paul Malone. All rights reserved.
//

/*****************************************
 TODOs
 TODO - Figure out how to architect this
*****************************************/

#include <stdio.h>
#include "Die.h"

int main(int argc, const char * argv[]) {
    Die die = {4, 1, 1};
    
    int i = 20;
    while (i > 0) {
        printf("You rolled: %i\n", roll(die));
        i -= 1;
    }
    return 0;
}
