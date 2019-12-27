CC=g++
EXE_FILE=hunt

all: $ (EXE_FILE)

$ (EXE_FILE): wumpus.o gold.o bats.o pit.o event.o room.o adventurer.o game.o wumpus.hpp gold.hpp bats.hpp pit.hpp event.hpp room.hpp adventurer.hpp game.hpp app.cpp
	$(CC) wumpus.o gold.o bats.o pit.o event.o room.o adventurer.o game.o app.cpp -std=c++11 -o $(EXE_FILE)

wumpus.o: wumpus.hpp wumpus.cpp
	$(CC) -c wumpus.cpp

gold.o: gold.hpp gold.cpp
	$(CC) -c gold.cpp

bats.o: bats.hpp bats.cpp
	$(CC) -c bats.cpp

pit.o: pit.hpp pit.cpp
	$(CC) -c pit.cpp

event.o: event.hpp event.cpp
	$(CC) -c event.cpp

room.o: room.hpp room.cpp
	$(CC) -c room.cpp

adventurer.o: adventurer.hpp adventurer.cpp
	$(CC) -c adventurer.cpp

game.o: game.hpp game.cpp
	$(CC) -c game.cpp -std=c++11

clean:
	rm -f *.o $(EXE_FILE)
