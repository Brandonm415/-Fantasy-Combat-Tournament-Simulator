/***********************************************************
** Program name: Project 4
** Author: Brandon Mai
** Date: 5/22/2019
** Description: A fantasy combat game that uses linked lists
**              to allow user to select teams of hero's to
**              face off against one another.
************************************************************/
#include "Game.hpp"
#include <iostream>

//Constructor
Game::Game()
{
    damage = 0;
    damageDifference = 0;
    rounds = 1;
    menuChoice = 0;
    menuChoice2 = 0;
    team1Score = 0;
    team2Score = 0;
    battles = 1;
    head = nullptr;
    tail = nullptr;
    head2 = nullptr;
    tail2 = nullptr;
    headLoser = nullptr;
    tailLoser = nullptr;
}

//Destructor
Game::~Game()
{
    if(head != nullptr)
    {
        //Adapted from textbook chapter 17.2
        team1 *temp = head;
        team1 *tempGarbage = temp;
        temp = temp->next;
        delete tempGarbage;
        //If only one node left
        if(temp != nullptr)
        {
            while(temp != tail)
            {
                team1 *garbage = temp;
                temp = temp->next;
                delete garbage;
            }
        }
        head = nullptr;
        tail = nullptr;
    }
    if(head2 != nullptr)
    {
        team1 *temp = head2;
        team1 *tempGarbage = temp;
        temp = temp->next;
        delete tempGarbage;
        if(temp != nullptr)
        {
            while(temp != tail2)
            {
                team1 *garbage = temp;
                temp = temp->next;
                delete garbage;
            }
        }
        head2 = nullptr;
        tail2 = nullptr;
    }
    if(headLoser != nullptr)
    {
        team1 *temp = headLoser;
        team1 *tempGarbage = temp;
        temp = temp->next;
        delete tempGarbage;
        if(temp != nullptr)
        {
            while(temp != tailLoser)
            {
                team1 *garbage = temp;
                temp = temp->next;
                delete garbage;
            }
        }
        headLoser = nullptr;
        tailLoser = nullptr;
    }
}

//Function to add hero to team1
void Game::addBack(Character *ptr)
{
    team1 *newNode = new team1;
    //If team is empty
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        head->hero1 = ptr;
    }
    //If team is not empty
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->hero1 = ptr;
    }
}

//Function to add hero to team2
void Game::addBackTeam2(Character *ptr)
{
    team1 *newNode = new team1;
    //If team is empty
    if(head2 == nullptr)
    {
        head2 = newNode;
        tail2 = newNode;
        head2->hero1 = ptr;
    }
    //If team is not empty
    else
    {
        tail2->next = newNode;
        tail2 = newNode;
        tail2->hero1 = ptr;
    }
}

//Function to move hero from team1 to loser pile
void Game::killHero1()
{
    //If only one node left
    if(head->next == nullptr)
    {
        //If nothing in loser container yet
        if(headLoser == nullptr)
        {
            headLoser = head;
            tailLoser = headLoser;
            head->next = nullptr;
            head = nullptr;
            tail = nullptr;
        }
        //If something already in loser container
        else
        {
            tailLoser->next = head;
            tailLoser = tailLoser->next;
            head->next = nullptr;
            head = nullptr;
            tail = nullptr;
        }
    }
    //If multiple hero's left alive
    else
    {
        //If nothing in loser container yet
        if(headLoser == nullptr)
        {
            headLoser = head;
            tailLoser = headLoser;
            head = head->next;
            headLoser->next = nullptr;
        }
        //If something already in loser container
        else
        {
            tailLoser->next = head;
            tailLoser = tailLoser->next;
            head = head->next;
            tailLoser->next = nullptr;
        }
    }
}

