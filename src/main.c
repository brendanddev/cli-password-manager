#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


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
    printf("========= CLI Password Manager =========");
    printf("1) Add new password\n");
    printf("2) View Password\n");
    printf("0) Exit ");
    printf("Enter your choice: \n");

    int choice;
    scanf("%d", &choice);
    printf("You entered: %d\n", choice);
    return choice;
}

void handle_choice(int choice) {

    switch (choice) {

        case 1:
            printf("Enter USERNAME, PASSWORD, TYPE in the provided format: \n");
            break;
        case 2:
            printf("Enter the TYPE of password to view: \n");
            break;
        default:
            break;
    }
    printf("\n");
}