#include <iostream>
#include <string>

#include "MiniDB.h"

using namespace std;

void createMoreObjects();

const int OBJECTS = 1000;

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
    for(int i = 0; i < OBJECTS; i++)
    {
        string s = "SavaLione";
        MiniDB mdb;
        bool some = mdb.checkPlayer(s);
        if(some)
        {
            
        }
    }
}