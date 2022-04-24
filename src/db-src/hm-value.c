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
    int index; // the index of the value (when inside a hashmap)
};

typedef struct Value value_t;

/**
 * @b value_t contains the value and a int which
 * tells the program what type the value is,
 * since we can't escape the void* pointer in any 
 * other way.
*/

value_t newValue(void* value, int type, int id) {
    value_t s = {.value = value, .type = type, .index = id};
    return s;
}

#endif