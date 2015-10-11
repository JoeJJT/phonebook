#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
LastNameEntry *findName(char lastname[], LastNameEntry *pHead)
{
    /* TODO: implement */
    while(pHead != NULL) 
	{
        if(strcasecmp(lastname,pHead->lastName) == 0) 
		{
            printf("%s is found!\n",lastname);
            return pHead;
        }
        pHead = pHead->pNext;
    }
    return NULL;
}

LastNameEntry *append(char lastName[], LastNameEntry *e)
{
    e->pNext = (LastNameEntry *)malloc (sizeof(LastNameEntry));
    e = e->pNext;
    strcpy(e->lastName,lastName);
    e->pNext = NULL;
    return e;
}
