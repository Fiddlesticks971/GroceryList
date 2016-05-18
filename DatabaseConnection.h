#ifndef DATABASECONNECTION_H_
#define DATABASECONNECTION_H_

#include <sqlite3.h>
#include <string>

using namespace std;

class DatabaseConnection
{
  
 public:
  DatabaseConnection(string filePath);
  DatabaseConnection();
  int ConnectToDB();
  int ConnectToDB(string filePath);
  int ConnectToTable();
  ~DatabaseConnection();
  
 private:
  void CreatTable();
  sqlite3 *DatabaseHandle_;
  string filePath_;

};

#endif
