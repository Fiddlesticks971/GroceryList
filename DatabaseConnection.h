#ifndef DATABASECONNECTION_H_
#define DATABASECONNECTION_H_

#include <sqlite3.h>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

class DatabaseConnection
{
  
 public:
  DatabaseConnection(string filePath);
  DatabaseConnection();
  int ConnectToDB();
  int ConnectToDB(string filePath);
  int ConnectToTable();
  void AddRecord(string item, string desc);
  ~DatabaseConnection();

  
 private:
  int CreateTable();
  sqlite3 *DatabaseHandle_;
  string filePath_;

};

#endif
