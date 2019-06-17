/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#include "Vampire.hpp"

//Constructor
Vampire::Vampire()
{
    armor = 1;
    strengthPoints = 18;
    type = "Vampire";
    attackRoll = 0;
    defenseRoll = 0;
    characteristics = "Suave, debonair, but vicious and surprisingly resilient.";
    specialAbility = "Charm: Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent does not actually attack them.";
}

//Attack roll for vampire
int Vampire::attack()
{
    //1d12
    attackRoll = rand() % 12 + 1;
    return attackRoll;
}

//Defense roll for vampire
int Vampire::defense()
{
    //1d6
    defenseRoll = rand() % 6 + 1;
    int charm = rand() % 2;
    //If charm activates vampire takes no damage
    //50% chance of activation
    if(charm == 1)
    {
        defenseRoll = 9999;
    }
    return defenseRoll;
}

