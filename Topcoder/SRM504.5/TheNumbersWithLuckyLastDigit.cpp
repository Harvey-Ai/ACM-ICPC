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
class TheNumbersWithLuckyLastDigit
{
public:
int find(int n)
{
	if (n <= 0)
		return -1;

	int dp[20], minN[20];
	int dig = n % 10;
	int i, j;

	memset(minN, 0, sizeof(minN));
	memset(dp, 0, sizeof(dp));
	dp[4] = 1;	minN[4] = 4;
	dp[7] = 1;  minN[7] = 7;
	
	int flag = 1;
	while(flag)
	{
		flag = 0;
		for(i = 0;i < 10;i++)
			if (dp[i])
			{
				j = (i + 4) % 10;
				if (dp[j] == 0 || dp[j] > dp[i] + 1)
				{
					dp[j] = dp[i] + 1;
					if (minN[j] > minN[i] + 4 || minN[j] == 0)
						minN[j] = minN[i] + 4;
					flag = 1;
				}

				j = (i + 7) % 10;
				if (dp[j] == 0 || dp[j] > dp[i] + 1)
				{
					dp[j] = dp[i] + 1;
					if (minN[j] > minN[i] + 7 || minN[j] == 0)
						minN[j] = minN[i] + 7;
					flag = 1;
				}
			}
			else
				flag = 1;
	}

	if (n < minN[dig])
		return -1;
	else
		return dp[dig];

}
}; 
