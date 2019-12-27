#include "event.hpp"
#include <iostream>
using namespace std;

#ifndef WUMPUS_HPP
#define WUMPUS_HPP

class Wumpus : public Event{
  protected:
    bool died;
  public:
    Wumpus();
    void setDied(bool b);
    void encounter();
    void message();
    char print();
};

#endif
