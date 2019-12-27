#include "event.hpp"
#include <iostream>
using namespace std;

#ifndef GOLD_HPP
#define GOLD_HPP

class Gold : public Event{
  protected:
    bool found;
  public:
    Gold();
    void encounter();
    void message();
    char print();
};

#endif
