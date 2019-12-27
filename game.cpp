#include "game.hpp"

/******************************************************************
 * Function: Game(int dim)
 * Description: Paramaterized Game constructor
 * Parameters: int dim
 * Pre-Conditions: The class itself has already called the constructor
                    for the other private variables
 * Post-Conditions: The game begins as not over
******************************************************************/
Game::Game(int dim){
  isGameOver = false;
  len = dim;
  initializeRooms();
  int begRow = randInd(dim);
  int begCol = randInd(dim);
  fillRooms(begRow, begCol);
  escape = roomAt(begRow, begCol);
  adv = new Adventurer(escape);
}

Game::~Game(){
  delete adv;
}

Room* Game::roomAt(int row, int col){
  Room* roomPtr = &rooms.at(row).at(col);
  return roomPtr;
}

int Game::randInd(int len){
  int num = rand() % len;
  return num;
}

/******************************************************************
 * Function: initializeRooms()
 * Description: initialize 2d vector of rooms
 * Parameters: None
 * Pre-Conditions: rooms has been declared already
 * Post-Conditions: rooms has empty room objects
******************************************************************/
void Game::initializeRooms(){

  for(int i = 0; i < len; i++){
    vector<Room> row;
    for(int j = 0; j < len; j++){
      row.push_back(Room(i, j));
    }
    rooms.push_back(row);
  }
}

/******************************************************************
 * Function: fillRooms(int& advRow, int& advCol)
 * Description: randomly assign events to rooms
 * Parameters: int& advRow, int& advCol
 * Pre-Conditions: rooms has been initialized already
 * Post-Conditions: some rooms are pointing to events
******************************************************************/
void Game::fillRooms(int& advRow, int& advCol){
  /* Place events in random rooms */
  int randRow = randInd(len);
  int randCol = randInd(len);
  Wumpus* wump = new Wumpus(); /* place wumpus */
  evtPtrs.push_back(wump);    /* track to delete later */
  rooms.at(randRow).at(randCol).setEvent(wump);
  roomPtrs.push_back(roomAt(randRow, randCol));  /*track to restart same game */

  Gold* gold = new Gold(); /* place gold */
  evtPtrs.push_back(gold);
  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  rooms.at(randRow).at(randCol).setEvent(gold);
  roomPtrs.push_back(roomAt(randRow, randCol));

  Bats* bats = new Bats(); /* place bats */
  evtPtrs.push_back(bats);
  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  rooms.at(randRow).at(randCol).setEvent(bats);
  roomPtrs.push_back(roomAt(randRow, randCol));

  Bats* bats2 = new Bats(); /* place bats2 */
  evtPtrs.push_back(bats2);
  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  rooms.at(randRow).at(randCol).setEvent(bats2);
  roomPtrs.push_back(roomAt(randRow, randCol));

  Pit* pit = new Pit(); /* place pit */
  evtPtrs.push_back(pit);
  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  rooms.at(randRow).at(randCol).setEvent(pit);
  roomPtrs.push_back(roomAt(randRow, randCol));

  Pit* pit2 = new Pit(); /* place pit2 */
  evtPtrs.push_back(pit2);
  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  rooms.at(randRow).at(randCol).setEvent(pit2);
  roomPtrs.push_back(roomAt(randRow, randCol));

  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  advRow = randRow; /* generate loc for adventurer */
  advCol = randCol;
}

/******************************************************************
 * Function: operator== (Room const &r1, Room const &r2)
 * Description: comparison operator overlaod for comparing rooms
 * Parameters: Room const &r1, Room const &r2
 * Pre-Conditions: rooms must be initialized
 * Post-Conditions: rooms don't change
******************************************************************/
bool operator== (Room const &r1, Room const &r2){
  return (r1.row == r2.row) && (r1.col == r2.col);
}

/******************************************************************
 * Function: displayDebugGame()
 * Description: displays everything in the rooms
 * Parameters: None
 * Pre-Conditions: rooms must be accurate
 * Post-Conditions: rooms don't change
******************************************************************/
void Game::displayDebugGame(){
  cout << endl;
  for(int i = 0; i < len; i++){
    cout << "-------";
  }
  cout << endl;
  for(int i = 0; i < len; i++){   /* display everything in cave */
    for(int j = 0; j < len; j++){
      if(rooms.at(i).at(j) == *(adv->getCurRoom())) {
          cout << "*\t";
      } else if(rooms.at(i).at(j).getHasEvent()){
        cout << rooms.at(i).at(j).getEvent()->print();
        cout << "\t";
      } else {
        cout << "E\t";
      }
    }
    cout << endl;
  }
  for(int i = 0; i < len; i++){
    cout << "-------";
  }
  cout << endl << "You have " << adv->getNumArrows() << " arrows left." << endl << endl;
}

