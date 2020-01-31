
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

// declare the 4 functions
bool isValidAnimalParkString(string animalparkString); // 4 main functions
int  dogsLeft(string animalparkString);
int  catsLeft(string animalparkString);
int  peopleLeft(string animalparkString);
bool checkCharacters(string animalparkString); // validity checks, if the string fails any one of them, it is invalid
bool checkLastChar(string animalparkString);
bool noMixedPets(string animalparkString);
bool noPeopleBeforePets(string animalparkString);
bool noPeopleLeavingWithoutPet(string animalparkString);
bool noPeopleEnteringWithoutPet(string animalparkString);
int countKittens(string animalparkString); // counting the characters that have entered the park
int countCats(string animalparkString);
int countPuppies(string animalparkString);
int countDogs(string animalparkString);
int countChildren(string animalparkString);
int countAdults(string animalparkString);
int countKittensLeaving(string animalparkString); // counting the characters that have left the park
int countCatsLeaving(string animalparkString);
int countPuppiesLeaving(string animalparkString);
int countDogsLeaving(string animalparkString);
int countChildrenLeaving(string animalparkString);
int countAdultsLeaving(string animalparkString);
bool noKittensLeaving(string animalparkString); // validity checks to check if characters have left that did not enter
bool noCatsLeaving(string animalparkString);
bool noPuppiesLeaving(string animalparkString);
bool noDogsLeaving(string animalparkString);
bool noChildrenLeaving(string animalparkString);
bool noAdultsLeaving(string animalparkString);

int main()
{
    cout.setf(ios::boolalpha); // make the compiler return bools as true and false, not 1 and 0
    string animalparkString = "";


    //invalid strings
    /*assert(!isValidAnimalParkString(""));
    assert(!isValidAnimalParkString("   "));
    assert(!isValidAnimalParkString("asdf1ABC000"));
    assert(!isValidAnimalParkString("+dp+cp"));
    assert(!isValidAnimalParkString("-dp+dp"));
    assert(!isValidAnimalParkString("d p + c p"));
    assert(!isValidAnimalParkString("Pd"));
    assert(!isValidAnimalParkString("P"));
    assert(!isValidAnimalParkString("p"));
    assert(!isValidAnimalParkString("ddDP+ccCP-"));
    assert(!isValidAnimalParkString("ddDP+cccP+"));
    assert(!isValidAnimalParkString("cCcDP"));
    assert(!isValidAnimalParkString("dDdCP"));
    assert(!isValidAnimalParkString("dddddPcccccP"));
    assert(!isValidAnimalParkString("dcdcdcdcdcPP"));
    assert(!isValidAnimalParkString("dp-CP"));
    assert(!isValidAnimalParkString("cP+dP-cdPP"));
    assert(!isValidAnimalParkString("cpP-P"));
    assert(!isValidAnimalParkString("cp+P-cpP"));
    assert(!isValidAnimalParkString("dp+cp "));

    //valid strings
    assert(isValidAnimalParkString("CP+dp-CP-dp"));
    assert(isValidAnimalParkString("dp+cp"));
    assert(isValidAnimalParkString("CP+dp-CP"));
    assert(isValidAnimalParkString("ccCP+ddDP"));
    assert(isValidAnimalParkString("dP+dp-ddPp"));
    assert(isValidAnimalParkString("DP+CP+cp+dp-Dp-Cp-dP-cP"));
    assert(isValidAnimalParkString("CCP-CP"));*/
    assert(isValidAnimalParkString("dp-dp+Cp"));

    //dogs left
    assert(dogsLeft("    ") == -1);
    assert(dogsLeft("dp+DP") == 2);
    assert(dogsLeft("CP+cp") == 0);
    assert(dogsLeft("CP+dp+DP") == 2);

    //cats left
    assert(catsLeft("dp+DP") == 0);
    assert(catsLeft("CP+cp-CP") == 1);
    assert(catsLeft("CP+cp") == 2);
    assert(catsLeft("CP+cp") == 2);
    assert(catsLeft("CP+dp+DP-CP") == 0);

    //people left
    assert(peopleLeft("      ") == -1);
    assert(peopleLeft("dp+DP") == 2);
    assert(peopleLeft("CP+cp") == 2);
    assert(peopleLeft("CP+dp-dp-CP") == 0);

    cerr << "All tests succeeded!" << endl;
    return 0;
}

