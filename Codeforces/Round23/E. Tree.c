#include <stdio.h>
#include <string.h>
#define N 705

int g[N][N];
int visit[N];
int n;
int res;

int multiN[N];

__int64 dfs(int nn, bool isRoot)
{
	__int64 res = 1;
	__int64 rootN = 1;
	__int64 temp;
	__int64 min;
	int i;
	int ch;

	visit[nn] = 1;

	min = -1;
	ch = 0;
	for(i = 1;i <= n;i++)
		if (g[i][nn] && !visit[i])
		{
			ch = 1;
			visit[i] = 1;
			if (!multiN[i])
			{

			}
		}

	if (ch == 0)
		return 1;f
	
	return rootN
}

int main()
{
	__int64 max;
	int i;
	int a, b;
	scanf("%d", &n);

	memset(g, 0, sizeof(g));

	for(i = 1;i < n;i++)
	{
		scanf("%d %d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}

	max = 0;
	for(i = 1;i <= n;i++)
	{
		memset(visit, 0, sizeof(visit));
		memset(multiN, 0, sizeof(multiN));
		res = dfs(i, 1);
		if (res > max)
			max = res;
	}

	printf("%I64d\n", max);
	return 0;
}
