
/**
 * password.h
 * 
 * Declares functions for managing stored password entries.
 * 
 * Brendan Dileo
 */
#ifndef PASSWORD_H
#define PASSWORD_H
#include <stdbool.h>
#include "../include/entry.h"

bool add_password(PasswordEntry *entry);
bool view_password(char *type, char *out);
bool edit_password(char *new, char *type);
bool delete_password(char *type);

#endif