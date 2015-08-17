// BEGIN CUT HERE
// PROBLEM STATEMENT
// Goose Tattarrattat has a string S of lowercase letters.
A string is called smooth if all its letters are the same.
Tattarrattat wants to change her string into a smooth one.

She will do this in a series of steps.
In each step, Tattarrattat will choose two letters of the alphabet: X and Y.
She will then change each X in her string into an Y.
Changing each single character takes 1 second.

For example, if S="goose" and Tattarrattat chooses X='o' and Y='e' in the next step, the step will take 2 seconds (because there are two 'o's in S) and after the step she would have S="geese".

You are given the string S.
Return the smallest number of seconds in which Tattarrattat can change S into a smooth string.

DEFINITION
Class:GooseTattarrattatDiv2
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"geese"

Returns: 2

There are many ways how Tattarrattat can change this S into a smooth string.
For example, she could do it in two steps as follows:

Change all 'g's to 'e's: this takes 1 second and produces the string "eeese".
Change all 'e's to 's's: this takes 4 seconds and produces the string "sssss".

This way took her 1+4 = 5 seconds.
However, there are faster ways.
The best one only takes 2 seconds.
For example, she can first change all 'g's to 'e's (1 second), and then change all 's's to 'e's (1 second), obtaining the smooth string "eeeee".

1)
"tattarrattat"

Returns: 6



2)
"www"

Returns: 0

This string is already smooth so no changes are needed.

3)
"topcoder"

Returns: 6



4)
"xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"

Returns: 43



// END CUT HERE
#line 78 "GooseTattarrattatDiv2.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class GooseTattarrattatDiv2 {
	public:
	int getmin(string S) {
		
	}
};
