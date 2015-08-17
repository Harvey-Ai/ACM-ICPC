#include <stdio.h>
#define N 505
#define MOD 100003

long long dp[N][N];
long long cc[N][N];
int main()
{
	int i, j, k;
	int n;
	int ncase, icase;
	long long res;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	for(i = 0;i < N;i++)
		cc[0][i] = 1;
	for(i = 1;i < N;i++)
	{
		cc[i][0] = 1;
		cc[i][1] = i;
		cc[i][i] = 1;
		for(j = 2;j <i;j++)
			cc[i][j] = (cc[i-1][j] + cc[i-1][j-1]) % MOD;
	}

	dp[2][1] = 1;
	for(i = 3;i < N;i++)
	{
		dp[i][1] = 1;
		for(j = 2;j < i;j++)
		{
			dp[i][j] = 0;
			for(k = j - 1;k >= 1;k--)
				if (i >= 2 * j - k)
					dp[i][j] += (dp[j][k] * cc[i - j - 1][j - k - 1]);
			dp[i][j] %= MOD;
		}
	}

	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d", &n);
		res = 0;
		for(i = 1;i < n;i++)
			res += dp[n][i];
	
		printf("Case #%d: %lld\n", icase, res % MOD);

	}
	return 0;
}
