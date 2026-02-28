
/**
 * entry.c
 * 
 * Implements the PasswordEntry struct functions.
 * 
 * Brendan Dileo
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/entry.h"


/**
 * Creates a new PasswordEntry on the heap from the given fields.
 * Caller is responsible for freeing with free_entry().
 */
PasswordEntry* create_entry(char *username, char *password, char *type) {
    if (username == NULL || password == NULL || type == NULL) {
        return NULL;
    }

    PasswordEntry *entry = malloc(sizeof(PasswordEntry));
    if (entry == NULL) {
        return NULL;
    }

    strcpy(entry->username, username);
    strcpy(entry->password, password);
    strcpy(entry->type, type);
    return entry;
}


/**
 * Frees the memory previously allocated by the PasswordEntry.
 */
void free_entry(PasswordEntry *entry) {
    if (entry != NULL) {
        free(entry);
    }
}

/**
 * Parses a raw CSV line into a PasswordEntry struct
 */
bool parse_entry(char *line, PasswordEntry *out) {
    if (line == NULL) {
        return false;
    }

    // Split line by commas
    char *username = strtok(line, ",");
    char *password = strtok(NULL, ",");
    char *type = strtok(NULL, ",");

    if (username == NULL || password == NULL || type == NULL) {
        return false;
    }

    strcpy(out->username, username);
    strcpy(out->password, password);
    strcpy(out->type, type);
    return true;
}

/**
 * Prints the fields of a PasswordEntry to stdout
 */
void print_entry(PasswordEntry *entry) {
    if (entry == NULL) {
        return;
    }
    printf("Username: %s, Password: %s, Type: %s\n", entry->username, entry->password, entry->type);
}