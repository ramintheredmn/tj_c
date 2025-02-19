#include <stdio.h>

int main(void) {
    int* ptr_list[3];
    
    printf("%p", *ptr_list);

    printf("%p, %d", ptr_list[0], *(ptr_list[0]));

}
