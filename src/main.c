#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Prototypes
int display_menu(void);
void handle_choice(int choice);


int main(void) {
    int choice = display_menu();
    handle_choice(choice);
    return 0;
}

int display_menu(void) {
    printf("========= CLI Password Manager =========");
    printf("1) Add new password\n");
    printf("2) Edit existing password\n");
    printf("3) Delete existing password\n");
    printf("4) Generate new password\n");
    printf("Enter your choice: \n");

    int choice;
    scanf("%d", &choice);
    printf("You entered: %d\n", choice);
    return choice;
}

void handle_choice(int choice) {

    switch (choice) {
    
        case 0:
            printf("You entered 0?");
            break;
        case 1:
            printf("You entered 1?");
            break;
        case 2:
            printf("You entered 2?");
            break;
        case 3:
            printf("You entered 2?");
            break;
        case 4:
            printf("You entered 4?");
            break;
        default:
            break;
    }
    printf("\n");
}