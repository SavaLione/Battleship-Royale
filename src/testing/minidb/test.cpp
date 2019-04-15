#include <iostream>
#include <string>

#include "MiniDB.h"

int main()
{
    MiniDB *mdb = new MiniDB;
    mdb->setTable();
    delete mdb;
    
    return 0;
}