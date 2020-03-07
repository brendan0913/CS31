//
//  Player.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include <iostream>

namespace cs31
{
    // set up three six sided dice
    // indicate that none of the spots 1-12 have yet been tossed
    Player::Player() : mDie1(6), mDie2(6), mDie3(6), hasRolled1(false), hasRolled2(false), hasRolled3(false), hasRolled4(false), hasRolled5(false), hasRolled6(false), hasRolled7(false), hasRolled8(false), hasRolled9(false), hasRolled10(false), hasRolled11(false), hasRolled12(false)
    {

    }

    // CS 31 TODO: cheat by accepting a particular set of dies for this player to use
    void Player::roll(Die d1, Die d2, Die d3)
    {
        // assign each of the arguments to the Player's member variables to enable cheating...
        mDie1 = d1;
        mDie2 = d2;
        mDie3 = d3;
    }

    // CS 31 TODO: randomly roll each of the player's three dies
    void Player::roll()
    {
        mDie1.roll();
        mDie2.roll();
        mDie3.roll();
        // randomly roll each of the three Die member variables
    }

    // CS 31 TODO: based on what has been tossed previously, determine the spot that is
    //             needed next
    // returning 1 means, in order to progress in the game at this point, the Player
    //             needs to toss a one
    // returning 2 means, in order to progress in the game at this point, the Player
    //             needs to toss a two
    // etc...
    int  Player::whatSpotIsNeededNext()
    {
        // for now to get it to build...
        int result = 1;
        if (hasRolledOne()) { result = 2; }
        if (hasRolledTwo()) { result = 3; }
        if (hasRolledThree()) { result = 4; }
        if (hasRolledFour()) { result = 5; }
        if (hasRolledFive()) { result = 6; }
        if (hasRolledSix()) { result = 7; }
        if (hasRolledSeven()) { result = 8; }
        if (hasRolledEight()) { result = 9; }
        if (hasRolledNine()) { result = 10; }
        if (hasRolledTen()) { result = 11; }
        if (hasRolledEleven()) { result = 12; }

        return(result);
    }

    // CS 31 TODO: this operation is called to indicate that the argument has been rolled
    //             in conjunction with the operation whatSpotIsNeededNext( ), adjust member
    //             variables correctly so that play can progress in the game
    // passing 1 means that a one was just tossed
    // passing 2 means that a two was just tossed
    // etc...
    void Player::rolled(int spot)
    {
        //if (spot < 1 || spot > 12) { hasRolled1 = true; }
        if (spot == 1 && whatSpotIsNeededNext() == 1) { hasRolled1 = true; }
        if (spot == 2 && whatSpotIsNeededNext() == 2) { hasRolled2 = true; }
        if (spot == 3 && whatSpotIsNeededNext() == 3) { hasRolled3 = true; }
        if (spot == 4 && whatSpotIsNeededNext() == 4) { hasRolled4 = true; }
        if (spot == 5 && whatSpotIsNeededNext() == 5) { hasRolled5 = true; }
        if (spot == 6 && whatSpotIsNeededNext() == 6) { hasRolled6 = true; }
        if (spot == 7 && whatSpotIsNeededNext() == 7) { hasRolled7 = true; }
        if (spot == 8 && whatSpotIsNeededNext() == 8) { hasRolled8 = true; }
        if (spot == 9 && whatSpotIsNeededNext() == 9) { hasRolled9 = true; }
        if (spot == 10 && whatSpotIsNeededNext() == 10) { hasRolled10 = true; }
        if (spot == 11 && whatSpotIsNeededNext() == 11) { hasRolled11 = true; }
        if (spot == 12 && whatSpotIsNeededNext() == 12) { hasRolled12 = true; }

    }

    // trivial getter operation
    Die Player::getDie1() const
    {
        return(mDie1);
    }

    // trivial getter operation
    Die Player::getDie2() const
    {
        return(mDie2);
    }

    // trivial getter operation
    Die Player::getDie3() const
    {
        return(mDie3);
    }

    // trivial getter operation
    bool Player::hasRolledOne() const
    {
        return(hasRolled1);
    }

    // trivial getter operation
    bool Player::hasRolledTwo() const
    {
        return(hasRolled2);
    }

    // trivial getter operation
    bool Player::hasRolledThree() const
    {
        return(hasRolled3);
    }

    // trivial getter operation
    bool Player::hasRolledFour() const
    {
        return(hasRolled4);
    }

    // trivial getter operation
    bool Player::hasRolledFive() const
    {
        return(hasRolled5);
    }

    // trivial getter operation
    bool Player::hasRolledSix() const
    {
        return(hasRolled6);
    }

    // trivial getter operation
    bool Player::hasRolledSeven() const
    {
        return(hasRolled7);
    }

    // trivial getter operation
    bool Player::hasRolledEight() const
    {
        return(hasRolled8);
    }

    // trivial getter operation
    bool Player::hasRolledNine() const
    {
        return(hasRolled9);
    }

    // trivial getter operation
    bool Player::hasRolledTen() const
    {
        return(hasRolled10);
    }

    // trivial getter operation
    bool Player::hasRolledEleven() const
    {
        return(hasRolled11);
    }

    // trivial getter operation
    bool Player::hasRolledTwelve() const
    {
        return(hasRolled12);
    }

    // used solely for testing purposes to see the value of each die
    // if we are using random rolls, we won't know what was tossed
    //         unless we use this operation
    std::string Player::whatWasRolled()
    {
        using namespace std;
        std::string s = "";
        s += "Die1: ";
        s += std::to_string(mDie1.getValue());
        s += " Die2: ";
        s += std::to_string(mDie2.getValue());
        s += " Die3: ";
        s += std::to_string(mDie3.getValue());
        s += "\n";
        return(s);
    }



}
