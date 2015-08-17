#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TIME 105
#define LOCATION 105

int dp[TIME][LOCATION];
int present[TIME][LOCATION];

int main()
{
	int res;
	int i, j, k, v, t, m, max, dis;
	int time, x, y, c;

	while(scanf("%d %d %d", &v, &t, &m), v || t || m)
	{
		memset(present, 0, sizeof(present));
		for(i = 0;i < m;i++)
		{
			scanf("%d %d %d %d", &time, &x, &y, &c);
			present[time][(x - 1) * 10 + y - 1] += c;
		}

		for (i = 0;i <= 100;i++)
			for(j = 0;j < LOCATION - 5;j++)
				dp[i][j] = -1;

		dp[0][0] = 0;

		for(i = 1;i <= t;i++)
			for(j = 0;j < LOCATION - 5;j++)
			{
				max = -1;
				//find max values from all location can reach this place
				for(k = 0;k < LOCATION - 5;k++)
				{
					//!!!!! the anti-process is not abs(j - k) / 10 + abs(j - k) % 10;
					dis = (abs(k/10 - j/10)) + (abs(k%10 - j%10));
					if (dis <= v  && max < dp[i-1][k])
						max = dp[i-1][k];
				}
				if (max != -1)
					dp[i][j] = max + present[i][j];
			}
		
		res = 0;
		for(j = 0;j < LOCATION - 5;j++)
			if (res < dp[t][j])
				res = dp[t][j];

		printf("%d\n", res);
	}
	return 0;
}