/******************************************************************
 * Function: displayGame()
 * Description: displays only the adventurer in the rooms
 * Parameters: None
 * Pre-Conditions: rooms must be accurate
 * Post-Conditions: rooms don't change
******************************************************************/
void Game::displayGame(){
  cout << endl;
  for(int i = 0; i < len; i++){
    cout << "-------";
  }
  cout << endl;
  for(int i = 0; i < len; i++){ /* display only adv in cave */
    for(int j = 0; j < len; j++){
      if(rooms.at(i).at(j) == *(adv->getCurRoom())) {
          cout << "**\t";
      } else {
        cout << "[]\t";
      }
    }
    cout << endl;
  }
  for(int i = 0; i < len; i++){
    cout << "-------";
  }
  cout << endl << "You have " << adv->getNumArrows() << " arrows left." << endl;
  cout << endl;
}

/******************************************************************
 * Function: move(char dir)
 * Description: moves the adventurer N,S,E, or W
 * Parameters: char dir
 * Pre-Conditions: rooms must be accurate
 * Post-Conditions: adenturer's curRoom changes
******************************************************************/
void Game::move(char dir){
  int row = adv->getCurRoom()->getRow();
  int col = adv->getCurRoom()->getCol();
  switch(dir){
    case 'w':  /* move up */
      if(row - 1 >= 0){
        adv->setCurRoom(roomAt(row-1, col));
      } else {
        cout << "out of bounds" << endl;
      }
      break;
    case 's':  /* move down */
      if(row + 1 < len){
        adv->setCurRoom(roomAt(row+1, col));
      } else {
        cout << "out of bounds" << endl;
      }
      break;
    case 'a':  /* move left */
      if(col - 1 >= 0){
        adv->setCurRoom(roomAt(row, col-1));
      } else {
        cout << "out of bounds" << endl;
      }
      break;
    case 'd':  /* move right */
      if(col + 1 < len){
        adv->setCurRoom(roomAt(row, col+1));
      } else {
        cout << "out of bounds" << endl;
      }
  }
}

/******************************************************************
 * Function: fireArrow(char dir)
 * Description: fire's an arrow N, S, E, or W
 * Parameters: char dir
 * Pre-Conditions: numArrows must not be negative
 * Post-Conditions: numArrows has decremented by 1
******************************************************************/
void Game::fireArrow(char dir){
  if(adv->getKilledWump()){
    cout << "You already killed the Wumpus!" << endl;
    adv->setNumArrows(adv->getNumArrows() - 1);
    return;
  }
  int row = adv->getCurRoom()->getRow();
  int col = adv->getCurRoom()->getCol();
  switch(dir){
    case 'w':  /* fire north */
      cout << "You fire an arrow north." << endl;
      for(int i = 1; i < 4; i++){
        if(row - i >= 0){
          if(roomAt(row-i, col)->getHasEvent()){
            if((roomAt(row-i, col)->getEvent()->print()) == 'W'){
              adv->setKilledWump(true);
            }
          }
        }
      }
      break;
    case 's':  /* fire south */
      cout << "You fire an arrow south." << endl;
      for(int i = 1; i < 4; i++){
        if(row + i < len){
          if(roomAt(row+i, col)->getHasEvent()){
            if((roomAt(row+i, col)->getEvent()->print()) == 'W'){
              adv->setKilledWump(true);
            }
          }
        }
      }
      break;
    case 'a':  /* fire west */
      cout << "You fire an arrow west." << endl;
      for(int i = 1; i < 4; i++){
        if(col - i >= 0){
          if(roomAt(row, col-i)->getHasEvent()){
            if(roomAt(row, col-i)->getEvent()->print() == 'W'){
              adv->setKilledWump(true);
            }
          }
        }
      }
      break;
    case 'd':  /* fire east */
      cout << "You fire an arrow east." << endl;
      for(int i = 1; i < 4; i++){
        if(col + i < len){
          if(roomAt(row, col+i)->getHasEvent()){
            if(roomAt(row, col+i)->getEvent()->print() == 'W'){
              adv->setKilledWump(true);
            }
          }
        }
      }
  }
  adv->setNumArrows(adv->getNumArrows() - 1);
  if(adv->getKilledWump()){   /* check if hit */
    cout << "Your arrow pierced the Wumpus's heart!" << endl;
  } else {
    cout << "Your arrow missed." << endl;
    wakeUp();
  }
  /* check for no more arrows and alive wumpus */
  if(adv->getNumArrows() < 1 && !adv->getKilledWump()){
    cout << "Looks like you ran out of arrows to kill the Wumpus!" << endl;
    isGameOver = true;
  }
}

