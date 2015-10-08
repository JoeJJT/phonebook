
#define MAX_LAST_NAME_SIZE 16
typedef struct __PHONE_BOOK_ENTRY {
     char firstName[MAX_LAST_NAME_SIZE];
     char email[16];
     char phone[10];
     char cell[10];
     char addr1[16];
     char addr2[16];
     char city[16];
     char state[2];
	 char zip[5];
     struct __PHONE_BOOK_ENTRY *pNext;
}entry;
				 
