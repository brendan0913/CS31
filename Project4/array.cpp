#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMaximum(const string array[], int n);
bool hasDuplicates(const string array[], int  n);
int countSs(const string array[], int n);
int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties);
bool isInDecreasingOrder(const string array[], int  n);
bool matchingValuesTogether(const string array[], int n);
int divide(string array[], int n, string divider);

int main()
{
	string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
	string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	string morepeople[6] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "tyrion" };
	string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "howard123", "jon" };
	string numbers[5] = { "5", "4", "3", "2", "15" };
	string alsonumbers[5] = { "2", "2", "3", "4", "5" };

	// locate maximum
	assert(locateMaximum(people, 5) == 4);
	assert(locateMaximum(morepeople, 6) == 4);

	// has duplicates
	assert(hasDuplicates(a, 3) == false);
	assert(hasDuplicates(a, 6) == true);
	assert(hasDuplicates(people, 5) == false);
	assert(hasDuplicates(people, 0) == false);
	assert(hasDuplicates(folks, 8) == true);
	assert(hasDuplicates(folks, 5) == false);

	// countSs
	assert(countSs(people, 5) == 2);

	// is in decreasing order
	assert(isInDecreasingOrder(people, 5) == false);
	assert(isInDecreasingOrder(people, 2) == true);

	// matching values together
	assert(matchingValuesTogether(people, 5) == true);
	assert(matchingValuesTogether(folks, 8) == false);

	// shift left
	assert(shiftLeft(people, 5, 3, "foo") == 3);

	shiftLeft(folks, 8, 3, "foo");
	cerr << folks[0] << folks[1] << folks[2] << folks[3] << folks[4] << folks[5] << folks[6] << folks[7] << endl;
	shiftLeft(people, 5, 3, "foo");
	cerr << people[0] << people[1] << people[2] << people[3] << people[4] << endl;

	// divide
	assert(divide(numbers, 5, "21") == 2);
	assert(divide(alsonumbers, -1, "0")==0);
	assert(divide(numbers, 5, "0") == 0);

	cerr << "All tests succeeded!" << endl;
	return(0);
}

// Return the index of the largest item found in the array or -1 if n <= 0. 
int locateMaximum(const string array[], int n)
{
	if (n <= 0)
	{
		return -1;
	}
	else
	{
		string max = array[0];
		int iOfMax = 0;
		for (int i = 0; i < n; i++)
		{
			if (array[i] > max)
			{
				max = array[i];
				iOfMax = i;
			}
		}
		return iOfMax;
	}
}

// If there is a value that is repeatedly found in the array, return true otherwise false or if n <= 0 return false. 
bool hasDuplicates(const string array[], int  n)
{
	if (n <= 0)
	{
		return false;
	}
	else
	{
		bool result = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				if (array[i] == array[j])
				{
					result = true;
				}
			}
		}
		return result;
	}
}

// Return the number of  's' or 'S' characters found inside each of the elements of the passed array or if n <= 0 return -1.
int countSs(const string array[], int n)
{
	if (n <= 0)
	{
		return -1;
	}
	else
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (size_t j = 0; j < array[i].length(); j++)
			{
				if (array[i][j] == 's' || array[i][j] == 'S')
				{
					count++;
				}
			}
		}
		return count;
	}
}

// Adjust the items found in the array, shifting each value to the left by amount parameter, filling the resulting first amount elements of the array 
// with the placeholder parameter and returning the number of times the placeholder value has been used after all the shifting has been performed
int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties)
{
	if (n <= 0 || amount <= 0) // declares an array of size 0 or smaller, no array exists; or no shifts at all, the original array remains as is
	{
		return 0;
	}
	else if (amount >= n) // more shifts than there are places in the array, so the entire array gets changed to the placeholder, the size of the array is returned
	{
		for (int i = 0; i < n; i++)
		{
			array[i] = placeholderToFillEmpties;
		}
		return n;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{  
			array[i] = array[(i+amount)%n];
		}
		/*int temp = 0;
		temp = amount;
		for (int i = 0; i < amount; i++)
		{
			array[temp-1]
		}*/

	}
	return amount;
}

// If every value in the array is smaller than the one that precedes it, return true otherwise false or if n <= 0 return false
bool isInDecreasingOrder(const string array[], int  n)
{
	if (n <= 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < n-1; i++)
		{
			if (array[i] <= array[i + 1])
			{
				return false;
			}
		}
		return true;
	}
}

//If all the duplicated values found in the array are located one right after the other, return true otherwise false.  
//If you don't find any duplicated values at all, then return true since you never found any values violating this together principle.  If n <=0, return false. 
bool matchingValuesTogether(const string array[], int n)
{
	if (n <= 0)
	{
		return false;
	}
	else if (hasDuplicates(array, n) == false)
	{
		return true;
	}
	else
	{
		bool result = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (array[i] == array[i + 1])
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
		return result;
	}
}

// Rearrange the elements of the array so that all the elements whose value is < divider come before all the other elements, 
// and all the elements whose value is > divider come after all the other elements.  (Yes, there might be numerous correct rearrangements that are valid.)
// Return the position of the first element that, after the rearrangement, is not < divider, or 0 if there are none. 
int divide(string array[], int n, string divider)
{
	if (n <= 0)
	{
		return 0;
	}
	bool keepGoing = true;
	for (int i = 0; i < n && keepGoing==true; i++)
	{
		if (array[i] < divider) // if all indices are above or equal to the divider, then the first index that is not below the divider is 0
		{
			keepGoing = false;
		}
	}
	if (keepGoing == true)
	{
		return 0;
	}
	bool continuing = true;
	for (int i = 0; i < n && continuing == true; i++)
	{
		if (array[i] >= divider) // if all indices are below the divider, then there are no indices that are not < divider, so it returns 0
		{
			continuing = false;
		}
	}
	if (continuing == true)
	{
		return 0;
	}
	else
	{
		int i = 0;
		string temp = "";
		int result = 0;
		while (i < n)
		{
			for (int j = 0; j < n; j++)
			{
				if (array[i] < array[j])
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
			i++;
		}
		int divValue = 0;
		bool keepGoing = true;
		for (int k = 0; k < n && keepGoing == true; k++)
		{
			if (!(array[k] < divider))
			{
				divValue = k;
				keepGoing = false;
			}
		}
		return divValue;
	}
}