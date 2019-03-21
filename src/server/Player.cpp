#include "Player.h"

Player::Player(/* args */)
{
    setName();
    
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

void Player::setUnique()
{

}

void Player::setName()
{

}

void Player::setPos()
{

}

void Player::setNumber()
{

}

void Player::setLive()
{

}

void Player::setBot()
{
    *b_bot = true;
}

int Player::getId()
{
    return *i_id;
}

std::string Player::getName()
{
    return *s_name;
}

Pos Player::getPos()
{
    return *pos_pos;
}

int Player::getNumber()
{
    return *i_number;
}

bool Player::getLive()
{
    return *b_live;
}

bool Player::getBot()
{
    return *b_bot;
}