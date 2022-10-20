#ifndef __PLAYER_H
#define __PLAYER_H
#include<iostream>
#include<string>

class Player
{
private:
    size_t ID;
    int countS;

public:
    Player(size_t _ID)
    {
        ID = _ID;
        countS = 0;
    }
    size_t getID()const
    {
        return ID;
    }

    int getCountS() const
    {
        return countS;
    }

    void setCountS(int newCountS)
    {
        countS = newCountS;
    }

    void print()
    {
        std::cout << ID <<"--"<< countS << std::endl;
    }
};


#endif
