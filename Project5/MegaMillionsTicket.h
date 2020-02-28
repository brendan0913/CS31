#ifndef MEGAMILLIONSTICKET_H
#define MEGAMILLIONSTICKET_H

class MegaMillionsTicket
{
public:
	MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball); // constructor
	int getBall1() const; // accessors
	int getBall2() const;
	int getBall3() const;
	int getBall4() const;
	int getBall5() const;
	int getMegaBall() const;

private:
	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mMegaBall;
};

#endif
