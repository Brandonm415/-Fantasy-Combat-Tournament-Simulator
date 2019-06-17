/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"
#include <iostream>

//Game class contains menu and controls flow of game
//Also contains team1 struc and functions to edit nodes
class Game
{
    struct team1
    {
        team1 *next;
        Character *hero1;
        team1()
        {
            next = nullptr;
            hero1 = nullptr;
        }
    };

    public:
        Game();
        ~Game();
        void startGame();

    private:
        int menuChoice;
        int menuChoice2;
        int damage;
        int damageDifference;
        int rounds;
        int numOfFighter;
        int team1Score;
        int team2Score;
        int battles;
        std::string nameHolder;
        void addBack(Character *ptr);
        void addBackTeam2(Character *ptr);
        void killHero1();
        void killHero2();
        void recoverHP(team1 *ptr);
        team1 *head;
        team1 *tail;
        team1 *head2;
        team1 *tail2;
        team1 *headLoser;
        team1 *tailLoser;
};

#endif // GAME_HPP