bool isValidAnimalParkString(string animalparkString)
{
    bool result = true; // initialize the result as true, if the string fails any single test, the function returns false
    // it never updates the result to false, since the function should immediately return false if it is invalid
    // if the string passes a validity check, the function updates the result to true, but doesn't return true (as it may fail a following check)

    if (animalparkString.length() <= 1) // empty strings and strings of length 1 are invalid, since both pets and people cannot enter alone, and 
    {                       // the string cannot start with a plus or minus
        return false;
    }
    else // the result gets updated to true as it passes this check
    {
        result = true;
    }
    if (animalparkString[0] != 'C' && animalparkString[0] != 'c' && animalparkString[0] != 'd' && animalparkString[0] != 'D')
        // strings that dont start with c, C, d,D are invalid (people must follow their pets, and strings cannot start with + or -)
    {
        return false;
    }
    if (result == true) // strings that have characters that are not c, C, d, D, p, P, +, - are invalid
    {                     
        if (checkCharacters(animalparkString) == false)
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true) // if the last character is a pet or a + or -, the string is invalid; the last character must be a person
    {
        if (checkLastChar(animalparkString) == false)
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noMixedPets(animalparkString) == false) // if dogs and cats are right next to each other within a string, it is invalid
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noPeopleBeforePets(animalparkString) == false) // if a person comes before a pet, the string is invalid
        {// this check for validity also removes the option that dogs and cats aren't next to each other but still mixed, since a person would be in between them
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noPeopleLeavingWithoutPet(animalparkString) == false) // people cannot leave without a pet
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noPeopleEnteringWithoutPet(animalparkString) == false) // people cannot enter without a pet
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noKittensLeaving(animalparkString) == false) // if more kittens leave than the amount that have entered, it is invalid
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noCatsLeaving(animalparkString) == false) // if more cats leave than the amount that have entered, it is invalid
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noPuppiesLeaving(animalparkString) == false) // if more puppies leave than the amount that have entered, it is invalid
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noDogsLeaving(animalparkString) == false) // if more dogs leave than the amount that have entered, it is invalid
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noChildrenLeaving(animalparkString) == false) // if more children leave than the amount that have entered, it is invalid
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    if (result == true)
    {
        if (noAdultsLeaving(animalparkString) == false) // if more adults leave than the amount that have entered, it is invalid
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    else
    {
        return true; // if all other checks for invalidity are false, then the string is valid
    }
    if (result == true) // this is to make sure all control paths return a value since I kept getting a warning and g31 wouldn't compile
    {
        return true;
    }
    else
        return false;
}

int  dogsLeft(string animalparkString)
{
    if (isValidAnimalParkString(animalparkString) == false)
    {
        return(-1);
    }
    else
    {
        int dogsIn = 0;
        int dogsOut = 0;
        int dogsInPark = 0;
        dogsIn = countPuppies(animalparkString) + countDogs(animalparkString); //adds the dogs and puppies that enter up until a minus sign
        dogsOut = countPuppiesLeaving(animalparkString) + countDogsLeaving(animalparkString); // adds the dogs and puppies after a minus sign
        dogsInPark = dogsIn - dogsOut;
        return dogsInPark; // subtracts the total leaving dogs from the total entered dogs
    }
}

int  catsLeft(string animalparkString)
{
    if (isValidAnimalParkString(animalparkString) == false)
    {
        return(-1);
    }
    else
    {
        int catsIn = 0;
        int catsOut = 0;
        int catsInPark = 0;
        catsIn = countKittens(animalparkString) + countCats(animalparkString); // adds the kittens and cats that enter up until a minus sign
        catsOut = countKittensLeaving(animalparkString) + countCatsLeaving(animalparkString); // adds the kittens and cats after a minus sign
        catsInPark = catsIn - catsOut;
        return catsInPark; // subtracts the total leaving cats from the total entered cats
    }
}

int  peopleLeft(string animalparkString)
{
    if (isValidAnimalParkString(animalparkString) == false)
    {
        return(-1);
    }
    else
    {
        int peopleIn = 0;
        int peopleOut = 0;
        int peopleInPark = 0;
        peopleIn = countChildren(animalparkString) + countAdults(animalparkString); // adds the children and adults that enter up until a minus sign
        peopleOut = countChildrenLeaving(animalparkString) + countAdultsLeaving(animalparkString); // adds the children and adults after a minus sign
        peopleInPark = peopleIn - peopleOut;
        return peopleInPark; // subtracts the total leaving people from the total entered people
    }
}

bool checkCharacters(string animalparkString)
{
    bool result = true;
    for (size_t i = 1; i < animalparkString.length(); i+=1)
    {
        //other chars can equal c d p C D P + -
        if (animalparkString[i] !='c' && animalparkString[i] !='C' && animalparkString[i] !='d' && animalparkString[i] != 'D' && 
            animalparkString[i] != 'p' && animalparkString[i] != 'P' && animalparkString[i] != '+' && animalparkString[i] != '-')
        {
            result = false;
        }
    }
    return result;
}

