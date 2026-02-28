
/**
 * password.c
 * 
 * Implements functions for managing stored password entries.
 * 
 * Brendan Dileo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/**
 * Searches the CSV file for a password entry matching the given type and copies the password into out if found.
 */
bool view_password(char *type, char *out) {

    PasswordEntry entry;
    FILE *fptr = NULL;
    fptr = fopen("data/passwords.csv", "r");
    if (fptr == NULL) return false;

    // Allocate memory on stack for the contents of file
    char buffer[256];

    // Read file line by line into buffer until EOF
    while (fgets(buffer, 256, fptr) != NULL) {
        if (!parse_entry(buffer, &entry)) continue;
        
        printf("ENTRY TYPE: %s\n", entry.type);
        
        if (strcmp(type, entry.type) == 0) {
            memcpy(out, entry.password, 256);
            fclose(fptr);
            fptr = NULL;
            return true;
        }
    }

    fclose(fptr);
    fptr = NULL;
    return false;
}
