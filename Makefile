#*******************************************
#** Program Name: Project3
#** Author: Brandon Mai
#** Date: 5/9/2019
#******************************************

#Template Adapted from Makefile help from class module 

output: main.o Barbarian.o BlueMen.o Character.o Game.o HarryPotter.o Medusa.o Vampire.o
	g++ -std=c++11 main.o Barbarian.o BlueMen.o Character.o Game.o HarryPotter.o Medusa.o Vampire.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++11 -c BlueMen.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++11 -c Character.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++11 -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++11 -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++11 -c Vampire.cpp

target: dependencies
	action

clean:
	rm *.o output
