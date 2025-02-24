typedef enum lang_kind {
	INTEGER
} lang_obj_kind_t;

typedef union lang_value {
	int v_int;
} lang_obj_value_t;

typedef struct langObj {
	lang_obj_kind_t kind;
	lang_obj_value_t value;
} langObj_t;
