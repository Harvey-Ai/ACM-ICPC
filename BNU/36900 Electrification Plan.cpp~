/*
Some country has n cities. The government has decided to electrify all these cities. At first, power stations in k different cities were built. The other cities should be connected with the power stations via power lines. For any cities i, j it is possible to build a power line between them in cij roubles. The country is in crisis after a civil war, so the government decided to build only a few power lines. Of course from every city there must be a path along the lines to some city with a power station. Find the minimum possible cost to build all necessary power lines.
Input
The first line contains integers n and k (1 ≤ k ≤ n ≤ 100). The second line contains k different integers that are the numbers of the cities with power stations. The next n lines contain an n × n table of integers {cij} (0 ≤ cij ≤ 105). It is guaranteed that cij = cji, cij > 0 for i ≠ j, cii = 0.

Output
Output the minimum cost to electrify all the cities.
Sample Input
input
4 2
1 4
0 2 4 3
2 0 5 2
4 5 0 1
3 2 1 0
output
3
*/


#include <iostream>
#include <cstdio>
using namespace std;

int graph[105][105];
int dist[105];
int flag[105];

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		dist[i] = -1;
		flag[i] = 0;
	}

	for(int i = 0;i < k;i++)
	{
		int a;
		cin >> a;
		dist[a] = 0;
		flag[a] = 1;
	}

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
		{
			int a;
			scanf("%d", &a);
			graph[i][j] = graph[j][i] = a;
            
			if ((dist[i] == -1 || dist[i] > graph[i][j]) && flag[j])
				dist[i] = graph[i][j];
			if ((dist[j] == -1 || dist[j] > graph[i][j]) && flag[i])
				dist[j] = graph[i][j];
		}

	int res = 0;
	while(1)
	{
		int min = -1;
		int index = -1;
		for(int i = 1;i <= n;i++)
		{
			if (flag[i])
				continue;
			if ((min == -1 || min > dist[i]) && dist[i] != -1)
			{
				min = dist[i];
				index = i;
			}
		}

		if (index == -1)
			break;

		res += min;
		flag[index] = 1;
		for(int i = 1;i <= n;i++)
		{
			if (flag[i])
				continue;
			if (graph[index][i] < dist[i] || dist[i] == -1)
				dist[i] = graph[index][i];
		}
	}
	cout << res << endl;
	return 0;
}
