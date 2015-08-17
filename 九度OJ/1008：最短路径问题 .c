/*
题目描述：
给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s终点t，要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，则输出花费最少的。
输入：
输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。最后一行是两个数 s,t;起点s，终点t。n和m为0时输入结束。
(1<n<=1000, 0<m<100000, s != t)
输出：
输出 一行有两个数， 最短距离及其花费。
样例输入：
3 2
1 2 5 6
2 3 4 5
1 3
0 0
样例输出：
9 11

*/


#include <iostream>
#include <cstring>
using namespace std;


int n;
int g[1005][1005], p[1005][1005];
int resD, resP;
int s, t;

void dijkstra()
{
	int i;
	int set[1005];
	int distance[1005], expense[1005];
	memset(set, 0, sizeof(set));
	memset(distance, -1, sizeof(distance));
	memset(expense, -1, sizeof(expense));


	set[s] = 1;
	distance[s] = 0;
	expense[s] = 0;
	for(i = 1;i <= n;i++)
		if (g[i][s] != -1)
		{
			distance[i] = g[i][s];
			expense[i] = p[i][s];
		}

	while(1)
	{
		int minD = -1, minP = -1;
		int index = -1;
		for(i = 1;i <= n;i++)
			if (!set[i] && distance[i] != -1 && (minD == -1 || distance[i] < minD || distance[i] == minD && (minP == -1 || minP > expense[i])))
			{
				minD = distance[i];
				minP = expense[i];
				index = i;
			}

		distance[index] = minD;
		expense[index] = minP;
		set[index] = 1;

		if (index == t)
		{
			resD = minD;
			resP = minP;
			return;
		}

		for(i = 1;i <= n;i++)
		{
			if (!set[i] && g[i][index] != -1)
			{
				if (distance[i] == -1 || distance[i] > minD + g[i][index])
				{
					distance[i] = minD + g[i][index];
					expense[i] = minP + p[i][index];
				}
			}
		}
	}
}

int main()
{
	int m;

	while(cin >> n >> m, n)
	{
		int a, b, d, pp;
		int i;
		memset(g, -1, sizeof(g));
		memset(p, -1, sizeof(p));
		for(i = 0;i < m;i++)
		{
			cin >> a >> b >> d >> pp;
			g[a][b] = g[b][a] = d;
			p[a][b] = p[b][a] = pp;
		}

		cin >> s >> t;
		dijkstra();
		cout << resD << " " << resP << endl;
	}
	return 0;
}
