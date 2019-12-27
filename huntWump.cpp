#include "huntWump.hpp"

/************EVENT CLASS*****************/
Event::Event(){
  //empty
}

/************WUMPUS CLASS*****************/
Wumpus::Wumpus(){
  died = false;
}

void Wumpus::setDied(bool b){
  died = b;
}

void Wumpus::encounter(){
  if(!died){
    cout << "You walk into the Wumpus's room. Death." << endl;
  }
}

void Wumpus::message(){
  cout << "You smell a terrible stench." << endl;
}

char Wumpus::print(){
  return 'W';
}

/************GOLD CLASS*****************/
Gold::Gold(){
  found = false;
}

void Gold::encounter(){
  if(!found){
    cout << "You found the Gold!" << endl;
    found = true;
  }
}

void Gold::message(){
  if(!found){
    cout << "You see a glimmer nearby." << endl;
  }
}

char Gold::print(){
  return 'G';
}

/************BATS CLASS*****************/
Bats::Bats(){
  //empty
}

void Bats::encounter(){
  cout << "You walk into a room of Bats!" << endl;
  cout << "They carry you off to a random room!" << endl;
}

void Bats::message(){
  cout << "You hear wings flapping." << endl;
}

char Bats::print(){
  return 'B';
}

/************PIT CLASS*****************/
Pit::Pit(){
  //empty
}

void Pit::encounter(){
  cout << "You fall into an endless pit. Death." << endl;
}

void Pit::message(){
  cout << "You feel a cool breeze." << endl;
}

char Pit::print(){
  return 'P';
}

/************ROOM CLASS*****************/
Room::Room(){
  row = 0;
  col = 0;
  hasEvent = false;
  event = NULL;
}

Room::Room(int r, int c){
  row = r;
  col = c;
  hasEvent = false;
  event = NULL;
}

int Room::getRow(){
  return row;
}

int Room::getCol(){
  return col;
}

bool Room::getHasEvent(){
  return hasEvent;
}

void Room::setHasEvent(bool b){
  hasEvent = b;
}

Event* Room::getEvent(){
  return event;
}

void Room::setEvent(Event* evt){
  event = evt;
  hasEvent = true;
}

/************ADVENTURER CLASS*****************/
Adventurer::Adventurer(){
  //empty
}

Adventurer::Adventurer(Room* r){
  numArrows = 3;
  hasGold = false;
  killedWump = false;
  curRoom = r;
}

int Adventurer::getNumArrows(){
  return numArrows;
}

void Adventurer::setNumArrows(int num){
  numArrows = num;
}

bool Adventurer::getHasGold(){
  return hasGold;
}

void Adventurer::setHasGold(bool b){
  hasGold = b;
}

bool Adventurer::getKilledWump(){
  return killedWump;
}

void Adventurer::setKilledWump(bool b){
  killedWump = b;
}

Room* Adventurer::getCurRoom(){
  return curRoom;
}

void Adventurer::setCurRoom(Room* r){
  curRoom = r;
}

/************ MAIN *****************/

