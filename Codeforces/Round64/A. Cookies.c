#include <stdio.h>

int main()
{
	int n;
	int i;
	int dp[1005];

	dp[0] = 1;
	dp[1] = 1;
	
	scanf("%d", &n);

	for(i = 2;i <= n;i++)
		dp[i] = (dp[i - 1] * 3) % 1000003;

	printf("%d\n", dp[n]);
	return 0;
}
