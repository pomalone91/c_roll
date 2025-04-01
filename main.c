//
//  main.c
//  c_roll
//
//  Created by Paul Malone on 10/19/19.
//  Copyright © 2019 Paul Malone. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "roll.h"
#include "helper.h"
#include <bits/getopt_core.h>
#include "mode.h"

// Argument flags
//enum flag {bulk, batch, normal};

int main(int argc, char *argv[]) {
    //const char *argv[]) {
    
    
    // Local variables and stuff
    int c;
    char *arg = NULL;
    int flagused = 0;
    
    if (argc == 1) {
        interactive();
    } else {
        // Switching on arg flags
        while ((c = getopt(argc, argv, "b:h")) != -1) {
            switch (c) {
                case 'h':
                    help(); // TODO - help function
                    flagused = 1;
                    break;
                // case 'u':
                    // arg = optarg;
                    // printf("%s\n", arg);
                    // bulk(arg);
                    // flagused = 1;
                    // break;
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
