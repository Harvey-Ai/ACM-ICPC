// BEGIN CUT HERE
// PROBLEM STATEMENT
// Let A be a sequence of integers.
The LISNumber of A is the smallest positive integer L such that A can be obtained by concatenating L strictly increasing sequences.
For example, the LISNumber of A = {1, 4, 4, 2, 6, 3} is 4, since we can obtain A as {1, 4} + {4} + {2, 6} + {3}, and there is no way to create A by concatenating 3 (or fewer) strictly increasing sequences.
The LISNumber of a strictly increasing sequence is 1.

You have N types of cards.
For each i, 0 <= i < N, you have cardsnum[i] cards of the i-th type.
Each card of the i-th type contains the number i.

You are given the vector <int> cardsnum and an int K.
You want to arrange all the cards you have into a row in such a way that the resulting sequence of integers has LISNumber K.
Note that you must use all the cards you have, you can only choose their order.

Let X be the number of different valid sequences you can produce.
Compute and return the number X, modulo 1,000,000,007.

DEFINITION
Class:LISNumber
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> cardsnum, int K)


CONSTRAINTS
-cardsnum will contain between 1 and 36 elements, inclusive.
-Each element of cardsnum will be between 1 and 36, inclusive.
-K will be between 1 and 1296, inclusive.


EXAMPLES

0)
{1, 1, 1}
2

Returns: 4

In this case, there are 3 types of cards and you have one of each. Among the 6 sequences you can make, the following 4 have LISNumber 2:

{0, 2, 1}
{1, 0, 2}
{1, 2, 0}
{2, 0, 1}



1)
{2}
1

Returns: 0

The only sequence you can make is {0, 0} and its LISNumber is 2.

2)
{36, 36, 36, 36, 36}
36

Returns: 1

Only the sequence {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, ... (36 times) ... } has LISNumber 36.

3)
{3, 2, 11, 5, 7}
20

Returns: 474640725



4)
{31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26}
58

Returns: 12133719



5)
{27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5,
 36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7,
 7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9}
116

Returns: 516440918



// END CUT HERE
#line 94 "LISNumber.cpp"
#include <string>
#include <vector>
class LISNumber {
	public:
	int count(vector <int> cardsnum, int K) {
		
	}
};
