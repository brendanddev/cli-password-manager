#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool add_password(char *input);
bool view_password(char *type);

int main(void) {
    
    printf("Enter USERNAME,PASSWORD,TYPE \n");

    // Allocate memory for the input string to read
    char *input = NULL;
    input = malloc(256 * sizeof(char));
    if (input == NULL) return -1;

    // scanf("%s", input);
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


    printf("Enter the type of password to view: \n");

    char *type = NULL;
    type = malloc(100 * sizeof(char));
    if (type == NULL) return -1;

    fgets(type, 100, stdin);
    printf("You entered: %s", type);

    // Creates pointer to the first substring seperated by the delimeter
    char *token = strtok(input, ",");

    // Loop through each token
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");      // Get next token
    }

    free(type);
    type = NULL;


    return 0;
}


// Adds a new password entry to the csv file
bool add_password(char *input) {

    // Create a file pointer to the opened file
    FILE *fptr = NULL;
    fptr = fopen("passwords.csv", "a");
    if (fptr == NULL) return false;

    // Writes the input text to the file
    fprintf(fptr, input);

    // Close the open file and nullify pointer
    fclose(fptr);
    fptr = NULL;
    return true;
}

// View a password by type
bool view_password(char *type) {

    FILE *fptr = NULL;
    fptr = fopen("passwords.csv", "r");
    if (fptr == NULL) return false;

    // char *token = strtok(fptr, ",");

    // // Loop through each token
    // while (token != NULL) {
    //     printf("%s\n", token);
    //     token = strtok(NULL, ",");      // Get next token
    // }


    // Close the open file and nullify pointer
    fclose(fptr);
    fptr = NULL;
    return true;
}