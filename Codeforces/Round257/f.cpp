#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > graph;
vector< vector<long long> > cost;
vector<long long> trainCost;
vector<int> removeTrain;

void dijkstra(int src, int n)
{
	vector<long long> dist;
	dist.resize(n + 1);
	for(int i = 0;i < n;i++)
		dist[i] = -1;
	for(int i = 0;i < graph[src].size();i++)
		dist[graph[src][i]] = cost[src][i];
	vector<int> found;
	found.resize(n + 1);
	for(int i = 0;i < n;i++)
		found[i] = 0;
	found[src] = 1;

	for(int i = 1;i < n;i++)
	{
		long long minDist = -1;
		long long minPoint = -1;
		for(int j = 0;j < n;j++)
			if (dist[j] != -1 && !found[j] && (minDist == -1 || minDist > dist[j]))
			{
				minDist = dist[j];
				minPoint = j;
			}
		if (minDist == -1)
			break;
		if (trainCost[minPoint] >= minDist)
			removeTrain[minPoint] = 1;

		for(int j = 0;j < graph[minPoint].size();j++)
			if (!found[graph[minPoint][j]] && (dist[graph[minPoint][j]] == -1 || dist[graph[minPoint][j]] > minDist + cost[minPoint][j]))
				dist[graph[minPoint][j]] = minDist + cost[minPoint][j];
		found[minPoint] = 1;
	}
}	

int main()
{
	int n, m, k;

	cin >> n >> m >> k;
	graph.resize(n + 1);
	cost.resize(n + 1);
	for(int i = 0;i <= n;i++)
	{
		vector<long long> a;
		graph.push_back(a);
		cost.push_back(a);
	}
	for(int i = 0;i < m;i++)
	{
		long long ui, vi, xi;
		cin >> ui >> vi >> xi;
		ui--;
		vi--;
		int updated = 0;
		for(int j = 0;j < graph[ui].size();j++)
			if (graph[ui][j] == vi)
			{
				cost[ui][j] = cost[ui][j] < xi ? cost[ui][j] : xi;
				for(int k = 0;k < graph[vi].size();k++)
					if (graph[vi][k] == ui)
					{
						cost[vi][k] = cost[vi][k] < xi ? cost[vi][k] : xi;
						break;
					}
				updated = 1;
				break;
			}
		if (!updated)
		{
			graph[ui].push_back(vi);
			cost[ui].push_back(xi);
			graph[vi].push_back(ui);
			cost[vi].push_back(xi);
		}
	}

	long long res = 0;
	trainCost.resize(n + 1);
	for(int i = 0;i <= n;i++)
		trainCost[i] = -1;
	trainCost[0] = 0;
	removeTrain.resize(n + 1);
	for(int i = 0;i <= n;i++)
		removeTrain[i] = 0;
	for(int i = 0;i < k;i++)
	{
		int si, yi;
		cin >> si >> yi;
		si--;
		res += (trainCost[si] != -1);
		if (trainCost[si] == -1 || trainCost[si] > yi) 
			trainCost[si] = yi;
	}

	dijkstra(0, n);
	for(int i = 0;i < n;i++)
		if (trainCost[i] && removeTrain[i])
			res++;
	cout << res << endl;
	return 0;
}
