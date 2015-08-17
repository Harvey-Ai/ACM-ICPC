#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
class DoubleTree {
	public:
	int n;
	int graph1[55][55], graph2[55][55];
	int scores[55];
	set<int> nodeSet;
	int checkedNum;

	void dfs2(int node, int f)
	{
		for(int i = 0;i < n;i++)
			if (graph2[node][i] && i != f && nodeSet.find(i) != nodeSet.end())
			{
				checkedNum++;
				dfs2(i, node);
			}
	}

	void checkTree()
	{
		if (nodeSet.size() > 0)
		{
			checkedNum = 0;
			dfs2(*(nodeSet.begin()));
			if (checkedNum == nodeSet.size())
			{
				int temp = 0;
				for(set<int>::iterator it = nodeSet.begin();it != nodeSet.end();it++)
					temp += scores[*it];
				if (ans < temp)
					ans = temp;
			}
		}
	}

	set<int> dfs(int node, int f)
	{
		set<int> set1, set2;
		for(int i = 0;i < n;i++)
			if (graph[node][i] && i != f)
			{
				int set 
					set1 = dfs(i, node);
				else
					set2 = dfs(i,
	
	}

	int maximalScore(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> score) {
		int n = a.size() + 1;

		memset(graph1, 0, sizeof(graph1));
		memset(graph2, 0, sizeof(graph2));
		for(int i = 0;i < a.size();i++)
			graph1[a[i]][b[i]] = graph1[b[i]][a[i]] = 1;
		for(int i = 0;i < c.size();i++)
			graph2[c[i]][d[i]] = graph2[d[i]][c[i]] = 1;

		for(int i = 0;i < n;i++)
			scores[i] = score[i];

		ans = 0;
		for(int i = 0;i < n;i++)
			dfs(i, -1);
		return ans;
	}
};
