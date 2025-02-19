#include <stdio.h>
#include <stdlib.h>


char* string_cat(char* string_1, char* string_2) {

    int size_1 = 0;
    while (string_1[size_1] != '\0') {  // Loop until null terminator
        size_1++;
    }

    int size_2 = 0;
    while (string_2[size_2] != '\0') {  // Loop until null terminator
        size_2++;
    }

    char* result = malloc(size_1 + size_2 + 1);

    for (int i = 0; i < size_1; i++) {
        result[i] = string_1[i];
    }

    for (int i = 0; i < size_2; i++) {
        result[size_1 + i] = string_2[i];
    }

    // Add null terminator at the end
    result[size_1 + size_2] = '\0';

    return result;

}


int main(void) {
    char string_1[50] = "Ramin ";
    char* string_2 = "Rafiee";

    char* con = string_cat(string_1, string_2);

    printf("%s\n", con);

    free(con);

}