bool checkLastChar(string animalparkString)
{
    bool result = true;
    char last = animalparkString[animalparkString.length() - 1];
    if (last == '+' || last == '-' || last == 'c' || last == 'C' || last == 'd' || last == 'D')
    {
        result = false;
    }
    return result;
}

bool noMixedPets(string animalparkString)
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length() - 1; i += 1)
    {
        if (animalparkString[i] == 'c' && animalparkString[i + 1] == 'd')
        {
            result = false;
        }
        if (animalparkString[i] == 'c' && animalparkString[i + 1] == 'D')
        {
            result = false;
        }
        if (animalparkString[i] == 'C' && animalparkString[i + 1] == 'd')
        {
            result = false;
        }
        if (animalparkString[i] == 'C' && animalparkString[i + 1] == 'D')
        {
            result = false;
        }
        if (animalparkString[i] == 'd' && animalparkString[i + 1] == 'c')
        {
            result = false;
        }
        if (animalparkString[i] == 'd' && animalparkString[i + 1] == 'C')
        {
            result = false;
        }
        if (animalparkString[i] == 'D' && animalparkString[i + 1] == 'c')
        {
            result = false;
        }
        if (animalparkString[i] == 'D' && animalparkString[i + 1] == 'C')
        {
            result = false;
        }
    }
    return result;
}

bool noPeopleBeforePets(string animalparkString)
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length() - 1; i += 1)
    {
        if (animalparkString[i] == 'p' && animalparkString[i + 1] == 'c')
        {
            result = false;
        }
        if (animalparkString[i] == 'p' && animalparkString[i + 1] == 'C')
        {
            result = false;
        }
        if (animalparkString[i] == 'p' && animalparkString[i + 1] == 'd')
        {
            result = false;
        }
        if (animalparkString[i] == 'p' && animalparkString[i + 1] == 'D')
        {
            result = false;
        }
        if (animalparkString[i] == 'P' && animalparkString[i + 1] == 'c')
        {
            result = false;
        }
        if (animalparkString[i] == 'P' && animalparkString[i + 1] == 'C')
        {
            result = false;
        }
        if (animalparkString[i] == 'P' && animalparkString[i + 1] == 'd')
        {
            result = false;
        }
        if (animalparkString[i] == 'P' && animalparkString[i + 1] == 'D')
        {
            result = false;
        }
    }
    return result;
}

bool noPeopleLeavingWithoutPet(string animalparkString)
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length(); i += 1)
    {
        if (animalparkString[i] == '-' && animalparkString[i + 1] == 'p')
        {
            result = false;
        }
        if (animalparkString[i] == '-' && animalparkString[i + 1] == 'P')
        {
            result = false;
        }
    }
    return result;
}

bool noPeopleEnteringWithoutPet(string animalparkString)
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length(); i += 1)
    {
        if (animalparkString[i] == '+' && animalparkString[i + 1] == 'p')
        {
            result = false;
        }
        if (animalparkString[i] == '+' && animalparkString[i + 1] == 'P')
        {
            result = false;
        }
    }
    return result;
}

int countKittens(string animalparkString)
{
    bool keepGoing = true;
    int kittens = 0;
    size_t i = 0;

    while (i < animalparkString.size() && keepGoing)
    {
        char c = animalparkString[i];
        switch (c)
        {
        case 'c':
             kittens += 1;
             keepGoing = true;
             break;
        case 'C':
        case 'd':
        case 'D':
        case 'p':
        case 'P':
        case '+':
            keepGoing = true;
            break;
        case '-':
        default:
            keepGoing = false;
            break;
        }
        i += 1;
    }
    return kittens;
}

// find count after minus, update a variable until it it '-' then do a counter for cats

int countCats(string animalparkString)
{
    bool keepGoing = true;
    size_t i = 0;
    int cats = 0;

    while (i < animalparkString.size() && keepGoing)
    {
        char c = animalparkString.at(i);
        switch (c)
        {
        case 'C':
            cats += 1;
            keepGoing = true;
            break;
        case 'c':
        case 'd':
        case 'D':
        case 'p':
        case 'P':
        case '+':
            keepGoing = true;
            break;
        case '-':
        default:
            keepGoing = false;
            break;
        }
        i += 1;
    }
    return cats;
}

