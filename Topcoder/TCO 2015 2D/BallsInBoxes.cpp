/*
PROBLEM STATEMENT
There are N boxes arranged in a row. The boxes are numbered 0 through N-1 from left to right.


Cat Snuke knows that exactly K consecutive boxes contain balls. Formally, there exists some i (0 <= i <= N-K)
such that the boxes i, i+1, ..., i+K-1 contain balls while all others are empty.


He wants to determine which boxes contain balls. In each turn, he can choose a box, open it and check whether the box contains a ball or not. Note that the result of each turn may affect his future decisions about which boxes to open in the next turns.


How many turns are required to determine the positions of the balls in the worst case, assuming that Snuke uses the optimal strategy?


DEFINITION
Class:BallsInBoxes
Method:maxTurns
Parameters:long long, long long
Returns:long long
Method signature:long long maxTurns(long long N, long long K)


CONSTRAINTS
-N will be between 1 and 10^18, inclusive.
-K will be between 1 and N, inculsive.


EXAMPLES

0)
10
10

Returns: 0

Snuke knows that all boxes contain balls, so he doesn't need to open any boxes.

1)
100
1

Returns: 99

In the worst case, if he opens 98 boxes and none of them contains the only ball, he can't determine which box contains the ball.

2)
1000
999

Returns: 1

There are two possibilities:

Boxes 0, 1, ..., 998 contain balls.
Boxes 1, 2, ..., 999 contain balls.

He can determine the positions of the balls if he opens box 0.


3)
10
5

Returns: 3



*/

#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

class BallsInBoxes {
	public:
	long long maxTurns(long long N, long long K) {
		if (N <= K) {
			return 0;
		}

		N -= K;
		long long left = N - max((N + K - 1) / K - 2, 0LL) * K;
		long long res = max((N + K - 1) / K - 2, 0LL);

		while(left > 0) {
			left /= 2;
			res++;
		}

		return res;
	}
};
