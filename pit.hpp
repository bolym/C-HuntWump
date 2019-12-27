#include "event.hpp"
#include <iostream>
using namespace std;

#ifndef PIT_HPP
#define PIT_HPP

class Pit : public Event{
  protected:

  public:
    Pit();
    void encounter();
    void message();
    char print();
};

#endif
