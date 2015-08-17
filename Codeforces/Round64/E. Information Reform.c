#include <iostream>

int visited[300];

void dfs(int root)
{
	visited[root] = 1;
	set < int > son;
	for(i = 1;i <= n;i++)
		if (g[root][i] && !visited[i])
		{
			son.push_back(i);
			dfs(i);
		}

	for(i = 1;i <= n;i++)
	{
		dp[root][i] = g[root][i];
		for(set < int >::iterator it = son.begin();it != son.end();it++)
		{
			dp[root][i] += MIN(dp[*it][best[*it]], dp[*it][i])
			
		}

	}
}

int main()
{
	int n, k;
	int d[200];

	scanf("%d %d", &n, &k);
	for(i = 1;i < n;i++)
		scanf("%d", &d[i]);

	memset(g, 0, sizeof(g));
	for(i = 1;i < n;i++)
	{
		scanf("%d %d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}

	for(k = 1;k <= n;k++)
		for(i = 1;i <= n;i++)
			for(j = 1;j <= n;j++)
				if ((g[i][k] + g[k][j] < g[i][j] || g[i][j] == 0) && g[i][k] && g[k][j])
					g[i][j] = g[i][k] + g[k][j];

	memset(visited, 0, sizeof(visited));
	dfs(1);

}

