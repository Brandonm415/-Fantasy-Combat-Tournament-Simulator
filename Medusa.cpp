/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#include "Medusa.hpp"

//Constructor
Medusa::Medusa()
{
    armor = 3;
    strengthPoints = 8;
    type = "Medusa";
    attackRoll = 0;
    defenseRoll = 0;
    characteristics = "Scrawny lady with snakes for hair which helps her during combat. Just don't look at her!";
    specialAbility = "Glare: If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life.";
}

//Medusa attack roll
int Medusa::attack()
{
    //2d6
    int dice1, dice2;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    attackRoll = dice1 + dice2;
    //If Medusa activates Glare by rolling a 12
    //One shot the enemy by turning them to stone
    if(attackRoll == 12)
    {
        attackRoll = 9999;
    }
    return attackRoll;
}

//Medusa Defense roll
int Medusa::defense()
{
    //1d6
    defenseRoll = rand() % 6 + 1;
    return defenseRoll;
}
