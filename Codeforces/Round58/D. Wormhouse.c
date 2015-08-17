#include <stdio.h>
#include <string.h>

int ans[2005];
int way[2005];
int g[105][105];
int visited[105][105];
int m, n;

int check()
{
	int i, j;
	for(i = 1;i <= n;i++)
		for(j = 1;j <= n;j++)
			if (g[i][j] && !visited[i][j])
				return 0;
	return 1;
}

int work(int kk, int num, int flag)
{
	int i;
	int temp;
	if (num == m)
	{
		if (flag == 0)
			return 0;
	//	printf("%d", flag);
	//	for(i = 1;i < m;i++)
		//		printf(" %d", ans[i]);
	//	printf("%d\n", kk);
	//	putchar('\n');
		if (kk == way[0] && check())
		{
			printf("%d", way[0]);
			for(i = 1;i < m;i++)
				printf(" %d", ans[i]);
			printf(" %d", way[0]);
			return 1;
		}
		else
			return 0;
	}
	for(i = 1;i <= n;i++)
		if (g[kk][i] && !visited[kk][i] && (flag || i >= way[num + 1]))
		{
		//	printf("%d %d \n", num, i);
			visited[kk][i] = 1;
			visited[i][kk] = 1;
			ans[num + 1] = i;
			temp = 0;
			if (i > way[num + 1])
				temp = 1;
		//	printf("%d %d %d\n", flag, temp, flag | temp);
			if (work(i, num + 1, flag | temp))
				return 1;
			visited[kk][i] = 0;
			visited[i][kk] = 0;
		}
	return 0;
}

int main()
{
	int i;
	int res;
	int dg[105];
	scanf("%d %d", &n, &m);
	memset(g, 0, sizeof(g));
	memset(dg, 0, sizeof(dg));
	scanf("%d", &way[0]);
	for(i = 1;i <= m;i++)
	{
		scanf("%d", &way[i]);
		g[way[i]][way[i - 1]] = g[way[i - 1]][way[i]] = 1;
		dg[way[i]]++;
		dg[way[i - 1]]++;
	}
	for(i = 1;i <= n;i++)
		if (dg[i] % 2 != 0)
		{
			printf("No solution\n");
			return 0;
		}
	memset(visited, 0, sizeof(visited));
	ans[m] = way[0];
	res = work(way[0], 0, 0);
	if (!res)
		printf("No solution\n");
	return 0;
}
