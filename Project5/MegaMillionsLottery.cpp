#include "MegaMillionsLottery.h"
#include "MegaMillionsTicket.h"
#include "RandomNumber.h"
#include <cassert>

MegaMillionsLottery::MegaMillionsLottery() // if no ints for balls are passed in, creates the winning lottery set of balls if none are given
{
	RandomNumber b1(1, 75); // the first ball is a random value between 1 and 75
	mBall1 = b1.random();

	bool unique2 = false;
	RandomNumber b2(1, 75);
	mBall2 = b2.random();
	while (!unique2) // runs since not unique2 is true, sets the second ball to a new random value until the second ball is unique from the first ball
	{
		RandomNumber b2(1, 75);
		mBall2 = b2.random();
		if (mBall2 != mBall1)
		{
			unique2 = true;
		}
	}

	bool unique3 = false;
	RandomNumber b3(1, 75);
	mBall3 = b3.random();
	while (!unique3) // sets the third ball to a new random value until the third ball is unique from the first and second balls
	{
		RandomNumber b3(1, 75);
		mBall3 = b3.random();
		if (mBall3 != mBall1 && mBall3 != mBall2)
		{
			unique3 = true;
		}
	}

	bool unique4 = false;
	RandomNumber b4(1, 75);
	mBall4 = b4.random();
	while (!unique4) // sets the fourth ball to a new random value until the fourth ball is unique from the first, second, and third balls
	{
		RandomNumber b4(1, 75);
		mBall4 = b4.random();
		if (mBall4 != mBall1 && mBall4 != mBall2 && mBall4 != mBall3)
		{
			unique4 = true;
		}
	}

	bool unique5 = false;
	RandomNumber b5(1, 75);
	mBall5 = b5.random();
	while (!unique5) // sets the fifth to a new random value until the fifth ball is unique to the first, second, third, and fourth balls
	{
		RandomNumber b5(1, 75);
		mBall5 = b5.random();
		if (mBall5 != mBall1 && mBall5 != mBall2 && mBall5 != mBall3 && mBall5 != mBall4)
		{
			unique5 = true;
		}
	}

	RandomNumber mega(1, 25); // sets the megaball to a random number between 1 and 25
	mMegaBall = mega.random();

	assert(mBall1 != mBall2 && mBall1 != mBall3 && mBall1 != mBall4 && mBall1 != mBall5); // makes sure all the balls are random and between 1-75, megaball between 1-25
	assert(mBall2 != mBall3 && mBall2 != mBall4 && mBall2 != mBall5);
	assert(mBall3 != mBall4 && mBall3 != mBall5);
	assert(mBall4 != mBall5);
	assert(mBall1 >= 1 && mBall1 <= 75);
	assert(mBall2 >= 1 && mBall2 <= 75);
	assert(mBall3 >= 1 && mBall3 <= 75);
	assert(mBall4 >= 1 && mBall4 <= 75);
	assert(mBall5 >= 1 && mBall5 <= 75);
	assert(mMegaBall >= 1 && mMegaBall <= 25);
}

MegaMillionsLottery::MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball) // sets the balls to the given values if they are given
{
	mBall1 = ball1;
	mBall2 = ball2;
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mMegaBall = megaball;
}

int MegaMillionsLottery::getBall1() const // accessors
{
	return mBall1;
}

int MegaMillionsLottery::getBall2() const
{
	return mBall2;
}

int MegaMillionsLottery::getBall3() const
{
	return mBall3;
}

int MegaMillionsLottery::getBall4() const
{
	return mBall4;
}

int MegaMillionsLottery::getBall5() const
{
	return mBall5;
}

int MegaMillionsLottery::getMegaBall() const
{
	return mMegaBall;
}

