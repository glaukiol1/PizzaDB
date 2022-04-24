#ifndef DB_ENTRY

#define DB_ENTRY 1

#include "hashmap.c"

struct Entry
{
    hashmap_t *map; // the key-value pairs
};

typedef struct Entry entry_t;

entry_t* newEntry(hashmap_t* map) {
    static entry_t entry;
    entry = (entry_t) {.map = map};
    return &entry;
}


#endif