#ifndef HASHTABLE_H
#define HASHTABLE_H

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
void ht_add(ht_t* ht, key_t key, val_t val); // set a key and val pair
void ht_free(ht_t* ht); // free the memory

#endif // ifndef HASHTABLE_H

