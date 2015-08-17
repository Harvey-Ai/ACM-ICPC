#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int graph[55][55];
int used[55];
int subGraphSize;

void dfs(int k, int n)
{
	used[k] = 1;
	subGraphSize++;
	for(int i = 0;i < n;i++)
		if (!used[i] && graph[k][i])
			dfs(i, n);
}

int main()
{
	memset(graph, 0, sizeof(graph));
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		a--;b--;
		graph[a][b] = graph[b][a] = 1;
	}
	
	int matchNum = 0;
	memset(used, 0, sizeof(used));
	for(int i = 0;i < n;i++)
	{
		if (!used[i])
		{
			subGraphSize = 0;
			dfs(i, n);
			matchNum += subGraphSize - 1;
		}
	}
	long long res = 1;
	for(int i = 0;i < matchNum;i++)
		res *= 2;
	printf("%lld\n", res);

	return 0;
}
