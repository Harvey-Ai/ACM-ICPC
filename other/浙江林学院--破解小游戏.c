#include <stdio.h>
#include <string.h>
#define MAXP 1<<17
#define N 20

int g[N][N], buf[N];
__int64 dp[2][MAXP][N];
int m, n;

void calc(int pos, int depth, int chose, int choseN)
{
	int i, j;
	__int64 temp, ttemp;
	if (choseN == pos)
	{
		
		for(i = 1;i < n;i++)
			if (chose & buf[i])
			{
				temp = 0;
				if (pos == 1 && g[i][0])
				{
					dp[1][chose][i] = 1;
					return;
				}
				for(j = 1;j < n;j++)
					if (g[i][j] && (chose & buf[j]))
						temp += dp[(pos - 1) & 0x01][chose & ~buf[i]][j];

				dp[pos & 0x01][chose][i] = temp;
			}
		return;
	}
	calc(pos, depth + 1, chose | buf[depth], choseN + 1);

	if (n - 1 - depth >= pos - choseN)
		calc(pos, depth + 1, chose, choseN);
}

int main()
{
	int i, j, a, b, resN[N];
	__int64 res;

	buf[0] = 0;
	buf[1] = 1;
	for(i = 2;i < N;i++)
		buf[i] = buf[i - 1]<<1;

	resN[1] = 1;
	for(i = 2;i < N;i++)
		resN[i] = (resN[i - 1] | buf[i]);

	while(scanf("%d %d", &n, &m) != EOF)
	{
		memset(g, 0, sizeof(g));
		for(i = 0;i < m;i++)
		{
			scanf("%d %d", &a, &b);
			g[a][b] = g[b][a] = 1;
		}

		if (n == 1)
		{
			printf("1\n");
			return 0;
		}

		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for(i = 1;i < n;i++)
			calc(i, 1, 0, 0);

		res = 0;

		for(i = 1;i < n;i++)
			if (g[0][i])
				res += dp[(n - 1) & 0x01][resN[n - 1]][i];

		printf("%I64d\n", res);
	}
	return 0;
}

