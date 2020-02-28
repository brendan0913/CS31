#include "MegaMillionsTicket.h"
#include "MegaMillionsLottery.h"
#include "RandomNumber.h"

#include <iostream>
#include <cassert>

int main()
{
    MegaMillionsTicket ticket(1, 2, 3, 4, 5, 6);
    assert(ticket.getBall1() == 1);
    assert(ticket.getBall2() == 2);
    assert(ticket.getBall3() == 3);
    assert(ticket.getBall4() == 4);
    assert(ticket.getBall5() == 5);
    assert(ticket.getMegaBall() == 6);
    MegaMillionsLottery lottery(1, 2, 3, 4, 5, 6);
    assert(lottery.getBall1() == 1);
    assert(lottery.getBall2() == 2);
    assert(lottery.getBall3() == 3);
    assert(lottery.getBall4() == 4);
    assert(lottery.getBall5() == 5);
    assert(lottery.getMegaBall() == 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls plus the megaball!");

    MegaMillionsLottery lot(12, 74, 75, 19, 20, 8);
    assert(lot.getBall1() == 12);
    assert(lot.getBall2() == 74);
    assert(lot.getBall3() == 75);
    assert(lot.getBall4() == 19);
    assert(lot.getBall5() == 20);
    assert(lot.getMegaBall() == 8);
    assert(lot.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::NOTWINNING);
    assert(lot.whatHappened(ticket) == "You didn't win anything at all!");

    ticket = MegaMillionsTicket(7, 8, 9, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::MEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched the megaball!");
    ticket = MegaMillionsTicket(8, 28, 9, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::MEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched the megaball!");
    ticket = MegaMillionsTicket(8, 9, 31, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::MEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched the megaball!");
    ticket = MegaMillionsTicket(8, 9, 10, 46, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::MEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched the megaball!");
    ticket = MegaMillionsTicket(8, 9, 10, 11, 69, 6);
    assert(ticket.getBall1() == 8);
    assert(ticket.getBall2() == 9);
    assert(ticket.getBall3() == 10);
    assert(ticket.getBall4() == 11);
    assert(ticket.getBall5() == 69);
    assert(ticket.getMegaBall() == 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::MEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched the megaball!");

    ticket = MegaMillionsTicket(1, 8, 9, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");
    ticket = MegaMillionsTicket(8, 1, 9, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");
    ticket = MegaMillionsTicket(8, 9, 1, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");
    ticket = MegaMillionsTicket(8, 9, 10, 1, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");
    ticket = MegaMillionsTicket(8, 9, 10, 11, 1, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");
    ticket = MegaMillionsTicket(8, 2, 10, 11, 12, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");
    ticket = MegaMillionsTicket(2, 8, 10, 11, 12, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");
    ticket = MegaMillionsTicket(8, 10, 2, 11, 12, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");
    ticket = MegaMillionsTicket(8, 10, 11, 2, 12, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");
    ticket = MegaMillionsTicket(8, 10, 11, 12, 2, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::ONEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 1 ball plus the megaball!");

    ticket = MegaMillionsTicket(1, 2, 9, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::TWOPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 2 balls plus the megaball!");
    ticket = MegaMillionsTicket(2, 1, 9, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::TWOPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 2 balls plus the megaball!");
    ticket = MegaMillionsTicket(2, 9, 1, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::TWOPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 2 balls plus the megaball!");
    ticket = MegaMillionsTicket(8, 9, 10, 1, 2, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::TWOPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 2 balls plus the megaball!");
    ticket = MegaMillionsTicket(8, 2, 10, 11, 1, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::TWOPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 2 balls plus the megaball!");

    ticket = MegaMillionsTicket(1, 2, 3, 10, 11, 7);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREE);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls!");
    ticket = MegaMillionsTicket(8, 1, 4, 10, 5, 8);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREE);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls!");
    ticket = MegaMillionsTicket(2, 9, 1, 10, 4, 21);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREE);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls!");
    ticket = MegaMillionsTicket(3, 4, 10, 1, 11, 1);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREE);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls!");
    ticket = MegaMillionsTicket(8, 2, 10, 5, 1, 2);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREE);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls!");

    ticket = MegaMillionsTicket(1, 2, 3, 10, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls plus the megaball!");
    ticket = MegaMillionsTicket(8, 1, 4, 10, 5, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls plus the megaball!");
    ticket = MegaMillionsTicket(2, 9, 1, 10, 4, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls plus the megaball!");
    ticket = MegaMillionsTicket(3, 4, 10, 1, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls plus the megaball!");
    ticket = MegaMillionsTicket(8, 2, 10, 5, 1, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 3 balls plus the megaball!");

    ticket = MegaMillionsTicket(1, 2, 3, 4, 11, 7);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOUR);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls!");
    ticket = MegaMillionsTicket(8, 1, 4, 3, 5, 8);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOUR);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls!");
    ticket = MegaMillionsTicket(2, 3, 1, 10, 4, 21);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOUR);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls!");
    ticket = MegaMillionsTicket(3, 4, 2, 1, 11, 1);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOUR);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls!");
    ticket = MegaMillionsTicket(8, 2, 3, 5, 1, 2);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOUR);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls!");

    ticket = MegaMillionsTicket(1, 2, 3, 4, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOURPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls plus the megaball!");
    ticket = MegaMillionsTicket(8, 1, 4, 3, 5, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOURPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls plus the megaball!");
    ticket = MegaMillionsTicket(2, 3, 1, 10, 4, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOURPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls plus the megaball!");
    ticket = MegaMillionsTicket(3, 4, 2, 1, 11, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOURPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls plus the megaball!");
    ticket = MegaMillionsTicket(8, 2, 3, 5, 1, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FOURPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 4 balls plus the megaball!");

    ticket = MegaMillionsTicket(1, 2, 3, 4, 5, 19);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVE);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls!");
    ticket = MegaMillionsTicket(2, 1, 4, 3, 5, 1);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVE);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls!");
    ticket = MegaMillionsTicket(2, 3, 1, 5, 4, 2);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVE);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls!");
    ticket = MegaMillionsTicket(3, 4, 2, 1, 5, 3);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVE);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls!");
    ticket = MegaMillionsTicket(4, 2, 3, 5, 1, 17);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVE);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls!");

    ticket = MegaMillionsTicket(1, 2, 3, 4, 5, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls plus the megaball!");
    ticket = MegaMillionsTicket(2, 1, 4, 3, 5, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls plus the megaball!");
    ticket = MegaMillionsTicket(2, 3, 1, 5, 4, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls plus the megaball!");
    ticket = MegaMillionsTicket(3, 4, 2, 1, 5, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls plus the megaball!");
    ticket = MegaMillionsTicket(4, 2, 3, 5, 1, 6);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVEPLUSMEGABALL);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls plus the megaball!");

    ticket = MegaMillionsTicket(7, 8, 9, 10, 11, 7);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::NOTWINNING);
    assert(lottery.whatHappened(ticket) == "You didn't win anything at all!");
    ticket = MegaMillionsTicket(8, 28, 9, 10, 11, 23);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::NOTWINNING);
    assert(lottery.whatHappened(ticket) == "You didn't win anything at all!");
    ticket = MegaMillionsTicket(8, 9, 31, 10, 11, 24);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::NOTWINNING);
    assert(lottery.whatHappened(ticket) == "You didn't win anything at all!");
    ticket = MegaMillionsTicket(8, 9, 10, 46, 11, 25);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::NOTWINNING);
    assert(lottery.whatHappened(ticket) == "You didn't win anything at all!");
    ticket = MegaMillionsTicket(8, 9, 10, 11, 69, 14);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::NOTWINNING);
    assert(lottery.whatHappened(ticket) == "You didn't win anything at all!");

    ticket = MegaMillionsTicket(1, 2, 3, 4, 5, 12);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::FIVE);
    assert(lottery.whatHappened(ticket) == "You matched 5 balls!");

    ticket = MegaMillionsTicket(3, 7, 1, 8, 5, 3);
    assert(lottery.checkTicket(ticket) == MegaMillionsLottery::WinningPossibility::THREE);

    MegaMillionsTicket t(1, 2, 3, 4, 5, 6);
    MegaMillionsLottery l(6, 5, 4, 3, 2, 1);
    assert(l.checkTicket(t) == MegaMillionsLottery::WinningPossibility::FOUR);

    MegaMillionsTicket quickPickTicket(1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 20; i++)
    {
        quickPickTicket = lottery.quickPick();
        // all the ball numbers need to be different...
        assert(quickPickTicket.getBall1() != quickPickTicket.getBall2() &&
            quickPickTicket.getBall1() != quickPickTicket.getBall3() &&
            quickPickTicket.getBall1() != quickPickTicket.getBall4() &&
            quickPickTicket.getBall1() != quickPickTicket.getBall5() &&
            quickPickTicket.getBall2() != quickPickTicket.getBall3() &&
            quickPickTicket.getBall2() != quickPickTicket.getBall4() &&
            quickPickTicket.getBall2() != quickPickTicket.getBall5() &&
            quickPickTicket.getBall3() != quickPickTicket.getBall4() &&
            quickPickTicket.getBall3() != quickPickTicket.getBall5() &&
            quickPickTicket.getBall4() != quickPickTicket.getBall5());
    }
    std::cerr << "All tests passed!" << std::endl;
    return 0;
}