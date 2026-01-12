#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "password.h"


// Prototypes
int display_menu(void);
void handle_choice(int choice);


int main(void) {
    
    int choice;
    do {
        choice = display_menu();
        handle_choice(choice);
    } while (choice != 0);

    return 0;
}

int display_menu(void) {
    printf("========= CLI Password Manager =========\n");
    printf("1) Add new password\n");
    printf("2) View Password\n");
    printf("0) Exit ");
    printf("Enter your choice: \n");

    char line[3];
    fgets(line, 3, stdin);
    int choice = atoi(line);
    printf("You entered: %d\n", choice);
    return choice;
}

void handle_choice(int choice) {

    switch (choice) {

        case 1:
            printf("Enter USERNAME,PASSWORD,TYPE in the provided format: \n");

            // Allocate memory for the input string to read
            char *input = NULL;
            input = malloc(265 * sizeof(char));
            if (input == NULL) return;

            fgets(input, 256, stdin);
            printf("You entered: %s", input);

            if (add_password(input)) {
                printf("Successfully wrote the password.\n");
            } else {
                printf("Failed to write the password.\n");
            }

            // Free memory allocated for input string
            free(input);
            input = NULL;

            break;
        case 2:
            printf("Enter the TYPE of password to view: \n");

            char *type = NULL;
            type = malloc(100 * sizeof(char));
            if (type == NULL) return;

            fgets(type, 100, stdin);
            char password[256];
            if (view_password(type, password)) {
                printf("Password: %s\n", password);
            } else {
                printf("Failed to find a corresponding password.\n");
            }

            free(type);
            type = NULL;

            break;
        default:
            break;
    }
    printf("\n");
}