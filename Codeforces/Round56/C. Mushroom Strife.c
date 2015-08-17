#include <stdio.h>
#include <string.h>
long long g[105][105][4];
int visited[105];
long long ans[105];

int gggcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gggcd(b, a % b);
}

int ggcd(int a, int b, int c)
{
	int aa = a, bb = b;
	int temp;
	if (aa < bb)
	{
		temp = aa;
		aa = bb;
		bb = temp;
	}
	temp = gggcd(aa, bb);
	if (temp != c)
		return 0;
	else
		return 1;
}

int dfs(int kk, int n)
{
	int i;
	for(i = 0;i < n;i++)
		if (!visited[i] && g[i][kk][0])
		{
			visited[i] = 1;
			ans[i] = g[i][kk][1] * g[i][kk][0] / ans[kk];
			if (ans[i] * ans[kk]  != g[i][kk][1] * g[i][kk][0])
			{
				ans[i] = 0;
				return 0;
			}
			if (ggcd(ans[i], ans[kk], g[i][kk][0]))
			{
				if (dfs(i, n) == 0)
				{
					ans[i] = 0;
					return 0;
				}
			}
			else
			{
				ans[i] = 0;
				return 0;
			}
		}
	return 1;
}

int main()
{
	int i, j, k;
	int a, b, gcd, lcm;
	int m, n;
	__int64 mul;
	int ff, tt;
	int fail;

	scanf("%d %d", &n, &m);
	memset(g, 0, sizeof(g));
	memset(ans, 0, sizeof(ans));
	for(i = 0;i < m;i++)
	{
		scanf("%d %d %d %d", &a, &b, &gcd, &lcm);
		g[a - 1][b - 1][0] = g[b - 1][a - 1][0] = gcd;
		g[a - 1][b - 1][1] = g[b - 1][a - 1][1] = lcm;
	}
	fail = 0;
	for(i = 0;i < n;i++)
	{
		if (ans[i] == 0)
		{
			ff = 0;
			for(j = 0;j < n;j++)
				if (g[i][j][0])
				{
					ff = 1;
					mul = g[i][j][1] * g[i][j][0];
					for(k = 1;k * k <= mul;k++)
						if (mul % k == 0)
						{
							ans[i] = k;
							memset(visited, 0, sizeof(visited));
							visited[i] = 1;
							if (dfs(i, n) == 1)
								break;
							ans[i] = 0;

							ans[i] = mul / k;
							memset(visited, 0, sizeof(visited));
							visited[i] = 1;
							if (dfs(i, n) == 1)
								break;
							ans[i] = 0;
						}
					if (ans[i] == 0)
						break;
				}
			if (j >= n)
			{
				if (ans[i] == 0)
					ans[i] = 1;
			}
			else
			{
				fail = 1;
				break;
			}
		}
	}

	if (!fail)
	{
		printf("YES\n");
		for(i = 0;i < n;i++)
			printf("%d ", ans[i]);
	}
	else
		printf("NO\n");
	return 0;
}
