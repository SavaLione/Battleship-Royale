#include <iostream>
#include <string>

#include "MiniDB.h"

using namespace std;

void createMoreObjects();

const int OBJECTS = 1000;

int main()
{
    MiniDB mdb;
    mdb.setTable();

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
        mdb.checkPlayer(s);
    }
}