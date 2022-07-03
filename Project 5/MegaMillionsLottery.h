#ifndef MEGAMILLIONSLOTTERY_H
#define MEGAMILLIONSLOTTERY_H
#include "MegaMillionsTicket.h"

class MegaMillionsLottery {

public: 
	//enumerations
	enum  WinningPossibility {MEGABALL, ONEPLUSMEGABALL, TWOPLUSMEGABALL, THREE, THREEPLUSMEGABALL,
		FOUR, FOURPLUSMEGABALL, FIVE, FIVEPLUSMEGABALL, NOTWINNING};

	//constructors
	MegaMillionsLottery();
	MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball);

	//accessors
	int getBall1();
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getMegaBall();

	//operations
	MegaMillionsTicket quickPick();
	WinningPossibility checkTicket(MegaMillionsTicket ticket);
	string whatHappened(MegaMillionsTicket ticket);

private:
	//datamembers
	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mMegaBall;

};

#endif
