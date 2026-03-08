
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
#include "../include/utils.h"

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
 * Searches the CSV file for a password entry matching the given type and copies the password 
 * into out if found.
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
        
        // Compare specified type against the current entry in file
        if (strcmp(type, normalize_str(entry.type)) == 0) {
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

/**
 * Searches the CSV file for the password entry matching the given type, and edits it
 * by writing the new password to a new file and deleting the old.
 */
bool edit_password(char *new, char *type) {

    bool edited = false;
    PasswordEntry entry;

    // Create pointer to passwords file
    FILE *fptr = NULL;
    fptr = fopen("data/passwords.csv", "r");
    if (fptr == NULL) return false;

    // Create pointer to temp file
    FILE *temp = NULL;
    temp = fopen("data/temp.csv", "w");
    if (temp == NULL) {
        fclose(fptr);
        return false;
    }

    // Read file line by line into buffer until EOF
    char buffer[256];
    while (fgets(buffer, 256, fptr) != NULL) {
        if (!parse_entry(buffer, &entry)) continue;
        
        // Compare specified type against the current entry in file
        if (strcmp(type, normalize_str(entry.type)) == 0) {
            fprintf(temp, "%s,%s,%s\n", entry.username, new, entry.type);
            edited = true;
            continue;
        }
        fprintf(temp, "%s,%s,%s\n", entry.username, entry.password, entry.type);
    }

    fclose(fptr);
    fptr = NULL;
    fclose(temp);
    temp = NULL;

    // Remove old file and rename the temp
    remove("data/passwords.csv");
    rename("data/temp.csv", "data/passwords.csv");
    return edited;
}