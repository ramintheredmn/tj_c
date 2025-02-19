#include <stdio.h>


typedef struct xyz{
    int i;
    int j;
    int z;
} xyz_t;

xyz_t list_[4] = {

    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12}
}; 


int main(void) {

    printf("the sizeof list is %d\n", sizeof(list_));
    printf("this is a pointer? %p\n", list_);
    printf("the first element is %d, and the pointer to it is %p\n", list_[0].i, &list_[0]);

    printf("this is the 3rd item, %d\n", *(list_+3));

    int* ptr = (int*)(list_);

    for (int i=0; i<(sizeof(list_)/sizeof(list_[0].i)); i++)
    {
        printf("the number is %d\n",ptr[i]);
    }
    
}
