#include "room.hpp"

/******************************************************************
 * Function: Room()
 * Description: Default Room constructor initializes fields
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: protected fields initialized
******************************************************************/
Room::Room(){
  row = 0;
  col = 0;
  hasEvent = false;
  event = NULL;
}

/******************************************************************
 * Function: Room(int r, int c)
 * Description: Parameterized Room constructor initializes fields
 * Parameters: int r, int c
 * Pre-Conditions: None
 * Post-Conditions: protected fields initialized using parameters
******************************************************************/
Room::Room(int r, int c){
  row = r;
  col = c;
  hasEvent = false;
  event = NULL;
}

/******************************************************************
 * Function: getRow()
 * Description: returns row
 * Parameters: None
 * Pre-Conditions: row has been initialized
 * Post-Conditions: None
******************************************************************/
int Room::getRow(){
  return row;
}

/******************************************************************
 * Function: getCol()
 * Description: returns col
 * Parameters: None
 * Pre-Conditions: col has been initialized
 * Post-Conditions: None
******************************************************************/
int Room::getCol(){
  return col;
}

/******************************************************************
 * Function: getHasEvent()
 * Description: returns hasEvent
 * Parameters: None
 * Pre-Conditions: hasEvent has been initialized
 * Post-Conditions: None
******************************************************************/
bool Room::getHasEvent(){
  return hasEvent;
}

/******************************************************************
 * Function: setHasEvent(bool b)
 * Description: sets hasEvent to b
 * Parameters: bool b
 * Pre-Conditions: None
 * Post-Conditions: hasEvent is b
******************************************************************/
void Room::setHasEvent(bool b){
  hasEvent = b;
}

/******************************************************************
 * Function: getEvent()
 * Description: returns event
 * Parameters: None
 * Pre-Conditions: event has been initialized
 * Post-Conditions: None
******************************************************************/
Event* Room::getEvent(){
  return event;
}

/******************************************************************
 * Function: setEvent(Event* evt)
 * Description: sets event to evt and makes hasEvent true
 * Parameters: Event* evt
 * Pre-Conditions: None
 * Post-Conditions: event is evt and hasEvent is true
******************************************************************/
void Room::setEvent(Event* evt){
  event = evt;
  hasEvent = true;
}
