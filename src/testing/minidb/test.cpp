#include <iostream>
#include <string>

#include "MiniDB.h"

using namespace std;

void createMoreObjects();

const int OJECTS = 1000;

int main()
{
    MiniDB *mdb = new MiniDB;
    mdb->setTable();
    delete mdb;
    
    ///
    createMoreObjects();

    return 0;
}

void createMoreObjects()
{
    for(int i = 0; i < OJECTS; i++)
    {
        string *s = new string;
        
        checkPlayer(s);

        delete s;
    }
    /*
    for(int i = 0; i < OJECTS; i++)
    {
        string *s = new string;
        MiniDB *mdb = new MiniDB;
        
        *s = "SavaLione";

        mdb->checkPlayer(s);
        mdb->close();

        delete mdb;
        delete s;
    }
    */
}