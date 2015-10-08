#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#include "phonebook_detail.h"
#define MAX_LAST_NAME_SIZE 16
/* optimal version1 */
typedef struct __PHONE_BOOK_LAST_NAME {
	char lastName[MAX_LAST_NAME_SIZE];
	entry *detail;
	struct __PHONE_BOOK_LAST_NAME *pNext;
}LastNameEntry;

LastNameEntry *findName(char lastname[], LastNameEntry *pHead);
LastNameEntry *append(char lastName[], LastNameEntry *e);

#endif
