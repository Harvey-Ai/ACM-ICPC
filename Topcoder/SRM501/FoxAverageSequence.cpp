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
class FoxAverageSequence
{
public:
int theCount(vector <int> seq)
{
	int len = seq.size();
	int dp[50][2000];

	for(i = 0;i < 2000;i++)
		dp[0][i] = 0;

	if (seq[0] == -1)
		for(i = 0;i < 41;i++)
			dp[0][i] = 1;
	else
		dp[0][seq[0]] = 1;

	for(i = 1;i < len;i++)
	{
		if (i == 1)
		{
			for(j = 0;j < 2000;j++)
				dp[1][j] = 0;
			if (seq[1] == -1)
			{
				for(j = 40;j >= 1;j--)
					dp[1][j] += dp[0][j] * j;
			}
			else
			{
				for(j = 40;j > seq[1];j--)
					dp[1][seq[1]] += dp[0][j];
				
			}
		}
		else
		{

		}


}
}; 
