/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#include "BlueMen.hpp"

//Constructor
BlueMen::BlueMen()
{
    armor = 3;
    strengthPoints = 12;
    type = "Blue Men";
    attackRoll = 0;
    defenseRoll = 0;
    characteristics = "They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies' armor or clothing.";
    specialAbility = "Mob: Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense.";
}

//Blue Men attack roll
int BlueMen::attack()
{
    //2d10
    int dice1, dice2;
    dice1 = rand() % 10 + 1;
    dice2 = rand() % 10 + 1;
    attackRoll = dice1 + dice2;
    return attackRoll;
}

//Blue Men defense roll
int BlueMen::defense()
{
    //3d6
    int dice1, dice2, dice3;
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    dice3 = rand() % 6 + 1;
    //If Blue Men take 4 damage
    if(strengthPoints <= 8 && strengthPoints > 4)
    {
        //2d6
        defenseRoll = dice1 + dice2;
        return defenseRoll;
    }
    //If Blue Men take 8 damage
    else if(strengthPoints <= 4)
    {
        //1d6
        defenseRoll = dice1;
        return defenseRoll;
    }
    else
    {
        defenseRoll = dice1 + dice2 + dice3;
        return defenseRoll;
    }
}
