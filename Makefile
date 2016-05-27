testdb: testdb.o
	g++ DatabaseConnection.o LinkedList.o testdb.o -o testdb -lsqlite3
testdb.o: DatabaseConnection.o LinkedList.o testdb.cpp
	g++ -c testdb.cpp
DatabaseTest: DatabaseTest.o
	g++ DatabaseTest.o DatabaseConnection.o -o DatabaseTest -lsqlite3 
DatabaseTest.o: DatabaseTest.cpp DatabaseConnection.o
	g++ -c DatabaseTest.cpp
DatabaseConnection.o: DatabaseConnection.cpp DatabaseConnection.h
	g++ -c DatabaseConnection.cpp
LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

clean:
	rm *.o DatabaseTest
	pkill -9 DatabaseTest
