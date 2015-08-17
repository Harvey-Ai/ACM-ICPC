#include <iostream>
#include <cstdio>
using namespace std;

int modulo = 1000000009;
long long dp[100005];
int main()
{
	int ncase;
	int n;
	freopen("3.txt", "r", stdin);
	freopen("4.txt", "w", stdout);
	cin >> ncase;

	for(int icase = 0;icase < ncase;icase++)
	{
		cin >> n;
		dp[0] = 1;
		for(int i = 1;i <= n;i++)
		{
			if (i >= 2)	dp[i] = dp[i - 2];
			else	dp[i] = 0;
			dp[i] += dp[i - 1];
			dp[i] %= modulo;
		}

		long long res = dp[n];
		dp[0] = 1;
		for(int i = 1;i <= n;i++)
		{
			dp[i] = dp[i - 1];
			if (i >= 2) dp[i] += dp[i - 2];
			if (i >= 3) dp[i] += dp[i - 3];
			if (i >= 4) dp[i] += dp[i - 4];
			dp[i] %= modulo;
		}

		res *= dp[n];
		res %= modulo;
		printf("%lld\n", res);
	}
	return 0;
}
