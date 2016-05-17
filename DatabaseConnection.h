#ifndef DATABASECONNECTION_H_
#define DATABASECONNECTION_H_

#include <sqlite3>

class DatabaseConnection
{
  
 public:
  DatabaseConnection(string filePath);
  DatabaseConnection();
  int ConnectToDB();
  int ConnectToDB(string filePath);
  ~DatabaseConnection();
  
 private:
  sqlite3::sqlite3 *DatabaseHandle_;
  string filePath_;

};

#endif