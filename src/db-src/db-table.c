#ifndef DB_TABLE

#define DB_TABLE 1
struct Table
{
    int id;         // ID of the table
    char *name;    // Name of the table
} table;

typedef struct Table table_t;

table_t* newTable(char* name, int id) {
    static table_t table;
    table = (table_t) {.id = id, .name = name};
    return &table;
}

#define success 1
#define failed 0

#endif