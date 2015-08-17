/*
描述
Given a connected undirected graph, tell if its minimum spanning tree is unique.

Definition 1 (Spanning Tree): Consider a connected, undirected graph G = (V, E). A spanning tree of G is a subgraph of G, say T = (V', E'), with the following properties:
1. V' = V.
2. T is connected and acyclic.

Definition 2 (Minimum Spanning Tree): Consider an edge-weighted, connected, undirected graph G = (V, E). The minimum spanning tree T = (V, E') of G is the spanning tree that has the smallest total cost. The total cost of T means the sum of the weights on all the edges in E'.
输入
The first line contains a single integer t (1 <= t <= 20), the number of test cases. Each case represents a graph. It begins with a line containing two integers n and m (1 <= n <= 100), the number of nodes and edges. Each of the following m lines contains a triple (xi, yi, wi), indicating that xi and yi are connected by an edge with weight = wi. For any two nodes, there is at most one edge connecting them.
输出
For each input, if the MST is unique, print the total cost of it, or otherwise print the string 'Not Unique!'.
样例输入
2
3 3
1 2 1
2 3 2
3 1 3
4 4
1 2 2
2 3 2
3 4 2
4 1 2
样例输出
3
Not Unique!
*/


#include <iostream>
using namespace std;

int key[101][101];
int g[101][101];
int m, n;

int mst(int node, int tag)
{
	int dist[101];
	int link[101];
	int contained[101];
	dist[1] = -1;
	link[1] = 1;
	contained[1] = 1;
	int i, j;
	for(i = 2;i <= n;i++)
	{
		contained[i] = 0;
		dist[i] = g[i][1];
		link[i] = 1;
	}

	int sum = 0;
	int min;
	int id;
	for(i = 2;i <= n;i++)
	{
		min = 100000000;
		id = -1;
		for(j = 2;j <= n;j++)
			if (contained[j] == 0 && dist[j] != -1 && dist[j] < min)
			{
				min = dist[j];
				id = j;
			}

//		if (tag == 0)
//			cout << "id " << id << "min " << min << endl;
		if (id != -1)
		{
			sum += dist[id];
			contained[id] = 1;
			if (tag)
				key[id][link[id]] = 1;
			for(j = 2;j <= n;j++)
				if (contained[j] == 0 && g[id][j] != -1 && (g[id][j] < dist[j] || dist[j] == -1))
				{
					dist[j] = g[id][j];
					link[j] = id;
				}
		}
		else
			break;
	}
	if (i > n)
		return sum;
	else
		return -1;
}

int main()
{
	int ncase;
	int a, b, w;
	int i, j;
	int min, temp, sum;
	int unique;
	cin >> ncase;
	while(ncase--)
	{
		cin >> n >> m;
		for(i = 1;i < 101;i++)
			for(j = 1;j < 101;j++)
				key[i][j] = 0;
		
		for(i = 1;i < 101;i++)
			for(j = 1;j < 101;j++)
				if (i == j)
					g[i][j] = 0;
				else
					g[i][j] = -1;
		for(i = 0;i < m;i++)
		{
			cin >>a >> b >> w;
			g[a][b] = g[b][a] = w;
		}
		min = mst(1, 1);

	//	cout << min << endl;
		unique = 1;
		for(i = 1;i < 101;i++)
		{
			for(j = 1;j < 101;j++)
				if (key[i][j])
				{
					temp = g[i][j] = g[j][i];
					g[i][j] = g[j][i] = -1;
					sum = mst(1, 0);
				//	if (sum < min && sum != -1)
				//		while(1);
				//	cout << "sum " << sum << endl;
					if (sum == min && sum != -1)
					{
						unique = 0;
						break;
					}
					g[i][j] = g[j][i] = temp;
				}
			if (unique == 0)
				break;
		}
		if (unique)
			cout << min << endl;
		else
			cout << "Not Unique!" << endl;
	}
}
