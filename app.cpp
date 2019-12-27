/******************************************************************
 * Program: app.cpp
 * Author: Michael Boly
 * Date: 3/3/2019
 * Description: Plays Hunt the Wumpus by the rules
 * Input: The user chooses to move or fire an arrow
 * Output: A wholesome game of Hun the Wumpus.
 *****************************************************************/
 
#include "game.hpp"
#include <iostream>
using namespace std;

/******************************************************************
 * Function: main()
 * Description: Creates a game of Hunt the Wump that continues one
                move at a time until the user wins or loses. Then
                can choose to play again with same or different
                configuration.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: The user will be appreciating your hard work.
 ******************************************************************/
int main(int argc, char* argv[]){
  /* check for valid number of args */
  if(argc != 2){
    cout << "Invalid number of arguments. No game for you." << endl;
    exit(1);
  } else if(stoi(argv[1]) < 4){
    cout << "Argument for cave dimensions too small: size 4 or bigger only." << endl;
    exit(1);
  }

  int dim = stoi(argv[1]);
  srand(time(NULL));

  char again = ' ';
  char difGame = ' ';
  Game firstGame(dim);  /* begin a game */
  firstGame.beginGame();
  again = firstGame.checkInput("Play again? Enter 'y' or 'n': ", "yn");

  while(again == 'y'){  /* play again */
    difGame = firstGame.checkInput("Same or different configuration? Enter 's' or 'd': ", "sd");
    if(difGame == 'd'){   /* diff game */
      Game nextGame(dim);
      nextGame.beginGame();
      nextGame.clearData();
    } else if(difGame == 's'){  /* same game */
      firstGame.restart();
    }
    again = firstGame.checkInput("Play again? Enter 'y' or 'n': ", "yn");
  }
  firstGame.clearData();   /* avoid memory leaks */
  cout << "Thanks for playing!" << endl;
}
