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
class ComparerInator
{
public:
int makeProgram(vector <int> A, vector <int> B, vector <int> wanted)
{
	int len = A.size();
	int i, min, max;
	int temp;
	int ok1, ok2, ok3, ok4;

	ok1 = ok2 = ok3 = ok4 = 1;
	for(i = 0;i < len;i++)
	{
		max = A[i];
		min = B[i];

		if (min > max)
		{
			temp = max;
			max = min;
			min = temp;
		}
		if (A[i] != wanted[i])
			ok1 = 0;
		if (B[i] != wanted[i])
			ok2 = 0;

		if (min != wanted[i])
			ok3 = 0;
		if (max != wanted[i])
			ok4 = 0;
	}

	if (ok1 | ok2)
		return 1;
	if (ok3 || ok4)
		return 7;
	return -1;
}
}; 