//Function to move hero of team2 to loser pile
void Game::killHero2()
{
    //If only one node left
    if(head2->next == nullptr)
    {
        //If nothing in loser container yet
        if(headLoser == nullptr)
        {
            headLoser = head2;
            tailLoser = headLoser;
            head2->next = nullptr;
            head2 = nullptr;
            tail2 = nullptr;
        }
        //If something already in loser container
        else
        {
            tailLoser->next = head2;
            tailLoser = tailLoser->next;
            head2->next = nullptr;
            head2 = nullptr;
            tail2 = nullptr;
        }
    }
    //If multiple hero's left alive
    else
    {
        //If nothing in loser container yet
        if(headLoser == nullptr)
        {
            headLoser = head2;
            tailLoser = headLoser;
            head2 = head2->next;
            headLoser->next = nullptr;
        }
        //If something already in loser container
        else
        {
            tailLoser->next = head2;
            tailLoser = tailLoser->next;
            head2 = head2->next;
            tailLoser->next = nullptr;
        }
    }

}

//Recover strength points for hero after fights
void Game::recoverHP(team1 *ptr)
{
    int currentHP;
    int recovery;
    currentHP = ptr->hero1->getStrengthPoints();
    //Random number from 1-10 to recover strength points for hero
    recovery = rand() % 10 + 1;
    std::cout << ptr->hero1->getHeroName() << " recovers " << recovery << " strength points after the fight!" << std::endl;
    currentHP += recovery;
    ptr->hero1->setStrengthPoints(currentHP);
}

