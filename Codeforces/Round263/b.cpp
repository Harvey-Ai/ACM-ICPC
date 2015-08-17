#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const long long mod = 1000000009;
vector< vector<int> > adjList;
vector<int> color;

long long dfs(int node, int f, int &whiteNum)
{
	long long splitNum = 1;
	int flag = 0;
	whiteNum = 0;

	for(int i = 0;i < adjList[node].size();i++)
	{
		if (adjList[node][i] == f)
			continue;

		long long temp;
		int whiteTemp;

		temp = dfs(adjList[node][i], node, whiteTemp);
		if (temp != 0)
		{
			flag = 1;
			if (color[node] == 1)
				splitNum *= temp * (whiteTemp + 1);
			else
			{
				splitNum *= temp;
				whiteNum += whiteTemp + 1;
			}
			splitNum %= mod;
		}
	}

	if (flag == 0 && color[node] == 0)
		return 0;

	cout << node << " " << splitNum << endl;
	return splitNum;
}

int main()
{
	int n;
	cin >> n;

	adjList.resize(n);
	color.resize(n);
	for(int i = 0;i < n - 1;i++)
	{
		int a;
		scanf("%d", &a);
		adjList[i + 1].push_back(a);
		adjList[a].push_back(i + 1);
	}

	int index = -1;
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &color[i]);
		if (color[i] == 1 && index == -1)
			index = i;
	}

	if (index == -1)
		cout << 0 << endl;
	else
	{
		int temp;
		long long res = dfs(index, -1, temp);
		cout << res << endl;
	}
	return 0;
}
