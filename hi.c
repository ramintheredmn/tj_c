#include <stddef.h>
#include <stdio.h>
#include <stdint.h>


int main(void)
{
    int start = 1;
    int end = 5;

    int i = end;
    while (i>start)
    {
        printf("%d\n", i);
        i--;
    }
}
