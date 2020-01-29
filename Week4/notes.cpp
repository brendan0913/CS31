overloaded functions
// multiple functions can have same name
// the number or type of arguments in the parameter list must differ

default valued arguments
can have optional arguments, they are defined but do not need to be passed by the caller

void showVolume(int length, int width = 1, int height = 1); // default values in declared function

void showVolume(int length, int width, int height) // the default values is 1, the only required argument is length, if the other two are not passed, then
	// they will be 1, must put the default aruments at the end of the parameter list

// read only argument
void foo(const int& i) //(const and &)
//inside function, i is marked read only and cannot be changed no matter what

string s = "a string of letters";
.at(int) or []
set of other kinds of data, an array with size, must be known in advcance, must be fixed constant quality
int grades[400]
// elements grades[0]
grades[1]
...
grades[399]

cant just put grades[size]
access each element in the array, cannot use .at or .size on arrays