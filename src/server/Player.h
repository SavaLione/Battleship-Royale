#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    /* data */
    int *i_id = new int;
    bool *b_live = new bool;
public:
    std::string *s_name = new std::string;
    Player(/* args */);
    ~Player();
};

Player::Player(/* args */)
{
}

Player::~Player()
{
}


#endif // PLAYER_H