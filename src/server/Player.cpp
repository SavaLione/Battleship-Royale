
#include "Player.h"

using namespace std;

Player::Player(/* args */)
{
}

Player::~Player()
{
    delete i_id;
    delete b_live;
    delete pos_pos;
    delete b_bot;
    delete i_number;
    delete s_name;
}