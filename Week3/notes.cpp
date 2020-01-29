
#include <iostream>
#include <string>

strings
loop letter by letter
.length().size()
.at(positionalValue)---- > single char
[positionValue] is the same thing

use period for strings to access its position, length, etc.

the size of the string can never be negative

size_t(sizetype) 0 ---- -

size_t sizeOfS = s.size();

for (size_t i = 0; i < sizeOfS; i++)
{
	char c = s.at(i); //walks a string letter by letter
}

to make functions
#include <cmath> // gets sqrt, log, floor, ceil, abs, pow
create the function

// 1. declare the function outside of main, what it returns, put the required arguments in here
int foo();
double bar(int i);

int main()
{
	double d, e;
	cin >> d;
	e = sqrt(d);

	// 3. call the function
	int i = foo();
	cout << i << endl;
	return 0;
}

// 2. below main function, implement what the function does
int foo() // no semi colon
{
	// implement how the function does its work
	double d;
	cin >> d;
	d = sqrt(d);
}

void is nothing

void prompt(string&vehicleModel) // prompt, given a string, returns nothing
// pass by values involves copies
{

}

// pass by reference, use & to have no copy
// difference between string and string &
// reference to a string

// really strict, must be a declared int & or string &

acceptInt(int & i);
only takes acceptInt(i)