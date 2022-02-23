#include<stdio.h>
#include"hashtable.h"

int main(){
    ht_t* ht = ht_new();
    if(ht == NULL){
        fputs("Couldn't allocate hash table", stderr);
        return 1;
    }
    ht_add(ht, "name1", "Shane");
    ht_add(ht, "name2", "Sam");
    ht_add(ht, "name3", "Patrick");
    ht_add(ht, "name3", "Pj");
    ht_add(ht, "name4", "Test");
    ht_add(ht, "name5", "Weird name");
    ht_add(ht, "name6", "Shawn");
    ht_add(ht, "name7", "Loay Alnaji");
    ht_add(ht, "name8", "McDonough");
    ht_add(ht, "name9", "More name");
    ht_add(ht, "name10", "McDonough");
    ht_add(ht, "a", "a");
    ht_add(ht, "b", "b");
    ht_add(ht, "c", "c");
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("ht->entries[%d] ", i);
        entry_t* curr = ht->entries[i];
        while(curr != NULL){
            printf("%s=%s -> ", curr->key, curr->val);
            curr = curr->next;
        }
        printf("NULL\n");
    }
    ht_free(ht);
    return 0;
}
