//
//  NCArray.h
//  c_roll
//
//  Created by Paul Malone on 10/20/19.
//  Copyright © 2019 Paul Malone. All rights reserved.
//

#ifndef NCArray_h
#define NCArray_h

#include <stdio.h>

// Public array structure
typedef struct intArray {
    int *array;
    size_t used;
    size_t size;
} intArray;

// Public function prototypes
void init_intArray(intArray *a, size_t size);
void insert_intArray(intArray *a, int element);
void free_intArray(intArray *a);

#endif /* NCArray_h */
