
/**
 * main.c
 * 
 * Entry point for the CLI password manager. Handles the main loop and user input.
 * 
 * Brendan Dileo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/entry.h"
#include "../include/password.h"



int main(void) {

    char username[64] = "ADMIN";
    char password[128] = "ADMIN";
    char type[32] = "TEST";

    PasswordEntry *entry = create_entry(username, password, type);
    if (entry == NULL) {
        return -1;
    }

    print_entry(entry);

    free_entry(entry);
    return 0;
}