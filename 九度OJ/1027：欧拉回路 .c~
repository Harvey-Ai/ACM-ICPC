/*
题目描述：
    欧拉回路是指不令笔离开纸面，可画过图中每条边仅一次，且可以回到起点的一条回路。现给定一个图，问是否存在欧拉回路？
输入：
    测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是节点数N ( 1 < N < 1000 )和边数M；随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个节点的编号（节点从1到N编号）。当N为0时输入结束。
输出：
    每个测试用例的输出占一行，若欧拉回路存在则输出1，否则输出0。
样例输入：
3 3
1 2
1 3
2 3
3 2
1 2
2 3
0
样例输出：
1
0
*/

#include <iostream>
#include <cstring>
using namespace std;


int g[1005][1005];
int used[1005];
int n;

int dfs(int p)
{
	used[p] = 1;
	for(int i = 1;i <= n;i++)
		if (!used[i] && g[i][p])
			dfs(i);
}

int main()
{
	int m;
	int du[1005];
	int i, a, b;

	while(cin >> n, n)
	{
		cin >> m;
		memset(g, 0, sizeof(g));
		memset(used, 0, sizeof(used));
		memset(du, 0, sizeof(du));
		for(i = 0;i < m;i++)
		{
			cin >> a >> b;
			g[a][b] = g[b][a] = 1;
			du[a]++;
			du[b]++;
		}
		dfs(1);
		for(i = 1;i <= n;i++)
			if (!used[i])
				break;
		if (i <= n)
		{
			cout << 0 << endl;
			continue;
		}
		for(i = 1;i <= n;i++)
			if (du[i] % 2)
				break;
		if (i <= n)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
}
