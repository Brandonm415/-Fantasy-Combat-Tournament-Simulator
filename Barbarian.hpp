/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Character.hpp"

//Barbarian class inherits from Character
class Barbarian: public Character
{
    public:
        Barbarian();
        int attack() override;
        int defense() override;

    protected:

    private:
};

#endif // BARBARIAN_HPP
