/***********************************************************
 ** Program name: Project 4
 ** Author: Brandon Mai
 ** Date: 5/22/2019
 ** Description: A fantasy combat game that uses linked lists
 **              to allow user to select teams of hero's to
 **              face off against one another.
 ************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Character.hpp"

class HarryPotter: public Character
{
    public:
        HarryPotter();
        int attack() override;
        int defense() override;

    protected:

    private:
};

#endif // HARRYPOTTER_HPP
