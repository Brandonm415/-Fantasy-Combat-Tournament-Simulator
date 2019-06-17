/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"

//Medusa class inherits from Character
class Medusa: public Character
{
    public:
        Medusa();
        int attack() override;
        int defense() override;

    protected:

    private:
};

#endif // MEDUSA_HPP
