#include "wumpus.hpp"
#include "gold.hpp"
#include "bats.hpp"
#include "pit.hpp"
#include "event.hpp"
#include "room.hpp"
#include "adventurer.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

using namespace std;

#ifndef GAME_HPP
#define GAME_HPP

class Game{
  protected:
    bool isGameOver;
    int len;
    vector<vector<Room> > rooms;
    vector<Event *> evtPtrs;
    vector<Room *> roomPtrs;
    Room* escape;
    Adventurer* adv;
  public:
    Game(int dim);
    ~Game();
    Room* roomAt(int row, int col);
    int randInd(int len);
    void initializeRooms();
    void fillRooms(int& advRow, int& advCol);
    void displayDebugGame();
    void displayGame();
    void move(char dir);
    void fireArrow(char dir);
    void wakeUp();
    void enteredRoom();
    void messageAdj();
    char checkInput(string question, string valid);
    bool checkWin();
    void restart();
    void clearData();
    void beginGame();
  friend bool operator== (Room const &r1, Room const &r2);
};

#endif