int countPuppies(string animalparkString)
{
    bool keepGoing = true;
    size_t i = 0;
    int puppies = 0;

    while (i < animalparkString.size() && keepGoing)
    {
        char c = animalparkString.at(i);
        switch (c)
        {
        case 'd':
            puppies += 1;
            keepGoing = true;
            break;
        case 'c':
        case 'C':
        case 'D':
        case 'p':
        case 'P':
        case '+':
            keepGoing = true;
            break;
        case '-':
        default:
            keepGoing = false;
            break;
        }
        i += 1;
    }
    return puppies;
}

int countDogs(string animalparkString)
{
    bool keepGoing = true;
    size_t i = 0;
    int dogs = 0;

    while (i < animalparkString.size() && keepGoing)
    {
        char c = animalparkString.at(i);
        switch (c)
        {
        case 'D':
            dogs += 1;
            keepGoing = true;
            break;
        case 'c':
        case 'C':
        case 'd':
        case 'p':
        case 'P':
        case '+':
            keepGoing = true;
            break;
        case '-':
        default:
            keepGoing = false;
            break;
        }
        i += 1;
    }
    return dogs;
}

int countChildren(string animalparkString)
{
    bool keepGoing = true;
    size_t i = 0;
    int children = 0;

    while (i < animalparkString.size() && keepGoing)
    {
        char c = animalparkString.at(i);
        switch (c)
        {
        case 'p':
            children += 1;
            keepGoing = true;
            break;
        case 'c':
        case 'C':
        case 'd':
        case 'D':
        case 'P':
        case '+':
            keepGoing = true;
            break;
        case '-':
        default:
            keepGoing = false;
            break;
        }
        i += 1;
    }
    return children;
}

int countAdults(string animalparkString)
{
    bool keepGoing = true;
    size_t i = 0;
    int adults = 0;

    while (i < animalparkString.size() && keepGoing)
    {
        char c = animalparkString.at(i);
        switch (c)
        {
        case 'P':
            adults += 1;
            keepGoing = true;
            break;
        case 'c':
        case 'C':
        case 'd':
        case 'D':
        case 'p':
        case '+':
            keepGoing = true;
            break;
        case '-':
        default:
            keepGoing = false;
            break;
        }
        i += 1;
    }
    return adults;
}

int countKittensLeaving(string animalparkString)
{
    bool keepGoing = true;
    size_t firstMinusPosition = 0;
    int kittens = 0;

    for (size_t i = 0; i < animalparkString.size() && keepGoing == true; i++)
    {
        if (animalparkString[i] == '-')
        {
            keepGoing = false;
            firstMinusPosition = i;
        }
    }
    if (firstMinusPosition == 0)
    {
        return kittens;
    }
    else 
    {
        size_t i = 0;
        i += firstMinusPosition;
        bool keepGoing = true;
        while (i < animalparkString.size() && keepGoing)
        {
            char c = animalparkString.at(i);
            switch (c)
            {
            case 'c':
                kittens += 1;
                keepGoing = true;
                break;
            case 'P':
            case 'C':
            case 'd':
            case 'D':
            case 'p':
            case '-':
                keepGoing = true;
                break;
            case '+':
            default:
                keepGoing = false;
                break;
            }
            i += 1;
        }
    }
    return kittens;
}

int countCatsLeaving(string animalparkString)
{
    bool keepGoing = true;
    size_t firstMinusPosition = 0;
    int cats = 0;

    for (size_t i = 0; i < animalparkString.size() && keepGoing == true; i++)
    {
        if (animalparkString[i] == '-')
        {
            keepGoing = false;
            firstMinusPosition = i;
        }
    }
    if (firstMinusPosition == 0)
    {
        return cats;
    }
    else
    {
        size_t i = 0;
        i += firstMinusPosition;
        bool keepGoing = true;
        while (i < animalparkString.size() && keepGoing)
        {
            char c = animalparkString.at(i);
            switch (c)
            {
            case 'C':
                cats += 1;
                keepGoing = true;
                break;
            case 'c':
            case 'P':
            case 'd':
            case 'D':
            case 'p':
            case '-':
                keepGoing = true;
                break;
            case '+':
            default:
                keepGoing = false;
                break;
            }
            i += 1;
        }
    }
    return cats;
}

