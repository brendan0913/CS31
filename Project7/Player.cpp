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

    // cheats by accepting a particular set of dice for this player to use
    void Player::roll(Die d1, Die d2, Die d3)
    {
        // assigns each of the arguments to the Player's member variables to enable cheating
        mDie1 = d1;
        mDie2 = d2;
        mDie3 = d3;
    }

    // randomly rolls each of the player's three dies
    void Player::roll()
    {
        mDie1.roll();
        mDie2.roll();
        mDie3.roll();
        // randomly rolls each of the three Die member variables
    }

    int  Player::whatSpotIsNeededNext() // determines the result that is needed next
    {
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
        if (hasRolledTwelve()) { result = 0; }

        return(result);
    }

    void Player::rolled(int spot) // changes the hasRolled booleans to true if they have been rolled and it is the roll that was needed next
    {
        if (spot == 1 && whatSpotIsNeededNext() == 1) { hasRolled1 = true; }
        if (spot == 2 && whatSpotIsNeededNext() == 2 && hasRolled1 == true) { hasRolled2 = true; }
        if (spot == 3 && whatSpotIsNeededNext() == 3 && hasRolled2 == true) { hasRolled3 = true; }
        if (spot == 4 && whatSpotIsNeededNext() == 4 && hasRolled3 == true) { hasRolled4 = true; }
        if (spot == 5 && whatSpotIsNeededNext() == 5 && hasRolled4 == true) { hasRolled5 = true; }
        if (spot == 6 && whatSpotIsNeededNext() == 6 && hasRolled5 == true) { hasRolled6 = true; }
        if (spot == 7 && whatSpotIsNeededNext() == 7 && hasRolled6 == true) { hasRolled7 = true; }
        if (spot == 8 && whatSpotIsNeededNext() == 8 && hasRolled7 == true) { hasRolled8 = true; }
        if (spot == 9 && whatSpotIsNeededNext() == 9 && hasRolled8 == true) { hasRolled9 = true; }
        if (spot == 10 && whatSpotIsNeededNext() == 10 && hasRolled9 == true) { hasRolled10 = true; }
        if (spot == 11 && whatSpotIsNeededNext() == 11 && hasRolled10 == true) { hasRolled11 = true; }
        if (spot == 12 && whatSpotIsNeededNext() == 12 && hasRolled11 == true) { hasRolled12 = true; }

    }

    // getters
    Die Player::getDie1() const
    {
        return(mDie1);
    }

    Die Player::getDie2() const
    {
        return(mDie2);
    }

   Die Player::getDie3() const
    {
        return(mDie3);
    }

    bool Player::hasRolledOne() const
    {
        return(hasRolled1);
    }

    bool Player::hasRolledTwo() const
    {
        return(hasRolled2);
    }

    bool Player::hasRolledThree() const
    {
        return(hasRolled3);
    }

    bool Player::hasRolledFour() const
    {
        return(hasRolled4);
    }

    bool Player::hasRolledFive() const
    {
        return(hasRolled5);
    }

    bool Player::hasRolledSix() const
    {
        return(hasRolled6);
    }

    bool Player::hasRolledSeven() const
    {
        return(hasRolled7);
    }

    bool Player::hasRolledEight() const
    {
        return(hasRolled8);
    }

    bool Player::hasRolledNine() const
    {
        return(hasRolled9);
    }

    bool Player::hasRolledTen() const
    {
        return(hasRolled10);
    }

    bool Player::hasRolledEleven() const
    {
        return(hasRolled11);
    }

    bool Player::hasRolledTwelve() const
    {
        return(hasRolled12);
    }

    // outputs the value of each die
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
