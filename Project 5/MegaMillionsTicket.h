#ifndef MEGAMILLIONSTICKET_H
#define MEGAMILLIONSTICKET_H
#include <iostream>
using namespace std;
#include <string>

class MegaMillionsTicket {

public: 
	//constructors 
	MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball);
	
	//accessors
	int getBall1(); 
	int getBall2(); 
	int getBall3();
	int getBall4();
	int getBall5(); 
	int getMegaBall();

private: 
	//data members
	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mMegaBall;
};

#endif
