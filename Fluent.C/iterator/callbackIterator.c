#define MAX_NAME_LENGTH 50
#define MAX_PWD_LENGTH 50

#include <stddef.h>
#include <string.h>
#include "callbackIterator.h"


struct ACCOUNT
{
  char loginname[MAX_NAME_LENGTH];
  char password[MAX_PWD_LENGTH];
  struct ACCOUNT* next;
};

/* for simplicity reasons, we'll have a fixed set of list elements */
static struct ACCOUNT accountData1;
static struct ACCOUNT accountData2;
static struct ACCOUNT accountData3;
static struct ACCOUNT* accountList;

static void initList()
{
  strcpy(accountData1.loginname, "Y");
  strcpy(accountData1.password, "Y");
  accountData1.next = &accountData2;
  
  strcpy(accountData2.loginname, "X");
  strcpy(accountData2.password, "X");
  accountData2.next = &accountData3;
  
  strcpy(accountData3.loginname, "Y");
  strcpy(accountData3.password, "Y");
  accountData3.next = NULL;
  
  accountList = &accountData1;
}

static struct ACCOUNT* getFirst()
{
  return accountList;
}

static struct ACCOUNT* getNext(struct ACCOUNT* current)
{
  return current->next;
}


void iterateLoginNames(FP_CALLBACK callback, void* arg)
{
  initList();
  
  struct ACCOUNT* element = getFirst();
  while(element != NULL)
  {
    callback(element->loginname, arg);
    element = getNext(element);
  }
}





