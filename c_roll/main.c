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
#include <string.h>

int main(int argc, const char * argv[]) {
    Die d;
    if (argc < 2) {
        // TODO - change this so that it enters ineractive mode
        char input[40];
        const char exit[5] = "exit\n";
        printf("Enter a roll: \n");
        do {
            if (fgets(input, 40, stdin)) {
                if (strcmp(input, exit) != 0) {
                    d = init_die(input);
                    printf("%i\n", roll(d));
                }
            }
//            printf("%i\n", strcmp(input, exit));
        } while (strcmp(input, exit) != 0);
        
        return 0;
    }
    
    int i = 1;
    
    while (i < argc) {
        d = init_die((char *)argv[i]);
        printf("%i ", roll(d));
        ++i;
    }
    printf("\n");
//    d = init_die((char *)argv[1]);
    // Uncomment below for debugging
//    int i = 50; while (i > 0) { printf("%i\n", roll(d)); --i;}
//    printf("%i\n", roll(d));
    return 0;
}
