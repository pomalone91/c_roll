//
//  Interactive.c
//  c_roll
//
//  Created by Paul Malone on 3/29/20.
//  Copyright © 2020 Paul Malone. All rights reserved.
//

#include <string.h>
#include "Interactive.h"
#include "../Structures/Die.h"

// Starts interactive rolling mode
int interactive(void) {
    Die d;
    char input[40];
    const char exit[5] = "exit\n";
    printf("Enter a roll: \n");
    do {
        if (fgets(input, 40, stdin)) {
            if (strncmp(input, exit, 5) != 0) {
                d = init_die(input);
                printf("%i\n", roll(d));
            } else {
                break;
            }
        }
//            printf("%i\n", strcmp(input, exit));
    } while (strncmp(input, exit, 5) != 0);
    
    return 0;
}
