#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

using namespace std;

class Event{
  protected:
  public:
    Event();
    virtual void encounter() = 0;
    virtual void message() = 0;
    virtual char print() = 0;
};

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

class Gold : public Event{
  protected:
    bool found;
  public:
    Gold();
    void encounter();
    void message();
    char print();
};

class Bats : public Event{
  protected:

  public:
    Bats();
    void encounter();
    void message();
    char print();
};

class Pit : public Event{
  protected:

  public:
    Pit();
    void encounter();
    void message();
    char print();
};

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