MegaMillionsTicket MegaMillionsLottery::quickPick() // creates a MegaMillionsTicket that has a new set of values from the lottery values
{													// the new values of the ticket are also random, unique, and between 1-75 (1-25 for the megaball)
	RandomNumber B1(1, 75);
	int Ball1 = B1.random();

	bool unique2 = false;
	RandomNumber B2(1, 75);
	int Ball2 = B2.random();
	while (!unique2)
	{
		Ball2 = B2.random();
		if (Ball2 != Ball1)
		{
			unique2 = true;
		}
	}

	bool unique3 = false;
	RandomNumber B3(1, 75);
	int Ball3 = B3.random();
	while (!unique3)
	{
		Ball3 = B3.random();
		if (Ball3 != Ball1 && Ball3 != Ball2)
		{
			unique3 = true;
		}
	}

	bool unique4 = false;
	RandomNumber B4(1, 75);
	int Ball4 = B4.random();
	while (!unique4)
	{
		Ball4 = B4.random();
		if (Ball4 != Ball1 && Ball4 != Ball2 && Ball4 != Ball3)
		{
			unique4 = true;
		}
	}

	bool unique5 = false;
	RandomNumber B5(1, 75);
	int Ball5 = B5.random();
	while (!unique5)
	{
		Ball5 = B5.random();
		if (Ball5 != Ball1 && Ball5 != Ball2 && Ball5 != Ball3 && Ball5 != Ball4)
		{
			unique5 = true;
		}
	}

	RandomNumber m(1, 25);
	int MegaB = m.random();

	assert(Ball1 != Ball2 && Ball1 != Ball3 && Ball1 != Ball4 && Ball1 != Ball5);
	assert(Ball2 != Ball3 && Ball2 != Ball4 && Ball2 != Ball5);
	assert(Ball3 != Ball4 && Ball3 != Ball5);
	assert(Ball4 != Ball5);
	assert(Ball1 >= 1 && Ball1 <= 75);
	assert(Ball2 >= 1 && Ball2 <= 75);
	assert(Ball3 >= 1 && Ball3 <= 75);
	assert(Ball4 >= 1 && Ball4 <= 75);
	assert(Ball5 >= 1 && Ball5 <= 75);
	assert(MegaB >= 1 && MegaB <= 25);

	MegaMillionsTicket ticket = MegaMillionsTicket(Ball1, Ball2, Ball3, Ball4, Ball5, MegaB); // creates a ticket with the new balls
	
	return ticket;
}

MegaMillionsLottery::WinningPossibility MegaMillionsLottery::checkTicket(MegaMillionsTicket ticket)
{
	int Ball1 = ticket.getBall1(); // accesses the balls from the ticket class
	int Ball2 = ticket.getBall2();
	int Ball3 = ticket.getBall3();
	int Ball4 = ticket.getBall4();
	int Ball5 = ticket.getBall5();
	int MegaB = ticket.getMegaBall();

	int count = 0;

	if (Ball1 == getBall1() || Ball1 == getBall2() || Ball1 == getBall3() || Ball1 == getBall4() || Ball1 == getBall5()) // adds the number of balls that are the same
	{
		count++;
	}
	if (Ball2 == getBall1() || Ball2 == getBall2() || Ball2 == getBall3() || Ball2 == getBall4() || Ball2 == getBall5())
	{
		count++;
	}
	if (Ball3 == getBall1() || Ball3 == getBall2() || Ball3 == getBall3() || Ball3 == getBall4() || Ball3 == getBall5())
	{
		count++;
	}
	if (Ball4 == getBall1() || Ball4 == getBall2() || Ball4 == getBall3() || Ball4 == getBall4() || Ball4 == getBall5())
	{
		count++;
	}
	if (Ball5 == getBall1() || Ball5 == getBall2() || Ball5 == getBall3() || Ball5 == getBall4() || Ball5 == getBall5())
	{
		count++;
	}
	
	if (MegaB == getMegaBall())
	{
		if (count == 0)
		{
			return MEGABALL;
		}
		if (count == 1)
		{
			return ONEPLUSMEGABALL;
		}
		if (count == 2)
		{
			return TWOPLUSMEGABALL;
		}
		if (count == 3)
		{
			return THREEPLUSMEGABALL;
		}
		if (count == 4)
		{
			return FOURPLUSMEGABALL;
		}
		else
		{
			return FIVEPLUSMEGABALL;
		}
	}
	else // without megaball, one or two balls total won't win
	{
		if (count == 3)
		{
			return THREE;
		}
		if (count == 4)
		{
			return FOUR;
		}
		if (count == 5)
		{
			return FIVE;
		}
		else
		{
			return NOTWINNING;
		}
	}
}

std::string MegaMillionsLottery::whatHappened(MegaMillionsTicket ticket) 
{
	int result = checkTicket(ticket);
	if (result == MEGABALL)
	{
		return "You matched the megaball!";
	}

	else if (result == ONEPLUSMEGABALL)
	{
		return "You matched 1 ball plus the megaball!";
	}

	else if (result == TWOPLUSMEGABALL)
	{
		return "You matched 2 balls plus the megaball!";
	}

	else if (result == THREE)
	{
		return "You matched 3 balls!";
	}

	else if (result == THREEPLUSMEGABALL)
	{
		return "You matched 3 balls plus the megaball!";
	}

	else if (result == FOUR)
	{
		return "You matched 4 balls!";
	}

	else if (result == FOURPLUSMEGABALL)
	{
		return "You matched 4 balls plus the megaball!";
	}

	else if (result == FIVE)
	{
		return "You matched 5 balls!";
	}

	else if (result == FIVEPLUSMEGABALL)
	{
		return "You matched 5 balls plus the megaball!";
	}

	else
	{
		return "You didn't win anything at all!";
	}
}