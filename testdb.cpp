#include <stdio.h>
#include <sqlite3.h>
#include "LinkedList.h"
#include "DatabaseConnection.h"

int callback(void *notUsed,int argc,char **argv, char **colName)
{
  for (int i=0 ; i < argc ; i++)
    printf("%s = %s\n",colName[i],argv[i]);
  printf("\n");
  return 0;
}
int main ()
{
  DatabaseConnection *db;
  db = new DatabaseConnection("test.db");
  db->ConnectToDB();
  db->ConnectToTable();
  db->AddRecord("Eggs","Xtra Large");
  db->AddRecord("Milk","2%");
  db->UpdateRecord("1,Eggs,Xtra Large, ,5,10");
  //sqlite3_exec(db,"Select * from GroceryList",callback,0,&Err);
  //sqlite3_close(db);
  return 0;
}
