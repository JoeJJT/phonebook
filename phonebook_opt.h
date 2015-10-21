#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#include "phonebook_detail.h"
#define MAX_LAST_NAME_SIZE 16
#define OPT
/* optimal version1:reduce structure size */
typedef struct __PHONE_BOOK_LAST_NAME {
    char lastName[MAX_LAST_NAME_SIZE];
    detail_entry *detail;
    struct __PHONE_BOOK_LAST_NAME *pNext;
} entry;

entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);


/*optimal version2:use hash table*/
typedef unsigned int hashIndex;
typedef struct __PHONE_BOOK_HASH_TABLE {
    unsigned int tableSize;
    entry **list;
} hashTable;
entry *findNameHash(char *key,hashTable *ht);
entry *appendHash(char *key,hashTable *ht);
hashIndex hash1(char *key,hashTable *ht);
hashIndex hash2(char *key,hashTable *ht);

#endif
