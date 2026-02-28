
/**
 * password.c
 * 
 * Implements functions for managing stored password entries.
 * 
 * Brendan Dileo
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/password.h"

/**
 * Appends a new password entry to the CSV file.
 */
bool add_password(PasswordEntry *entry) {

    // Create pointer to opened file
    FILE *fptr = NULL;
    fptr = fopen("data/passwords.csv", "a");
    if (fptr == NULL) return false;

    // Write to file
    fprintf(fptr, "%s,%s,%s\n", entry->username, entry->password, entry->type);

    fclose(fptr);
    fptr = NULL;
    return true;
}

