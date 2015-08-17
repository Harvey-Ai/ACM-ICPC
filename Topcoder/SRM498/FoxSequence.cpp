// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel likes sequences.  One day, she invented a new type of sequence and named it the fox sequence.  A sequence seq containing N elements is called a fox sequence if and only if there exist four integers a, b, c and d such that 0 < a < b <= c < d < N-1 and the following five conditions are met:

seq[0], seq[1], ... , seq[a] forms an arithmetic progression with a positive common difference.  An arithmetic progression is a sequence where the difference between successive elements is equal.  The difference between successive elements is called the common difference.  Note that 0 is neither positive nor negative.
seq[a], seq[a+1], ... , seq[b] forms an arithmetic progression with a negative common difference.
seq[b], seq[b+1], ... , seq[c] are all equal.
seq[c], seq[c+1], ... , seq[d] forms an arithmetic progression with a positive common difference.
seq[d], seq[d+1], ... , seq[N-1] forms an arithmetic progression with a negative common difference.


In the following image, the top 3 sequences are fox sequences, while the bottom 3 sequences are not:



You are given a sequence seq.  Return "YES" if it is a fox sequence, or "NO" if it is not (all quotes for clarity).

DEFINITION
Class:FoxSequence
Method:isValid
Parameters:vector <int>
Returns:string
Method signature:string isValid(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 2,000, inclusive.


EXAMPLES

0)
{1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}


Returns: "YES"

This is the top-left sequence of the image shown in the statement.  The next five examples are also from that image.

1)
{1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}


Returns: "YES"



2)
{3,6,9,1,9,5,1}


Returns: "YES"



3)
{1,2,3,2,1,2,3,2,1,2,3,2,1}


Returns: "NO"



4)
{1,3,4,3,1,1,1,1,3,4,3,1}


Returns: "NO"



5)
{6,1,6}


Returns: "NO"



// END CUT HERE
#line 83 "FoxSequence.cpp"
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
class FoxSequence
{
public:
	string isValid(vector <int> seq)
	{
		int i;
		int dis;
		if (seq.size() < 2)
			return "NO";
		dis = seq[1] - seq[0];
		if (dis <= 0)
			return "NO";
		for(i = 1;i < seq.size();i++)
		{
			if (seq[i] - seq[i - 1] < 0)
			{
				dis = seq[i] - seq[i - 1];
				break;
			}
			else if (seq[i] - seq[i - 1] != dis)
				return "NO";
		}
		if (i == seq.size())
			return "NO";

		for(;i < seq.size();i++)
		{
			if (seq[i] - seq[i - 1] < 0)
			{
				if (seq[i] - seq[i - 1] != dis)
					return "NO";
			}
			else if (seq[i] - seq[i - 1] > 0)
			{
				dis = seq[i] - seq[i - 1];
				break;
			}
			else if (seq[i] - seq[i - 1] == 0)
				dis = 0;
		}

		if (i == seq.size())
			return "NO";

		for(;i < seq.size();i++)
		{
			if (seq[i] - seq[i - 1] >= 0)
			{
				if (seq[i] - seq[i - 1] != dis)
					return "NO";
			}
			else if (seq[i] - seq[i - 1] < 0)
			{
				dis = seq[i] - seq[i - 1];
				break;
			}
		}
		if (i == seq.size())
			return "NO";

		for(;i < seq.size();i++)
			if (seq[i] - seq[i - 1] != dis)
				return "NO";

		return "YES";
	}
};

// BEGIN CUT HERE
int main()
{
FoxSequence ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
