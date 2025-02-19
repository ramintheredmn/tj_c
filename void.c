#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap_(void* var1, void* var2, size_t size) {

    void* temp = malloc(size);
    memcpy(temp, var2, size);
    memcpy(var2, var1, size);
    memcpy(var1, temp, size);
    free(temp);
}

int main(void) {
    
    char* a = "mobinlskfjalk";
    char* b = "ramin";

    swap_(&a, &b, sizeof(int));
    printf("when we swap the vars the a, b are: %s, %s resp\n", a, b);

    size_t h = 1;
    printf("the size of size_t h is %d", (int)sizeof(h));



    return 0;
}
