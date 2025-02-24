#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleobj.h"

langObj_t* new_ptr_obj(char* value) {
    langObj_t* new_ptr_obj = malloc(sizeof(langObj_t));
    if (new_ptr_obj == NULL) {return NULL;};

    new_ptr_obj->value.v_string = malloc(strlen(value) + 1);
    strcpy(new_ptr_obj->value.v_string, value);
    new_ptr_obj->kind = STRING;



    return new_ptr_obj;
}

int main(void) {
    langObj_t* lang_obj = new_ptr_obj("Ramin was here!!!!!");

    printf("Hello with new object!, %s", lang_obj->value);

}
