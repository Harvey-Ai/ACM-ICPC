// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Little Elephant from the Zoo of Lviv has a set S. The set S contains the integers 1, 2, 3, ..., N. He considers some non-empty subset of S cool if we can write down all elements of the subset by using each of the digits 0-9 at most once.




Examples:
The subsets {12,345,67890} and {47,109} are cool.
The subset {147,342} is not cool because the digit 4 is used twice.
The subset {404} is not cool for the same reason.




You are given the int N. Let X be the total number of non-empty cool subsets of S. Return the value (X modulo 1,000,000,007).


DEFINITION
Class:LittleElephantAndSubset
Method:getNumber
Parameters:int
Returns:int
Method signature:int getNumber(int N)


CONSTRAINTS
-N will be between 1 and 1,000,000,000 (10^9), inclusive.


EXAMPLES

0)
3

Returns: 7

All 7 non-empty subsets are cool in this case:


{1, 2, 3}


{1, 2}


{1, 3}


{2, 3}


{1}


{2}


{3}



1)
10

Returns: 767

In this case, the total number of non-empty subsets is 2^10-1 = 1023. The only not cool subsets are those that contain both 1 and 10. There are 2^8 = 256 of them. Thus, the answer is 1023-256 = 767.

2)
47

Returns: 25775



3)
4777447

Returns: 66437071



// END CUT HERE
#line 87 "LittleElephantAndSubset.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class LittleElephantAndSubset {
	public:
	int getNumber(int N) {
		
	}
};
