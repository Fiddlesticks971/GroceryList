import sqlite3

def WelcomeScreen():
    print("\nWelcome to the Grocery List App\n" +
          "Command List:\n" +
          "    p -print current list\n" +
          "    m -modify list\n" +
          "    g -generates list of groceries\n" +  
          "    n -new empty list of groceries\n" +
          "    e -exit\n" +
          "    h -list commands\n\n")
    
def CreateCurrentList(listItems,connection):
    cursor = connection.cursor()
    cursor.execute("CREATE TABLE IF NOT EXISTS "+
                   "CurrentList(keyNum int,item text)")
    cursor.execute("SELECT * "+
                   "FROM " +
                   "CurrentList;")

    itemArray=cursor.fetchall()
    i = len(itemArray)
    for item in listItems:
        cursor.execute("INSERT INTO CurrentList "+
                       "VALUES({},'{}')".format(i,item))
        i=i+1
    connection.commit()
    
def GenList(connection):
    listItems = []
    newItem = input("Add item to list: ")
    while newItem != "back":
        listItems.append(newItem)
        i=1
        for thing in listItems:
            print("{}. {}".format(i,thing))
            i=i+1
        newItem = input("Add item to list: ")
    CreateCurrentList(listItems,connection)
        
def AddItems(connection):
    listItems = []
    newItem = input("Add item to list: ")
    while newItem != "back":
        listItems.append(newItem)
        i=1
        for thing in listItems:
            print("{}. {}".format(i,thing))
            i=i+1
        newItem = input("Add item to list: ")
    CreateCurrentList(listItems,connection)

def PrintList(connection):
    cursor=connection.cursor()
    cursor.execute("SELECT * FROM CurrentList")
    listItem = cursor.fetchall()
    for i,item in listItem:
        print("{}. {}".format(i,item))

def  ModifyList(connection):
    cursor=connection.cursor()
    command = input("enter command: ")
    while command != "back":
        if command == "p":
            PrintList(connection)
        elif command == "r":
            itemNum = input("Enter number of item to remove: ")
        elif command == "a":
            AddItems(connection)
        elif command == "d":
            itemNum = input("delete all items in current list? (y/n): ")
        elif command == "":
            item = input("Enter Item to add to the list:")
        command = input("enter command: ")
            
def CheckInput(connection,command):
    if command == "h":
        WelcomeScreen()
    elif command == "g":
        GenList(connection)
    elif command == "n":
        AddItems(connection)
    elif command == "m":
        ModifyList(connection)
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
