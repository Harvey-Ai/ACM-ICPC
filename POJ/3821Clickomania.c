#include <stdio.h>
#include <string.h>

char str[155];
int dp[155][155];

int solve(int from, int to)
{
	int res, i;
	int b, e;
	if (from > to)
		return 2;
	if (dp[from][to])
		return dp[from][to];

	res = 1;

	if (str[from] == str[to] && to > from)
	{
		for(b = from;b < to && str[b] == str[from];b++);
		for(e = to;e > from && str[e] == str[to];e--);
		res = solve(b, e);
		if (b < e)
			for (i = b;i <= e;i++)
				if (str[i] == str[from] && solve(b, i - 1) == 2 && solve(i + 1, e) == 2)
				{
					res = 2;
					break;
				}
	}

	for(i = from;i < to;i++)
		if (solve(from, i) == 2 && solve(i + 1, to) == 2)
		{
			res = 2;
			break;
		}
	dp[from][to] = res;
	return dp[from][to];
}

int main()
{
	while(scanf("%s", str) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		if (solve(0, strlen(str) - 1) == 2)
			printf("solvable\n");
		else
			printf("unsolvable\n");	
	}
	return 0;
}
