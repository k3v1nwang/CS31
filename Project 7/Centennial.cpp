//
//  Centennial.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Centennial.h"
#include"Player.h"
#include"Die.h"
#include"Board.h"
#include <iostream>
#include <string>

namespace cs31
{
    // human goes first
    Centennial::Centennial() : isHumanTurn(true)
    {

    }

    // prints the state of the game play with each round of play
    std::string Centennial::display(std::string msg)
    {
        using namespace std;
        std::string s("");
        if (isHumanTurn)
        {
            s += "Human-";
            s += mHuman.whatWasRolled();
        }
        else
        {
            s += "Computer-";
            s += mComputer.whatWasRolled();
        }
        s += mBoard.display();

        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Centennial!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Centennial!\n";
            }
        }
        else
        {
            s = s + msg;
        }
        return(s);
    }

    // CS 31 TODO: randomly play a human turn in the game
    void Centennial::humanPlay()
    {
        // mark that it is the human's turn
        // let the human player randomly roll
        // look at what was rolled and update the board spots accordingly
        isHumanTurn = true;
        while (isHumanTurn)
        {
            Player human = getHuman();
            Die d1;
            Die d2;
            Die d3;
            d1.roll();
            d2.roll();
            d3.roll();
            human.roll(d1, d2, d3);
            //acquire dice values to int
            int die1 = d1.getValue();
            int die2 = d2.getValue();
            int die3 = d3.getValue();
            //other possibsle outcomes
            int c1 = die1 + die2;
            int c2 = die1 + die3;
            int c3 = die2 + die3;
            int c4 = die1 + die2 + die3;
            //create array of 7 for the possible outcomes 
            //create a pointer variable that would assign values to the array supplied by dice rolls
            int array[7];
            int* ptr;
            ptr = array;

            *ptr = die1;
            *(ptr + 1) = die2;
            *(ptr + 2) = die3;
            *(ptr + 3) = c1;
            *(ptr + 4) = c2;
            *(ptr + 5) = c3;
            *(ptr + 6) = c4;


            //start maniplation of player values
            int target;
            Board board = getBoard();
            //will loop through 36 times (6 x6) and look for possible matches of what spot is needed next and the rolled outcome
            for (int k = 0; k < 7; k++)
            {
                for (int i = 0; i < 7; i++)
                {
                    target = human.whatSpotIsNeededNext();
                    if (target == *(ptr + i))
                    {
                        human.rolled(target);
                        board.setHumanSpot(target);
                    }
                }
            }
            //set the memeber functions to the variables created and manipulated within the turn
            mBoard = board;
            mHuman = human;
            isHumanTurn = false;    //set the humnan turn to false so computer can play
        }

   
    }

    // CS 31 TODO: force a certain roll in the human's turn of the game by cheating...
    void Centennial::humanPlay(Die d1, Die d2, Die d3)
    {
        // mark that it is the human's turn
        // force the human player to cheat
        // look at what was rolled and update the board spots accordingly
        isHumanTurn = true;
        //create human variable and supply it with the die values that were used to cheat
        Player human = getHuman();
        human.roll(d1, d2, d3);
        int die1 = d1.getValue();
        int die2 = d2.getValue();
        int die3 = d3.getValue();
        //other combinations of outcomes
        int c1 = die1 + die2;
        int c2 = die1 + die3;
        int c3 = die2 + die3;
        int c4 = die1 + die2 + die3;

        int array[7];
        int* ptr;
        ptr = array;

        *ptr = die1;
        *(ptr + 1) = die2;
        *(ptr + 2) = die3;
        *(ptr + 3) = c1;
        *(ptr + 4) = c2;
        *(ptr + 5) = c3;
        *(ptr + 6) = c4;


        int target;
        Board board = getBoard();
        //find if spot needed next and rolled values match, update board accordinng to each match
        for (int k = 0; k < 7; k++)
        {
            for (int i = 0; i < 7; i++)
            {
                target = human.whatSpotIsNeededNext();
                if (target == *(ptr + i))
                {
                    human.rolled(target);
                    board.setHumanSpot(target);
                }
            }
        }
        //return the maninplated variables to update the member data of the game
        mBoard = board;
        mHuman = human;


        
    }

    // CS 31 TODO: randomly play a computer turn in the game
    void Centennial::computerPlay()
    {
        // mark that it is no longer the human's turn
        // let the computer player randomly roll
        // look at what was rolled and update the board spots accordingly
        isHumanTurn = false;
        while (isHumanTurn == false)
        {
            Player computer = getComputer();
            //randolly roll die values for the computer
            Die d1;
            Die d2;
            Die d3;
            d1.roll();
            d2.roll();
            d3.roll();
            computer.roll(d1, d2, d3);
            int die1 = d1.getValue();
            int die2 = d2.getValue();
            int die3 = d3.getValue();
            //other combinations of rolls
            int c1 = die1 + die2;
            int c2 = die1 + die3;
            int c3 = die2 + die3;
            int c4 = die1 + die2 + die3;
            //create an array with the possible outcomes
            int array[7];
            int* ptr;
            ptr = array;

            *ptr = die1;
            *(ptr + 1) = die2;
            *(ptr + 2) = die3;
            *(ptr + 3) = c1;
            *(ptr + 4) = c2;
            *(ptr + 5) = c3;
            *(ptr + 6) = c4;


            int target;
            Board board = getBoard();
            //find values that match the outcome and update the spots accordingly 
            for (int k = 0; k < 7; k++)
            {
                for (int i = 0; i < 7; i++)
                {
                    target = computer.whatSpotIsNeededNext();
                    if (target == *(ptr + i))
                    {
                        computer.rolled(target);
                        board.setComputerSpot(target);
                    }
                }
            }
            //return the values that were manipulated to the member values 
            mBoard = board;
            mComputer = computer;
            isHumanTurn = true;
        }
    }

    // CS 31 TODO: force a certain roll in the computer's turn of the game by cheating...
    void Centennial::computerPlay(Die d1, Die d2, Die d3)
    {
        // mark that it is no longer the human's turn
        // force the computer player to cheat
        // look at what was rolled and update the board spots accordingly
        isHumanTurn = false;
        Player computer = getComputer();
       //set die values to the supplied values used to cheat
        int die1 = d1.getValue();
        int die2 = d2.getValue();
        int die3 = d3.getValue();
        //other combinations
        int c1 = die1 + die2;
        int c2 = die1 + die3;
        int c3 = die2 + die3;
        int c4 = die1 + die2 + die3;
        //creates array with possible outcomes
        int array[7];
        int* ptr;
        ptr = array;

        *ptr = die1;
        *(ptr + 1) = die2;
        *(ptr + 2) = die3;
        *(ptr + 3) = c1;
        *(ptr + 4) = c2;
        *(ptr + 5) = c3;
        *(ptr + 6) = c4;

        //find spots that match what is needed next and is what is rolled
        //update board and member values
        int target;
        Board board = getBoard();

        for (int k = 0; k < 7; k++)
        {
            for (int i = 0; i < 7; i++)
            {
                target = computer.whatSpotIsNeededNext();
                if (target == *(ptr + i))
                {
                    computer.rolled(target);
                    board.setComputerSpot(target);
                }
            }
        }
        //return manipulated variables to member values
        mBoard = board;
        mComputer = computer;
    }

    // CS 31 TODO: determine the current state of the game
    // Officially, the human won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // Officially, the computer won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // If neither, then the game is still underway
    Centennial::GAMEOUTCOME  Centennial::determineGameOutcome() const
    {
        // for now, just to get it to build...
        GAMEOUTCOME result = GAMENOTOVER;

        Player player = getHuman();
        Player computer = getComputer();

        if (player.hasRolledTwelve())
            result = HUMANWONGAME;
        if (computer.hasRolledTwelve())
            result = COMPUTERWONGAME;
        
        return(result);
    }

    // CS 31 TODO: determine if the game has ended
    // HINT: call determineGameOutcome( )
    bool Centennial::isGameOver()
    {
        // for now, just to get it to build...
        bool result = false;
        if (determineGameOutcome() == GAMENOTOVER)
            result = false;
        else
            result = true;

        return(result);
    }

    // trivial getter operation
    Player Centennial::getHuman() const
    {
        return(mHuman);
    }

    // trivial getter operation
    Player Centennial::getComputer() const
    {
        return(mComputer);
    }

    // trivial getter operation
    Board  Centennial::getBoard() const
    {
        return(mBoard);
    }
}
