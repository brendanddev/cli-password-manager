
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

void display_menu(void);
int get_input(void);
void handle_input(int choice);

int main(void) {

    int choice;
    do {
        display_menu();
        choice = get_input();
        handle_input(choice);
    } while (choice != 5);

    return 0;











    // // This would be read from user
    // char username[64] = "ADMIN";
    // char password[128] = "ADMIN";
    // char type[32] = "TEST";

    // // // Create the password entry
    // // PasswordEntry *entry = create_entry(username, password, type);
    // // if (entry == NULL) {
    // //     return -1;
    // // }

    // // // Print and write entry to file
    // // print_entry(entry);
    // // add_password(entry);

    // // View password based on specified type
    // char pswd[128];
    // if (view_password(type, pswd)) {
    //     printf("Found Password: %s\n", pswd);
    // } else {
    //     printf("Could not find password!\n");
    // }

    // char new_pswd[128] = "PASSWORD";
    // if (edit_password(new_pswd, type)) {
    //     printf("Edited password successfully!\n");
    // } else {
    //     printf("Failed to edit the password!\n");
    // }

    // char delete_type[32] = "TEST";
    // if (delete_password(delete_type)) {
    //     printf("The password was deleted successfully!\n");
    // } else {
    //     printf("Could not find the password to delete: %s\n", delete_type);
    // }

    // // free_entry(entry);
    // return 0;
}

/**
 * Displays the password manager menu options to stdout.
 */
void display_menu(void) {
    printf(
        "======CLI PASSWORD MANAGER======\n"
        "BY BRENDAN DILEO\n"
        "1) View a password\n"
        "2) Add a password\n"
        "3) Edit a password\n"
        "4) Delete a password\n"
        "5) Exit\n"
        "Enter your choice: \n"
    );
}

/**
 * Reads a line from stdin, converts to an integer, and returns it 
 * representing the users choice.
 */
int get_input(void) {
    char line[3];
    fgets(line, 3, stdin);
    int choice = atoi(line);
    printf("You entered: %d\n", choice);
    return choice;
}

/**
 * Handles the user input.
 */
void handle_input(int choice) {

    if (choice == 1) {
    } else if (choice == 2) {
    } else if (choice == 3) {
    } else if (choice == 4) {
    } else if (choice == 5) {
        printf("Goodbye!\n");
        return;
    } else {
        printf("This was not an option. Please try again!\n");
    }
}
