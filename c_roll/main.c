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
    if (argc != 2) {
        printf("No roll provided\n");
        return EXIT_FAILURE;
    }
    Die d;
    d = init_die((char *)argv[1]);
    printf("You rolled: %i\n", roll(d));
//    int i = 10;
//    while (i > 0) {
//        printf("You rolled: %i\n", roll(d));
//        i--;
//    }

    
    

    
    return 0;
}
