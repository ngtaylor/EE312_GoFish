# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary.

final: go_fish.o player.o deck.o card.o
	g++ -o GoFish go_fish.o player.o deck.o card.o
go_fish.o: go_fish.cpp player.h deck.h card.h
	g++ -std=c++0x -c go_fish.cpp
player.o: player.cpp player.h deck.h card.h
 	g++ -std=c++0x -c player.cpp
deck.o: deck.cpp deck.h card.h
    g++ -std=c++0x -c deck.cpp
card.o: card.cpp card.h
    g++ -std=c++0x -c card.cpp