int countPuppiesLeaving(string animalparkString)
{
    bool keepGoing = true;
    size_t firstMinusPosition = 0;
    int puppies = 0;

    for (size_t i = 0; i < animalparkString.size() && keepGoing == true; i++)
    {
        if (animalparkString[i] == '-')
        {
            keepGoing = false;
            firstMinusPosition = i;
        }
    }
    if (firstMinusPosition == 0)
    {
        return puppies;
    }
    else
    {
        size_t i = 0;
        i += firstMinusPosition;
        bool keepGoing = true;
        while (i < animalparkString.size() && keepGoing)
        {
            char c = animalparkString.at(i);
            switch (c)
            {
            case 'd':
                puppies += 1;
                keepGoing = true;
                break;
            case 'c':
            case 'C':
            case 'P':
            case 'D':
            case 'p':
            case '-':
                keepGoing = true;
                break;
            case '+':
            default:
                keepGoing = false;
                break;
            }
            i += 1;
        }
    }
    return puppies;
}

int countDogsLeaving(string animalparkString)
{
    bool keepGoing = true;
    size_t firstMinusPosition = 0;
    int dogs = 0;

    for (size_t i = 0; i < animalparkString.size() && keepGoing == true; i++)
    {
        if (animalparkString[i] == '-')
        {
            keepGoing = false;
            firstMinusPosition = i;
        }
    }
    if (firstMinusPosition == 0)
    {
        return dogs;
    }
    else
    {
        size_t i = 0;
        i += firstMinusPosition;
        bool keepGoing = true;
        while (i < animalparkString.size() && keepGoing)
        {
            char c = animalparkString.at(i);
            switch (c)
            {
            case 'D':
                dogs += 1;
                keepGoing = true;
                break;
            case 'c':
            case 'C':
            case 'd':
            case 'p':
            case 'P':
            case '-':
                keepGoing = true;
                break;
            case '+':
            default:
                keepGoing = false;
                break;
            }
            i += 1;
        }
    }
    return dogs;
}

int countChildrenLeaving(string animalparkString)
{
    bool keepGoing = true;
    size_t firstMinusPosition = 0;
    int children = 0;

    for (size_t i = 0; i < animalparkString.size() && keepGoing == true; i++)
    {
        if (animalparkString[i] == '-')
        {
            keepGoing = false;
            firstMinusPosition = i;
        }
    }
    if (firstMinusPosition == 0)
    {
        return children;
    }
    else
    {
        size_t i = 0;
        i += firstMinusPosition;
        bool keepGoing = true;
        while (i < animalparkString.size() && keepGoing)
        {
            char c = animalparkString.at(i);
            switch (c)
            {
            case 'p':
                children += 1;
                keepGoing = true;
                break;
            case 'c':
            case 'C':
            case 'd':
            case 'D':
            case 'P':
            case '-':
                keepGoing = true;
                break;
            case '+':
            default:
                keepGoing = false;
                break;
            }
            i += 1;
        }
    }
    return children;
}

int countAdultsLeaving(string animalparkString)
{
    bool keepGoing = true;
    size_t firstMinusPosition = 0;
    int adults = 0;

    for (size_t i = 0; i < animalparkString.size() && keepGoing == true; i++)
    {
        if (animalparkString[i] == '-')
        {
            keepGoing = false;
            firstMinusPosition = i;
        }
    }
    if (firstMinusPosition == 0)
    {
        return adults;
    }
    else
    {
        size_t i = 0;
        i += firstMinusPosition;
        bool keepGoing = true;
        while (i < animalparkString.size() && keepGoing)
        {
            char c = animalparkString.at(i);
            switch (c)
            {
            case 'P':
                adults += 1;
                keepGoing = true;
                break;
            case 'c':
            case 'C':
            case 'd':
            case 'D':
            case 'p':
            case '-':
                keepGoing = true;
                break;
            case '+':
            default:
                keepGoing = false;
                break;
            }
            i += 1;
        }
    }
    return adults;
}

bool noKittensLeaving(string animalparkString)
{
    if (countKittens(animalparkString) < countKittensLeaving(animalparkString))
    {
        return false;
    }
    else
    {
        return true;
    }
} 

bool noCatsLeaving(string animalparkString)
{
    if (countCats(animalparkString) < countCatsLeaving(animalparkString))
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool noPuppiesLeaving(string animalparkString)
{
    if (countPuppies(animalparkString) < countPuppiesLeaving(animalparkString))
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool noDogsLeaving(string animalparkString)
{
    if (countDogs(animalparkString) < countDogsLeaving(animalparkString))
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool noChildrenLeaving(string animalparkString)
{
    if (countChildren(animalparkString) < countChildrenLeaving(animalparkString))
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool noAdultsLeaving(string animalparkString)
{
    if (countAdults(animalparkString) < countAdultsLeaving(animalparkString))
    {
        return false;
    }
    else
    {
        return true;
    }
}