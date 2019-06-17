/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#include "Barbarian.hpp"

//Constructor
Barbarian::Barbarian()
{
    armor = 0;
    strengthPoints = 12;
    type = "Barbarian";
    attackRoll = 0;
    defenseRoll = 0;
    characteristics = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
    specialAbility = "None";
}

//Attack roll for Barbarian
int Barbarian::attack()
{
    //2d6
    int dice1, dice2;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    attackRoll = dice1 + dice2;
    return attackRoll;
}

//Defense roll for Barbarian
int Barbarian::defense()
{
    //2d6
    int dice1, dice2;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    defenseRoll = dice1 + dice2;
    return defenseRoll;
}


