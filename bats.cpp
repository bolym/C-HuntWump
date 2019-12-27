#include "bats.hpp"

/******************************************************************
 * Function: Bats()
 * Description: Default empty Bats constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
Bats::Bats(){
  //empty
}

/******************************************************************
 * Function: encounter()
 * Description: prints encounter message to screen
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Bats::encounter(){
  cout << "You walk into a room of Bats!" << endl;
  cout << "They carry you off to a random room!" << endl;
}

/******************************************************************
 * Function: message()
 * Description: prints adjacent-to message to screen
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Bats::message(){
  cout << "You hear wings flapping." << endl;
}

/******************************************************************
 * Function: message()
 * Description: returns Bats's char 
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char Bats::print(){
  return 'B';
}
