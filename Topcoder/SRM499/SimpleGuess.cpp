// BEGIN CUT HERE
// PROBLEM STATEMENT
// A cat and a rabbit are playing a simple number guessing game. 
The cat chose two different positive integers X and Y. 
He then told the rabbit several numbers. 
One of those numbers was X + Y and another was X - Y. 
The others were simply made up.


The rabbit thinks the cat prefers large numbers. 
Given a vector <int> hints containing the numbers the cat told the rabbit, 
return the largest possible value of X * Y. 


DEFINITION
Class:SimpleGuess
Method:getMaximum
Parameters:vector <int>
Returns:int
Method signature:int getMaximum(vector <int> hints)


CONSTRAINTS
-hints will contain between 2 and 50 elements, inclusive.  
-Each element of hints will be between 1 and 100, inclusive. 
-All elements of hints will be distinct. 
-There will exist at least one pair of positive integers (X, Y) such that both X + Y and X - Y are elements of hints.


EXAMPLES

0)
{ 1, 4, 5 }

Returns: 6

The?rabbit?can?determine?that?(X,?Y)?=?(3,?2).

1)
{ 1, 4, 5, 8 }

Returns: 12

Possible pairs (X, Y) are (3, 2) and (6, 2). 
The values of X * Y are 6 and 12, respectively, and the largest is 12. 


2)
{ 9, 8, 7, 6, 5, 4, 3, 2, 1 }

Returns: 20

3)
{ 2, 100 }

Returns: 2499

4)
{ 50, 58, 47, 57, 40 }

Returns: 441

// END CUT HERE
#line 65 "SimpleGuess.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
class SimpleGuess {
	public:
	int getMaximum(vector <int> hints) {
		int i, j;
		int x, y;
		int max = 0;
		for(i = 0;i < hints.size();i++)
			for(j = 0;j < hints.size();j++)
			{
				if (i == j)
					continue;
				x = (hints[i] + hints[j] ) / 2;
				y = (hints[i] - hints[j] ) / 2;
				if (x + y != hints[i] || x - y != hints[j])
					continue;
				if (x > 0 && y > 0 && x * y > max)
					max = x * y;
			}
		return max;
	}
};
// BEGIN CUT HERE
int main()
{
SimpleGuess ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
