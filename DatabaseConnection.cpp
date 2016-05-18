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

void DatabaseConnection::ConnectToTable()
{
}

void DatabaseConnection::CreateTable()
{
  string SQL;
  char* pzTail;
  sqlite_stmt *ppStmt;
  
  SQL = "CREATE TABLE main.TestTable (" &_
    "Key INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," &_
    "Item TEXT NOT NULL," &_
    "Description TEXT," &_
    "LastDateBrought BLOB NOT NULL,"&_
    "AvgDays INTEGER," &_
    "TimesBrought INTEGER);";

  sqlite3_prepare(DatabaseHandle,SQL.c_str(),SQL.length(),&ppStmt,&pzTail);

}


DatabaseConnection::~DatabaseConnection()
{
  //delete &filePath_;
  //delete DatabaseHandle_;
}




