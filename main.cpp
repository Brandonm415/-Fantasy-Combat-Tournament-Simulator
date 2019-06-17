/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#include <iostream>
#include "Character.hpp"
#include "Game.hpp"
#include <time.h>


int main()
{
    //Seed for random
    srand(time(0));
    Game fantasy;
    int counter = 0;
    int counter2 = 0;
    int menuChoice;
    //First menu screen
    while(counter < 1)
    {
        std::cout << "Welcome to the Fantasy Combat Game!" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cin >> menuChoice;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
        }
        else
        {
            if(menuChoice == 1)
            {
                counter++;
                fantasy.startGame();
            }
            else if(menuChoice == 2)
            {
                counter++;
            }
            else
            {
                std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
            }
        }
    }
    int answer;
    //Replay or exit loop
    while(counter2 < 1)
    {
        std::cout << "-----------------------" << std::endl;
        std::cout << "1. Play again." << std::endl;
        std::cout << "2. Exit." << std::endl;
        std::cin >> answer;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
        }
        else
        {
            if(answer == 2)
            {
                counter2++;
            }
            else if(answer == 1)
            {
                Game fantasyReplay;
                fantasyReplay.startGame();
            }
            else
            {
                std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
            }
        }
    }
    return 0;
}
