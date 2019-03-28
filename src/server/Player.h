#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "BattleshipRoyale.h"

class Player
{
private:
    /* data */
    int *i_id = new int;
    bool *b_live = new bool;
    Pos *pos_pos = new Pos;
    bool *b_bot = new bool;
    int *i_number = new int;
    std::string *s_name = new std::string;

    /* func */
    void setUnique();
    void setName();
    void setPos();
    void setNumber();
    void setLive();
    void setBot();
public:
    /* data */


    /* func */
    Player(/* args */);

    int getId();
    std::string getName();
    Pos getPos();
    int getNumber();
    bool getLive();
    bool getBot();

    /* des */
    ~Player();
};

#endif // PLAYER_H