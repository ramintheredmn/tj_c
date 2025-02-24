#include <stdio.h>
#include <stdlib.h>
#include "simpleobj.h"

langObj_t* new_ptr_obj(int value) {
    langObj_t* new_ptr_obj = malloc(sizeof(langObj_t));
    if (new_ptr_obj == NULL) {return NULL;};

    new_ptr_obj->value.v_int = value;
    new_ptr_obj->kind = INTEGER;

    return new_ptr_obj;
}

int main(void) {
    langObj_t* lang_obj = new_ptr_obj(69);

    printf("Hello with new object!, %i", lang_obj->value);

}
