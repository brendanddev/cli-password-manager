
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

    // This would be read from user
    char username[64] = "ADMIN";
    char password[128] = "ADMIN";
    char type[32] = "TEST";

    // // Create the password entry
    // PasswordEntry *entry = create_entry(username, password, type);
    // if (entry == NULL) {
    //     return -1;
    // }

    // // Print and write entry to file
    // print_entry(entry);
    // add_password(entry);

    // View password based on specified type
    char pswd[128];
    if (view_password(type, pswd)) {
        printf("Found Password: %s\n", pswd);
    } else {
        printf("Could not find password!\n");
    }

    char new_pswd[128] = "PASSWORD";
    if (edit_password(new_pswd, type)) {
        printf("Edited password successfully!\n");
    } else {
        printf("Failed to edit the password!\n");
    }

    char delete_type[32] = "TEST";
    if (delete_password(delete_type)) {
        printf("The password was deleted successfully!\n");
    } else {
        printf("Could not find the password to delete: %s\n", delete_type);
    }

    // free_entry(entry);
    return 0;
}