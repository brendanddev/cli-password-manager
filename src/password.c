#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password.h"


// Adds a new password entry to the csv file
bool add_password(char *input) {

    // Create a file pointer to the opened file
    FILE *fptr = NULL;
    fptr = fopen("passwords.csv", "a");
    if (fptr == NULL) return false;

    // Split input by delimeter and encode password before writing
    char *username = strtok(input, ",");
    char *password = strtok(NULL, ",");
    char *encoded_password = encode(password);
    char *type = strtok(NULL, ",");

    // Writes the input text to the file
    fprintf(fptr, "%s,%s,%s\n", username, encoded_password, type);

    // Close the open file and nullify pointer
    fclose(fptr);
    fptr = NULL;
    return true;
}

// View a password by type
bool view_password(char *type, char *out_password) {

    FILE *fptr = NULL;
    fptr = fopen("passwords.csv", "r");
    if (fptr == NULL) return false;

    // Allocate memory on the stack for the file contents (fixed size buffer)
    char contents[256];

    // Read the file line by line into the buffer until EOF is reached or read error occurs
    while (fgets(contents, 256, fptr) != NULL) {
        char *username = strtok(contents, ",");
        char *password = strtok(NULL, ",");
        char *ptype = strtok(NULL, ",");

        // Find where new line character is in string with `strcspn`, go to that index, and replace with null terminator
        if (ptype != NULL && type != NULL) {
            normalize_str(ptype);
            normalize_str(type);
        }

        if (strcmp(type, ptype) == 0) {
            char *decoded = encode(password);
            memcpy(out_password, decoded, 256);
            return true;
        }
    }

    // Close the open file and nullify pointer
    fclose(fptr);
    fptr = NULL;
    return false;
}

// Edits a password by type
bool edit_password(char *new_password, char *type) {

    // Open the passwords csv file
    FILE *fptr = NULL;
    fptr = fopen("passwords.csv", "r");
    if (fptr == NULL) return false;

    // Open a temporary file to write updated contents into
    FILE *temp = NULL;
    temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        fclose(fptr);
        return false;
    }

    // Allocate memory on the stack for the contents of the file,
    // the original contents, and whether the password has been edited or not
    char contents[256];
    char original[256];
    bool edited = false;

    // Continue reading lines of the file until the end
    while (fgets(contents, 256, fptr) != NULL) {

        // Copy the current line into the original buffer before tokenizing
        strcpy(original, contents);

        // Split the current line into username, password, and type
        char *username = strtok(contents, ",");
        char *password = strtok(NULL, ",");
        char *ptype = strtok(NULL, ",");

        // Normalize both strings for comparison
        if (ptype != NULL && type != NULL) {
            normalize_str(ptype);
            normalize_str(type);
            normalize_str(new_password);
        }

        // Check if we found type of password to edit
        if (strcmp(ptype, type) == 0) {
            // Write the line including the updated password to the temp file
            fprintf(temp, "%s,%s,%s\n", username, new_password, ptype);
            edited = true;
        } else {
            fputs(original, temp);
        }
    }

    fclose(fptr);
    fclose(temp);
    fptr = NULL;
    temp = NULL;

    return edited;
}


// Deletes a stored password by type
bool delete_password(char *type) {

    // Declare a file pointer and open csv file to read
    FILE *fptr = NULL;
    fptr = fopen("passwords.csv", "r");
    if (fptr == NULL) return false;

    // Open a temporary file for writing
    FILE *temp = NULL;
    temp = fopen("temp.csv", "w");
    if (temp == NULL) return false;

    // Store file contents on the stack
    char contents[256];
    char original[256];
    bool deleted = false;

    // Read the file line by line into the buffer 
    while (fgets(contents, 256, fptr) != NULL) {

        // Store current line before tokenizing incase its being written
        strcpy(original, contents);

        // Tokenize current line of file to seperate values by comma
        char *username = strtok(contents, ",");
        char *password = strtok(NULL, ",");
        char *ptype = strtok(NULL, ",");

        // Normalize the types to compare 
        if (ptype != NULL && type != NULL) {
            normalize_str(ptype);
            normalize_str(type);
        }

        if (strcmp(type, ptype) != 0) {
            // Write the current line into the temp file
            fputs(original, temp);
        } else {
            deleted = true;
        }
    }

    fclose(fptr);
    fclose(temp);
    fptr = NULL;
    temp = NULL;

    // Remove old file and rename temporary file
    remove("passwords.csv");
    rename("temp.csv", "passwords.csv");
    return deleted;
}

// Encodes a raw password by applying XOR to each bit
char* encode(char *raw) {
    char key = 0x55;
    if (raw == NULL) return NULL;
    
    int i = 0;
    while (raw[i] != '\0') {
        raw[i] = raw[i] ^ key;
        i++;
    }
    return raw;
}


// Normalizes a string at a byte level
char* normalize_str(char *str) {

    if (str == NULL) return NULL;

    int length = strlen(str);
    while (length > 0 && (str[length - 1] == '\n' || str[length - 1] == '\r')) {
        str[length - 1] = '\0';
        length--;
    }
    return str;
}

// Prints the contents of a string character by character
void print_str(char *str) {

    for (int i = 0; i < strlen(str) + 1; i++) {
        if (str[i] == '\0') printf("<NULL>");
        else if (str[i] == '\n') printf("<LB>");
        else if (str[i] == '\r') printf("<CR>");
        else printf("%c", str[i]);
    }
}