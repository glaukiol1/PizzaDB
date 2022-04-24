# 🍕DB (PizzaDB)

🍕DB is a _simple_, _in-memory_ database for the purpose of learning more about pointers and C in general. In the future, I plan to expand it to have an API, full CLI, and browsing the databases on the web.

## What does 🍕DB currently have❓❓

- _database_t_. Holds all tables (currently maxed at `100`).
- _table_t_. Holds all the entries in that specific table (currently maxed at `500`).
- _entry_t_. Holds a hashmap, a key-value storage.
- _hashmap_t_. Holds 2 relative slices (`char*keys[MAX_SIZE_HASHMAP]` and `value_t*values[MAX_SIZE_HASHMAP]`). `keys[X]` is the key for the value `values[X]`. The maximum amount of key-value pairs is currently maxed at `100`.
- _value_t_. Holds a `void*` pointer (`value`), and the type of that pointer in a `int`, `type`. To escape the `void*` pointer, it casts it accordingly with the `type`. (look at `void test2()` in `src/main.c` for an example).

Creating a database:

```c
database_t* db = newDatabase( (char*) "Database Name");
```
