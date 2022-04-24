#ifndef HM_VALUE

#define HM_VALUE 1

// this struct will be the holder for values
// in the `hashmap_t` type.

/* The value types */

#define HM_VALUE_INT    0 //
#define HM_VALUE_FLOAT  1 //
#define HM_VALUE_DOUBLE 2 //
#define HM_VALUE_CHAR   4 //
#define HM_VALUE_CUSTOM 5 // the unknown datatype

struct Value {
    void*value;
    int type;
};

typedef struct Value value_t;

/**
 * @b value_t contains the value and a int which
 * tells the program what type the value is,
 * since we can't escape the void* pointer in any 
 * other way.
*/

value_t* newValue(void* value, int type) {
    static value_t s;
    s = (value_t) {.value = value, .type = type};
    return &s;
}

#endif