// BEGIN CUT HERE
// PROBLEM STATEMENT
// For an integer n, let F(n) = (n - 0^2) * (n - 1^2) * (n - 2^2) * (n - 3^2) * ... * (n - k^2), where k is the largest integer such that n - k^2 > 0.
You are given three long longs lo, hi and divisor.
It is guaranteed that divisor will be a prime number.
Compute and return the number of integers n between lo and hi, inclusive, such that F(n) is divisible by divisor.

DEFINITION
Class:SparseFactorialDiv2
Method:getCount
Parameters:long long, long long, long long
Returns:long long
Method signature:long long getCount(long long lo, long long hi, long long divisor)


CONSTRAINTS
-lo will be between 1 and 1,000,000,000,000, inclusive.
-hi will be between lo and 1,000,000,000,000, inclusive.
-divisor will be between 2 and 997, inclusive.
-divisor will be a prime number.


EXAMPLES

0)
4
8
3

Returns: 3

The value of F(n) for each n = 4, 5, ..., 8 is as follows. 

F(4) = 4*3   = 12
F(5) = 5*4*1 = 20
F(6) = 6*5*2 = 60
F(7) = 7*6*3 = 126
F(8) = 8*7*4 = 224

Thus, F(4), F(6), F(7) are divisible by 3 but F(5) and F(8) are not.

1)
9
11
7

Returns: 1


F(9)  = 9*8*5     = 360
F(10) = 10*9*6*1  = 540
F(11) = 11*10*7*2 = 1540

Only F(11) is divisible by 7.

2)
1
1000000000000
2

Returns: 999999999999

Watch out for the overflow. 

3)
16
26
11

Returns: 4



4)
10000
20000
997

Returns: 1211



5)
123456789
987654321
71

Returns: 438184668



// END CUT HERE
#line 94 "SparseFactorialDiv2.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class SparseFactorialDiv2 {
	public:
	long long getCount(long long lo, long long hi, long long divisor) {
		
	}
};
