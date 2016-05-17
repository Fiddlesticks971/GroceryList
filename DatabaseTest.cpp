#include "DatabaseConnection.h"
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  DatabaseConnection *TestDB;
  string filePath;
  cout << "enter file path: ";
  cin >> filePath;
  TestDB = new DatabaseConnection(filePath);
  cout << TestDB->ConnectToDB();
  return 0;
}