/******************************************************************
 * Function: wakeUp()
 * Description: wumpus has 75% chance of moving to a different room
 * Parameters: None
 * Pre-Conditions: adventurer must have missed arrow shot
 * Post-Conditions: wumpus may move rooms
******************************************************************/
void Game::wakeUp(){
  int randNum = rand() % 4 + 1;
  if(randNum <= 3){     /* 75% chance */
    cout << "The Wumpus woke to your shot and moved to a different room." << endl;
    Event* wPtr;
    for(int i = 0; i < len; i++){
      for(int j = 0; j < len; j++){
        if(roomAt(i,j)->getHasEvent()){
          if(roomAt(i,j)->getEvent()->print() == 'W'){
            wPtr = roomAt(i,j)->getEvent();
            roomAt(i,j)->setEvent(NULL);
            roomAt(i,j)->setHasEvent(false);
          }
        }
      }
    }
    int randRow = randInd(len);
    int randCol = randInd(len);
    while(rooms.at(randRow).at(randCol).getHasEvent()){
      randRow = randInd(len);
      randCol = randInd(len);
    }
    rooms.at(randRow).at(randCol).setEvent(wPtr); /* wump moves rooms */
  } else {
    cout << "The Wumpus didn't hear your shot." << endl;
  }
}

/******************************************************************
 * Function: messageAdj()
 * Description: messages all in bound adjacent rooms
 * Parameters: None
 * Pre-Conditions: rooms must be initialized
 * Post-Conditions: messges printed to the screen
******************************************************************/
void Game::messageAdj(){
  cout << endl << endl;
  int row = adv->getCurRoom()->getRow();
  int col = adv->getCurRoom()->getCol();
  if(row - 1 >= 0){   /* message top */
    if(rooms.at(row - 1).at(col).getHasEvent()){
      rooms.at(row - 1).at(col).getEvent()->message();
    }
  }
  if(row + 1 < len){  /* message bottom */
    if(rooms.at(row + 1).at(col).getHasEvent()){
      rooms.at(row + 1).at(col).getEvent()->message();
    }
  }
  if(col - 1 >= 0){   /* message left */
    if(rooms.at(row).at(col - 1).getHasEvent()){
      rooms.at(row).at(col - 1).getEvent()->message();
    }
  }
  if(col + 1 < len){  /* message right */
    if(rooms.at(row).at(col + 1).getHasEvent()){
      rooms.at(row).at(col + 1).getEvent()->message();
    }
  }
  cout << endl << endl;
}

/******************************************************************
 * Function: enteredRoom()
 * Description: encounters the event in the room of the adventurer
 * Parameters: None
 * Pre-Conditions: rooms must be initialized
 * Post-Conditions: adventurer could win or lose
******************************************************************/
void Game::enteredRoom(){
  cout << endl << endl;
  if(adv->getCurRoom()->getHasEvent()){   /* encounter with the event */
    char event = adv->getCurRoom()->getEvent()->print();
    if(event == 'W'){
      if(adv->getKilledWump()){
        cout << "You walk back into the room with the dead Wumpus..." << endl;
      } else {
        adv->getCurRoom()->getEvent()->encounter();
      }
    } else {
      adv->getCurRoom()->getEvent()->encounter();
    }

    switch(event){
      case 'W': {
        if(!adv->getKilledWump()){
          isGameOver = true;
        }
        break;
      }
      case 'G': {
        adv->setHasGold(true);
        break;
      }
      case 'B': {   /* pick any rand room */
        Room* randRoom = roomAt(randInd(len), randInd(len));
        adv->setCurRoom(randRoom);
        enteredRoom();
        break;
      }
      case 'P': {
        isGameOver = true;
      }
    }
  }
}

