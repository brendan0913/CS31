//
//  Centennial.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Centennial.h"
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

    // randomly plays a human turn in the game
    void Centennial::humanPlay()
    {
        isHumanTurn = true; // marks that it is the human's turn
        mHuman.roll(); // lets the human player randomly roll
        int first = mHuman.getDie1().getValue();
        int second = mHuman.getDie2().getValue();
        int third = mHuman.getDie3().getValue();
        mHuman.whatWasRolled();
        int firsttwo = first + second;
        int lasttwo = second + third;
        int firstandthird = first + third;
        int total = first + second + third;
        if ((first == 1 || second == 1 || third == 1) && mHuman.whatSpotIsNeededNext() == 1)
        {
            mHuman.rolled(1);
            mBoard.setHumanSpot(1); // looks at what was rolled and update the board spots accordingly
        }
        if ((first == 2 || second == 2 || third == 2 || firsttwo == 2 || lasttwo == 2 || firstandthird == 2) && mHuman.hasRolledOne() == true && mHuman.whatSpotIsNeededNext() == 2)
        {
            mHuman.rolled(2); // different combinations of rolls, the past roll has to be true and the spot needed has to be the same as what is rolled to not go backwards
            mBoard.setHumanSpot(2);
        }
        if ((first == 3 || second == 3 || third == 3 || firsttwo == 3 || lasttwo == 3 || firstandthird == 3 || total == 3) && mHuman.hasRolledTwo() == true && mHuman.whatSpotIsNeededNext() == 3)
        {
            mHuman.rolled(3);
            mBoard.setHumanSpot(3);
        }       
        if ((first == 4 || second == 4 || third == 4 || firsttwo == 4 || lasttwo == 4 || firstandthird == 4 || total == 4) && mHuman.hasRolledThree() == true && mHuman.whatSpotIsNeededNext() == 4)
        {
            mHuman.rolled(4);
            mBoard.setHumanSpot(4);
        }      
        if ((first == 5 || second == 5 || third == 5 || firsttwo == 5 || lasttwo == 5 || firstandthird == 5 || total == 5) && mHuman.hasRolledFour() == true && mHuman.whatSpotIsNeededNext() == 5)
        {
            mHuman.rolled(5);
            mBoard.setHumanSpot(5);
        }     
        if ((first == 6 || second == 6 || third == 6 || firsttwo == 6 || lasttwo == 6 || firstandthird == 6 || total == 6) && mHuman.hasRolledFive() == true && mHuman.whatSpotIsNeededNext() == 6)
        {
            mHuman.rolled(6);
            mBoard.setHumanSpot(6);
        }      
        if ((firsttwo == 7 || lasttwo == 7 || firstandthird == 7 || total == 7) && mHuman.hasRolledSix() == true && mHuman.whatSpotIsNeededNext() == 7)
        {
            mHuman.rolled(7); // for 7-12, a single die cannot get the value alone
            mBoard.setHumanSpot(7);
        }      
        if ((firsttwo == 8 || lasttwo == 8 || firstandthird == 8 || total == 8) && mHuman.hasRolledSeven() == true && mHuman.whatSpotIsNeededNext() == 8)
        {
            mHuman.rolled(8);
            mBoard.setHumanSpot(8);
        }      
        if ((firsttwo == 9 || lasttwo == 9 || firstandthird == 9 || total == 9) && mHuman.hasRolledEight() == true && mHuman.whatSpotIsNeededNext() == 9)
        {
            mHuman.rolled(9);
            mBoard.setHumanSpot(9);
        }   
        if ((firsttwo == 10 || lasttwo == 10 || firstandthird == 10 || total == 10) && mHuman.hasRolledNine() == true && mHuman.whatSpotIsNeededNext() == 10)
        {
            mHuman.rolled(10);
            mBoard.setHumanSpot(10);
        }      
        if ((firsttwo == 11 || lasttwo == 11 || firstandthird == 11 || total == 11) && mHuman.hasRolledTen() == true && mHuman.whatSpotIsNeededNext() == 11)
        {
            mHuman.rolled(11);
            mBoard.setHumanSpot(11);
        }
        if ((firsttwo == 12 || lasttwo == 12 || firstandthird == 12 || total == 12) && mHuman.hasRolledEleven() == true && mHuman.whatSpotIsNeededNext() == 12)
        {
            mHuman.rolled(12);
            mBoard.setHumanSpot(12);
            mBoard.setGameOver(true);
            mBoard.markHumanAsWinner();
        }
    }

    // forces a certain roll in the human's turn of the game by cheating...
    void Centennial::humanPlay(Die d1, Die d2, Die d3)
    {
        isHumanTurn = true; // marks that it is the human's turn
        int first = d1.getValue(); // forces the human player to cheat
        int second = d2.getValue();
        int third = d3.getValue();
        int firsttwo = first + second;
        int lasttwo = second + third;
        int firstandthird = first + third;
        int total = first + second + third;
        if ((first == 1 || second == 1 || third == 1) && mHuman.whatSpotIsNeededNext() == 1)
        {
            mHuman.rolled(1);
            mBoard.setHumanSpot(1); // looks at what was rolled and update the board spots accordingly
        }
        if ((first == 2 || second == 2 || third == 2 || firsttwo == 2 || lasttwo == 2 || firstandthird == 2) && mHuman.hasRolledOne() == true && mHuman.whatSpotIsNeededNext() == 2)
        {
            mHuman.rolled(2); // different combinations of rolls, the past roll has to be true and the spot needed has to be the same as what is rolled to not go backwards
            mBoard.setHumanSpot(2);
        }
        if ((first == 3 || second == 3 || third == 3 || firsttwo == 3 || lasttwo == 3 || firstandthird == 3 || total == 3) && mHuman.hasRolledTwo() == true && mHuman.whatSpotIsNeededNext() == 3)
        {
            mHuman.rolled(3);
            mBoard.setHumanSpot(3);
        }
        if ((first == 4 || second == 4 || third == 4 || firsttwo == 4 || lasttwo == 4 || firstandthird == 4 || total == 4) && mHuman.hasRolledThree() == true && mHuman.whatSpotIsNeededNext() == 4)
        {
            mHuman.rolled(4);
            mBoard.setHumanSpot(4);
        }
        if ((first == 5 || second == 5 || third == 5 || firsttwo == 5 || lasttwo == 5 || firstandthird == 5 || total == 5) && mHuman.hasRolledFour() == true && mHuman.whatSpotIsNeededNext() == 5)
        {
            mHuman.rolled(5);
            mBoard.setHumanSpot(5);
        }
        if ((first == 6 || second == 6 || third == 6 || firsttwo == 6 || lasttwo == 6 || firstandthird == 6 || total == 6) && mHuman.hasRolledFive() == true && mHuman.whatSpotIsNeededNext() == 6)
        {
            mHuman.rolled(6);
            mBoard.setHumanSpot(6);
        }
        if ((firsttwo == 7 || lasttwo == 7 || firstandthird == 7 || total == 7) && mHuman.hasRolledSix() == true && mHuman.whatSpotIsNeededNext() == 7)
        {
            mHuman.rolled(7); // for 7-12, a single die cannot get the value alone
            mBoard.setHumanSpot(7);
        }
        if ((firsttwo == 8 || lasttwo == 8 || firstandthird == 8 || total == 8) && mHuman.hasRolledSeven() == true && mHuman.whatSpotIsNeededNext() == 8)
        {
            mHuman.rolled(8);
            mBoard.setHumanSpot(8);
        }
        if ((firsttwo == 9 || lasttwo == 9 || firstandthird == 9 || total == 9) && mHuman.hasRolledEight() == true && mHuman.whatSpotIsNeededNext() == 9)
        {
            mHuman.rolled(9);
            mBoard.setHumanSpot(9);
        }
        if ((firsttwo == 10 || lasttwo == 10 || firstandthird == 10 || total == 10) && mHuman.hasRolledNine() == true && mHuman.whatSpotIsNeededNext() == 10)
        {
            mHuman.rolled(10);
            mBoard.setHumanSpot(10);
        }
        if ((firsttwo == 11 || lasttwo == 11 || firstandthird == 11 || total == 11) && mHuman.hasRolledTen() == true && mHuman.whatSpotIsNeededNext() == 11)
        {
            mHuman.rolled(11);
            mBoard.setHumanSpot(11);
        }
        if ((firsttwo == 12 || lasttwo == 12 || firstandthird == 12 || total == 12) && mHuman.hasRolledEleven() == true && mHuman.whatSpotIsNeededNext() == 12)
        {
            mHuman.rolled(12);
            mBoard.setHumanSpot(12);
            mBoard.setGameOver(true);
            mBoard.markHumanAsWinner();
        }
    }   

    // randomly plays a computer turn in the game
    void Centennial::computerPlay()
    {
        isHumanTurn = false; // marks that it is no longer the human's turn
        mComputer.roll();// lets the computer player randomly roll
        int first = mComputer.getDie1().getValue();
        int second = mComputer.getDie2().getValue();
        int third = mComputer.getDie3().getValue();
        int firsttwo = first + second;
        int lasttwo = second + third;
        int firstandthird = first + third;
        int total = first + second + third;
        if ((first == 1 || second == 1 || third == 1) && mComputer.whatSpotIsNeededNext() == 1)
        {
            mComputer.rolled(1);
            mBoard.setComputerSpot(1); // looks at what was rolled and update the board spots accordingly
        }
        if ((first == 2 || second == 2 || third == 2 || firsttwo == 2 || lasttwo == 2 || firstandthird == 2) && mComputer.hasRolledOne() == true && mComputer.whatSpotIsNeededNext() == 2)
        {
            mComputer.rolled(2); // different combinations of rolls, the past roll has to be true and the spot needed has to be the same as what is rolled to not go backwards
            mBoard.setComputerSpot(2);
        }
        if ((first == 3 || second == 3 || third == 3 || firsttwo == 3 || lasttwo == 3 || firstandthird == 3 || total == 3) && mComputer.hasRolledTwo() == true && mComputer.whatSpotIsNeededNext() == 3)
        {
            mComputer.rolled(3);
            mBoard.setComputerSpot(3);
        }
        if ((first == 4 || second == 4 || third == 4 || firsttwo == 4 || lasttwo == 4 || firstandthird == 4 || total == 4) && mComputer.hasRolledThree() == true && mComputer.whatSpotIsNeededNext() == 4)
        {
            mComputer.rolled(4);
            mBoard.setComputerSpot(4);
        }
        if ((first == 5 || second == 5 || third == 5 || firsttwo == 5 || lasttwo == 5 || firstandthird == 5 || total == 5) && mComputer.hasRolledFour() == true && mComputer.whatSpotIsNeededNext() == 5)
        {
            mComputer.rolled(5);
            mBoard.setComputerSpot(5);
        }
        if ((first == 6 || second == 6 || third == 6 || firsttwo == 6 || lasttwo == 6 || firstandthird == 6 || total == 6) && mComputer.hasRolledFive() == true && mComputer.whatSpotIsNeededNext() == 6)
        {
            mComputer.rolled(6);
            mBoard.setComputerSpot(6);
        }
        if ((firsttwo == 7 || lasttwo == 7 || firstandthird == 7 || total == 7) && mComputer.hasRolledSix() == true && mComputer.whatSpotIsNeededNext() == 7)
        {
            mComputer.rolled(7); // for 7-12, a single die cannot get the value alone
            mBoard.setComputerSpot(7);
        }
        if ((firsttwo == 8 || lasttwo == 8 || firstandthird == 8 || total == 8) && mComputer.hasRolledSeven() == true && mComputer.whatSpotIsNeededNext() == 8)
        {
            mComputer.rolled(8);
            mBoard.setComputerSpot(8);
        }
        if ((firsttwo == 9 || lasttwo == 9 || firstandthird == 9 || total == 9) && mComputer.hasRolledEight() == true && mComputer.whatSpotIsNeededNext() == 9)
        {
            mComputer.rolled(9);
            mBoard.setComputerSpot(9);
        }
        if ((firsttwo == 10 || lasttwo == 10 || firstandthird == 10 || total == 10) && mComputer.hasRolledNine() == true && mComputer.whatSpotIsNeededNext() == 10)
        {
            mComputer.rolled(10);
            mBoard.setComputerSpot(10);
        }
        if ((firsttwo == 11 || lasttwo == 11 || firstandthird == 11 || total == 11) && mComputer.hasRolledTen() == true && mComputer.whatSpotIsNeededNext() == 11)
        {
            mComputer.rolled(11);
            mBoard.setComputerSpot(11);
        }
        if ((firsttwo == 12 || lasttwo == 12 || firstandthird == 12 || total == 12) && mComputer.hasRolledEleven() == true && mComputer.whatSpotIsNeededNext() == 12)
        {
            mComputer.rolled(12);
            mBoard.setComputerSpot(12);
            mBoard.setGameOver(true);
            mBoard.markComputerAsWinner();
        }
    }

    // forces a certain roll in the computer's turn of the game by cheating...
    void Centennial::computerPlay(Die d1, Die d2, Die d3)
    {
        isHumanTurn = false; // marks that it is no longer the human's turn
        int first = d1.getValue(); // forces the computer player to cheat
        int second = d2.getValue();
        int third = d3.getValue();
        int firsttwo = first + second;
        int lasttwo = second + third;
        int firstandthird = first + third;
        int total = first + second + third;
        if ((first == 1 || second == 1 || third == 1) && mComputer.whatSpotIsNeededNext() == 1)
        {
            mComputer.rolled(1);
            mBoard.setComputerSpot(1); // looks at what was rolled and update the board spots accordingly
        }
        if ((first == 2 || second == 2 || third == 2 || firsttwo == 2 || lasttwo == 2 || firstandthird == 2) && mComputer.hasRolledOne() == true && mComputer.whatSpotIsNeededNext() == 2)
        {
            mComputer.rolled(2); // different combinations of rolls, the past roll has to be true and the spot needed has to be the same as what is rolled to not go backwards
            mBoard.setComputerSpot(2);
        }
        if ((first == 3 || second == 3 || third == 3 || firsttwo == 3 || lasttwo == 3 || firstandthird == 3 || total == 3) && mComputer.hasRolledTwo() == true && mComputer.whatSpotIsNeededNext() == 3)
        {
            mComputer.rolled(3);
            mBoard.setComputerSpot(3);
        }
        if ((first == 4 || second == 4 || third == 4 || firsttwo == 4 || lasttwo == 4 || firstandthird == 4 || total == 4) && mComputer.hasRolledThree() == true && mComputer.whatSpotIsNeededNext() == 4)
        {
            mComputer.rolled(4);
            mBoard.setComputerSpot(4);
        }
        if ((first == 5 || second == 5 || third == 5 || firsttwo == 5 || lasttwo == 5 || firstandthird == 5 || total == 5) && mComputer.hasRolledFour() == true && mComputer.whatSpotIsNeededNext() == 5)
        {
            mComputer.rolled(5);
            mBoard.setComputerSpot(5);
        }
        if ((first == 6 || second == 6 || third == 6 || firsttwo == 6 || lasttwo == 6 || firstandthird == 6 || total == 6) && mComputer.hasRolledFive() == true && mComputer.whatSpotIsNeededNext() == 6)
        {
            mComputer.rolled(6);
            mBoard.setComputerSpot(6);
        }
        if ((firsttwo == 7 || lasttwo == 7 || firstandthird == 7 || total == 7) && mComputer.hasRolledSix() == true && mComputer.whatSpotIsNeededNext() == 7)
        {
            mComputer.rolled(7); // for 7-12, a single die cannot get the value alone
            mBoard.setComputerSpot(7);
        }
        if ((firsttwo == 8 || lasttwo == 8 || firstandthird == 8 || total == 8) && mComputer.hasRolledSeven() == true && mComputer.whatSpotIsNeededNext() == 8)
        {
            mComputer.rolled(8);
            mBoard.setComputerSpot(8);
        }
        if ((firsttwo == 9 || lasttwo == 9 || firstandthird == 9 || total == 9) && mComputer.hasRolledEight() == true && mComputer.whatSpotIsNeededNext() == 9)
        {
            mComputer.rolled(9);
            mBoard.setComputerSpot(9);
        }
        if ((firsttwo == 10 || lasttwo == 10 || firstandthird == 10 || total == 10) && mComputer.hasRolledNine() == true && mComputer.whatSpotIsNeededNext() == 10)
        {
            mComputer.rolled(10);
            mBoard.setComputerSpot(10);
        }
        if ((firsttwo == 11 || lasttwo == 11 || firstandthird == 11 || total == 11) && mComputer.hasRolledTen() == true && mComputer.whatSpotIsNeededNext() == 11)
        {
            mComputer.rolled(11);
            mBoard.setComputerSpot(11);
        }
        if ((firsttwo == 12 || lasttwo == 12 || firstandthird == 12 || total == 12) && mComputer.hasRolledEleven() == true && mComputer.whatSpotIsNeededNext() == 12)
        {
            mComputer.rolled(12);
            mBoard.setComputerSpot(12);
            mBoard.setGameOver(true);
            mBoard.markComputerAsWinner();
        }
    }

    // Officially, the human won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // Officially, the computer won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // If neither, then the game is still underway
    Centennial::GAMEOUTCOME  Centennial::determineGameOutcome() const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
        if (mHuman.hasRolledOne() == true && mHuman.hasRolledTwo() == true && mHuman.hasRolledThree() == true && mHuman.hasRolledFour() == true &&
            mHuman.hasRolledFive() == true && mHuman.hasRolledSix() == true && mHuman.hasRolledSeven() == true && mHuman.hasRolledEight() == true && 
            mHuman.hasRolledNine() == true && mHuman.hasRolledTen() == true && mHuman.hasRolledEleven() == true && mHuman.hasRolledTwelve() == true)
        { // if the human has rolled to all spots, then they have won the game
            result = GAMEOUTCOME::HUMANWONGAME;
        }
        else if (mComputer.hasRolledOne() == true && mComputer.hasRolledTwo() == true && mComputer.hasRolledThree() == true && mComputer.hasRolledFour() == true && 
            mComputer.hasRolledFive() == true && mComputer.hasRolledSix() == true && mComputer.hasRolledSeven() == true && mComputer.hasRolledEight() == true && 
            mComputer.hasRolledNine() == true && mComputer.hasRolledTen() == true && mComputer.hasRolledEleven() == true && mComputer.hasRolledTwelve() == true)
        { // if the computer has rolled to all spots, then they have won the game (if the human has not rolled 12 spots before the computer)
            result = GAMEOUTCOME::COMPUTERWONGAME;
        }
        return(result);
    }

    // determines if the game has ended
    bool Centennial::isGameOver()
    {
        if (determineGameOutcome() == GAMEOUTCOME::GAMENOTOVER) { return false; }
        else { return true; }
    }

    // getters
    Player Centennial::getHuman() const
    {
        return(mHuman);
    }

    Player Centennial::getComputer() const
    {
        return(mComputer);
    }

    Board  Centennial::getBoard() const
    {
        return(mBoard);
    }
}
