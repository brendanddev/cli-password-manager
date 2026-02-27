
/**
 * entry.h
 * 
 * Defines the PasswordEntry struct and functions for managing it.
 */
#ifndef ENTRY_H
#define ENTRY_H
#include <stdbool.h>

// Defines the PasswordEntry struct
typedef struct {
    char username[64];
    char password[128];
    char type[32];
} PasswordEntry;

PasswordEntry* create_entry(char *username, char *password, char *type);
void free_entry(PasswordEntry *entry);

#endif