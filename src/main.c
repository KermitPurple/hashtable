#include<stdio.h>
#include"hashtable.h"

int main(){
    ht_t* ht = ht_new();
    if(ht == NULL){
        fputs("Couldn't allocate hash table", stderr);
        return 1;
    }
    ht_set(ht, "name1", "Shane");
    ht_set(ht, "name2", "Sam");
    ht_set(ht, "name3", "Patrick");
    ht_set(ht, "name3", "Pj");
    ht_set(ht, "name4", "Test");
    ht_set(ht, "name5", "Weird name");
    ht_set(ht, "name6", "Shawn");
    ht_set(ht, "name7", "Loay Alnaji");
    ht_set(ht, "name8", "McDonough");
    ht_set(ht, "name9", "More name");
    ht_set(ht, "name10", "McDonough");
    ht_set(ht, "a", "a");
    ht_set(ht, "b", "b");
    ht_set(ht, "c", "c");
    ht_print(ht);
    puts(ht_get(ht, "name8"));
    ht_del(ht, "a");
    ht_del(ht, "b");
    ht_del(ht, "c");
    ht_del(ht, "name10");
    ht_print(ht);
    ht_free(ht);
    return 0;
}
