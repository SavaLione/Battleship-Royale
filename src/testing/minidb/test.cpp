#include <iostream>
#include <string>

#include "MiniDB.h"

using namespace std;

int main()
{
    MiniDB mdb;
    mdb.setTable();
    cout << mdb.checkPlayer("SavaLione") << endl;
    cout << mdb.checkPlayer("OwO") << endl;
    cout << mdb.checkPlayer("asdwqfzbdr") << endl;
    cout << "---------------------------" << endl;
    string pass = "";
    cout << pass << endl;
    mdb.getPassword("SavaLione", pass);
    cout << pass << endl;
    mdb.getPassword("OwO", pass);
    cout << pass << endl;
    mdb.getPassword("asdwqfzbdr", pass);
    cout << pass << endl;
    return 0;
}