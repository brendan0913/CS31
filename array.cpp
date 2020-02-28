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
	string numbers2[5] = { "5", "4", "3", "2", "15" };
	string alsonumbers[5] = { "2", "2", "3", "4", "5" };
	string numbs[6] = { "2", "2", "5", "5", "2", "0" };
	string nums[5] = { "20", "2", "3", "4", "35" };
	string electrons[5] = { "2s", "2s5", "3s", "4s", "2s" };
	string cons2[5] = { "1", "2", "2", "2", "5" };
	string letters[7] = { "a", "b", "c", "d", "e", "f", "g" };
	string reverseletters[3] = { "c", "b", "a" };
	string notcons2[6] = { "1", "2", "2", "2", "5" , "2" };
	string decNumbers[5] = { "5", "4", "3", "2", "1" };
	string decNumbers2[5] = { "5", "4", "3", "2", "1" };

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
	assert(hasDuplicates(morepeople, 5) == false);

	// countSs
	assert(countSs(people, 5) == 2);
	assert(countSs(electrons, 5) == 5);
	assert(countSs(cons2, 5) == 0);
	assert(countSs(electrons, 3) == 3);

	// is in decreasing order
	assert(isInDecreasingOrder(people, 5) == false);
	assert(isInDecreasingOrder(people, 2) == true);
	assert(isInDecreasingOrder(letters, 7) == false);
	assert(isInDecreasingOrder(reverseletters, 3) == true);
	assert(isInDecreasingOrder(a, 6) == false);

	// matching values together
	assert(matchingValuesTogether(people, 5) == true);
	assert(matchingValuesTogether(folks, 8) == false);
	assert(matchingValuesTogether(numbs, 6) == false);
	assert(matchingValuesTogether(electrons, 5) == false);
	assert(matchingValuesTogether(cons2, 5) == true);
	assert(matchingValuesTogether(notcons2, 6) == false);
	assert(matchingValuesTogether(notcons2, 5) == true);

	// shift left
	assert(shiftLeft(people, 5, 3, "foo") == 3);
	assert(shiftLeft(nums, 5, 2, "X") == 2);
	assert(shiftLeft(folks, 8, 7, "Z") == 7);
	assert(shiftLeft(folks, 8, 10, "beep") == 8);
	assert(shiftLeft(folks, 8, 3, "x") == 3);
	assert(shiftLeft(letters, 5, 3, "x") == 3);
	assert(shiftLeft(letters, 5, 0, "x") == 0);

	// divide
	assert(divide(numbers, 5, "21") == 2);
	assert(divide(alsonumbers, -1, "0")==0);
	assert(divide(numbers2, 5, "0") == 0);
	assert(divide(decNumbers, 5, "6") == 0);
	assert(divide(decNumbers2, 5, "2") == 1);

	cerr << "All tests succeeded!" << endl;
	return(0);
}

// Return the index of the largest item found in the array or -1 if n <= 0. 
int locateMaximum(const string array[], int n)
{
	if (n <= 0) // if the array is size less than 0, the array doesn't exist, return -1
	{
		return -1;
	}
	else
	{
		string max = array[0]; // initialize the max string to the first string in the array
		int iOfMax = 0; // variable to find the index of the largest string
		for (int i = 0; i < n; i++)
		{
			if (array[i] > max)
			{
				max = array[i]; // if the string the loop is checking is larger than the previous max, the max value is updated
				iOfMax = i; // and so is the index
			}
		}
		return iOfMax;
	}
}

// If there is a value that is repeatedly found in the array, return true otherwise false or if n <= 0 return false. 
bool hasDuplicates(const string array[], int  n)
{
	if (n <= 0) // if the array is size smaller than 0, it doesn't exist
	{
		return false;
	}
	else
	{
		bool result = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++) // comparing the elements of the array to themselves (without comparing a element to itself)
			{
				if (array[i] == array[j]) // if elements are equal (without checking the position with itself)
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
			for (size_t j = 0; j < array[i].length(); j++) // checking each string itself, not just the index of the array
			{
				if (array[i][j] == 's' || array[i][j] == 'S') // going into each index of the array, then each index of the string
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
	else if (amount >= n) // there are more shifts than there are places in the array, so the entire array gets changed to the placeholder, the size of the array is returned
	{
		for (int i = 0; i < n; i++)
		{
			array[i] = placeholderToFillEmpties;
		}
		return n;
	}
	else
	{
		int temp = 0;
		temp = amount;
		for (int i = 0; i < n - amount; i++) // n-amount focuses on the elements of the array that will not be updated to the placeholder
		{
			array[i] = array[temp]; // shifts the array left by making the element equal to the element of the amount, then moves onto the next position until the
			// one that will be the placeholder
			temp++;
		}
		for (int i = n-amount; i < n; i++) // starts at the position that will be the placeholder (the one that the last loop stopped at, goes until the end of the array)
		{  
			array[i] = placeholderToFillEmpties; // updates the remaining elements to the placeholder
		}
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
			if (array[i] <= array[i + 1]) // if the next element is greater than or equal to the previous one, then the array is not in strictly decreasing order
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
	else if (hasDuplicates(array, n) == false) // if the string has no duplicates, then there are no matching values, so the functions returns true
	{
		return true;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int maxIndex = -1;
			for (int j = 0; j < i; j++) // looks at subarrays 
			{
				if (array[i] == array[j]) // if there are two equal elements, the greatest index is updated to the equal element's index
				{
					maxIndex = j;
				}
			}
			if (!(maxIndex == -1 || maxIndex == i - 1)) // if the greatest index is not -1 and not the last element in the subarray, then the equal elements are not consectuive
			{
				return false;
			}
		}
		return true;
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
	else
	{
		int i = 0;
		string temp = "";
		while (i < n)
		{
			for (int j = 0; j < n; j++)
			{
				if (array[i] < array[j]) // sorts the array from smallest to greatest element
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
			if (!(array[k] < divider)) // if the position's string is not less than the divider, the value gets updated to that index, and is reutrned since the loop is broken
			{
				divValue = k;	// if they are all below the divider, then the divValue is never updated, so it is 0
				keepGoing = false; // if they are all equal to or above the divider, the first element that is not less than the divider is at i = 0
			}
		}
		return divValue;
	}
}