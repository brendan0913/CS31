#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main()
{
	cout.setf(ios::showpoint); // places decimal and two zeroes to make the total resemble a dollar amount
	cout.setf(ios::fixed);
	cout.precision(2);

	string model = "", kind = "", color = "", leather = "", autop = ""; // variables for each vehicle property, autop is autopilot
	int wheel = 0; // wheel size
	double total = 0.0;

	cout << "Which vehicle would you like to order? ";
	getline(cin, model);
	if (model != "3" && model != "S" && model != "X") // error messages for each vehicle property
	{
		cout << "Error - Incorrect model choice." << endl;
		return(-1);
	}

	cout << "Which kind would you like? ";
	getline(cin, kind);
	if (kind != "Performance" && kind != "Long Range")
	{
		cout << "Error - Incorrect kind choice." << endl;
		return(-1);
	}
	
	cout << "What exterior color would you like? ";
	getline(cin, color);
	if (color != "White" && color != "Black" && color != "Blue" && color != "Grey" && color != "Red")
	{
		cout << "Error - Incorrect color choice." << endl;
		return(-1);
	}

	cout << "Which wheels would you like? ";
	cin >> wheel;
	cin.ignore(INT_MAX, '\n');

	if (wheel != 18 && wheel != 19 && wheel != 20 && wheel != 21 && wheel != 22)
	{
		cout << "Error - Incorrect wheel value." << endl;
		return(-1);
	}
	else if (model == "3" && wheel != 18 && wheel != 19)
	{
		cout << "Error - Incorrect wheel value." << endl;
		return(-1);
	}
	else if (model == "S" && wheel != 19 && wheel != 21)
	{
		cout << "Error - Incorrect wheel value." << endl;
		return(-1);
	}
	else if (model == "X" && wheel != 20 && wheel != 22)
	{
		cout << "Error - Incorrect wheel value." << endl;
		return(-1);
	}

	cout << "Want leather interior? ";
	getline(cin, leather);
	if (leather != "Yes" && leather != "No")
	{
		cout << "Error - Incorrect leather choice." << endl;
		return(-1);
	}

	cout << "Want Auto-Pilot? ";
	getline(cin, autop);
	if (autop != "Yes" && autop != "No")
	{
		cout << "Error - Incorrect autopilot choice." << endl;
		return(-1);
	}

	else // accumulates the total if there are no error messages
	{
		if (model == "3") // accumulating the total cost for each property for model 3
		{
			if (kind == "Long Range")
			{
				total += 47990;
			}
			else if (kind == "Performance")
			{
				total += 55990;
			}
			if (color == "Black")
			{
				total += 500;
			}
			else if (color == "Blue" || color == "Grey")
			{
				total += 1000;
			}
			else if (color == "Red")
			{
				total += 1500;
			}
			if (wheel == 19)
			{
				total += 1500;
			}
			if (leather == "Yes")
			{
				total += 1000;
			}
			if (autop == "Yes")
			{
				total += 6000;
			}
		}
		if (model == "S") // accumulating the total cost for each property for model S
		{
			if (kind == "Long Range")
			{
				total += 79990;
			}
			else if (kind == "Performance")
			{
				total += 99990;
			}
			if (color == "Black")
			{
				total += 1000;
			}
			else if (color == "Blue" || color == "Grey")
			{
				total += 1500;
			}
			else if (color == "Red")
			{
				total += 2500;
			}
			if (wheel == 21)
			{
				total += 4500;
			}
			if (leather == "Yes")
			{
				total += 1000;
			}
			if (autop == "Yes")
			{
				total += 6000;
			}
		}
		if (model == "X") // accumulating the total cost for each property for model X
		{
			if (kind == "Long Range")
			{
				total += 84990;
			}
			else if (kind == "Performance")
			{
				total += 104990;
			}
			if (color == "Black")
			{
				total += 1000;
			}
			else if (color == "Blue" || color == "Grey")
			{
				total += 1500;
			}
			else if (color == "Red")
			{
				total += 2500;
			}
			if (wheel == 22)
			{
				total += 5500;
			}
			if (leather == "Yes")
			{
				total += 1000;
			}
			if (autop == "Yes")
			{
				total += 6000;
			}
		}
		cout << "Enjoy your new $" << total << " " << color << " Model " << model << "!" << endl;
		return(0);
	}
}