// the main file for PizzaDB
#include "db-src/db.h"
#include <stdio.h>

void test1() {
    database_t *db = newDatabase( (char*) "Test Database (1)");
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


void test2() {
    database_t* db = newDatabase( (char*) "Test Database (2)");
    table_t* t = addTableToDB(db, (char*) "Test Table");
    entry_t* e = newEntry(newHashmap(), 10020);
    insertEntry(t, e);
    int q = 1234;
    hashmapSet(e->map, (char*) "username", &q, HM_VALUE_INT);

    value_t* result = hashmapGet(e->map, (char*) "username"); // this returns the type of the value that the (dest*) pointer is holding

    switch (result->type)
    {
    case HM_VALUE_INT:
        printf("Value is %d, of type int\n", *(int*) result->value);
        break;
    case HM_ERROR:
        printf("Error while getting result of the hashmap entry...\n");
        exit(1);
    default:
        // there are more cases...
        break;
    }
}

void test3() {
    database_t* db = newDatabase( (char*) "Test Database (3)");
    table_t* t = addTableToDB(db, (char*) "Test Table");
    entry_t* e = newEntry(newHashmap(), 999);

    int xval = 111;
    hashmapSet(e->map, (char*) "test1", &xval, HM_VALUE_INT);

    insertEntry(t, e);

    entry_t* x = getEntry(t, 999);

    value_t* y = hashmapGet(x->map, (char*) "test1");

    switch (y->type)
    {
    case HM_VALUE_INT:
        printf("Value is %d, of type int\n", *(int*) y->value);
        break;
    case HM_ERROR:
        printf("Error while getting result of the hashmap entry...\n");
        exit(1);
    default:
        // there are more cases...
        break;
    }
}

// int argc, char const *argv[]
int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}