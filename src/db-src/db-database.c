#ifndef DB_DATABASE
#define DB_DATABASE 1

#include "db-table.c"

#define MAX_TABLES 100 // the maxiumum number of tables in a database

struct Database {
    table_t *dbtables[MAX_TABLES];
    char *name;
    int current_index; // the current index of the highest init-ed table
};

typedef struct Database database_t;

database_t* newDatabase(char *name) {
    static database_t db;
    db = (database_t) {.name = name, .current_index = -1};
    return &db;
}

// addTableToDB returns a pointer to the new table
// in the DB that was added.
table_t* addTableToDB(database_t* db, char* name) {
    table_t *writeTable = newTable(name, db->current_index+1);
    db->current_index = db->current_index+1;
    writeTable->id = db->current_index;
    writeTable->name = name;
    return writeTable;
}

#endif