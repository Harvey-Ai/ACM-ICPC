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

class PerfectSequences
{
public:
string fixIt(vector <int> seq)
{
	int i, j;
	long long sum;
	long long a, b;
	
	sum = 0;
	for(i = 0;i < seq.size();i++)
		sum += seq[i];

	for(i = 0;i < seq.size();i++)
	{
		a = sum - seq[i];
		b = 1;
		for(j = 0;j < seq.size();j++)
		{
			if (i == j)
				continue;
			b *= seq[j];
			if (b < 0 || b > a + 1)
				break;
		}
		
		if (j < seq.size())
			continue;

		if (b == 1)
		{
			if (a == 0)
				return "Yes";
		}
		else
		{
			if (a % (b - 1) == 0 && a / (b - 1) >= 0 && a / (b - 1) != seq[i])
				return "Yes";
		}
	}
	return "No";
}
}; 
