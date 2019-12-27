#include "pit.hpp"

/******************************************************************
 * Function: Pit()
 * Description: Default empty Pit constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
Pit::Pit(){
  //empty
}

/******************************************************************
 * Function: encounter()
 * Description: prints encounter message to screen
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Pit::encounter(){
  cout << "You fall into an endless pit. Death." << endl;
}

/******************************************************************
 * Function: message()
 * Description: prints adjacent-to message to screen
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Pit::message(){
  cout << "You feel a cool breeze." << endl;
}

/******************************************************************
 * Function: message()
 * Description: returns Pit's char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char Pit::print(){
  return 'P';
}
