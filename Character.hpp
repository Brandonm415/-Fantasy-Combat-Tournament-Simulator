/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <stdlib.h>
#include <string>
#include <iostream>

//Base class for all the different character types
class Character
{
    public:
        Character();
        virtual int attack() = 0;
        virtual int defense() = 0;
        int getStrengthPoints();
        void setStrengthPoints(int x);
        std::string getType();
        int getArmor();
        int getAttackRoll();
        int getDefenseRoll();
        void reviveHarry();
        int getRevive();
        void setHeroName(std::string name);
        std::string getHeroName();

    protected:
        int armor;
        int strengthPoints;
        std::string type;
        int attackRoll;
        int defenseRoll;
        std::string characteristics;
        std::string specialAbility;
        bool revive;
        std::string heroName;

    private:
};

#endif // CHARACTER_HPP
