#include <iostream>

#include "BattleshipRoyale.h"
#include "Player.h"

using namespace std;

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    int i_size = 16;
    for (int i = 0; i < i_size/2; i++) {
        for (int z = 0; z < i_size*2; z++) {
            cout << "#";
        }
        cout << endl;
    }
}