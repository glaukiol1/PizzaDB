// the main file for PizzaDB
#include "db-src/db.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    database_t *db = newDatabase("Test Database");
    printf("Database:\n\t Name: %s\n", db->name);
    table_t *nt = addTableToDB(db, "Test Table");
    printf("Table:\n\t Name: %s\n\t ID: %d\n", nt->name, nt->id);
    table_t *nt1 = addTableToDB(db, "Test Table 1");
    printf("Table:\n\t Name: %s\n\t ID: %d\n", nt1->name, nt1->id);
}