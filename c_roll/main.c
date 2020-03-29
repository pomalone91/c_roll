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
#include "Static.h"

// Argument flags
enum flag {bulk, batch, normal};

int main(int argc, const char * argv[]) {
    
    // Function prototypes
    void staticmode(int argc, const char **arg);
    int bulkMode(char *arg);
    int batchMode(char *arg);
    
    // Local variables and stuff
    int c;
    char *arg = NULL;
    const char **argvconst = argv;
    
    /*
     TODO -
     Flag possibilities...
        - crol              Interactive mode
        - crol 1d4-1        Static mode
        - crol -w 10w6u3    Warhammer-like roll. Roll 10 6-sided dice and return the count of rolls over 3
        - crol -b ~/file    crol reads in a file of rolls and gives the result for each
     */
    
    printf("argc: %i\n", argc);
    if (argc == 1) {
        interactive();
    } else if (argc > 1 && getopt(argc, argvconst, "u:b:") == -1) {
        staticmode(argc, argv);
    } else {
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
    }
    return 0;
}

int bulkMode(char *arg) {
    return 0;
}

int batchMode(char *arg) {
    return 0;
}
