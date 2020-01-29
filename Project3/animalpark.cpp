
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

// declare the 4 functions
bool isValidAnimalParkString(string animalparkString);
int  dogsLeft(string animalparkString);
int  catsLeft(string animalparkString);
int  peopleLeft(string animalparkString);
bool countPets(string animalParkString, int dogs, int cats);
bool countPets(string animalParkString, size_t& position, int& dogs, int& cats);

string animalparkString = "";

int main()
{
	cout.setf(ios::boolalpha);
    int dogs = 0;
    int cats = 0;
    size_t pos = 0;

    assert(!isValidAnimalParkString(""));
    assert(!isValidAnimalParkString("   "));
    assert(isValidAnimalParkString("asdf1ABC000"));
    assert(!isValidAnimalParkString("+ dp + cp"));
    assert(!isValidAnimalParkString("d p + c p"));
    /*assert(!isValidAnimalParkString("- dp + dp"));
    assert(!isValidAnimalParkString("dp - CP"));
    assert(!isValidAnimalParkString("cCcDP"));
    assert(!isValidAnimalParkString("cP + dP - cdPP"));
    assert(!isValidAnimalParkString("cpP - P"));
    assert(!isValidAnimalParkString("cp + P - cpP"));
    assert(!isValidAnimalParkString("dddddPcccccP"));
    assert(!isValidAnimalParkString("ddDP + ccCP -"));
    assert(!isValidAnimalParkString("ddDP + cccP +"));*/

    pos = 1;
    assert(!countPets("aasdf", pos, dogs, cats));
    assert(pos == 2 && dogs == 0 && cats == 0);

    pos = 0;
    assert(countPets("ddddP", pos, dogs, cats));
    assert(pos == 5 && dogs == 4 && cats == 0);

    pos = 0;
    assert(countPets("ccccPP", pos, dogs, cats));
    assert(pos == 5 && dogs == 0 && cats == 4);

    pos = 1;
    assert(countPets("ddddP", pos, dogs, cats));
    assert(pos == 5 && dogs == 3 && cats == 0);

    pos = 1;
    assert(countPets("ccccPP", pos, dogs, cats));
    assert(pos == 5 && dogs == 0 && cats == 3);

    cerr << "All tests succeeded!" << endl;
    return 0;
}

bool isValidAnimalParkString(string animalparkString)
{
    int dogs = 0;
    int cats = 0;
    size_t pos = 0;
    char first = animalparkString.at(0);
    bool result = true;

    if (first != 'C' && first != 'c' && first != 'D' && first != 'd')
    {
        return false;
    }
    else if (first == 'C' || first == 'c' || first == 'D' || first == 'd')
    {
        result = countPets(animalparkString, pos, dogs, cats);
    }
    else
    {
        return result;
    }
}

int  dogsLeft(string animalparkString)
{
    if (!isValidAnimalParkString)
    {
        return(-1);
    }
}

int  catsLeft(string animalparkString)
{
    if (!isValidAnimalParkString)
    {
        return(-1);
    }
}

int  peopleLeft(string animalparkString)
{
    if (!isValidAnimalParkString)
    {
        return(-1);
    }
}

// starting with the beginning, count up all the dogs and cats found in the string
// return false if empty or has any letters other than dogs or cats or people

bool countPets(string animalParkString, int dogs, int cats)
{
    bool result = true;
    bool keepGoing = true;
    size_t index = 0;

    if (animalParkString.empty())
    {
        result = false;
    }

    else
    {
        while (index < animalParkString.size() && keepGoing)
        {
            char c = animalParkString.at(index);
            switch (c)
            {
            case 'd':
            case 'D':
                dogs += 1;
                keepGoing = true;
                break;
            case 'c':
            case 'C':
                cats += 1;
                keepGoing = true;
                break;
            case '+':
            case '-':
            case 'p':
            case 'P':
                // stop once you find non-pet characters...
                keepGoing = false;
                break;
            default:
                // stop once you find invalid characters...
                keepGoing = false;
                result = false;
                break;
            }
            index += 1;
        }
    }
    return(result);
}

bool countPets(string animalParkString, size_t& position, int& dogs, int& cats)
{
	bool result = true;
	bool keepGoing = true;

	dogs = 0;
	cats = 0;

	if (animalParkString.empty())
	{
		result = false;
	}

	else
	{
		while (position < animalParkString.size() && keepGoing)
		{
			char c = animalParkString.at(position);
            switch (c)
            {
            case 'd':
            case 'D':
                dogs += 1;
                keepGoing = true;
                break;
            case 'c':
            case 'C':
                cats += 1;
                keepGoing = true;
                break;
            case '+':
            case '-':
            case 'p':
            case 'P':
                // stop once you find non-pet characters...
                keepGoing = false;
                break;
            default:
                // stop once you find invalid characters...
                keepGoing = false;
                result = false;
                break;
            }
			position = position + 1;
		}
	}
	return(result);
}