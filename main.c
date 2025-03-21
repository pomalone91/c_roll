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
#include "Structures/Die.h"
#include "Structures/whroll.h"
#include "Structures/NCArray.h"
#include "Modes/Interactive.h"
#include "Modes/Static.h"
#include "Modes/Batch.h"
#include "Modes/Bulk.h"
#include "helper.h"

// Argument flags
//enum flag {bulk, batch, normal};

int main(int argc, char *argv[]) {
    //const char *argv[]) {
    
    
    // Local variables and stuff
    int c;
    char *arg = NULL;
    int flagused = 0;
    
    /*
     TODO -
     Flag possibilities...
        - crol              Interactive mode
        - crol 1d4-1        Static mode
        - crol -w 10w6u3    Warhammer-like roll. Roll 10 6-sided dice and return the count of rolls over 3
        - crol -b ~/file    crol reads in a file of rolls and gives the result for each
     */
    
    if (argc == 1) {
        interactive();
    } else {
        // Switching on arg flags
        while ((c = getopt(argc, argv, "u:b:h")) != -1) {
            switch (c) {
                case 'h':
                    help(); // TODO - help function
                    flagused = 1;
                    break;
                case 'u':
                    arg = optarg;
                    // printf("%s\n", arg);
                    bulk(arg);
                    flagused = 1;
                    break;
                case 'b':
                    arg = optarg;
                    batch(arg);
                    flagused = 1;
                    break;
                default:
                    printf("Invalid argument option ");
                    arg = optarg;
                    printf("optarg: %s\n", arg);
                    break;
            }
        }
    }
    
    if (argc > 1 && flagused == 0) {
        staticmode(argc, argv);
    } else
    return 0;
}
