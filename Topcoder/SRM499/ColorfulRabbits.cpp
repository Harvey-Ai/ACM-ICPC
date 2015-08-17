// BEGIN CUT HERE
// PROBLEM STATEMENT
// Cat Pochi visited a town of rabbits and asked some of the rabbits the following question: 
"How many rabbits in this town other than yourself have the same color as you?". 
The rabbits all replied truthfully, and no rabbit was asked the question more than once. 
You are given the rabbits' replies in the vector <int> replies. 
Return the minimum possible number of rabbits in this town. 


DEFINITION
Class:ColorfulRabbits
Method:getMinimum
Parameters:vector <int>
Returns:int
Method signature:int getMinimum(vector <int> replies)


CONSTRAINTS
-replies will contain between 1 and 50 elements, inclusive. 
-Each element of replies will be between 0 and 1,000,000, inclusive. 


EXAMPLES

0)
{ 1, 1, 2, 2 }


Returns: 5

If there are 2 rabbits with a color and 3 rabbits with another color, 
Pochi can get this set of replies. 




1)
{ 0 }


Returns: 1

A poor lonely rabbit. 


2)
{ 2, 2, 44, 2, 2, 2, 444, 2, 2 }


Returns: 499



// END CUT HERE
#line 56 "ColorfulRabbits.cpp"
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
class ColorfulRabbits {
	public:
	int getMinimum(vector <int> replies) {
		
			int i, j;
			int other;
			int res = 0;
			for(i = 0;i < replies.size();i++)
			{
				if (replies[i] < 0)
					continue;
				res += replies[i] + 1;
				other = replies[i];
				for(j = i + 1;j < replies.size();j++)
					if (replies[i] == replies[j] &&  other > 0)
					{
						replies[j] = -1;
						other--;
					}
				replies[i] = -1;
			}
			return res;
	}
};
// BEGIN CUT HERE
int main()
{
ColorfulRabbits ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
