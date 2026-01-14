#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "password.h"

int main(void) {

    // Each char is 1 byte (8 bits), and for each character in the provided string,
    // XOR is applied bit by bit, resulting in a potentially new character, and scrambled string
    char test[30] = "Hello World";
    char key = 0x55;


    encode(test);
    printf("%s\n", test);

    encode(test);
    printf("%s\n", test);



    // // Applies XOR to each of the 8 bits
    // for (int i = 0; i < strlen(test); i++) {
    //     test[i] = test[i] ^ key;
    //     printf("%c", test[i]);
    // }

    // for (int i = 0; i < strlen(test); i++) {
    //     test[i] = test[i] ^ key;
    //     printf("%c", test[i]);
    // }


    return 0;
}