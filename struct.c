#include <stdio.h>

int main(void)
{
    typedef struct person {
        char* name;
        int age;
        int salary;
    }person;


    person ramin = {
        .age = 22,
        .name = "Ramin",
        .salary = 0,
    };

    struct big_person {
        person Person;
        char* last_name;
    };

    printf("this is %s, he is %d years old, and his income is %d\n", ramin.name, ramin.age, ramin.salary);

    struct big_person new_big = {
        .Person = ramin,
        .last_name = "rafiee"
    };

    printf("this is ramin %s\n", new_big.last_name);
}
