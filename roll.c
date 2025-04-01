#include <stdio.h>
#include "roll.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "helper.h"

roll init_roll(const char *roll_string) {
    roll r;
    char *end;
    size_t len = strlen(roll_string);
    // printf("%zu\n", len);
    // Switch how to handle roll string
    // Parse roll type
    char roll_type[20];
    int j = 0;

    // Indexes that will help make parsing the strings easier that we may as well get right now. 
    int d_position;
    int h_position;
    int mod_position;


    // Builds our type string and also grabs positions of the positions of 'd', 'h' and '+/-' to make parsing easier later
    for (size_t i = 0; i < len; i++)
    {
        // Writes only alphabetical characters (and +/-) to roll type string
        if (isalpha(roll_string[i]) || roll_string[i] == '+' || roll_string[i] == '-')
        {
            roll_type[j] = roll_string[i];

            // Grab the positions of important characters while we're here.
            switch (roll_string[i])
            {
            case 'd':
                d_position = i;
                break;
            case 'h':
                h_position = i;
                break;
            case '-':
                mod_position = i;
                break;
            case '+':
                mod_position = i;
            default:
                break;
            }
            j++;
        } 
    }
    roll_type[j++] = '\0';
    // Allocate some strings to parse different components of dice into.
    char amt_dice[10];
    char num_sides[10];
    char hit_tgt[10];
    char mod[10];

    // Switch roll type and call appropriate functions to handle roll
    if (strcmp(roll_type, "d") == 0)
    {
        r.amount = strtol(strncpy(amt_dice, roll_string, d_position), &end, 10);
        r.sides = strtol(strncpy(num_sides, roll_string+(d_position+1), (len - (d_position))), &end, 10);
        r.type = D;
        
        r.target = 0;
        r.modifier = 0;
        //printf("Roll Type: %s\n", r.type);
        // printf("Amount of dice: %i\n", r.amount);
        // printf("Number of sides: %i\n", r.sides);
    } else if (strcmp(roll_type, "d+") == 0 || strcmp(roll_type, "d-") == 0)
    {
        r.type = D;
        r.amount = strtol(strncpy(amt_dice, roll_string, d_position), &end, 10);
        r.sides = strtol(strncpy(num_sides, roll_string+(d_position+1), (mod_position - d_position)), &end, 10);
        r.modifier = strtol(strncpy(mod, roll_string+(mod_position+1), (len - mod_position)), &end, 10);
        if (strcmp(roll_type, "d-") == 0)
        {
            r.modifier *= -1;
        }
        
        // printf("Roll Type: %s\n", r.type);
        // printf("Amount of dice: %i\n", r.amount);
        // printf("Number of sides: %i\n", r.sides);
        // printf("Modifier: %i\n", r.modifier);
        r.target = 0;
    } else if (strcmp(roll_type, "dh") == 0)
    {
        r.type = W;
        r.amount = strtol(strncpy(amt_dice, roll_string, d_position), &end, 10);
        r.sides = strtol(strncpy(num_sides, roll_string+(d_position+1), (h_position - d_position)), &end, 10);
        r.target = strtol(strncpy(mod, roll_string+(h_position+1), (len - h_position)), &end, 10);
        r.modifier = 0;
        // printf("Roll Type: %s\n", r.type);
        // printf("Amount of dice: %i\n", r.amount);
        // printf("Number of sides: %i\n", r.sides);
        // printf("Target: %i\n", r.target);
    } else if (strcmp(roll_type, "dh+") == 0 || strcmp(roll_type, "dh-") == 0)
    {
        r.type = W;
        r.amount = strtol(strncpy(amt_dice, roll_string, d_position), &end, 10);
        r.sides = strtol(strncpy(num_sides, roll_string+(d_position+1), (h_position - d_position)), &end, 10);
        r.target = strtol(strncpy(mod, roll_string+(h_position+1), (mod_position - h_position)), &end, 10);
        r.modifier = strtol(strncpy(hit_tgt, roll_string+(mod_position+1), (len - mod_position)), &end, 10);
        if (strcmp(roll_type, "dh-") == 0)
        {
            r.modifier *= -1;
        }
        
        // printf("Roll Type: %s\n", r.type);
        // printf("Amount of dice: %i\n", r.amount);
        // printf("Number of sides: %i\n", r.sides);
        // printf("Target: %i\n", r.target);
        // printf("Modifier: %i\n", r.modifier);
    } else {
        printf("Invalid roll string.\n");
    }

    return r;
}

int make_roll(roll die) {
    int result = 0;
    int i = 0;
    switch (die.type)
    {
    case D:
        while (i < die.amount) {
            result += getRandomInt(die.sides);
            i++;
        }
        result += die.modifier;
        break;
    case W:
        result = 0;

        printf("%i to hit\n", die.target);

        char sign = (die.modifier >= 0 ? '+' : '-');
        while (i < die.amount) {
            if (die.modifier < 0)
            {
                int r = getRandomInt(die.sides);
                printf("Roll #%i: %i - %i = %i\n", i+1, r, (die.modifier * -1), r + die.modifier);
                if (r + die.modifier >= die.target) {
                    result++;
                }
            } else
            {
                int r = getRandomInt(die.sides);
                printf("Roll #%i: %i + %i = %i\n", i+1, r, die.modifier, r + die.modifier);
                if (r + die.modifier >= die.target) {
                    result++;
                }
            }
            i++;
        }
        break;
    default:
        printf("Something went wrong.\n");
        break;
    }
    return result;
}