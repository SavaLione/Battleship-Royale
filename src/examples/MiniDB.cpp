#include <string>
#include <iostream>

#include "MiniDB.h"

int main()
{
    std::string name = "SavaLione", sha2 = "";
    MiniDB mdb;

    mdb.setTable();

    if (mdb.checkPlayer(name))
    {
        std::cout << "Player: " << name << " found." << std::endl;
    }

    mdb.getPassword(name, sha2);
    std::cout << "Player: " << name << " sha2: " << sha2 << std::endl;

    return 0;
}