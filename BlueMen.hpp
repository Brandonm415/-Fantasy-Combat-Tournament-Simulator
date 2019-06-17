/***********************************************************
 ** Program name: Project 4
 ** Author: Brandon Mai
 ** Date: 5/22/2019
 ** Description: A fantasy combat game that uses linked lists
 **              to allow user to select teams of hero's to
 **              face off against one another.
 ************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"

//Blue Men class inherits from Character
class BlueMen: public Character
{
    public:
        BlueMen();
        int attack() override;
        int defense() override;

    protected:

    private:
};

#endif // BLUEMEN_HPP
