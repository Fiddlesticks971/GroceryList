import sqlite3

def WelcomeScreen():
    print("\nWelcome to the Grocery List App")
    print("Command List:")
    print("")
    print("   p -print current list")
    print("   m -modify list")
    print("   g -generates list of groceries")  
    print("   n -new empty list of groceries")
    print("   e -exit")
    print("   h -list commands\n\n")

def GenList(connection):
    ListItems = []
    newItem = input("Add item to list: ")
    while newItem != "back":
        ListItems.append(newItem)
        i=1
        for thing in ListItems:
            print("{}. {}".format(i,thing))
            i=i+1
        newItem = input("Add item to list: ")
        
def NewList(connection):
    ListItems = []
    newItem = input("Add item to list: ")
    while newItem != "back":
        ListItems.append(newItem)
        i=1
        for thing in ListItems:
            print("{}. {}".format(i,thing))
            i=i+1
        newItem = input("Add item to list: ")

def PrintList(connection):
    exit()
    
def CheckInput(connection,command):
    if command == "h":
        WelcomeScreen()
    elif command == "g":
        GenList(connection)
    elif command == "n":
        NewList(connection)
    elif command == "p":
        PrintList(connection)
    elif command == "e":
        connection.close()
        exit()
    
def Main():
    WelcomeScreen()
    connection = sqlite3.connect('test.db')
    cursor = connection.cursor()
    cursor.execute("CREATE TABLE IF NOT EXISTS Groceries(keyNum int,item text,lastBought date,avgPeriod int)")
    while 1==1:
        CheckInput(connection,input("enter a command:"))
    connection.close()

Main()
