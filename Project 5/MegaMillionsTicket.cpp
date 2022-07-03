#include <iostream>
#include "MegaMillionsTicket.h"
#include "RandomNumber.h"

using namespace std;

//constructor
MegaMillionsTicket::MegaMillionsTicket(int ball1, int ball2, int  ball3, int ball4, int ball5, int megaBall)
{
	mBall1 = ball1; 
	mBall2 = ball2; 
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mMegaBall = megaBall;
}

//accessors
int MegaMillionsTicket::getBall1()
{
	return mBall1;
}
int MegaMillionsTicket::getBall2()
{
	return mBall2;
}
int MegaMillionsTicket::getBall3()
{
	return mBall3;
}
int MegaMillionsTicket::getBall4()
{
	return mBall4;
}
int MegaMillionsTicket::getBall5()
{
	return mBall5;
}
int MegaMillionsTicket::getMegaBall()
{
	return mMegaBall;
}