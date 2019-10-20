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
    
    printf("You rolled: %i\n", roll(die));

    char rollstring[6] = "1d8";
    parseRoll(rollstring);
    return 0;
}
