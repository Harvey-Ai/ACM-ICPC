#include <stdio.h>
#include <string.h>

char ss[4004], tt[4004];
int dp[4004][4004];

int main()
{
	int i, j;
	int len1, len2;
	int min;
	int temp;
	int ti, td, tr, te;

	scanf("%d %d %d %d %d", &ti, &td, &tr, &te);
	scanf("%s", ss);
	scanf("%s", tt);

	len1 = strlen(ss);
	len2 = strlen(tt);

	for(i = 0;i <= len2;i++)
		for(j = 0;j <= len1;j++)
			dp[i][j] = -1;

	dp[0][0] = 0;
	for(i = 1;i <= len2;i++)
		dp[i][0] = dp[i - 1][0] + td;

	for(i = 1;i <= len1;i++)
		dp[0][i] = dp[0][i - 1] + ti;

//	printf("%d\n", dp[0][1]);
	for(i = 0;i < len2;i++)
		for(j = 0;j < len1;j++)
		{
			min = 100000;
			if (ss[i] == tt[j])
				min = dp[i][j];
			
			//insert
			if (min > dp[i][j + 1] + ti)
				min = dp[i][j + 1] + ti;
				
			//delete
			if (min > dp[i + 1][j] + td)
				min = dp[i + 1][j] + td;

			//replace
			if (min > dp[i][j] + tr)
				min = dp[i][j] + tr;
				
			if (dp[i + 1][j + 1] > min || dp[i + 1][j + 1] == -1)
				dp[i + 1][j + 1] = min;

			printf("%d %d %d %d\n", i, j, min, dp[i][j + 1]);

			if (j > 0)
			{
				if (i > 0)
				{
					temp = 2 * td + 2 * ti;
					if (ss[j] == tt[i - 1])
					{
						if (ss[j - 1] == tt[i])
							temp = 0;
						else
							temp = (td + ti) < tr ? (td + ti) : tr;
					}
					if (ss[j] == tt[i])
					{
						if (temp > ti + td)
							temp = ti + td;
					}
					if (ss[j - 1] == tt[i - 1])
					{
						if (temp > ti + td)
							temp = ti + td;
					}
					if (ss[j - 1] == tt[i])
					{
						if (temp > ti + td)
							temp = ti + td;
						if (temp > te)
							temp = te;
					}
					if (dp[i + 1][j + 1] > (dp[i - 1][j - 1] + temp + te) || dp[i + 1][j + 1] == -1)
						dp[i + 1][j + 1] = dp[i - 1][j - 1] + temp + te;
				}
				else
				{
					temp = 2 * td + ti;
					if (ss[j] == tt[i] || ss[j - 1] == tt[i])
						temp = td;
					if (dp[i + 1][j + 1] > dp[i][j - 1] + temp + te || dp[i + 1][j + 1] == -1)
						dp[i + 1][j + 1] = dp[i][j - 1] + temp + te;
				}
			}
		}
	printf("%d\n", dp[len2][len1]);
	return 0;
}
