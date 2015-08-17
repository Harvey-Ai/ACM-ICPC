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

const int MOD = 1000000009;
map<vector<long long>, int> dp;
class YetAnotherORProblem
{
public:

int countSequences(vector<long long> R)
{
	int size = R.size();
	long long max = 1LL << 61;
	int fOne;
	int i;

	map<vector<long long>, int>::iterator it;
	if (dp.find(R) != dp.end())
		return dp[R];
	for(fOne = 0;fOne <= 61;fOne++)
	{
		long long temp = max >> fOne;
		for(i = 0;i < size;i++)
		{
			if (R[i] & temp)
				break;
		}
		if (i < size)
			break;
	}

//	printf("fdafasd\n");
//	printf("%d\n", fOne);
	if(fOne > 61)
		return 1;

	long long temp = max >> fOne;
	int res = 0;
	vector<long long> S = R;
	for(i = 0;i < size;i++)
		if (S[i] & temp)
			S[i] = temp - 1;

	res += countSequences(S);
	if (res >= MOD)
		res -= MOD;

	for(i = 0;i < size;i++)
		if (S[i] != R[i])
		{
			long long t = S[i];
			S[i] = R[i] - temp;
			res += countSequences(S);
			if (res >= MOD)
				res -= MOD;
			S[i] = t;
		}

	dp[R] = res;
//	printf("%d\n", res);
	return res;
}
};

