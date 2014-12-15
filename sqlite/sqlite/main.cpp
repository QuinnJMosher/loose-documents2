#include <iostream>
#include "sqlite3.h"
#include <string>

using namespace std;

static int Callback(void* notUsed, int numArgs, char **data, char **columnName)
{
    for(int i = 0; i < numArgs; i++)
    {
        cout << columnName[i] << ": " << data[i] << endl;
    }

    return 0;
}

int main()
{
    sqlite3* myDatabase = NULL;    //This is our database object

    sqlite3_open("TestDabase.db", &myDatabase); //Opens and creates database 
    //if it doesn't exist

    char* errorMsg = NULL;
    string sqlStatement;            //SQL Statement

	sqlStatement = "DROP TABLE Servers;";

    //Execute Query(myDatabase, SQL Statement, Callback func, ??, Error Msg)
    sqlite3_exec(myDatabase, sqlStatement.c_str(), Callback, 0, &errorMsg);

    if(errorMsg != NULL)
    {
        cout << "Error message: " << errorMsg << endl;

    }

    sqlite3_close(myDatabase);  //Closes the database after we're finished

    system("pause");

    return 0;
}