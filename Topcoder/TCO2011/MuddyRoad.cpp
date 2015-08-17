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
class MuddyRoad
{
public:
double getExpectedValue(vector <int> road)
{
	double dp[100][100];
	int n = road.size();
	int i, k;
	double res;

	res = 0;
	dp[1][0] = 0;
	dp[0][0] = 1;
	for(i = 1;i < n - 1;i++)
	{
		dp[0][i] = 1;
		for(k = 1;k <= i;k++)
		{
			if (k == 1)
				dp[k][i] = (road[i] * 1.0 / 100);
			else
				dp[k][i] = dp[k - 1][i - 1] * (road[i] * 1.0 / 100);
			res += (int)(k / 2) * dp[k][i] * (1 - (road[i - k] * 1.0 / 100)) * (1 - (road[i + 1] * 1.0 / 100));
		}
	}

	return res;
}
};

