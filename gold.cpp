#include "gold.hpp"

/******************************************************************
 * Function: Gold()
 * Description: Default Gold constructor sets found to false
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: found is false
******************************************************************/
Gold::Gold(){
  found = false;
}

/******************************************************************
 * Function: encounter()
 * Description: prints encounter message to screen if not found
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: found doesn't change
******************************************************************/
void Gold::encounter(){
  if(!found){
    cout << "You found the Gold!" << endl;
    found = true;
  }
}

/******************************************************************
 * Function: message()
 * Description: prints adjacent-to message to screen
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Gold::message(){
  if(!found){
    cout << "You see a glimmer nearby." << endl;
  }
}

/******************************************************************
 * Function: message()
 * Description: returns Gold's char
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
char Gold::print(){
  return 'G';
}
