#include "Die.h"
#include "Board.h"
#include "Player.h"
#include "Centennial.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void clearScreen();

int main()
{
    using namespace std;
    using namespace cs31;
    // Die test code
    int i, value;
    Die d, d1, d2, d3, d4, d5, d6;
    for (i = 1; i <= 50; i++)
    {
        d.roll();
        value = d.getValue();
        assert(value >= 1 && value <= 6);
    }

    // Player test code
    Player p, human, computer;
    // in the beginning of time, nothing has been rolled yet and the spot needed is 1...
    assert(!p.hasRolledOne());
    assert(!p.hasRolledTwo());
    assert(!p.hasRolledThree());
    assert(!p.hasRolledFour());
    assert(!p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 1);
    // now the player has rolled 1... so the spot next needed is 2...
    p.rolled(1);
    assert(p.hasRolledOne());
    assert(!p.hasRolledTwo());
    assert(p.whatSpotIsNeededNext() == 2);
    // only rolls from 1-12 are relevant...
    p.rolled(100);
    assert(p.hasRolledOne());
    assert(!p.hasRolledTwo());
    assert(p.whatSpotIsNeededNext() == 2);
    // rolls must be sequential for things to count...
    p.rolled(3);
    assert(p.hasRolledOne());
    assert(!p.hasRolledTwo());
    assert(!p.hasRolledThree());
    assert(p.whatSpotIsNeededNext() == 2);
    p.rolled(2);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(!p.hasRolledThree());
    assert(p.whatSpotIsNeededNext() == 3);
    p.rolled(3);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(!p.hasRolledFour());
    assert(p.whatSpotIsNeededNext() == 4);
    p.rolled(4);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(!p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 5);
    p.rolled(4);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(!p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 5);
    p.rolled(5);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(!p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 6);
    p.rolled(6);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(!p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 7);
    p.rolled(7);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 8);
    p.rolled(6);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(!p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 8);
    p.rolled(8);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(!p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 9);
    p.rolled(9);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(p.hasRolledNine());
    assert(!p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 10);
    p.rolled(10);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(p.hasRolledNine());
    assert(p.hasRolledTen());
    assert(!p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 11);
    p.rolled(11);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(p.hasRolledNine());
    assert(p.hasRolledTen());
    assert(p.hasRolledEleven());
    assert(!p.hasRolledTwelve());
    assert(p.whatSpotIsNeededNext() == 12);
    p.rolled(12);
    assert(p.hasRolledOne());
    assert(p.hasRolledTwo());
    assert(p.hasRolledThree());
    assert(p.hasRolledFour());
    assert(p.hasRolledFive());
    assert(p.hasRolledSix());
    assert(p.hasRolledSeven());
    assert(p.hasRolledEight());
    assert(p.hasRolledNine());
    assert(p.hasRolledTen());
    assert(p.hasRolledEleven());
    assert(p.hasRolledTwelve());

    // work the Player via Dice
    d1.setValue(6);
    d2.setValue(5);
    d3.setValue(4);
    p.roll(d1, d2, d3);
    assert(p.whatWasRolled() == "Die1: 6 Die2: 5 Die3: 4\n");

    // Board test code
    Board b;
    assert(b.getHumanSpot() == 0);
    assert(b.getComputerSpot() == 0);
    assert(b.isGameOver() == false);
    assert(b.isHumanWinner() == false);
    b.setHumanSpot(3);
    b.setComputerSpot(6);
    assert(b.getHumanSpot() == 3);
    assert(b.getComputerSpot() == 6);
    assert(b.isGameOver() == false);
    assert(b.isHumanWinner() == false);
    b.setHumanSpot(12);
    assert(b.getHumanSpot() == 12);
    assert(b.getComputerSpot() == 6);
    assert(b.isGameOver() == false);
    assert(b.isHumanWinner() == false);
    b.setGameOver(true);
    b.markHumanAsWinner();
    assert(b.isGameOver() == true);
    assert(b.isHumanWinner() == true);
    // Centennial test code
    Centennial game;
    assert(game.isGameOver() == false);
    assert(game.determineGameOutcome() == Centennial::GAMENOTOVER);
    human = game.getHuman();
    computer = game.getComputer();
    assert(human.whatSpotIsNeededNext() == 1);
    assert(computer.whatSpotIsNeededNext() == 1);
    d1.setValue(1);
    d2.setValue(2);
    d3.setValue(3);
    d4.setValue(4);
    d5.setValue(5);
    d6.setValue(6);
    game.humanPlay(d6, d5, d4);
    human = game.getHuman();
    assert(human.whatSpotIsNeededNext() == 1);
    game.computerPlay(d1, d2, d3);
    computer = game.getComputer();
    assert(computer.whatSpotIsNeededNext() == 7);
    game.humanPlay(d4, d2, d1);
    human = game.getHuman();
    assert(human.whatSpotIsNeededNext() == 8);
    game.computerPlay(d5, d2, d1);
    computer = game.getComputer();
    assert(computer.whatSpotIsNeededNext() == 9);
    game.humanPlay(d6, d2, d3);
    human = game.getHuman();
    assert(human.whatSpotIsNeededNext() == 10);
    game.computerPlay(d1, d2, d3);
    computer = game.getComputer();
    assert(computer.whatSpotIsNeededNext() == 9);
    game.humanPlay(d4, d5, d6);
    human = game.getHuman();
    assert(human.whatSpotIsNeededNext() == 12);
    game.computerPlay(d3, d2, d1);
    computer = game.getComputer();
    assert(computer.whatSpotIsNeededNext() == 9);
    assert(game.isGameOver() == false);
    assert(game.determineGameOutcome() == Centennial::GAMENOTOVER);
    game.humanPlay(d2, d4, d6);
    assert(game.isGameOver() == true);
    assert(game.determineGameOutcome() == Centennial::HUMANWONGAME);

    Centennial game2;
    Player h, c;
    game2.humanPlay(d1, d3, d4);
    h = game2.getHuman();
    assert(h.whatSpotIsNeededNext() == 2);
    game2.computerPlay(d1, d2, d3);
    c = game2.getComputer();
    assert(c.whatSpotIsNeededNext() == 7);
    game2.humanPlay(d4, d2, d1);
    h = game2.getHuman();
    assert(h.whatSpotIsNeededNext() == 8);
    game2.computerPlay(d5, d2, d1);
    c = game2.getComputer();
    assert(c.whatSpotIsNeededNext() == 9);
    game2.humanPlay(d6, d2, d3);
    h = game2.getHuman();
    assert(h.whatSpotIsNeededNext() == 10);
    game2.computerPlay(d5, d4, d1);
    c = game2.getComputer();
    assert(c.whatSpotIsNeededNext() == 11);
    game2.humanPlay(d4, d5, d6);
    h = game2.getHuman();
    assert(h.whatSpotIsNeededNext() == 12);
    game2.computerPlay(d6, d5, d2);
    c = game2.getComputer();
    assert(c.whatSpotIsNeededNext() == 12);
    assert(game2.isGameOver() == false);
    assert(game2.determineGameOutcome() == Centennial::GAMENOTOVER);
    game2.humanPlay(d2, d3, d6);
    h = game2.getHuman();
    assert(h.whatSpotIsNeededNext() == 12);
    game2.computerPlay(d6, d3, d3);
    c = game2.getComputer();
    assert(game2.isGameOver() == true);
    assert(game2.determineGameOutcome() == Centennial::COMPUTERWONGAME);

    Player P;
    assert(P.whatSpotIsNeededNext() == 1);
    P.roll(1, 2, 4);
    assert(P.whatSpotIsNeededNext() == 1);

    P.rolled(1);
    P.rolled(2);
    P.rolled(3);
    P.rolled(4);
    P.rolled(5);
    P.rolled(6);
    P.rolled(7);
    assert(P.whatSpotIsNeededNext() == 8);

    cout << "All tests passed!" << endl;

    using namespace cs31;
    using namespace std;

    clearScreen();

    Centennial game3;
    std::string action, message = "(r)oll (q)uit: ";
    std::cout << message;

    // for now...
    Die D1;
    Die D2;
    Die D3;

    do
    {
        getline(cin, action);
        while (action.size() == 0)
        {
            getline(cin, action);  // no blank entries allowed....
        }
        switch (action[0])
        {
        default:   // if bad move, nobody moves
            cout << '\a' << endl;  // beep
            continue;
        case 'Q':
        case 'q':
            return 0;
        case 'r':
        case 'R':
            game3.humanPlay();
            cout << game3.display("") << endl;
            if (!game3.isGameOver())
            {
                game3.computerPlay();
                cout << game3.display(message) << endl;
            }
            break;
        }

    } while (!game3.isGameOver());

    return 0;
}

///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
        &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr || strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif 