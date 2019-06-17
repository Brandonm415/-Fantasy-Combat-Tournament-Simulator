/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#include "HarryPotter.hpp"

//Constructor
HarryPotter::HarryPotter()
{
    armor = 0;
    strengthPoints = 10;
    type = "Harry Potter";
    attackRoll = 0;
    defenseRoll = 0;
    characteristics = "Harry Potter is a wizard.";
    specialAbility = "Hogwarts: If Harry Potter's strength reaches 0 or below, he immediately recovers and his total strength becomes 20. If he were to die again, then he's dead.";
    //Set Harry Potter revive status to TRUE
    revive = true;
}

//Harry Potter attack roll
int HarryPotter::attack()
{
    //2d6
    int dice1, dice2;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    attackRoll = dice1 + dice2;
    return attackRoll;
}

int HarryPotter::defense()
{
    //2d6
    int dice1, dice2;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    defenseRoll = dice1 + dice2;
    return defenseRoll;
}
