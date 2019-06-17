/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"

//Vampire class inherits from Character
class Vampire: public Character
{
    public:
        Vampire();
        int attack() override;
        int defense() override;

    protected:

    private:
};

#endif // VAMPIRE_HPP
