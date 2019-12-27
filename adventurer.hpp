#include "room.hpp"
#include <iostream>
using namespace std;

#ifndef ADVENTURER_HPP
#define ADVENTURER_HPP

class Adventurer{
  protected:
    int numArrows;
    bool hasGold;
    bool killedWump;
    Room* curRoom;
  public:
    Adventurer();
    Adventurer(Room* r);
    int getNumArrows();
    void setNumArrows(int num);
    bool getHasGold();
    void setHasGold(bool b);
    bool getKilledWump();
    void setKilledWump(bool b);
    Room* getCurRoom();
    void setCurRoom(Room* r);
};

#endif
