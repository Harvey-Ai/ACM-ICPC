// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel is playing a game called Addition Game.

Three numbers A, B and C are written on a blackboard, and Ciel initially has 0 points. She repeats the following operation exactly N times: She chooses one of the three numbers on the blackboard. Let X be the chosen number. She gains X points, and if X >= 1, the number X on the blackboard becomes X-1. Otherwise, the number does not change.

Return the maximum number of points she can gain if she plays optimally.


DEFINITION
Class:AdditionGame
Method:getMaximumPoints
Parameters:int, int, int, int
Returns:int
Method signature:int getMaximumPoints(int A, int B, int C, int N)


CONSTRAINTS
-A, B and C will each be between 1 and 50, inclusive.
-N will be between 1 and 150, inclusive.


EXAMPLES

0)
3
4
5
3

Returns: 13

The three numbers written on the blackboard are (3, 4, 5).  One possible optimal strategy is as follows:

Ciel chooses 5.  She gains 5 points, and the numbers become (3, 4, 4).
Ciel chooses 4.  She gains 4 points, and the numbers become (3, 3, 4).
Ciel chooses 4.  She gains 4 points, and the numbers become (3, 3, 3).

She gains a total of 5+4+4=13 points.


1)
1
1
1
8

Returns: 3

One optimal strategy is to choose a 1 in each of the first three turns, for a total of 3 points.  The numbers then become (0, 0, 0).  After that, she won't be able to gain any more points.


2)
3
5
48
40

Returns: 1140

The only optimal strategy is to choose the following numbers: 48, 47, 46, ..., 11, 10, 9.


3)
36
36
36
13

Returns: 446



4)
8
2
6
13

Returns: 57



// END CUT HERE
#line 86 "AdditionGame.cpp"
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
class AdditionGame {
	public:
	int getMaximumPoints(int A, int B, int C, int N) {
		
	}
};
// BEGIN CUT HERE
int main()
{
AdditionGame ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
