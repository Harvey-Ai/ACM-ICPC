// BEGIN CUT HERE
// PROBLEM STATEMENT
// Dmitry likes TopCoder Single Round Matches. Once, he registered for an SRM and was waiting for the coding phase to begin. To entertain himself while waiting, he decided to play the following game.

He makes a pile of cards, and on each card, he writes the number of an SRM in which he has competed.  No two cards contain the same number.  He then takes turns until the pile is empty.  Each turn consists of the following sequence of actions:

Dmitry chooses an arbitrary card from the pile. Let A be the number written on this card.
The card with number A is removed from the pile.
If the pile contains a card with number A-1, that card is removed from the pile.
If the pile contains a card with number A+1, that card is removed from the pile.

The game is finished when the pile becomes empty. It's fun to play the game, so Dmitry wants to spend as much time as possible playing it.

You are given a vector <int> cards containing the numbers written on the cards in the pile before the start of the game. Return the largest possible number of turns in which Dmitry can finish the game.

DEFINITION
Class:SRMCards
Method:maxTurns
Parameters:vector <int>
Returns:int
Method signature:int maxTurns(vector <int> cards)


CONSTRAINTS
-cards will contain between 1 and 50 elements, inclusive.
-Each element of cards will be between 1 and 499, inclusive.
-All elements of cards will be distinct.


EXAMPLES

0)
{498, 499}

Returns: 1

In the first turn, Dmitry can choose A = 498 or A = 499. In any of these cases both cards will be removed from the pile and the game will be finished.

1)
{491, 492, 495, 497, 498, 499}

Returns: 4

One out of many possible ways to spend 4 turns playing this game is to choose the following numbers in each turn: 497, 499, 495, 492.

2)
{100, 200, 300, 400}

Returns: 4



3)
{11, 12, 102, 13, 100, 101, 99, 9, 8, 1}

Returns: 6

Note that the elements of cards are not necessarily sorted in ascending order.

4)
{118, 321, 322, 119, 120, 320}

Returns: 4

5)
{10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9}

Returns: 7



// END CUT HERE
#line 74 "SRMCards.cpp"
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
class SRMCards {
	public:
	int maxTurns(vector <int> cards) {
		int n;
		int i;
		int time;
		int ph, pr, op;
		int temp, max;
		int arr[100];
	
		for(i = 0;i < cards.size();i++)
			arr[i] = cards[i];

		n = cards.size();
		sort(&arr[0], &arr[n]);

		ph = 0;pr = n - 1;
		time = 0;

		while(ph <= pr)
		{
			op = 1;
			max = 1;
			if (ph + 1 <= pr && arr[ph + 1] == arr[ph] + 1)
				max = 2;

			if (pr - 1 >= ph && arr[pr - 1] == arr[pr] - 1)
				temp = 2;
			else
				temp = 1;
			if (temp < max)
			{
				op = 2;
				max = 1;
			}
			if (op == 1)
				ph += max;
			else
				pr -= max;
			time++;
		}
		return time;
	}
};
// BEGIN CUT HERE
int main()
{
SRMCards ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
