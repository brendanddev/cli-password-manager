
/**
 * utils.c
 * 
 * Implements utility functions for debugging the password manager.
 * 
 * Brendan Dileo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"

/**
 * Prints a string character by character, displaying hidden characters like null terminators, newlines,
 * and carriage returns as readable labels for debugging.
 */
void print_raw(char *str) {
    for (int i = 0; i < strlen(str) + 1; i++) {
        if (str[i] == '\0') printf("<NULL>");
        else if (str[i] == '\n') printf("<LB>");
        else if (str[i] == '\r') printf("<CR>");
        else printf("%c", str[i]);
    }
}