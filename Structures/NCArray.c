//
//  NCArray.c
//  c_roll
//
//  Created by Paul Malone on 10/20/19.
//  Copyright © 2019 Paul Malone. All rights reserved.
//

#include "NCArray.h"
#include <stdlib.h>

// create a resizing intArray with an initial size
void init_intArray(intArray *a, size_t size) {
    a->array = (int *)calloc(sizeof(int), size);
    a->used = 0;
    a->size = size;
}

// Inserts a new element into the array, resizing it if necessary
void insert_intArray(intArray *a, int element) {
    // First check if array is full and resize if needed
    if (a->used == a->size) {
        a->size *= 2;
        // realloc the array w/ new size
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    // Does the actual insert and increments a->used which is tracking the end of the array.
    a->array[a->used] = element;
    a->used++;
}

// Resets *a as if it had just been initialized
void free_intArray(intArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->size = 0;
}
