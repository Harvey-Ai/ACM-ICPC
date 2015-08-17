#include <stdio.h>
#include <math.h>
#define N 105
#define MAX 256

int dp[N][MAX + 1];
int arr[N];

int main()
{
	int i, j, k, l;
	int icase, ncase;
	int d, ll, m, n;
	int temp, ttemp;
	int min;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d %d %d", &d, &ll, &m, &n);
		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		if (n == 0)
		{
			printf("Case #%d: 0\n", icase);
			continue;
		}

		for(j = 0;j < MAX;j++)
			dp[0][j] = abs(arr[0] - j);

		for(i = 1;i < n;i++)
			for(j = 0; j < MAX;j++)
			{
				dp[i][j] =  i * d + abs(arr[i] - j);
				for(l = 0;l < i;l++)
				{
					ttemp = (i - l - 1) * d + abs(arr[i] - j);
					min = -1;
					if (m == 0)
						min = dp[l][j];
					else
					{
						for(k = 0; k < MAX;k++)
						{
							if (j != k)
								temp = dp[l][k] + ((abs(j - k) - 1)/ m) * ll;
							else
								temp = dp[l][k];

							if (temp < min || min == -1)
								min = temp;
						}
					}
					ttemp += min;
					if (dp[i][j] > ttemp)
						dp[i][j] = ttemp;
				}
			}
	
		min = -1;
		for(i = 0;i < n;i++)
			for(j = 0;j < MAX;j++)
				if (min == -1 || dp[i][j] + (n - i - 1) * d < min)
					min = dp[i][j] + (n - i - 1) * d ;
		if (n * d < min)
			min = n * d;
		printf("Case #%d: %d\n", icase, min);
	}
	return 0;
}
