// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Shiny wants to hire some managers for her company.
There are N candidates, numbered 0 through N-1.
She can employ any subset of these candidates, including possibly none or all of them.

For each of the candidates we know an amount in dollars Shiny must pay if she wants to hire that candidate.
You are given a vector <int> value with N elements.
For each i, value[i] is the amount in dollars Shiny has to pay if she wants to hire candidate i.

For each pair i < j of candidates we also know a value E(i,j) with the following meaning:

If both i and j are employed, the company will earn E(i,j) dollars.
However, if neither i nor j are employed, they will cooperate to harm the company, which will cost the company E(i,j) dollars.

If one of them is employed and the other isn't, nothing happens.
All the values E(i,j) are between 0 and 9, inclusive.

For your convenience, we also define E(i,i)=0 and E(j,i)=E(i,j) for all i and j.

You are given the above values E(i,j) encoded as a vector <string> earning with N elements, each consisting of N characters.
For each i and j, earning[i][j] is the character ('0'-'9') that represents the value E(i,j).

You are given the vector <int> value and the vector <string> earning.
Compute and return the largest total profit (i.e., earnings minus costs) the company can obtain by hiring a suitable subset of candidates.



DEFINITION
Class:EmployManager
Method:maximumEarnings
Parameters:vector <int>, vector <string>
Returns:int
Method signature:int maximumEarnings(vector <int> value, vector <string> earning)


CONSTRAINTS
-value will contain between 1 and 50 elements, inclusive.
-earning will contain the same number of elements as value.
-The length of each element of earning will be the same as the number of elements in value.
-Each character in each element of earning will be a digit ('0'-'9').
-Each element of value will be between 0 and 1000, inclusive.
-For each i, earning[i][i] will be '0'.
-For each i and j, earning[i][j] will be equal to earning[j][i].


EXAMPLES

0)
{1, 1}
{"02", "20"}

Returns: 0

Hiring both managers is the optimal solution in this example.

1)
{2, 2}
{"01", "10"}

Returns: -1

Here it is best not to hire any manager.

2)
{1, 2, 3, 4}
{"0121", "1021", "2201", "1110"}

Returns: -1



3)
{2, 2, 0, 1, 4, 0, 1, 0, 0, 4}
{"0100451253",  "1010518123",  "0102989242",  "0020093171",  "4590045480",  "5189400676",  "1893500826",  "2121468008",  "5247872007",  "3321066870"}

Returns: 156



// END CUT HERE
#line 84 "EmployManager.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class EmployManager {
	public:
	int maximumEarnings(vector <int> value, vector <string> earning) {
		
	}
};
