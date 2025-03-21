/*
    whroll.c
    Implementation for warhammer style rolls

    Examples: 
        - 6d6h4 means roll 6 six-sided die hitting on 4s
        - 10d6h4-1 means roll 10 six-sided die hitting on 4s with a -1 modifier
*/

#include "whroll.h"
#include "../helper.h"
#include <string.h>
#include <stdlib.h>

// Parse a warhammer roll from a string
whroll init_whroll(char *roll_string) {
    whroll roll;

    /*
        Basic Steps
        1. Scan until you see a d
            If no 'd' then warn the user
        2. Assign numbers before d to amount
        3. Scan until you see an 'h'
            If no 'h' raise an error
        4. Assign numbers before h, but after d to hit target
        5. Scan until you see a + or -
        6. Mark if modifier is negative or positive
        7. Assign numbers after to modifier
    */

    puts(roll_string);
    // Random stuff we'll use multiple times
    char mod;
    int l = strlen(roll_string);
    char *end;

    // Getting the amount of die
    int i = 0;
    
    while (roll_string[i] != 'd')   // Find the position of the 'd' char
    {
        i++;
    }
    char amount[i]; // Use i to write correct size char array
    
    strncpy(amount, roll_string, i); // Copy the first i chars to amount string.
    roll.amount = strtol(amount, &end, 10); // Convert to long int and assign to struct

    // printf("%i\n", roll.amount);
    // printf("Got amount okay\n");
    // Get the number of sides
    // Going to copy everything after i (where we found 'd') to another string
    i++;    //Scoot i up the string past 'd'
    int j = 0;

    char sides_string[l-i];
    // printf("l = %i\n", l);
    while (i < l) {
        sides_string[j] = roll_string[i];
        j++, i++;
        // printf("i = %i, j = %i, %c\n", i, j, roll_string[i]);
    }
    printf("Line 63\n");
    // Reset i for finding 'h'
    i = 0;

    while (sides_string[i] != 'h')
    {
        i++;
    }
    char sides[i];
    strncpy(sides, sides_string, i);
    roll.sides = strtol(sides, &end, 10);

    printf("Got sides okay\n");
    // Get the target to hit for the dice to be a success
    // puts(sides_string);
    i++;
    j = 0;
    l = strlen(sides_string);
    char hit[l-i];
    while ((sides_string[i] != '-' || sides_string[i] != '+') && i < l)
    {
        hit[j] = sides_string[i];
        j++, i++;
        if (sides_string[i] == '-') {
            mod = sides_string[i];
            break;
        } else if (sides_string[i] == '+') {
            mod = sides_string[i];
            break;
        }
            
    }

    roll.target = strtol(hit, &end, 10);

    printf("Got target okay\n");
    // Modifier
    if (sides_string[i] == '-' || sides_string[i] == '+') {
        j = 0;
        char m[l-i];
        while (i < l) {
            m[j] = sides_string[i];
            i++, j++;
        }
        roll.modifier = strtol(m, &end, 10);
        
    } else {
        roll.modifier = 0;
    }
    printf("Got modifier okay\n");
  
    // printf("%i\n", roll.amount);
    // printf("%i\n", roll.sides);
    // printf("%i\n", roll.target);
    // printf("%i\n", roll.modifier);

    printf("Finished initializing\n");
    return roll;
};

int make_whroll(whroll die){
    printf("Making roll\n");
    int i = 0;
    int hits = 0;
    int roll_value = 0;

    printf("%i to hit\n", die.target);

    char sign = (die.modifier >= 0 ? '+' : '-');
    while (i < die.amount) {
        if (die.modifier < 0)
        {
            int result = getRandomInt(die.sides);
            printf("Roll #%i: %i - %i = %i\n", i, result, (die.modifier * -1), result + die.modifier);
            if (result + die.modifier >= die.target) {
                hits++;
            }
        } else
        {
            int result = getRandomInt(die.sides);
            printf("Roll #%i: %i + %i = %i\n", i, result, die.modifier, result + die.modifier);
            if (result + die.modifier >= die.target) {
                hits++;
            }
        }
        
        
        i++;
        
    }

    printf("Number of hits: %i\n", hits);

    return hits;
};