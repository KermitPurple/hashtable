#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<stdbool.h>

#define TABLE_SIZE 10

typedef const char* key_t;
typedef const char* val_t;

typedef struct entry_t{
    key_t key;
    val_t val;
    struct entry_t* next;
} entry_t;

typedef struct ht_t{
    entry_t** entries;
} ht_t;

ht_t* ht_new(); // allocate a new hashtable
void ht_set(ht_t* ht, key_t key, val_t val); // set a key and val pair
val_t ht_get(ht_t* ht, key_t key); // get a value based on key
bool ht_del(ht_t* ht, key_t key); // remove a key value pair from the table
void ht_print(ht_t* ht); // print an entire table
void ht_free(ht_t* ht); // free the memory

#endif // ifndef HASHTABLE_H

