#include <stdlib.h>

typedef struct langObj langObj_t;

typedef enum lang_kind {
	INTEGER,
	STRING,
	VECTOR,
	LIST

} lang_obj_kind_t;

typedef struct list {
	size_t size;
	langObj_t** data;
} list_t;

typedef struct vector {
	langObj_t* x;
	langObj_t* y;
	langObj_t* z;
} vector_t;

typedef union lang_value {
	int v_int;
	char* v_string;
	vector_t v_vector;
	list_t v_list;
} lang_obj_value_t;

typedef struct langObj {
	lang_obj_kind_t kind;
	lang_obj_value_t value;
} langObj_t;

