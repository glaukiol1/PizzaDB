#ifndef HASHMAP

#define HASHMAP 1

#include "hm-value.c"

#define MAX_SIZE_HASHMAP 100 // the maximum key/value pairs a hashmap can hold
#define HM_ERROR -999 // the error code
#define HM_SUCCESS 0 // the success code
#define DELETED_HASHMAP_ENTRY 148742 // the `type` for a deleted value_t;

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Hashmap {
    char*keys[MAX_SIZE_HASHMAP];    // the slice that holds the keys
    value_t values[MAX_SIZE_HASHMAP];  // the slice that holds the values
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
    static hashmap_t hm; // this will override all other hashmaps
    hm = (hashmap_t) {.current_index = -1};
    return &hm;
}

value_t getDeletedHashmapEntry() {
    value_t deletedHashmapEntryPointer = newValue(0x0, DELETED_HASHMAP_ENTRY, DELETED_HASHMAP_ENTRY);
    return deletedHashmapEntryPointer;
}

value_t getErrorHashmap() {
    value_t x = newValue(0x0, HM_ERROR, HM_ERROR);
    return x;
}


value_t hashmapGet(hashmap_t* hm, char* key) {
    for (int i = 0; i <= hm->current_index; i++) {
        if (*hm->keys[i] == *key) {
            return hm->values[i];
        }
    }
    return getErrorHashmap();
}


void hashmapSet(hashmap_t* hm, char* key, value_t v) {
    if (hm->current_index+1 > MAX_SIZE_HASHMAP) {
        printf("Fatal Error: tried to add more than MAX_SIZE_HASHMAP! (max: %d)", MAX_SIZE_HASHMAP);
        exit(1);
    }
    value_t x = hashmapGet(hm, key); // try to see if it already exists
    if (x.type != HM_ERROR) {
        hm->values[x.index] = x;
        return;
    }
    hm->current_index = hm->current_index + 1;
    hm->keys[hm->current_index] = key;
    hm->values[hm->current_index] = v;
}

int hashmapDelete(hashmap_t* hm, char* key) {
    value_t x = hashmapGet(hm, key); // try to see if it already exists
    if (x.type == HM_ERROR) {
        return HM_ERROR;
    }
    hm->values[x.index] = getDeletedHashmapEntry();
    return HM_SUCCESS;
}

#endif