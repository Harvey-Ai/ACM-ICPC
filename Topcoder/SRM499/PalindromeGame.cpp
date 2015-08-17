// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are playing a simple one-player game in which you are given a set of cards. 
Each card has a string written on the front and a number on the back. 
The strings on all the cards have the same length. 
You must choose some of these cards (at least one, possibly all) 
and place them in a row with the front sides visible, 
such that the concatenated string is a palindrome. 
A palindrome is a string that reads the same forward and backward. 
Your score is the sum of the numbers on the back sides of the chosen cards. 


You are given a vector <string> front and a vector <int> back 
describing the set of cards you are given. 
The i-th card has front[i] written on the front and back[i] on the back. 
Return the maximum possible score you can achieve with these cards. 
If it is impossible to compose a palindrome from the given cards, return 0 instead.


DEFINITION
Class:PalindromeGame
Method:getMaximum
Parameters:vector <string>, vector <int>
Returns:int
Method signature:int getMaximum(vector <string> front, vector <int> back)


CONSTRAINTS
-front will contain between 1 and 50 elements, inclusive. 
-Each element of front will contain between 1 and 50 characters, inclusive. 
-Each element of front will contain the same number of characters. 
-Each character in front will be a lowercase letter ('a' - 'z'). 
-front and back will contain the same number of elements. 
-Each element of back will be between 1 and 1,000,000, inclusive. 


EXAMPLES

0)
{ "topcoder", "redcoder", "redocpot" }
{ 7, 5, 3 }

Returns: 10

You?can?choose?"topcoder"?with?7?and?"redocpot"?with?3?to?get?a?palindrome?"topcoderredocpot". 


1)
{ "rabbit" }
{ 1000000 }

Returns: 0

No palindrome can be made. 


2)
{ "abc", "abc", "def", "cba", "fed" }
{ 24, 7, 63, 222, 190 }

Returns: 499

// END CUT HERE
#line 65 "PalindromeGame.cpp"
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
struct card
{
	char str[60];
	int num;
};
int ccmp(const void *a, const void *b)
{
	struct card *aa = (struct card *)a;
	struct card *bb = (struct card *)b;
	return bb->num - aa->num;
}

class PalindromeGame {

	public:
	int getMaximum(vector <string> front, vector <int> back) {
		int i, j, k;
		int len;
		struct card cc[100];
		int flag[100];
		int res;

		len = front[0].size();
		for(i = 0;i < front.size();i++)
		{
			strcpy(cc[i].str, front[i].c_str());
			cc[i].num = back[i];
		}

		qsort(cc, front.size(), sizeof(cc[0]), ccmp);

	//	for(i = 0;i < front.size();i++)
	//		printf("%s %d\n", cc[i].str, cc[i].num);

		res = 0;
		memset(flag, 0, sizeof(flag));
		for(i = 0;i < front.size();i++)
		{
			if (flag[i])
				continue;
			for(j = 0;j < front.size();j++)
			{
				if (flag[j] || i == j)
					continue;
				for(k = 0;k < len;k++)
					if (cc[i].str[k] != cc[j].str[len - k - 1])
						break;
				if (k >= len)
				{
					res += cc[i].num + cc[j].num;
					flag[i] = flag[j] = 1;
					break;
			//		printf("%d %d %d\n", i, j, res);
				}
			}
		}

	//	printf("ccc%d\n", res);
		for(i = 0;i < front.size();i++)
		{
			if (flag[i])
				continue;
			for(k = 0;k < len / 2;k++)
				if (cc[i].str[k] != cc[i].str[len - 1 - k])
					break;

			if (k >= len / 2)
			{
				res += cc[i].num;
				break;
			}
		}
		return res;
	}
};
// BEGIN CUT HERE
int main()
{
PalindromeGame ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
