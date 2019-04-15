#include <iostream>
#include <string>

#include "MiniDB.h"

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
        MiniDB *mdb = new MiniDB;
        delete mdb;
    }
}