Game::Game(int dim){
  isGameOver = false;
  len = dim;
  int begRow = randInd(dim);
  int begCol = randInd(dim);
  initializeRooms();
  cout << "before roomPtrs.size(): " << roomPtrs.size() << endl;
  fillRooms(begRow, begCol);
  cout << "after roomPtrs.size(): " << roomPtrs.size() << endl;
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

void Game::initializeRooms(){

  for(int i = 0; i < len; i++){
    vector<Room> row;
    for(int j = 0; j < len; j++){
      row.push_back(Room(i, j));
    }
    rooms.push_back(row);
  }
}

void Game::fillRooms(int& advRow, int& advCol){
  /* Place events random rooms */
  int randRow = randInd(len);
  int randCol = randInd(len);
  Wumpus* wump = new Wumpus();
  evtPtrs.push_back(wump);
  rooms.at(randRow).at(randCol).setEvent(wump);
  roomPtrs.push_back(roomAt(randRow, randCol));

  Gold* gold = new Gold();
  evtPtrs.push_back(gold);
  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  rooms.at(randRow).at(randCol).setEvent(gold);
  roomPtrs.push_back(roomAt(randRow, randCol));

  Bats* bats = new Bats();
  evtPtrs.push_back(bats);
  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  rooms.at(randRow).at(randCol).setEvent(bats);
  roomPtrs.push_back(roomAt(randRow, randCol));

  Bats* bats2 = new Bats();
  evtPtrs.push_back(bats2);
  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  rooms.at(randRow).at(randCol).setEvent(bats2);
  roomPtrs.push_back(roomAt(randRow, randCol));

  Pit* pit = new Pit();
  evtPtrs.push_back(pit);
  while(rooms.at(randRow).at(randCol).getHasEvent()){
    randRow = randInd(len);
    randCol = randInd(len);
  }
  rooms.at(randRow).at(randCol).setEvent(pit);
  roomPtrs.push_back(roomAt(randRow, randCol));

  Pit* pit2 = new Pit();
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
  advRow = randRow;
  advCol = randCol;
}

bool operator== (Room const &r1, Room const &r2){
  return (r1.row == r2.row) && (r1.col == r2.col);
}

void Game::displayDebugGame(){
  cout << endl;
  for(int i = 0; i < len; i++){
    cout << "-------";
  }
  cout << endl;
  for(int i = 0; i < len; i++){
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

void Game::displayGame(){
  cout << endl;
  for(int i = 0; i < len; i++){
    cout << "-------";
  }
  cout << endl;
  for(int i = 0; i < len; i++){
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
  if(adv->getKilledWump()){
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

void Game::wakeUp(){
  int randNum = rand() % 4 + 1;
  if(randNum <= 3){
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
    rooms.at(randRow).at(randCol).setEvent(wPtr);
  } else {
    cout << "The Wumpus didn't hear your shot." << endl;
  }
}

void Game::messageAdj(){
  cout << endl << endl;
  int row = adv->getCurRoom()->getRow();
  int col = adv->getCurRoom()->getCol();
  if(row - 1 >= 0){
    if(rooms.at(row - 1).at(col).getHasEvent()){
      rooms.at(row - 1).at(col).getEvent()->message();
    }
  }
  if(row + 1 < len){
    if(rooms.at(row + 1).at(col).getHasEvent()){
      rooms.at(row + 1).at(col).getEvent()->message();
    }
  }
  if(col - 1 >= 0){
    if(rooms.at(row).at(col - 1).getHasEvent()){
      rooms.at(row).at(col - 1).getEvent()->message();
    }
  }
  if(col + 1 < len){
    if(rooms.at(row).at(col + 1).getHasEvent()){
      rooms.at(row).at(col + 1).getEvent()->message();
    }
  }
  cout << endl << endl;
}

void Game::enteredRoom(){
  cout << endl << endl;
  if(adv->getCurRoom()->getHasEvent()){
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
      case 'B': {
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

bool Game::checkWin(){
  if(adv->getHasGold() && adv->getKilledWump() && *(adv->getCurRoom()) == *escape){
    cout << "You have safely killed the Wumpus, taken the gold, and escaped!" << endl;
    isGameOver = true;
    return true;
  }
  return false;
}

void Game::restart(){
  clearData();
  delete adv;
  isGameOver = false;
  adv = new Adventurer(escape);
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

void Game::clearData(){
  for(int i = 0; i < evtPtrs.size(); i++){
    delete evtPtrs[i];
  }
  evtPtrs.clear();
}

void Game::beginGame(){

  while(!isGameOver){
    displayDebugGame();
    messageAdj();
    char choice = ' ';
    choice = checkInput("Enter 'm' to move or 'f' to fire an arrow: ", "mf");
    if(choice == 'f'){
      if(adv->getNumArrows() < 1){
        cout << "You have no more arrows left." << endl;
        choice = 'm';
      } else {
        cout << "Which direction do you want to fire an arrow? " << endl;
        char fDir = ' ';
        fDir = checkInput("Enter w, a, s, or d: ", "wasd");
        fireArrow(fDir);
      }
    } else if(choice == 'm'){
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
  displayDebugGame();
  cout << "Game Over!" << endl;
}

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
  Game firstGame(dim);
  firstGame.beginGame();
  again = firstGame.checkInput("Play again? Enter 'y' or 'n': ", "yn");

  while(again == 'y'){
    difGame = firstGame.checkInput("Same or different configuration? Enter 's' or 'd': ", "sd");
    if(difGame == 'd'){
      Game nextGame(dim);
      nextGame.beginGame();
      nextGame.clearData();
    } else if(difGame == 's'){
      firstGame.restart();
    }
    again = firstGame.checkInput("Play again? Enter 'y' or 'n': ", "yn");
  }
  firstGame.clearData();
  cout << "Thanks for playing!" << endl;
}
