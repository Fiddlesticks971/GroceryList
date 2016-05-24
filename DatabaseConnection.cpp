#include "DatabaseConnection.h"


DatabaseConnection::DatabaseConnection(string filePath)
{
  filePath_ = filePath;
  //  DatabaseHandle_ = new sqlite3;
}

DatabaseConnection::DatabaseConnection()
{
  filePath_ = "";
  //DatabaseHandle = new sqlite3;
}

int DatabaseConnection::ConnectToDB(string filePath)
{
  return sqlite3_open(filePath.c_str(),&DatabaseHandle_);
}

int DatabaseConnection::ConnectToDB()
{
  if (filePath_ == "")
    return -1;
  return sqlite3_open(filePath_.c_str(),&DatabaseHandle_);
}

int DatabaseConnection::ConnectToTable()
{
  return CreateTable();
}

int DatabaseConnection::CreateTable()
{
  string SQL;
  const char *pzTail;
  sqlite3_stmt *ppStmt;
  
  SQL = "CREATE TABLE main.GroceryList (" 
    "Key INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," 
    "Item TEXT NOT NULL," 
    "Description TEXT," 
    "LastDateBrought BLOB NOT NULL,"
    "AvgDays INTEGER," 
    "TimesBrought INTEGER);";

  sqlite3_prepare_v2(DatabaseHandle_,SQL.c_str(),SQL.length(),&ppStmt,&pzTail);
  return sqlite3_step(ppStmt);
  
}


DatabaseConnection::~DatabaseConnection()
{
  //delete &filePath_;
  //delete DatabaseHandle_;
}




