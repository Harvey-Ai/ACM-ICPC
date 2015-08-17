#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int trr[105], wrr[105];
	int dp[105][205];
	int sum[105][105];

	for(int i = 1;i <= n;i++)
		scanf("%d %d", &trr[i], &wrr[i]);
	trr[n + 1] = 0;
	wrr[n + 1] = 0;
	n++;

	memset(sum, 0, sizeof(sum));
	for(int i = 1;i <= n;i++)
	{
		sum[i][i] = wrr[i];
		for(int j = i + 1;j <=  n;j++)
			sum[i][j] = sum[i][j - 1] + wrr[j];
	}
	for(int i = 0;i < 105;i++)
		for(int j = 0;j < 205;j++)
			dp[i][j] = -1;

	dp[0][0] = 0;
	
	for(int i = 1;i <= n;i++)
	{
		dp[i][0] = dp[i - 1][0] + wrr[i];
		for(int j = 1;j < 205;j++)
		{
			for(int k = 0;k < i;k++)
			{
				//if ((dp[i][j] == -1 || dp[i][j] > dp[k][j] + wrr[i]) && dp[k][j] >= 0)
				//	dp[i][j] = dp[k][j] + wrr[i];
				if (j < trr[i]) continue;
				if (((dp[i][j] < 0 || dp[i][j] > dp[k][j - trr[i]] + sum[k + 1][i - 1]) && dp[k][j - trr[i]] >= 0))
					dp[i][j] = dp[k][j - trr[i]] + sum[k + 1][i - 1];
			}
		}
	}

	int res = -1;
	for(int j = 0;j < 205;j++)
		if (dp[n][j] >= 0 && dp[n][j] <= j && ((j < res) || res < 0))
		{
			res = j;
			//printf("%d %d\n", res, i);
			break;
		}
	printf("%d\n", res);
	return 0;
}
