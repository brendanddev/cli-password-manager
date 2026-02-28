
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
