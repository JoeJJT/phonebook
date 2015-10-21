#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! *//*
entry *findName(char lastname[], entry *pHead)
{
    *//* TODO: implement *//*
     while(pHead != NULL) {
        if(strcasecmp(lastname,pHead->lastName) == 0) {
            printf("%s is found!\n",lastname);
            return pHead;
        }
        pHead = pHead->pNext;
    }
    return NULL;
}
*//*
entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *)malloc (sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName,lastName);
    e->pNext = NULL;
    return e;
}
*/
hashTable *createHashTable(int tableSize)
{
    hashTable *ht = NULL;
    int i;
    if(tableSize < 1) {
        return NULL;
    }
    if((ht = (hashTable *)malloc(sizeof(hashTable))) == NULL) {
        return NULL;
    }
    if((ht->list = malloc(sizeof(entry *)* tableSize)) == NULL) {
        return NULL;
    }

    for( i=0; i< tableSize ; i++) {
        ht->list[i] = NULL;
    }
    ht->tableSize = tableSize;
    return ht;
}

entry *findNameHash(char *key,hashTable *ht)
{
    entry *lne;
    hashIndex index = hash2(key,ht);

    for(lne = ht->list[index]; lne != NULL ; lne = lne->pNext) {
        if(strcasecmp(key,lne->lastName) == 0) {
            printf("%12s is found!\n",key);
            return lne;
        }
    }
    printf("%12s is not found!\n",key);
    return NULL;
}

entry *appendHash(char *key,hashTable *ht)
{
    hashIndex index = hash2(key,ht);
    entry *newEntry;

    if((newEntry = (entry *)malloc(sizeof(entry))) == NULL) {
        printf("error!\n");
        return NULL;
    } else {
        /*Insert into list*/
        strcpy(newEntry->lastName,key);
        newEntry->pNext = ht->list[index];
        ht->list[index] = newEntry;
    }
    return 0;
}
/*
hashIndex hash1(char *key,hashTable *ht)
{
    unsigned int hashVal = 0;
    while(*key != '\0') {
        hashVal += *key++;
    }
    return hashVal % ht->tableSize;
}
*/

/*use djb2 hash method*/
hashIndex hash2(char *key,hashTable *ht)
{
    unsigned int hashVal = 0;
    while(*key != '\0') {
        hashVal = (hashVal << 5) + *key++;
    }
    return hashVal % ht->tableSize;
}
