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

DatabaseConnection::~DatabaseConnection()
{
  //delete &filePath_;
  //delete DatabaseHandle_;
}
