#include "MegaMillionsTicket.h"
#include <cassert>

MegaMillionsTicket::MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball)
{
	mBall1 = ball1; // sets the private members to the given ints
	mBall2 = ball2;
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mMegaBall = megaball;

	assert(mBall1 != mBall2 && mBall1 != mBall3 && mBall1 != mBall4 && mBall1 != mBall5); // asserts that the regular balls are between 1 and 75 and are all unique
	assert(mBall2 != mBall3 && mBall2 != mBall4 && mBall2 != mBall5); // asserts that the megaball is between 1 and 25
	assert(mBall3 != mBall4 && mBall3 != mBall5);
	assert(mBall4 != mBall5);
	assert(mBall1 >= 1 && mBall1 <= 75);
	assert(mBall2 >= 1 && mBall2 <= 75);
	assert(mBall3 >= 1 && mBall3 <= 75);
	assert(mBall4 >= 1 && mBall4 <= 75);
	assert(mBall5 >= 1 && mBall5 <= 75);
	assert(mMegaBall >= 1 && mMegaBall <= 25);
}

int MegaMillionsTicket::getBall1() const // gets the private members, accessors
{
	return mBall1;
}

int MegaMillionsTicket::getBall2() const
{
	return mBall2;
}

int MegaMillionsTicket::getBall3() const
{
	return mBall3;
}

int MegaMillionsTicket::getBall4() const
{
	return mBall4;
}

int MegaMillionsTicket::getBall5() const
{
	return mBall5;
}

int MegaMillionsTicket::getMegaBall() const
{
	return mMegaBall;
}
