#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int main(void) {
    
    printf("Enter USERNAME,PASSWORD,TYPE \n");

    // Allocate memory for the input string to read
    char *input = NULL;
    input = malloc(256 * sizeof(char));
    if (input == NULL) return -1;

    // scanf("%s", input);
    fgets(input, 256, stdin);
    printf("You entered: %s", input);

    // Creates pointer to the first substring seperated by the delimeter
    char *token = strtok(input, ",");

    // Loop through each token
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");      // Get next token
    }

    free(input);
    input = NULL;
    return 0;
}
