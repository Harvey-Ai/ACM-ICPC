#include <stdio.h>
#include <string.h>
#define INF 0x7f7f7f7f7f7f7f7f

long long dp[4005];
int main()
{
	int n;
	int i, j;
	long long min;
	int t;
	long long c;
	scanf("%d", &n);

	memset(dp, INF, sizeof(dp));

	dp[0] = 0;
	for(i = 0;i < n;i++)
	{
		scanf("%d %lld", &t, &c);
		for(j = 4000; j >= 0;j--)
			if (j + t + 1 <= 4000 && 
				dp[j] != INF &&
				dp[j + t + 1] > dp[j] + c)
			{
				dp[j + t + 1] = dp[j] + c;
			}
	}

	min = INF;
	for(i = n;i <= 4000;i++)
		if (dp[i] < min)
			min = dp[i];

	printf("%lld\n", min);
	return 0;
}

