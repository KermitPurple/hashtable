#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hashtable.h"

static unsigned hash(key_t key){
    size_t len = strlen(key);
    unsigned result = 0;
    // djb2
    // http://www.cse.yorku.ca/~oz/hash.html
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

static void entry_free(entry_t* entry, bool recursive){
    if(entry == NULL){
        return;
    }
    if(recursive){
        entry_free(entry->next, recursive);
    }
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

void ht_set(ht_t* ht, key_t key, val_t val){
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

val_t ht_get(ht_t* ht, key_t key){
    unsigned index = hash(key);
    entry_t* curr = ht->entries[index];
    while(curr != NULL){
        if(strcmp(key, curr->key) == 0){
            return curr->val;
        }
        curr = curr->next;
    }
    return NULL;
}

bool ht_del(ht_t* ht, key_t key){
    unsigned index = hash(key);
    entry_t* curr = ht->entries[index];
    while(curr != NULL){
        if(strcmp(key, curr->key) == 0){
            entry_t* to_remove = ht->entries[index];
            curr->key = to_remove->key;
            curr->val = to_remove->val;
            ht->entries[index] = to_remove->next;
            entry_free(to_remove, false);
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool ht_contains(ht_t* ht, key_t key){
    unsigned index = hash(key);
    entry_t* curr = ht->entries[index];
    while(curr != NULL){
        if(strcmp(key, curr->key) == 0){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void ht_print(ht_t* ht){
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("ht->entries[%d] ", i);
        entry_t* curr = ht->entries[i];
        while(curr != NULL){
            printf("%s=%s -> ", curr->key, curr->val);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

void ht_free(ht_t* ht){
    for(int i = 0; i < TABLE_SIZE; i++){
        entry_free(ht->entries[i], true);
    }
    free(ht->entries);
    free(ht);
}
