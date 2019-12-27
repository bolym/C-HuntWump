#include "event.hpp"
#include <iostream>
using namespace std;

#ifndef BATS_HPP
#define BATS_HPP

class Bats : public Event{
  protected:

  public:
    Bats();
    void encounter();
    void message();
    char print();
};

#endif
