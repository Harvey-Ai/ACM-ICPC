/*
Description

After hearing about the epidemic of obesity in the USA, Farmer John wants his cows to get more exercise, so he has committed to create a bovine marathon for his cows to run. The marathon route will include a pair of farms and a path comprised of a sequence of roads between them. Since FJ wants the cows to get as much exercise as possible he wants to find the two farms on his map that are the farthest apart from each other (distance being measured in terms of total length of road on the path between the two farms). Help him determine the distances between this farthest pair of farms. 
Input

* Lines 1.....: Same input format as "Navigation Nightmare".
Output

* Line 1: An integer giving the distance between the farthest pair of farms. 
Sample Input

7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
Sample Output

52
Hint

The longest marathon runs from farm 2 via roads 4, 1, 6 and 3 to farm 5 and is of length 20+3+13+9+7=52. 
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

vector<vector<int> > graph;
vector<vector<int> > cost;
int endP;
int maxDist;
int visited[500005];

int dfs(int p, int dist)
{
	if (visited[p])
		return 0;
	visited[p] = 1;
	if (dist > maxDist)
	{
		maxDist = dist;
		endP = p;
	}
	for(int i = 0;i < graph[p].size();i++)
		dfs(graph[p][i], dist + cost[p][i]);
}

int main()
{
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	cost.resize(n);

	for(int i = 0;i < m;i++)
	{
		int a, b, w;
		char s[100];
		scanf("%d %d %d", &a, &b, &w);
		scanf("%s", s);

		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
		cost[a - 1].push_back(w);
		cost[b - 1].push_back(w);
	}

	memset(visited, 0, sizeof(visited));
	maxDist = 0;
	dfs(0, 0);

	memset(visited, 0, sizeof(visited));
	maxDist = 0;
	dfs(endP, 0);
	cout << maxDist << endl;

	return 0;
}
