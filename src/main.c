// the main file for PizzaDB
#include "db-src/db.h"
#include <stdio.h>

/* @IMPORTANT ---- 

test functions that are commented will NOT work.

*/

// void test1() {
//     database_t *db = newDatabase( (char*) "Test Database (1)");
//     printf("Database:\n\t Name: %s\n", db->name);
//     table_t *nt = addTableToDB(db, (char*) "Test Table");
//     printf("Table %d:\n\t Name: %s\n\t ID: %d\n", nt->id, nt->name, nt->id);
//     table_t *nt1 = addTableToDB(db, (char*) "Test Table 1");
//     printf("Table %d:\n\t Name: %s\n\t ID: %d\n", nt1->id, nt1->name, nt1->id);

//     printf("\n");

//     printf("getTableDB with (X) of 0...\n");
//     table_t *x1 = getTableDB(db, 0);
//     printf("Found table? %d\n", (x1 != NULL));

//     printf("getTableDB with (X) of 1...\n");
//     table_t *x2 = getTableDB(db, 1);
//     printf("Found table? %d\n", (x2 != NULL));

//     printf("getTableDB with (X) of 2...\n");
//     table_t *x3 = getTableDB(db, 2);
//     printf("Found table? %d\n", (x3 != NULL));
// }

// void test2() {
//     database_t* db = newDatabase( (char*) "Test Database (2)");
//     table_t* t = addTableToDB(db, (char*) "Test Table");
//     entry_t* e = newEntry(newHashmap(), 10020);
//     insertEntry(t, e);
//     int q = 1234;
//     hashmapSet(e->map, (char*) "username", &q, HM_VALUE_INT);

//     value_t* result = hashmapGet(e->map, (char*) "username"); // this returns the type of the value that the (dest*) pointer is holding

//     switch (result->type)
//     {
//     case HM_VALUE_INT:
//         printf("Value is %d, of type int\n", *(int*) result->value);
//         break;
//     case HM_ERROR:
//         printf("Error while getting result of the hashmap entry...\n");
//         exit(1);
//     default:
//         // there are more cases...
//         break;
//     }
// }

// void test3() {
//     database_t* db = newDatabase( (char*) "Test Database (3)");
//     table_t* t = addTableToDB(db, (char*) "Test Table");
//     entry_t* e = newEntry(newHashmap(), 999);

//     insertEntry(t, e);

//     entry_t* x = getEntry(t, 999);

//     int xval = 111;
//     hashmapSet(x->map, (char*) "test1", &xval, HM_VALUE_INT);

//     value_t* y = hashmapGet(x->map, (char*) "test1");

//     switch (y->type)
//     {
//     case HM_VALUE_INT:
//         printf("Value is %d, of type int\n", *(int*) y->value);
//         break;
//     case HM_ERROR:
//         printf("Error while getting result of the hashmap entry...\n");
//         exit(1);
//     default:
//         // there are more cases...
//         break;
//     }
//     char* z = (char*) "hello";
//     hashmapSet(x->map, (char*) "test1", z, HM_VALUE_CHAR); // reassigning

//     value_t* n = hashmapGet(x->map, (char*) "test1");
//     switch (y->type)
//     {
//     case HM_VALUE_CHAR:
//         printf("Value is \"%s\", of type char*\n", (char*) n->value);
//         break;
//     case HM_ERROR:
//         printf("Error while getting result of the hashmap entry...\n");
//         exit(1);
//     default:
//         // there are more cases...
//         break;
//     }
// }

void test4()
{
    database_t *db = newDatabase((char *)"Test Database (2)");
    table_t *t = addTableToDB(db, (char *)"Test Table");
    entry_t *e = newEntry(newHashmap(), 10020);
    insertEntry(t, e);
    entry_t *x = getEntry(t, 10020);
    int q = 1;
    int q1 = 2;
    int q2 = 3;
    value_t qq = newValue(&q, HM_VALUE_INT, -2);
    value_t qq1 = newValue(&q1, HM_VALUE_INT, -3);
    value_t qq2 = newValue(&q2, HM_VALUE_INT, -4);
    hashmapSet(x->map, (char *)"test1", qq);
    hashmapSet(x->map, (char *)"test2", qq1);
    hashmapSet(x->map, (char *)"test3", qq2);

    value_t n = hashmapGet(x->map, (char *)"test1");
    switch (n.type)
    {
    case HM_VALUE_INT:
        printf("Value is %d, of type int\n", *(int*)n.value);
        break;
    case HM_ERROR:
        printf("Error while getting result of the hashmap entry...\n");
        exit(1);
    default:
        // there are more cases...
        break;
    }

    // int dsuccess = hashmapDelete(x->map, (char*) "test2");
    // if (dsuccess == HM_SUCCESS) {
    //     printf("[success] deleted `test2`\n");
    // }

    // value_t* test1 = hashmapGet(x->map, (char*) "test1");
    // value_t* test2 = hashmapGet(x->map, (char*) "test2");
    // value_t* test3 = hashmapGet(x->map, (char*) "test3");

    // if (test1->type == HM_VALUE_INT && *(int*) test1->value == q) {
    //     printf("[success] test1 matched!");
    // }
}

// int argc, char const *argv[]
int main()
{
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}