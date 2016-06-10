
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
    "LastDateBrought BLOB,"
    "AvgDays INTEGER," 
    "TimesBrought INTEGER);";

  sqlite3_prepare_v2(DatabaseHandle_,SQL.c_str(),SQL.length(),&ppStmt,&pzTail);
  sqlite3_step(ppStmt);
  return sqlite3_finalize(ppStmt);
}

void DatabaseConnection::AddRecord(string item, string desc)
{
  char* Err;
  string SQLstr;
  time_t rawtime;
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  
  SQLstr = " INSERT INTO GroceryList(Item,Description,LastDateBrought)"
    "VALUES('" + item + "','" + desc +"','" + to_string(timeinfo->tm_mday) + "/" + to_string(timeinfo->tm_mon) +"/"+ to_string(timeinfo->tm_year + 1900) +"')";
  cout<<SQLstr<<endl;
  sqlite3_exec(DatabaseHandle_,SQLstr.c_str(),0,0,&Err);
}

void DatabaseConnection::UpdateRecord(string item)
{
  char* Err;
  string SQLstr , items[6];
  time_t rawtime;
  struct tm* timeinfo;
  int i = 0;
  

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  istringstream ss(item);
  
  while (!ss.eof())       
    {
      string x;               
      getline( ss, x, ',' );  
      items[i] = x;
      i++;
    }
  
  SQLstr = "UPDATE GroceryList "
           "SET Item = '" + items[1] + "', "
           "Description = '" + items[2] + "', "
           "LastDateBrought = '" + to_string(timeinfo->tm_mday) + "/" + to_string(timeinfo->tm_mon) +"/"+ to_string(timeinfo->tm_year + 1900) + "', "
           "AvgDays = '" + items[4] + "', "
           "TimesBrought = '" + items[5] + "' "
           "WHERE Key = " + items[0] + ";";
  
  cout<<SQLstr<<endl;
  sqlite3_exec(DatabaseHandle_,SQLstr.c_str(),0,0,&Err);
}

void DatabaseConnection::RemoveRecord(string item)
{
  char* Err;
  string SQLstr , items[6];
  int i = 0;

  istringstream ss(item);
  
  while (!ss.eof())       
    {
      string x;               
      getline( ss, x, ',' );  
      items[i] = x;
      i++;
    }
  
  SQLstr = "DELETE FROM GroceryList "
           "WHERE Key = " + items[0] + ";";
  
  cout<<SQLstr<<endl;
  sqlite3_exec(DatabaseHandle_,SQLstr.c_str(),0,0,&Err);
}

DatabaseConnection::~DatabaseConnection()
{
  //delete &filePath_;
  //delete DatabaseHandle_;
}

