#ifndef HASHMAP

#define HASHMAP 1

#include "hm-value.c"

#define MAX_SIZE_HASHMAP 100 // the maximum key/value pairs a hashmap can hold

struct Hashmap {
    char*keys[MAX_SIZE_HASHMAP];    // the slice that holds the keys
    value_t*values[MAX_SIZE_HASHMAP];  // the slice that holds the values
    int current_index;               // the highest init-ed index
};

typedef struct Hashmap hashmap_t;


/**
 * The Hashmap holds 2 relative slices. keys[(X)] is the key for values[(X)]
 * @a {char*keys[]} The slice which holds the keys          [char*]
 * @a {void*values[]} The slice which holds the values      [void*]
*/

// newHashmap will return an empty Hashmap (hashmap_t*)
hashmap_t* newHashmap() {
    static hashmap_t hm;
    hm = (hashmap_t) {.current_index = -1};
    return &hm;
}

void hashmapSet(hashmap_t* hm, char* key, void* value, int valuetype) {
    hm->current_index = hm->current_index + 1;
    hm->keys[hm->current_index] = key;
    hm->values[hm->current_index] = newValue(value,valuetype);
    // hm->current_index = hm->current_index+1;
}

#include <stddef.h>
#define HM_ERROR -999 // the error code

value_t* hashmapGet(hashmap_t* hm, char* key) {
    for (int i = 0; i <= hm->current_index; i++) {
        if (*hm->keys[i] == *key) {
            return hm->values[i];
        }
    }
    return newValue(NULL, HM_ERROR);
}

#endif