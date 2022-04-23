// the main file for PizzaDB
#include "db-src/db.h"
#include <stdio.h>

void test1() {
    database_t *db = newDatabase( (char*) "Test Database");
    printf("Database:\n\t Name: %s\n", db->name);
    table_t *nt = addTableToDB(db, (char*) "Test Table");
    printf("Table %d:\n\t Name: %s\n\t ID: %d\n", nt->id, nt->name, nt->id);
    table_t *nt1 = addTableToDB(db, (char*) "Test Table 1");
    printf("Table %d:\n\t Name: %s\n\t ID: %d\n", nt1->id, nt1->name, nt1->id);

    printf("\n");

    printf("getTableDB with (X) of 0...\n");
    table_t *x1 = getTableDB(db, 0);
    printf("Found table? %d\n", (x1 != NULL));

    printf("getTableDB with (X) of 1...\n");
    table_t *x2 = getTableDB(db, 1);
    printf("Found table? %d\n", (x2 != NULL));

    printf("getTableDB with (X) of 2...\n");
    table_t *x3 = getTableDB(db, 2);
    printf("Found table? %d\n", (x3 != NULL));
}

// int argc, char const *argv[]
int main()
{
    test1();
    return 0;
}