/******************************************************************
 * Function: checkInput
 * Description: Performs a do-while using question to only accept
 * 		characters that are in valid. Returns char
 * 		version of input.
 * Parameters: string question, string valid
 * Pre-Conditions: question and valid must not be empty
 * Post-Conditions: question and valid don't change
******************************************************************/
char Game::checkInput(string question, string valid){
   string var_str;
   size_t found;

   do{
      cout << question << endl;
      cin >> var_str;
      found = var_str.find_first_not_of(valid);
   }
   while(found != string::npos && var_str.length() < 2);

   return var_str[0];
}

/******************************************************************
 * Function: checkWin()
 * Description: checks to see if adventurer has won the game
 * Parameters: None
 * Pre-Conditions: escape rooms must be initialized
 * Post-Conditions: isGameOver could be made true
******************************************************************/
bool Game::checkWin(){
  if(adv->getHasGold() && adv->getKilledWump() && *(adv->getCurRoom()) == *escape){
    cout << "You have safely killed the Wumpus, taken the gold, and escaped!" << endl;
    isGameOver = true;
    return true;
  }
  return false;
}

/******************************************************************
 * Function: clearData()
 * Description: clears memory in evtPtrs
 * Parameters: None
 * Pre-Conditions: evtPtrs must be filled
 * Post-Conditions: no leaks from evtPtrs
******************************************************************/
void Game::clearData(){
  for(int i = 0; i < evtPtrs.size(); i++){
    delete evtPtrs[i];
  }
  evtPtrs.clear();
}

/******************************************************************
 * Function: restart()
 * Description: restarts the gaem with the same room configuration
 * Parameters: None
 * Pre-Conditions: previous game must be over
 * Post-Conditions: this game resets from the beginning
******************************************************************/
void Game::restart(){
  clearData();  /* clear old memory to store new */
  delete adv;
  isGameOver = false;
  adv = new Adventurer(escape);

  /* create new events in the same old rooms */
  Wumpus* wump = new Wumpus();
  evtPtrs.push_back(wump);
  roomPtrs.at(0)->setEvent(wump);

  Gold* gold = new Gold();
  roomPtrs.at(1)->setEvent(gold);
  evtPtrs.push_back(gold);

  Bats* bats = new Bats();
  roomPtrs.at(2)->setEvent(bats);
  evtPtrs.push_back(bats);

  Bats* bats2 = new Bats();
  roomPtrs.at(3)->setEvent(bats);
  evtPtrs.push_back(bats2);

  Pit* pit = new Pit();
  roomPtrs.at(4)->setEvent(pit);
  evtPtrs.push_back(pit);

  Pit* pit2 = new Pit();
  roomPtrs.at(5)->setEvent(pit2);
  evtPtrs.push_back(pit2);

  beginGame();
}

/******************************************************************
 * Function: beginGame()
 * Description: executes the structure of the game
 * Parameters: None
 * Pre-Conditions: all private variables initialized
 * Post-Conditions: this game has ended
******************************************************************/
void Game::beginGame(){
  while(!isGameOver){
    displayGame();
    messageAdj();
    char choice = ' ';
    choice = checkInput("Enter 'm' to move or 'f' to fire an arrow: ", "mf");
    if(choice == 'f'){   /* fire an arrow */
      if(adv->getNumArrows() < 1){
        cout << "You have no more arrows left." << endl;
        choice = 'm';
      } else {  /* has at least 1 arrow */
        cout << "Which direction do you want to fire an arrow? " << endl;
        char fDir = ' ';
        fDir = checkInput("Enter w, a, s, or d: ", "wasd");
        fireArrow(fDir);
      }
    } else if(choice == 'm'){   /* move */
      cout << "Which direction do you want to move? " << endl;
      char mDir = ' ';
      mDir = checkInput("Enter w, a, s, or d: ", "wasd");
      move(mDir);
      enteredRoom();
    }
    if(checkWin()){
      cout << "You Win!" << endl;
    }
  }
  displayGame();
  cout << "Game Over!" << endl;
}
