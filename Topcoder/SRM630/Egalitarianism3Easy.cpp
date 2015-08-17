#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
class Egalitarianism3Easy {
	public:
	
		int graph[15][15];
	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
		if (n <= 2)
			return n;

		memset(graph, 0, sizeof(graph));
		for(int i = 0;i < n - 1;i++)
		{
			a[i]--;
			b[i]--;
			graph[a[i]][b[i]] = graph[b[i]][a[i]] = len[i];
		}

		for(int k = 0;k < n;k++)
			for(int i = 0;i < n;i++)
			{
				if (i == k)
					continue;
				for(int j = 0;j < n;j++)
				{
					if (j == k || j == i)
						continue;
					if (graph[i][k] && graph[k][j] && (graph[i][j] == 0 || graph[i][j] > graph[i][k] + graph[k][j]))
						graph[i][j] = graph[j][i] = graph[i][k] + graph[k][j];
				}
			}

		int res = 2;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < i;j++)
			{
				int dist = graph[i][j];
				int temp = 2;

				int nodeSet[15];
				int nodeNum = 0;
				nodeSet[nodeNum++] = i;
				nodeSet[nodeNum++] = j;
				for(int k = 0;k < n;k++)
				{
					if (k == i || k == j)
						continue;
					int flag = 1;
					for(int l = 0;l < nodeNum;l++)
						if (graph[nodeSet[l]][k] != dist)
						{
							flag = 0;
							break;
						}
					if (flag)
					{
						nodeSet[nodeNum++] = k;
						temp++;
					}
				}
				cout << temp << endl;
				if (temp > res)
					res = temp;
			}
		
		return res;
	}
};
