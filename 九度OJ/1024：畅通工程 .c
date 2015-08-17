/*
题目描述：
    省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。经过调查评估，得到的统计表中列出了有可能建设公路的若干条道路的成本。现请你编写程序，计算出全省畅通需要的最低成本。
输入：
    测试输入包含若干测试用例。每个测试用例的第1行给出评估的道路条数 N、村庄数目M (N, M < =100 )；随后的 N 行对应村庄间道路的成本，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间道路的成本（也是正整数）。为简单起见，村庄从1到M编号。当N为0时，全部输入结束，相应的结果不要输出。
输出：
    对每个测试用例，在1行里输出全省畅通需要的最低成本。若统计数据不足以保证畅通，则输出“?”。
样例输入：
3 3
1 2 1
1 3 2
2 3 4
1 3
2 3 2
0 100
样例输出：
3
?
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
		if (min == -1)
			return -1;
		set[index] = 1;
		res += min;

		for(j = 1;j <= n;j++)
			if (!set[j] && g[index][j] != -1 && (dist[j] == -1 || g[index][j] < dist[j]))
				dist[j] = g[index][j];
	}
}

int main()
{
	int a, b, c;
	int i;
	int m;

	while(cin >> m >> n, m)
	{
		memset(g, -1, sizeof(g));
		for(i = 0;i < m;i++)
		{
			cin >> a >> b >> c;
			g[a][b] = g[b][a] = c;
		}
		res = 0;
		if (prime(1) == -1)
			cout << "?" << endl;
		else
			cout << res << endl;
	}
	return 0;
}

