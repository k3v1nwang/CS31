//
//  Player.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include "Die.h"

namespace cs31
{
    // set up three six sided dies
    // indicate that none of the spots 1-12 have yet been tossed
    Player::Player() : mDie1( 6 ), mDie2( 6 ), mDie3( 6 ), hasRolled1(false), hasRolled2(false), hasRolled3(false), hasRolled4(false), hasRolled5(false), hasRolled6(false), hasRolled7(false), hasRolled8(false), hasRolled9(false), hasRolled10(false), hasRolled11(false), hasRolled12(false)
    {
        
    }
    
    // CS 31 TODO: cheat by accepting a particular set of dies for this player to use
    void Player::roll( Die d1, Die d2, Die d3 )
    {
        mDie1 = d1;
        mDie2 = d2;
        mDie3 = d3;
    }

    // CS 31 TODO: randomly roll each of the player's three dies
    void Player::roll( )
    {
        Die d1;
        Die d2;
        Die d3;
        d1.roll();
        mDie1 = d1.getValue();
        d2.roll();
        mDie2 = d2.getValue();
        d3.roll();
        mDie3 = d3.getValue();

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
     
        int result = 1;
            
        if (hasRolledOne())
            result = 2;
        if (hasRolledOne() && hasRolledTwo())
            result = 3;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree())
            result = 4;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour())
            result = 5;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive())
            result = 6;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix())
            result = 7;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven())
            result = 8;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven() && hasRolledEight())
            result = 9;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven() && hasRolledEight() && hasRolledNine())
            result = 10;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven() && hasRolledEight() && hasRolledNine() && hasRolledTen())
            result = 11;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven() && hasRolledEight() && hasRolledNine() && hasRolledTen() && hasRolledEleven())
            result = 12;
        if (hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven() && hasRolledEight() && hasRolledNine() && hasRolledTen() && hasRolledEleven() && hasRolledTwelve())
            result = 0; 
        return( result );
    }
    
    // CS 31 TODO: this operation is called to indicate that the argument has been rolled
    //             in conjunction with the operation whatSpotIsNeededNext( ), adjust member
    //             variables correctly so that play can progress in the game
    // passing 1 means that a one was just tossed
    // passing 2 means that a two was just tossed
    // etc...
    void Player::rolled( int spot )
    {
        
        if (spot == 1)
            hasRolled1 = true;
        if (spot == 2 && hasRolledOne())
            hasRolled2 = true;
        if (spot == 3 && hasRolledOne() && hasRolledTwo())
            hasRolled3 = true;
        if (spot == 4 && hasRolledOne() && hasRolledTwo()&& hasRolledThree())
            hasRolled4 = true;
        if (spot == 5 && hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour())
            hasRolled5 = true;
        if (spot == 6 && hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour()&& hasRolledFive())
            hasRolled6 = true;
        if (spot == 7 && hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix())
            hasRolled7 = true;
        if (spot == 8 && hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven())
            hasRolled8 = true;
        if (spot == 9 && hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven() && hasRolledEight())
            hasRolled9 = true;
        if (spot == 10 && hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven() && hasRolledEight() && hasRolledNine())
            hasRolled10 = true;
        if (spot == 11 && hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven() && hasRolledEight() && hasRolledNine() && hasRolledTen())
            hasRolled11 = true;
        if (spot == 12 && hasRolledOne() && hasRolledTwo() && hasRolledThree() && hasRolledFour() && hasRolledFive() && hasRolledSix() && hasRolledSeven() && hasRolledEight() && hasRolledNine() && hasRolledTen() && hasRolledEleven())
            hasRolled12= true;
        
    }
    
    // trivial getter operation
    Die Player::getDie1() const
    {
        return( mDie1 );
    }
    
    // trivial getter operation
    Die Player::getDie2( ) const
    {
        return( mDie2 );
    }
    
    // trivial getter operation
    Die Player::getDie3( ) const
    {
        return( mDie3 );
    }
    
    // trivial getter operation
    bool Player::hasRolledOne() const
    {
        return( hasRolled1 );
    }

    // trivial getter operation
    bool Player::hasRolledTwo() const
    {
        return( hasRolled2 );
    }

    // trivial getter operation
    bool Player::hasRolledThree() const
    {
        return( hasRolled3 );
    }

    // trivial getter operation
    bool Player::hasRolledFour() const
    {
        return( hasRolled4 );
    }

    // trivial getter operation
    bool Player::hasRolledFive() const
    {
        return( hasRolled5 );
    }

    // trivial getter operation
    bool Player::hasRolledSix() const
    {
        return( hasRolled6 );
    }

    // trivial getter operation
    bool Player::hasRolledSeven() const
    {
        return( hasRolled7 );
    }

    // trivial getter operation
    bool Player::hasRolledEight() const
    {
        return( hasRolled8 );
    }

    // trivial getter operation
    bool Player::hasRolledNine() const
    {
        return( hasRolled9 );
    }

    // trivial getter operation
    bool Player::hasRolledTen() const
    {
        return( hasRolled10 );
    }

    // trivial getter operation
    bool Player::hasRolledEleven() const
    {
        return( hasRolled11 );
    }

    // trivial getter operation
    bool Player::hasRolledTwelve() const
    {
        return( hasRolled12 );
    }
    
    // used solely for testing purposes to see the value of each die
    // if we are using random rolls, we won't know what was tossed
    //         unless we use this operation
    std::string Player::whatWasRolled()
    {
        using namespace std;
        std::string s = "";
        s += "Die1: ";
        s += std::to_string( mDie1.getValue() );
        s += " Die2: ";
        s += std::to_string( mDie2.getValue() );
        s += " Die3: ";
        s += std::to_string( mDie3.getValue() );
        s += "\n";
        return( s );
    }
    
    

}