//Start game function
//Contains menu and flow of game logic
void Game::startGame()
{
    //Menu
    //Barbarian = 1
    //Vampire = 2
    //Medusa = 3
    //Harry Potter = 4
    //Blue men = 5
    int counter = 0;
    //Display Menu and Input Validation
    while(counter < 1)
    {
        std::cout << "Please enter number of fighters for both teams, between 1 - 50." << std::endl;
        std::cin >> numOfFighter;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid number. Please enter a valid number." << std::endl;
        }
        else
        {
            if(numOfFighter >= 1 && numOfFighter <= 50)
            {
                int holder = 0;
                //Team 1 loop
                while(holder < numOfFighter)
                {
                    std::cout << "Please choose your character for team 1!" << std::endl;
                    std::cout << "------------------------------------" << std::endl;
                    std::cout << "1. Barbarian" << std::endl;
                    std::cout << "2. Vampire" << std::endl;
                    std::cout << "3. Medusa" << std::endl;
                    std::cout << "4. Harry Potter" << std::endl;
                    std::cout << "5. Blue Men" << std::endl;
                    std::cin >> menuChoice;
                    if(std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
                    }
                    //If user makes valid choice
                    else
                    {
                        //Add hero to team
                        if(menuChoice >= 1 && menuChoice <= 5)
                        {
                            //If barbarian
                            if(menuChoice == 1)
                            {
                                Character *temp = new Barbarian;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBack(temp);
                                holder++;
                            }
                            else if(menuChoice == 2)
                            {
                                Character *temp = new Vampire;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBack(temp);
                                holder++;
                            }
                            else if(menuChoice == 3)
                            {
                                Character *temp = new Medusa;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBack(temp);
                                holder++;
                            }
                            else if(menuChoice == 4)
                            {
                                Character *temp = new HarryPotter;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBack(temp);
                                holder++;
                            }
                            else if(menuChoice == 5)
                            {
                                Character *temp = new BlueMen;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBack(temp);
                                holder++;
                            }
                        }
                        else
                        {
                            std::cout << "That is not a valid choice." << std::endl;
                        }
                    }
                }
                //Team 2 loop
                holder = 0;
                while(holder < numOfFighter)
                {
                    std::cout << "Please choose your character for team 2!" << std::endl;
                    std::cout << "------------------------------------" << std::endl;
                    std::cout << "1. Barbarian" << std::endl;
                    std::cout << "2. Vampire" << std::endl;
                    std::cout << "3. Medusa" << std::endl;
                    std::cout << "4. Harry Potter" << std::endl;
                    std::cout << "5. Blue Men" << std::endl;
                    std::cin >> menuChoice2;
                    if(std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
                    }
                    else
                    {
                        //Add hero to team
                        if(menuChoice2 >= 1 && menuChoice2 <= 5)
                        {
                            //If barbarian
                            if(menuChoice2 == 1)
                            {
                                Character *temp = new Barbarian;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBackTeam2(temp);
                                holder++;
                            }
                            else if(menuChoice2 == 2)
                            {
                                Character *temp = new Vampire;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBackTeam2(temp);
                                holder++;
                            }
                            else if(menuChoice2 == 3)
                            {
                                Character *temp = new Medusa;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBackTeam2(temp);
                                holder++;
                            }
                            else if(menuChoice2 == 4)
                            {
                                Character *temp = new HarryPotter;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBackTeam2(temp);
                                holder++;
                            }
                            else if(menuChoice2 == 5)
                            {
                                Character *temp = new BlueMen;
                                std::cout << "Please enter your hero's name!" << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, nameHolder);
                                temp->setHeroName(nameHolder);
                                addBackTeam2(temp);
                                holder++;
                            }
                        }
                    }
                }
                //Fight until one team is all dead
                int dead = 0;
                while(dead < 1)
                {
                    //Fight starts
                    int fightCounter = 0;
                    team1 *ptr = head;
                    team1 *ptr2 = head2;
                    while(fightCounter < 1)
                    {
                        ptr->hero1->attack();
                        ptr2->hero1->defense();
                        damage = (ptr->hero1->getAttackRoll() - ptr2->hero1->getDefenseRoll()) - ptr2->hero1->getArmor();
                        //If damage is negative set floor to 0
                        if(damage <= 0)
                        {
                            damage = 0;
                        }
                        //Calculate damage done to target's armor and defense roll
                        damageDifference = ptr2->hero1->getStrengthPoints() - damage;
                        //Set targets new hp after calculating damage taken
                        ptr2->hero1->setStrengthPoints(damageDifference);
                        //If a fighter dies end the loop
                        if(ptr2->hero1->getStrengthPoints() <= 0)
                        {
                            //If Harry Potter revive is active
                            if(ptr2->hero1->getRevive() == true)
                            {
                                //Revive Harry
                                ptr2->hero1->reviveHarry();
                                //Character 2 attacks character 1 after Harry Potter revives
                                //Fixes issue with code looping back to beginning if Harry Potter revives after being attacked as fighter2 and gets attacked twice by fighter1
                                ptr2->hero1->attack();
                                ptr->hero1->defense();
                                damage = (ptr2->hero1->getAttackRoll() - ptr->hero1->getDefenseRoll()) - ptr->hero1->getArmor();
                                if(damage <= 0)
                                {
                                    damage = 0;
                                }
                                damageDifference = ptr->hero1->getStrengthPoints() - damage;
                                ptr->hero1->setStrengthPoints(damageDifference);
                                //If a fighter dies end the loop
                                if(ptr->hero1->getStrengthPoints() <= 0)
                                {
                                    fightCounter++;
                                }
                            }
                            //If no revive loop ends
                            else
                            {
                                fightCounter++;
                            }
                        }
                        //Next round
                        else
                        {
                            //Character 2 attacks character 1
                            ptr2->hero1->attack();
                            ptr->hero1->defense();
                            damage = (ptr2->hero1->getAttackRoll() - ptr->hero1->getDefenseRoll()) - ptr->hero1->getArmor();
                            if(damage <= 0)
                            {
                                damage = 0;
                            }
                            damageDifference = ptr->hero1->getStrengthPoints() - damage;
                            ptr->hero1->setStrengthPoints(damageDifference);
                            //If a fighter dies end the loop
                            if(ptr->hero1->getStrengthPoints() <= 0)
                            {
                                //If Harry has revive
                                if(ptr->hero1->getRevive() == true)
                                {
                                    //Revive harry and then loop back to beginning
                                    ptr->hero1->reviveHarry();
                                }
                                else
                                {
                                    //End loop
                                    fightCounter++;
                                }
                            }
                        }
                    }
                    //Decide who is the winner and print out result
                    //team 2 wins battle
                    if(ptr->hero1->getStrengthPoints() <= 0)
                    {
                        std::cout << "******" <<"Battle: " << battles << "******" << std::endl;
                        std::cout << "-------------------------------------------------------------------------" << std::endl;
                        std::cout << "Team 1: " << head->hero1->getHeroName() << "(" << head->hero1->getType() << ") " << "vs " << "Team 2: " << head2->hero1->getHeroName() << "(" << head2->hero1->getType() << ")" << std::endl;
                        std::cout << ptr2->hero1->getHeroName() << " wins the fight!" << std::endl;
                        //Recover strength points
                        recoverHP(ptr2);
                        std::cout << " " << std::endl;
                        //Move to loser pile
                        killHero1();
                        //Add to score
                        team2Score++;
                        battles++;
                    }
                    //team 1 wins battle
                    else if(ptr2->hero1->getStrengthPoints() <= 0)
                    {
                        std::cout << "******" <<"Battle: " << battles << "******" << std::endl;
                        std::cout << "-------------------------------------------------------------------------" << std::endl;
                        std::cout << "Team 1: " << head->hero1->getHeroName() << "(" << head->hero1->getType() << ") " << "vs " << "Team 2: " << head2->hero1->getHeroName() << "(" << head2->hero1->getType() << ")" << std::endl;
                        std::cout << ptr->hero1->getHeroName() << " wins the fight!" << std::endl;
                        //Recover strength points
                        recoverHP(ptr);
                        std::cout << " " << std::endl;
                        //Add to loser pile
                        killHero2();
                        //Add to score
                        team1Score++;
                        battles++;
                    }

                    //If team1 is dead end loop
                    if(head == nullptr)
                    {
                        dead++;
                    }
                    //If team2 is dead end loop
                    if(head2 == nullptr)
                    {
                        dead++;
                    }
                }
                //Display results and winners
                if(team1Score > team2Score)
                {
                    std::cout << "-------------------------------------------------------------------------" << std::endl;
                    std::cout << "The tournament is over!" << std::endl;
                    std::cout << "Team 1 score: " << team1Score << std::endl;
                    std::cout << "Team 2 score: " << team2Score << std::endl;
                    std::cout << "Team 1 wins!" << std::endl;
                }
                else
                {
                    std::cout << "-------------------------------------------------------------------------" << std::endl;
                    std::cout << "The tournament is over!" << std::endl;
                    std::cout << "Team 1 score: " << team1Score << std::endl;
                    std::cout << "Team 2 score: " << team2Score << std::endl;
                    std::cout << "Team 2 wins!" << std::endl;
                }
                int fallenAnswer;
                int fallenLoop = 0;
                while(fallenLoop < 1)
                {
                    std::cout << "-------------------------------------------------------------------------" << std::endl;
                    std::cout << "Display fallen heroes?" << std::endl;
                    std::cout << "1. Yes" << std::endl;
                    std::cout << "2. No" << std::endl;
                    std::cin >> fallenAnswer;
                    if(std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore();
                        std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
                    }
                    else
                    {
                        //Print out loser pile
                        if(fallenAnswer == 1)
                        {
                            team1 *temp = headLoser;
                            //If loser pile is not empty
                            if(temp != nullptr)
                            {
                                std::cout << "Fallen Hero's List" << std::endl;
                                std::cout << "-----------------------" << std::endl;
                                int deadHeros = 0;
                                //Loop through loser pile
                                while(deadHeros < 1)
                                {
                                    std::cout << temp->hero1->getHeroName() << " Class: " << temp->hero1->getType() << std::endl;
                                    temp = temp->next;
                                    //Reach end of loser pile end loop
                                    if(temp == nullptr)
                                    {
                                        deadHeros++;
                                        fallenLoop++;
                                        counter++;
                                    }
                                }
                            }
                        }
                        //Exit
                        else if(fallenAnswer == 2)
                        {
                            std::cout << "Game Over!" << std::endl;
                            fallenLoop++;
                            counter++;
                        }
                        else
                        {
                            std::cout << "That is not a valid option. Please choose a valid option." << std::endl;
                        }
                    }
                }
            }
        }
    }
}





