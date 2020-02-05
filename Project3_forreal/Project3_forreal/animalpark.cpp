
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

bool isValidAnimalParkString(string animalparkString); // 4 main functions
int  dogsLeft(string animalparkString);
int  catsLeft(string animalparkString);
int  peopleLeft(string animalparkString);
bool checkCharacters(string animalparkString); // validity checks, if the string fails any one of them, it is invalid
bool checkLastChar(string animalparkString);
bool noConsecutiveOperators(string animalparkString);
bool noMixedPets(string animalparkString);
bool noPeopleBeforePets(string animalparkString);
bool noPeopleLeavingWithoutPet(string animalparkString);
bool noPeopleEnteringWithoutPet(string animalparkString);
bool noPetsAlone(string animalparkString);
int countString(string animalparkString, char a); // counts the characters (excluding + and -) that are left in the park
// if the characters that are left in the park is less than 1, then the string is invalid (since the character left the park without entering)

int main()
{
    cout.setf(ios::boolalpha); // make the compiler return bools as true and false, not 1 and 0
    string animalparkString = "";
    
    //invalid strings
    assert(!isValidAnimalParkString(""));
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
    assert(!isValidAnimalParkString("cp-dP"));
    assert(!isValidAnimalParkString("dp-DP"));
    assert(!isValidAnimalParkString("cP+dP-cdPP"));
    assert(!isValidAnimalParkString("cpP-P"));
    assert(!isValidAnimalParkString("cp+P-cpP"));
    assert(!isValidAnimalParkString("dp+cp "));
    assert(!isValidAnimalParkString("cp-dp+cp"));
    assert(!isValidAnimalParkString("cccCCpppP-ddDDpp"));
    assert(!isValidAnimalParkString("cccCCpppP+ddDDpp-dddP"));
    assert(!isValidAnimalParkString("dp++dp"));
    assert(!isValidAnimalParkString("dp+-dp"));
    assert(!isValidAnimalParkString("dp--dp"));
    assert(!isValidAnimalParkString("dp-+dp"));
    assert(!isValidAnimalParkString("dp-d+cp"));
    assert(!isValidAnimalParkString("Ccp-C+cp"));

    //valid strings
    assert(isValidAnimalParkString("CP+dp-CP-dp"));
    assert(isValidAnimalParkString("dp+cp"));
    assert(isValidAnimalParkString("CP+dp-CP"));
    assert(isValidAnimalParkString("ccCP+ddDP"));
    assert(isValidAnimalParkString("dP+dp-ddPp"));
    assert(isValidAnimalParkString("DP+CP+cp+dp-Dp-Cp-dP-cP"));
    assert(isValidAnimalParkString("CCP-CP"));
    assert(isValidAnimalParkString("dp-dp+Cp"));
    assert(isValidAnimalParkString("dp-dp+CP-CP"));
    assert(isValidAnimalParkString("dddpP-dp+cccp+CCP-cCP"));
    assert(isValidAnimalParkString("DDp-Dp+Dp+cP-DDP"));
    
    //dogs left
    assert(dogsLeft("    ") == -1);
    assert(dogsLeft("cp-dp+cp") == -1);
    assert(dogsLeft("dp+DP") == 2);
    assert(dogsLeft("CP+cp") == 0);
    assert(dogsLeft("CP+dp+DP") == 2);
    assert(dogsLeft("dp-dp+CP-CP") == 0);
    assert(dogsLeft("DDp-Dp+Dp+cP-DDP") == 0);
    assert(dogsLeft("dDdDdDdpPPPPppP+ccCCcpPPpppP-dDdDpppP") == 3);

    //cats left
    assert(catsLeft("    ") == -1);
    assert(catsLeft("dp+DP") == 0);
    assert(catsLeft("CP+cp-CP") == 1);
    assert(catsLeft("CP+cp") == 2);
    assert(catsLeft("CP+dp+DP-CP") == 0);
    assert(catsLeft("DDp-Dp+Dp+cP-DDP") == 1);
    assert(catsLeft("dDdDdDdpPPPPppP+ccCCcpPPpppP-dDdDpppP") == 5);

    //people left
    assert(peopleLeft("      ") == -1);
    assert(peopleLeft("dp+DP") == 2);
    assert(peopleLeft("CP+cp") == 2);
    assert(peopleLeft("CP+dp-dp-CP") == 0);
    assert(peopleLeft("DDp-Dp+Dp+cP-DDP") == 1);
    assert(peopleLeft("dDdDdDdpPPPPppP+ccCCcpPPpppP-dDdDpppP+cPP") == 13);

    cerr << "All tests succeeded!" << endl;
    return 0;
}

