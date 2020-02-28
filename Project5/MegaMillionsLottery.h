#ifndef MEGAMILLIONSLOTTERY_H
#define MEGAMILLIONSLOTTERY_H

#include "MegaMillionsTicket.h"
#include <iostream>

class MegaMillionsLottery
{
public:
	MegaMillionsLottery(); // default constructor, randomizer
	MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball); // constructor when given the ints
	enum WinningPossibility { MEGABALL, ONEPLUSMEGABALL, TWOPLUSMEGABALL, THREE, THREEPLUSMEGABALL, FOUR, FOURPLUSMEGABALL, FIVE, FIVEPLUSMEGABALL, NOTWINNING };
	int getBall1() const; // accessors
	int getBall2() const;
	int getBall3() const;
	int getBall4() const;
	int getBall5() const;
	int getMegaBall() const;
	MegaMillionsTicket quickPick();
	WinningPossibility checkTicket(MegaMillionsTicket ticket);
	std::string whatHappened(MegaMillionsTicket ticket);

private:
	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mMegaBall;
};
#endif