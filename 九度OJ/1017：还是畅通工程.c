/*
题目描述：
    某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。
输入：
    测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。
    当N为0时，输入结束，该用例不被处理。
输出：
    对每个测试用例，在1行里输出最小的公路总长度。
样例输入：
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
样例输出：
3
5
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
	int a, b, c;
	int i;

	while(cin >> n, n)
	{
		memset(g, -1, sizeof(g));
		for(i = 0;i < (n * (n - 1)) / 2;i++)
		{
			cin >> a >> b >> c;
			g[a][b] = g[b][a] = c;
		}
		res = 0;
		prime(1);
		cout << res << endl;
	}
	return 0;
}
