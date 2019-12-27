#include "event.hpp"
#include <iostream>
using namespace std;

#ifndef ROOM_HPP
#define ROOM_HPP

class Room{
  protected:
    int row;
    int col;
    bool hasEvent;
    Event* event;
  public:
    Room();
    Room(int r, int c);
    int getRow();
    int getCol();
    bool getHasEvent();
    void setHasEvent(bool b);
    Event* getEvent();
    void setEvent(Event* event);
    friend bool operator== (Room const &r1, Room const &r2);
};

#endif
