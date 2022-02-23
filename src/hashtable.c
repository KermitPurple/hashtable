#include<stdlib.h>
#include<string.h>
#include"hashtable.h"

static unsigned hash(key_t key){
    size_t len = strlen(key);
    unsigned result = 0;
    for(int i = 0; i < len; i++){
        result = result * 33 + key[i];
    }
    result %= TABLE_SIZE;
    return result;
}

static entry_t* entry_new(key_t key, val_t val){
    entry_t* entry = malloc(sizeof(entry_t));
    if(entry == NULL){
        return NULL;
    }
    entry->key = key;
    entry->val = val;
    entry->next = NULL;
    return entry;
}

static void entry_free(entry_t* entry){
    if(entry == NULL){
        return;
    }
    entry_free(entry->next);
    free(entry);
}

ht_t* ht_new(){
    ht_t* ht = malloc(sizeof(ht_t));
    if(ht == NULL){
        return NULL;
    }
    ht->entries = malloc(sizeof(entry_t*) * TABLE_SIZE);
    if(ht->entries == NULL){
        return NULL;
    }
    for(int i = 0; i < TABLE_SIZE; i++){
        ht->entries[i] = NULL;
    }
    return ht;
}

void ht_add(ht_t* ht, key_t key, val_t val){
    unsigned index = hash(key);
    if(ht->entries[index] == NULL){
        ht->entries[index] = entry_new(key, val);
    }else{
        entry_t* prev = NULL;
        entry_t* curr = ht->entries[index];
        while(curr != NULL){
            if(strcmp(key, curr->key) == 0){
                curr->val = val;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = entry_new(key, val);
    }
}

void ht_free(ht_t* ht){
    for(int i = 0; i < TABLE_SIZE; i++){
        entry_free(ht->entries[i]);
    }
    free(ht->entries);
    free(ht);
}
