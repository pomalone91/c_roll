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
    Die die = {4, 1, 1};
    
    printf("You rolled: %i\n", roll(die));

    char rollstring[6] = "1d8";
    parseRoll(rollstring);
    printf("size of int = %lu\n", sizeof(die));
    
    intArray array;
    
    init_intArray(&array, 1);
    insert_intArray(&array, 2);
    
    for (int i = 0; i < array.size; i++) {
        printf("%i\n", array.array[i]);
    }
    
    insert_intArray(&array, 100);
    
    for (int i = 0; i < array.size; i++) {
        printf("%i\n", array.array[i]);
    }
    
    printf("array size %zu\n", array.size);
    printf("array used %zu\n", array.used);
    
    insert_intArray(&array, 100);
    
    printf("array size %zu\n", array.size);
    printf("array used %zu\n", array.used);
    
    free_intArray(&array);
    
    printf("array size %zu\n", array.size);
    printf("array used %zu\n", array.used);
    
    return 0;
}
