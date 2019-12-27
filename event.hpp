#include <iostream>
using namespace std;

#ifndef EVENT_HPP
#define EVENT_HPP

class Event{
  protected:
  public:
    Event();
    virtual void encounter() = 0;
    virtual void message() = 0;
    virtual char print() = 0;
};

#endif
