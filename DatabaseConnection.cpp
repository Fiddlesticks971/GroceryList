#include "DatabaseConnection.h"

DatabaseConnection::DatabaseConnection(string filePath)
{
  filePath_ = filePath;
  databaseHandle_ = new sqlite3;
}

DatabaseConnection::DatabaseConnection()
{
  filePath_ = "";
  databaseHandle = new sqlite3;
}

int DatabaseConnection::ConnectToDB(string filePath)
{
  return sqlile3_open(&filePath,&DatabaseHandle_);
}

int DatabaseConnection::ConnectToDB();
{
  if (filePath_ == "")
    return -1;
  return sqlite3_open(&filePath_,&DatabaseHandle_);
}

DatabaseConnection::~DatabaseConnection()
{
  delete &filePath_;
  delete DatabaseHandle_;
}