bool isValidAnimalParkString(string animalparkString)
{
    bool result = true; // initialize the result as true, if the string fails any single test, the function returns false
    // it never updates the result to false, since the function immediately returns false if it is invalid
    // if the string passes a validity check, the function updates the result to true, but doesn't return true (as it may fail a following check)

    if (animalparkString.length() <= 1) // empty strings and strings of length 1 are invalid, since both pets and people cannot enter alone, and 
    {                       // the string cannot start with a plus or minus
        return false;
    }
    else // the result gets updated to true as it passes this check
    {
        result = true;
    }
    if (animalparkString.at(0) != 'C' && animalparkString.at(0) != 'c' && animalparkString.at(0) != 'd' && animalparkString.at(0) != 'D')
        // strings that dont start with c, C, d, D are invalid (people must follow their pets, and strings cannot start with + or -)
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
        if (noConsecutiveOperators(animalparkString) == false) // if there are two consecutive pluses or minuses, it is invalid
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
        {// this check also removes the option that dogs and cats aren't next to each other but still mixed, since a person would be in between them
            // and therefore, before a pet, which is invalid
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
        if (noPetsAlone(animalparkString) == false) // a pet cannot leave or enter without a person following
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
        if (countString(animalparkString, 'c') < 0) // if more kittens leave than the amount that have entered, it is invalid
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
        if (countString(animalparkString, 'C') < 0) // if more cats leave than the amount that have entered, it is invalid
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
        if (countString(animalparkString, 'd') < 0) // if more puppies leave than the amount that have entered, it is invalid
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
        if (countString(animalparkString, 'D') < 0) // if more dogs leave than the amount that have entered, it is invalid
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
        if (countString(animalparkString, 'p') < 0) // if more children leave than the amount that have entered, it is invalid
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
        if (countString(animalparkString, 'P') < 0) // if more adults leave than the amount that have entered, it is invalid
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
    return result; // returns result at the end since apparently not all control paths return a value
}

int  dogsLeft(string animalparkString)
{
    if (isValidAnimalParkString(animalparkString) == false) // if the string is invalid
    {
        return(-1);
    }
    else
    {
        return countString(animalparkString,'d') + countString(animalparkString, 'D'); // adds the total amount of puppies and dogs left in the park
                                                                                           // after the whole string is processed
    }
}

int  catsLeft(string animalparkString)
{
    if (isValidAnimalParkString(animalparkString) == false) // if the string is invalid
    {
        return(-1);
    }
    else
    {
        return countString(animalparkString, 'c') + countString(animalparkString, 'C'); // adds the total amount of kittens and cats left in the park
                                                                                        // after the whole string is processed
    }
}

int  peopleLeft(string animalparkString)
{
    if (isValidAnimalParkString(animalparkString) == false) // if the string is invalid
    {
        return(-1);
    }
    else
    {
        return countString(animalparkString, 'p') + countString(animalparkString, 'P'); // adds the total amount of children and adults left in the park
                                                                                           // after the whole string is process
    }
}

bool checkCharacters(string animalparkString) // checks if there are any invalid characters (characters that are not c/C/d/D/p/P/+/-)
{
    bool result = true;
    for (size_t i = 1; i < animalparkString.length(); i+=1)
    {
        //other characters must equal c d p C D P + -
        if (animalparkString.at(i) !='c' && animalparkString.at(i) !='C' && animalparkString.at(i) !='d' && animalparkString.at(i) != 'D' &&
            animalparkString.at(i) != 'p' && animalparkString.at(i) != 'P' && animalparkString.at(i) != '+' && animalparkString.at(i) != '-')
        {
            result = false;
        }
    }
    return result;
}

bool checkLastChar(string animalparkString) // checks if the last character is invalid (+/-/c/C/d/D), all other strings that have invalid last characters
{                                                                                   // are returned as invalid through the prior check
    bool result = true;
    char last = animalparkString.at(animalparkString.length() - 1);
    if (last == '+' || last == '-' || last == 'c' || last == 'C' || last == 'd' || last == 'D')
    {
        result = false;
    }
    return result;
}

bool noConsecutiveOperators(string animalparkString) // checks if there are consectuive pluses or minuses; if so, the string is invalid
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length() - 1; i += 1)
    {
        if (animalparkString.at(i) == '+' && animalparkString.at(i + 1) == '+')
        {
            result = false;
        }
        if (animalparkString.at(i) == '+' && animalparkString.at(i + 1) == '-')
        {
            result = false;
        }
        if (animalparkString.at(i) == '-' && animalparkString.at(i + 1) == '-')
        {
            result = false;
        }
        if (animalparkString.at(i) == '-' && animalparkString.at(i + 1) == '+')
        {
            result = false;
        }
    }
    return result;
}

