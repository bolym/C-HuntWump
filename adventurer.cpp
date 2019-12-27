#include "adventurer.hpp"

/******************************************************************
 * Function: Adventurer()
 * Description: Default empty Adventurer constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
Adventurer::Adventurer(){
  //empty
}

/******************************************************************
 * Function: Adventurer(Room* r)
 * Description: Parameterized Adventurer constructor initializes fields
 * Parameters: Room* r
 * Pre-Conditions: None
 * Post-Conditions: protected fields initialized using parameters
******************************************************************/
Adventurer::Adventurer(Room* r){
  numArrows = 3;
  hasGold = false;
  killedWump = false;
  curRoom = r;
}

/******************************************************************
 * Function: getNumArrows()
 * Description: returns numArrows
 * Parameters: None
 * Pre-Conditions: numArrows has been initialized
 * Post-Conditions: None
******************************************************************/
int Adventurer::getNumArrows(){
  return numArrows;
}

/******************************************************************
 * Function: setNumArrows()
 * Description: sets numArrows to num
 * Parameters: int num
 * Pre-Conditions: None
 * Post-Conditions: numArrows is assigned num
******************************************************************/
void Adventurer::setNumArrows(int num){
  numArrows = num;
}

/******************************************************************
 * Function: getHasGold()
 * Description: returns hasGold
 * Parameters: None
 * Pre-Conditions: hasGold has been initialized
 * Post-Conditions: None
******************************************************************/
bool Adventurer::getHasGold(){
  return hasGold;
}

/******************************************************************
 * Function: setHasGold(bool b)
 * Description: sets hasGold to b
 * Parameters: bool b
 * Pre-Conditions: None
 * Post-Conditions: hasGold is b
******************************************************************/
void Adventurer::setHasGold(bool b){
  hasGold = b;
}

/******************************************************************
 * Function: getKilledWump()
 * Description: returns killedWump
 * Parameters: None
 * Pre-Conditions: killedWump has been initialized
 * Post-Conditions: None
******************************************************************/
bool Adventurer::getKilledWump(){
  return killedWump;
}

/******************************************************************
 * Function: setKilledWump(bool b)
 * Description: sets killedWump to b
 * Parameters: bool b
 * Pre-Conditions: None
 * Post-Conditions: killedWump is b
******************************************************************/
void Adventurer::setKilledWump(bool b){
  killedWump = b;
}

/******************************************************************
 * Function: getCurRoom()
 * Description: returns curRoom
 * Parameters: None
 * Pre-Conditions: curRoom has been initialized
 * Post-Conditions: None
******************************************************************/
Room* Adventurer::getCurRoom(){
  return curRoom;
}

/******************************************************************
 * Function: setCurRoom(Room* r)
 * Description: sets curRoom to r
 * Parameters: Room* r
 * Pre-Conditions: None
 * Post-Conditions: curRoom is r 
******************************************************************/
void Adventurer::setCurRoom(Room* r){
  curRoom = r;
}
