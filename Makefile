DatabaseTest: DatabaseTest.o
	g++ DatabaseTest.o DatabaseConnection.o -o DataBaseTest -lsqlite3 
DatabaseTest.o: DatabaseTest.cpp DatabaseConnection.o
	g++ -c DatabaseTest.cpp
DatabaseConnection.o: DatabaseConnection.cpp DatabaseConnection.h
	g++ -c DatabaseConnection.cpp

clean:
	rm *.o DatabaseTest
	pkill -9 DatabaseTest
