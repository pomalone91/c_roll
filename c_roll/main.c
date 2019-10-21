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
#include <stdlib.h>
#include "Die.h"
#include "NCArray.h"

int main(int argc, const char * argv[]) {
    Die d;
    char rollstring[6] = "1d8+1";
    d = init_die(rollstring);
    printf("You rolled: %i\n", roll(d));
    int i = 10;
    while (i > 0) {
        printf("You rolled: %i\n", roll(d));
        i--;
    }

    
    

    
    return 0;
}
