// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Alice is a high school student.
One day, her teacher asked her to draw a simple polygon (see Notes for a definition).
The polygon must satisfy two conditions:

First, each of its vertices must be at a grid point.
(I.e., both coordinates of each vertex must be integers.)

Second, the perimeter of the polygon must be exactly equal to the integer L.

You are given the int L.
If there is no such polygon, return -1.
If there is at least one such polygon, find the one which has the least number of sides. If there are still more than one choice, find the one with the smallest possible difference between the lengths of its longest side and its shortest side. Return the difference between the lengths of its longest side and its shortest side.

DEFINITION
Class:FindPolygons
Method:minimumPolygon
Parameters:int
Returns:double
Method signature:double minimumPolygon(int L)


NOTES
-A simple polygon is a polygon such that no two consecutive sides are parallel and no two non-consecutive sides share a common point.
-Return values with absolute or relative error at most 1e-9 will be accepted as correct. 


CONSTRAINTS
-L will be between 1 and 5000, inclusive.


EXAMPLES

0)
4

Returns: 0.0

There is no triangle whose perimeter is 4, but there is a square.

1)
5

Returns: -1.0

There is no simple polygon that matches all the constraints.

2)
12

Returns: 2.0

There is a triangle whose sides are 3, 4, 5.

3)
4984

Returns: 819.0



// END CUT HERE
#line 66 "FindPolygons.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class FindPolygons {
	public:
	double minimumPolygon(int L) {
		
	}
};
