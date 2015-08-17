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
class FoxListeningToMusic
{
public:
vector <double> getProbabilities(vector <int> length, int T)
{
	double dp[80005];
	vector <double> res;
	int i, j;
	double temp;
	int size = length.size();

	dp[0] = 1;
	for(i = 1;i <= T;i++)
	{
		dp[i] = 0;
		for(j = 0;j < size;j++)
			if (i - length[j] >= 0)
				dp[i] += dp[i - length[j]] * 1.0 / size;
	}

	res.clear();
	for(i = 0;i < size;i++)
	{
		temp = 0;
		for(j = T;j + length[i] >= T + 1 && j >= 0;j--)
			temp += dp[j] * 1.0 / size;
		res.push_back(temp);
	}
	return res;
}
}; 
