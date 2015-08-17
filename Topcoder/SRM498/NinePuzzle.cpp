// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel invented a game called Nine Puzzle.  The game is played on a board which is in the form of a regular triangle with side length 4.  There are 10 cells on the board, each in the form of a regular triangle with side length 1.  The cells are numbered 0 to 9 as shown in the picture below:



Nine of the cells on the board contain a triangular piece.  Each piece is painted red, green, blue or yellow.  The remaining tenth cell is empty.  The goal of the game is to arrange the cells to match a specified goal pattern.  To do this, the player can perform the following move any number of times: Choose a piece which is adjacent to an empty cell, and move the piece into that empty cell.  Two cells are considered adjacent if the distance between their centers is exactly 1.  An example of a valid move is shown in the following picture:



Ciel has painted the triangular pieces to form the starting pattern for the puzzle.  She has also chosen the goal pattern.  However, she has chosen both these patterns arbitrarily, so it's possible that the puzzle might not be solvable (i.e., it may be impossible to achieve the goal pattern from the given starting pattern using a sequence of valid moves).  If this is the case, she would like to repaint the minimum possible number of pieces in the starting pattern to make the puzzle solvable.

You are given two strings init and goal.  The i-th (0-indexed) character of init describes the content of the i-th cell in the starting pattern.  The '*' character denotes an empty cell.  'R', 'G', 'B' and 'Y' denote pieces which are colored red, green, blue and yellow, respectively.  The goal pattern is described in the string goal in the same format.

Return the minimum number of pieces which must be repainted in the starting pattern to make the puzzle solvable.  If the puzzle is already solvable without repainting, return 0.


DEFINITION
Class:NinePuzzle
Method:getMinimumCost
Parameters:string, string
Returns:int
Method signature:int getMinimumCost(string init, string goal)


CONSTRAINTS
-init and goal will each contain exactly 10 characters.
-Each character of init and goal will be one of 'R', 'G', 'B', 'Y' or '*'.
-init and goal will each contain exactly one '*' character.


EXAMPLES

0)
"BG*YRGRRYR" 
"BGGY*YRRRR" 

Returns: 0

No repainting is required because Ciel can achieve the goal pattern from the starting pattern in 3 moves:



1)
"GBBB*BGBBG" 
"RYYY*YRYYR"

Returns: 9

Ciel incautiously chose the starting pattern and the goal pattern, so unfortunately, she must repaint all the pieces.

2)
"RRBR*BRBBB" 
"BBRB*RBRRR" 

Returns: 1



// END CUT HERE
#line 62 "NinePuzzle.cpp"
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
class NinePuzzle {
	public:
	int getMinimumCost(string init, string goal) {
		
	}
};
// BEGIN CUT HERE
int main()
{
NinePuzzle ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
