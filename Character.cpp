/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#include "Character.hpp"

//Constructor
Character::Character()
{
    //Sets revive status for all characters to false
    revive = false;
}

//Set strength points function
void Character::setStrengthPoints(int x)
{
    strengthPoints = x;
}

//Get strength points function
int Character::getStrengthPoints()
{
    return strengthPoints;
}

//Get type function
std::string Character::getType()
{
    return type;
}

//Get armor function
int Character::getArmor()
{
    return armor;
}

//Get attack roll function
int Character::getAttackRoll()
{
    return attackRoll;
}

//Get defense roll function
int Character::getDefenseRoll()
{
    return defenseRoll;
}

//Function to revive Harry Potter
void Character::reviveHarry()
{
    strengthPoints = 20;
    //Set revive to false, only can revive once
    revive = false;
}

//Get revive status
int Character::getRevive()
{
    return revive;
}

//Set hero name
void Character::setHeroName(std::string name)
{
    heroName = name;
}

//Get hero name
std::string Character::getHeroName()
{
    return heroName;
}





