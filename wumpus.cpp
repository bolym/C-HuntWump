#include "wumpus.hpp"

/******************************************************************
 * Function: Wumpus()
 * Description: Default Wumpus constructor initializes died
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: died is false
******************************************************************/
Wumpus::Wumpus(){
  died = false;
}

/******************************************************************
 * Function: setDied(bool b)
 * Description: sets died to b
 * Parameters: bool b
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Wumpus::setDied(bool b){
  died = b;
}

/******************************************************************
 * Function: encounter()
 * Description: prints encounter message to screen if alive
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: died doesn't change
******************************************************************/
void Wumpus::encounter(){
  if(!died){
    cout << "You walk into the Wumpus's room. Death." << endl;
  }
}

/******************************************************************
 * Function: message()
 * Description: prints adjacent-to message to screen
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Wumpus::message(){
  cout << "You smell a terrible stench." << endl;
}

/******************************************************************
 * Function: message()
 * Description: returns Wumpus's char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char Wumpus::print(){
  return 'W';
}
