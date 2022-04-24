#ifndef DB_ENTRY

#define DB_ENTRY 1

#include "hashmap.c"

struct Entry
{
    hashmap_t *map; // the key-value pairs
    int id;         // the ID that will be used to get this entry
};

typedef struct Entry entry_t;

entry_t* newEntry(hashmap_t* map, int id) {
    static entry_t entry;
    entry = (entry_t) {.map = map, .id = id};
    return &entry;
}


#endif