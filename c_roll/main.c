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
#include <string.h>
#include <unistd.h>
#include "Die.h"
#include "NCArray.h"
#include "Interactive.h"

// Argument flags
enum flag {bulk, batch, normal};

int main(int argc, const char * argv[]) {
    
    // Function prototypes
    int staticMode(char *arg);
    int interactiveMode(void);
    int bulkMode(char *arg);
    int batchMode(char *arg);
    
    // Local variables and stuff
    int c;
    char *arg = NULL;
    const char **argvconst = argv;
    Die d;
    
    /*
     TODO -
     Flag possibilities...
        - crol              Interactive mode
        - crol 1d4-1        Static mode
        - crol -w 10w6u3    Warhammer-like roll. Roll 10 6-sided dice and return the count of rolls over 3
        - crol -b ~/file    crol reads in a file of rolls and gives the result for each
     */
    
    printf("argc: %i\n", argc);
    // Interactive mode
    if (argc == 1) {
        interactive();
    }

    // Switching on arg flags
    while ((c = getopt(argc, argvconst, "u:b:")) != -1) {
        switch (c) {
            case 'u':
                printf("bulk\n");
                arg = optarg;
                
                printf("optarg: %s\n", arg);
                break;
            case 'b':
                printf("batch\n");
                arg = optarg;
                printf("optarg: %s\n", arg);
                break;
            default:
                printf("normal");
                arg = optarg;
                printf("optarg: %s\n", arg);
                break;
        }
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

// Functions for each mode

int staticMode(char *arg) {
    return 0;
}

int interactiveMode(void) {
    return 0;
}

int bulkMode(char *arg) {
    return 0;
}

int batchMode(char *arg) {
    return 0;
}
