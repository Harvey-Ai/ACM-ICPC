#include <iostream>
using namespace std;

int used[1005];
int arr[1005][1005];
int g[1005][1005];
int dfs(int node)
{
	int i, j;
	arr[node][node] = 1;
	for(i = 1;i <= 1000;i++)
		if (g[node][i] && i != node)
		{
			if (!used[i])
			{
				used[i] = 1;
				dfs(i);
			}
			for(j = 1;j <= 1000;j++)
				arr[node][j] += arr[i][j];
		}
}

int main()
{
	int ncase, icase;
	int i, j, n;
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	cin >> ncase;

	for(icase = 1;icase <= ncase;icase++)
	{
		memset(g, 0, sizeof(g));		
		memset(arr, 0, sizeof(arr));
		memset(used, 0, sizeof(used));

		scanf("%d", &n);
		for(i = 1;i <= n;i++)
		{
			int num;
			scanf("%d", &num);
			for(j = 1;j <= num;j++)
			{
				int a;
				scanf("%d", &a);
				g[i][a] = 1;
			}
		}
		for(i = 1;i <= n;i++)
		{
			for(j = 1;j <= n;j++)
				if (g[j][i])
					break;
			if (j <= n)
				continue;
			dfs(i);
		}
		
		int ok = 0;
		for(i = 1;i < 1005;i++)
			for(j = 1;j < 1005;j++)
				if (arr[i][j] > 1)
				{
					ok = 1;
					break;
				}

		if (ok)
			printf("Case #%d: Yes\n", icase);
		else
			printf("Case #%d: No\n", icase);
	}
	return 0;
}
