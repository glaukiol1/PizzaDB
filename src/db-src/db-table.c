#ifndef DB_TABLE

#define DB_TABLE 1
#include "db-entry.c"


#define MAX_ENTRIES 500 // the maximum entries you can have in one table

struct Table
{
    int id;         // ID of the table
    char *name;    // Name of the table
    entry_t *entries[MAX_ENTRIES]; // the entries in the table
    int current_index; // the current index of the entry
};

typedef struct Table table_t;

table_t* newTable(char* name, int id) {
    static table_t table;
    table = (table_t) {.id = id, .name = name, .entries = {0} };
    return &table;
}
#include <stdlib.h>
#include <stdio.h>

void insertEntry(table_t* t, entry_t* e) {
    if (t->current_index != 0) {
        t->current_index = t->current_index + 1;
    }
    if (t->current_index>MAX_ENTRIES) {
        printf("Fatal Error: Tried to insert more entries than MAX_ENTRIES! (max: %d).", MAX_ENTRIES);
        exit(1);
    }
    t->entries[t->current_index] = e;
}

/**
 * returns a entry_t* if an entry was found
 * in the specified table_t* with set `id`,
 * or a NULL pointer.
*/
entry_t* getEntry(table_t* t, int id) {
    for (int i = 0; i <= t->current_index; i++)
    {
        if (t->entries[i]->id == id) {
            return t->entries[i];
        }
    }
    return NULL;
}

#endif