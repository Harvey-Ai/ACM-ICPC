#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 5005

long long dp[N][2];
long long arr[N], arr2[N];

int cmp(const void *a, const void * b)
{
	return *(long long *)a - *(long long *)b; 
}

int main()
{
	int i, j, n;
	int pre, now;
	int temp;
	long long min;
	long long dist;

	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%lld", &arr[i]);
		arr2[i] = arr[i];
	}

	qsort(arr, n, sizeof(arr[0]), cmp);
	memset(dp, 0, sizeof(dp));
	now = 1;
	pre = 0;
	for(i = 0;i < n;i++)
		if (arr[i] > arr2[0])
			dp[i][pre] = arr[i] - arr2[0];
		else
			dp[i][pre] = arr2[0] - arr[i];
	
	for(i = 1;i < n;i++)
	{
		min = dp[0][pre];
		for(j = 0;j < n;j++)
		{
			if (dp[j][pre] < min)
				min = dp[j][pre];
			if (arr2[i] > arr[j])
				dp[j][now] = min + arr2[i] - arr[j];
			else
				dp[j][now] = min + arr[j] - arr2[i];
		}
		temp = pre;
		pre = now;
		now = temp;
	}

	min = dp[0][pre];
	for(i = 0;i < n;i++)
		if (min > dp[i][pre])
			min = dp[i][pre];

	printf("%lld\n", min);
}
