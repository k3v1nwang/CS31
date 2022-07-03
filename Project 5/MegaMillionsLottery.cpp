#include <iostream>
#include "MegaMillionsLottery.h"
#include "MegaMillionsTicket.h"
#include "RandomNumber.h"

using namespace std;

//constructors
MegaMillionsLottery::MegaMillionsLottery()
{
	//When the constructor is called with no arguments, use the RandomNumber class to generate all the ball values.
	RandomNumber r1(1, 75);
	RandomNumber r2(1, 75);
	RandomNumber r3(1, 75);
	RandomNumber r4(1, 75);
	RandomNumber r5(1, 75);
	RandomNumber r6(1, 25);		//megaball has range from 1-25

	mBall1 = r1.random();		//first ball can be any value

	mBall2 = r2.random();
	while (mBall2 == mBall1)	//will loop if second ball is same value as first
	{
		mBall2 = r2.random();
	}

	mBall3 = r3.random();
	while (mBall3 == mBall2 || mBall3 == mBall1)	//ball3 cannot be the same as ball2 or ball1
	{
		mBall3 = r3.random();
	}

	mBall4 = r4.random();
	while (mBall4 == mBall3 || mBall4 == mBall2 || mBall4 == mBall1)	//ball4 cannot be same as ball1, 2, or 3 
	{
		mBall4 = r4.random();
	}

	mBall5 = r5.random();
	while (mBall5 == mBall4 || mBall5 == mBall3 || mBall5 == mBall2 || mBall5 == mBall1)	//ball5 cannot be the same as any preceding it
	{
		mBall5 = r5.random();
	}

	mMegaBall = r6.random();	//megaball can be of any value 1-25
}

MegaMillionsLottery::MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball)
{
	//when constructor is called with 6 ints, use those values for the balls
	mBall1 = ball1;
	mBall2 = ball2;
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mMegaBall = megaball;
}

//accessors
int MegaMillionsLottery::getBall1()
{
	return mBall1;
}
int MegaMillionsLottery::getBall2()
{
	return mBall2;
}
int MegaMillionsLottery::getBall3()
{
	return mBall3;
}
int MegaMillionsLottery::getBall4()
{
	return mBall4;
}
int MegaMillionsLottery::getBall5()
{
	return mBall5;
}
int MegaMillionsLottery::getMegaBall()
{
	return mMegaBall;
}

//operations
MegaMillionsTicket MegaMillionsLottery::quickPick()
{
	MegaMillionsLottery quickTicket;	//first create a MegaMillionsLottery type in order to acess the random function
	//create MegaMillionsTicket class that accesses the values from quickTicket
	MegaMillionsTicket ticket(quickTicket.getBall1(), quickTicket.getBall2(), quickTicket.getBall3(), quickTicket.getBall4(), quickTicket.getBall5(), quickTicket.getMegaBall());

	//return ticket which now is of the MegaMillionsTicket class but with values that are random
	return ticket;
}

MegaMillionsLottery::WinningPossibility MegaMillionsLottery::checkTicket(MegaMillionsTicket ticket)
{
	//get the values from the ticket that is fed in
	int checkedTicket[6] = { ticket.getBall1(), ticket.getBall2(), ticket.getBall3(), ticket.getBall4(), ticket.getBall5(), ticket.getMegaBall() };
	int winningTicket[6] = { getBall1(), getBall2(), getBall3(), getBall4(), getBall5(), getMegaBall() };	//create an array of the winnig combination

	//counter for matches 
	int ballCount = 0;
	int megaCount = 0;

	//count how many balls are matching
	for (int k = 0; k < 5; k++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkedTicket[k] == winningTicket[j])
				ballCount++;
		}
	}

	//see if megaball is matching
	if (checkedTicket[5] == winningTicket[5])
		megaCount = 1;

	//return the correct enumerated winning possibility based off of count
	if (megaCount == 1 && ballCount == 0)
		return MEGABALL;
	if (megaCount == 1 && ballCount == 1)
		return ONEPLUSMEGABALL;
	if (megaCount == 1 && ballCount == 2)
		return TWOPLUSMEGABALL;
	if (megaCount == 1 && ballCount == 3)
		return THREEPLUSMEGABALL;
	if (megaCount == 1 && ballCount == 4)
		return FOURPLUSMEGABALL;
	if (megaCount == 1 && ballCount == 5)
		return FIVEPLUSMEGABALL;
	if (megaCount == 0 && ballCount == 3)
		return THREE;
	if (megaCount == 0 && ballCount == 4)
		return FOUR;
	if (megaCount == 0 && ballCount == 5)
		return FIVE;

	//if none of them match, then it is not a winning ticket
	return NOTWINNING;

}

string MegaMillionsLottery::whatHappened(MegaMillionsTicket ticket)
{
	//call the checkeTicket function to return a winning possibilty 
	int result = checkTicket(ticket);
	string output = "";

	//change the output depending on the return of checkTicket
	switch (result)
	{
	case NOTWINNING:
		output = "You didn't win anything at all!";
		break;
	case MEGABALL:
		output = "You matched the megaball!";
		break;
	case ONEPLUSMEGABALL:
		output = "You matched 1 ball plus the megaball!";
		break;
	case TWOPLUSMEGABALL:
		output = "You matched 2 balls plus the megaball!";
		break;
	case THREEPLUSMEGABALL:
		output = "You matched 3 balls plus the megaball!";
		break;
	case THREE:
		output = "You matched 3 balls!";
		break;
	case FOURPLUSMEGABALL:
		output = "You matched 4 balls plus the megaball!";
		break;
	case FOUR:
		output = "You matched 4 balls!";
		break;
	case FIVE:
		output = "You matched 5 balls!";
		break;
	case FIVEPLUSMEGABALL:
		output = "You matched 5 balls plus the megaball!";
		break;
	}
	//return the output
	cout << output << endl;
	return output;
}