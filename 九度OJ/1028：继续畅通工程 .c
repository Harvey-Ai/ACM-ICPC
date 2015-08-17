/*
题目描述：
    省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。
输入：
    测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100 )；随后的 N(N-1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。

    当N为0时输入结束。
输出：
    每个测试用例的输出占一行，输出全省畅通需要的最低成本。
样例输入：
3
1 2 1 0
1 3 2 0
2 3 4 0
3
1 2 1 0
1 3 2 0
2 3 4 1
3
1 2 1 0
1 3 2 1
2 3 4 1
0
样例输出：
3
1
0

*/

#include <iostream>
#include <cstring>
using namespace std;

int res;
int n;
int g[105][105];

int prime(int node)
{
	int set[105], dist[105];
	int i, j;
	int min, index;
	memset(set, 0, sizeof(set));
	set[node] = 1;
	
	for(i = 1;i <= n;i++)
		dist[i] = g[i][node];

	for(i = 1;i < n;i++)
	{
		min = -1;
		for(j = 1;j <= n;j++)
			if (!set[j] && (min == -1 || min > dist[j]))
			{
				min = dist[j];
				index = j;
			}

		//cout << min << endl;
		set[index] = 1;
		res += min;

		for(j = 1;j <= n;j++)
			if (!set[j] && g[index][j] != -1 && (dist[j] == -1 || g[index][j] < dist[j]))
				dist[j] = g[index][j];
	}
}

int main()
{
	int a, b, c, d;
	int i;

	while(cin >> n, n)
	{
		memset(g, -1, sizeof(g));
		for(i = 0;i < (n * (n - 1)) / 2;i++)
		{
			cin >> a >> b >> c >> d;
			if (d == 1)
				g[a][b] = g[b][a] = 0;
			else
				g[a][b] = g[b][a] = c;
		}
		res = 0;
		prime(1);
		cout << res << endl;
	}
	return 0;
}