bool noMixedPets(string animalparkString) // checks if an entry has mixed pets by checking 2 consecutive indices
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length() - 1; i += 1)
    {
        if (animalparkString.at(i) == 'c' && animalparkString.at(i + 1) == 'd') // all possible mixed entries of pets
        {
            result = false;
        }
        if (animalparkString.at(i) == 'c' && animalparkString.at(i + 1) == 'D')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'C' && animalparkString.at(i + 1) == 'd')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'C' && animalparkString.at(i + 1) == 'D')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'd' && animalparkString.at(i + 1) == 'c')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'd' && animalparkString.at(i + 1) == 'C')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'D' && animalparkString.at(i + 1) == 'c')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'D' && animalparkString.at(i + 1) == 'C')
        {
            result = false;
        }
    }
    return result;
}

bool noPeopleBeforePets(string animalparkString) // checks if a person comes before a pet, which is invalid, by checking 2 consecutive indices
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length() - 1; i += 1)
    {
        if (animalparkString.at(i) == 'p' && animalparkString.at(i + 1) == 'c') // any combination of people and pet consecutively is invalid
        {
            result = false;
        }
        if (animalparkString.at(i) == 'p' && animalparkString.at(i + 1) == 'C')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'p' && animalparkString.at(i + 1) == 'd')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'p' && animalparkString.at(i + 1) == 'D')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'P' && animalparkString.at(i + 1) == 'c')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'P' && animalparkString.at(i + 1) == 'C')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'P' && animalparkString.at(i + 1) == 'd')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'P' && animalparkString.at(i + 1) == 'D')
        {
            result = false;
        }
    }
    return result;
}

bool noPeopleLeavingWithoutPet(string animalparkString) // checks if a person leaves without a pet by checking 2 consecutive indices
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length() - 1; i += 1)
    {
        if (animalparkString.at(i) == '-' && animalparkString.at(i + 1) == 'p') // this check does not take into account if a person leaves with a pet but comes
        {                                                                 // before it, but the prior check covers for this situation
            result = false;
        }
        if (animalparkString.at(i) == '-' && animalparkString.at(i + 1) == 'P')
        {
            result = false;
        }
    }
    return result;
}

bool noPeopleEnteringWithoutPet(string animalparkString) // checks if a person enters without a pet
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length()-1; i += 1)
    {
        if (animalparkString.at(i) == '+' && animalparkString.at(i + 1) == 'p') // this check does not take into a cat if a person enters with a pet but comes
        {                                               // before it, but it is the same situation as the prior check
            result = false;
        }
        if (animalparkString.at(i) == '+' && animalparkString.at(i + 1) == 'P') // additionally, this check does not know if a person enters as the first entry
        {                                                            // but that situation is already invalid since a person cannot be the first character
            result = false;
        }
    }
    return result;
}

bool noPetsAlone(string animalparkString) // checks if a pet enters or leaves without a person following
{
    bool result = true;
    for (size_t i = 0; i < animalparkString.length() - 1; i += 1)
    {
        if (animalparkString.at(i) == 'c' && animalparkString.at(i + 1) == '+') // all possible pets and entering/leaving combinations
        {
            result = false;
        }
        if (animalparkString.at(i) == 'c' && animalparkString.at(i + 1) == '-')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'C' && animalparkString.at(i + 1) == '+')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'C' && animalparkString.at(i + 1) == '-')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'd' && animalparkString.at(i + 1) == '+')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'd' && animalparkString.at(i + 1) == '-')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'D' && animalparkString.at(i + 1) == '+')
        {
            result = false;
        }
        if (animalparkString.at(i) == 'D' && animalparkString.at(i + 1) == '-')
        {
            result = false;
        }    
    }
    return result;
}

int countString(string animalparkString, char a) // counts the characters in the string given the string (which is valid by all prior checks as this check
{       // comes last) and the character to count
    int count = 0;
    int m = 1; // this is a multiplier; if the entry is added, the counter is added by 1, but if the entry leaves, the counter is decremented by 1
    for (size_t i = 0; i < animalparkString.length(); i++)
    {
        char c = animalparkString.at(i); // uses if statements instead of switch since switch must take constants
        if (c == '+') // no need to count pluses
        {
            m = 1; // the multiplier updates to positive 1 since the characters are entering
        }
        else if (c == '-') // no need to count minuses
        {
            m = -1; // the multiplier updates to negative 1 since the characters are leaving
        }
        else if (c == a) // the other characters that need to be counted (c, C, d, D, p, P)
        {
            count += m; // added by the multipler; if the entry is entering, the counter is +1; if the entry is leaving, the counter is -1
        }
    }
    return count;
}