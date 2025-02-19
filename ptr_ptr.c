#include <stdio.h>
#include <stdlib.h>



int main(void) {
    char** ptr_adam = malloc(3 * (sizeof(char*)));
    ptr_adam[0] = malloc(4);
    char* temp = "ram";
    for (int i=0; i<3; i++) {
        ptr_adam[0][i] = temp[i];
    }
    ptr_adam[0][3] = '\0';
    ptr_adam[1] = "mob";
    ptr_adam[2] = "hos";

    ptr_adam[0][0] = 'R';


    printf("1. %s, 2. %s, 3. %s, 4. %d", ptr_adam[0], ptr_adam[1], ptr_adam[2], (int)sizeof(char*));

    return 0;
}
