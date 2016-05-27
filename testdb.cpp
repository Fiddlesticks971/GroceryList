#include <stdio.h>
#include <sqlite3.h>
#include "LinkedList.h"

int callback(void *notUsed,int argc,char **argv, char **colName)
{
  for (int i=0 ; i < argc ; i++)
    printf("%s = %s\n",colName[i],argv[i]);
  printf("\n");
  return 0;
}
int main ()
{
  sqlite3 *db;
  char *Err;
  sqlite3_open("test.db",&db);
  sqlite3_exec(db,"Select * from employees",callback,0,&Err);
  sqlite3_close(db);
  return 0;
}
