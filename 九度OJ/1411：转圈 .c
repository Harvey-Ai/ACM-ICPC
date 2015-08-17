/*
题目描述：
在一个有向图有n个顶点（编号从1到n），给一个起点s，问从起点出发，至少经过一条边，回到起点的最短距离。
输入：
输入包括多组，每组输入第一行包括三个整数n,m,s（1<=n<=500,0<=m<=10000,1<=s<=n），接下来有m行，每行包括三个整数a,b,c(1<=a,b<=n,1<=c<=1000)，表示有一条a到b的边，长度为c。
输出：
对每组输入。输出最短距离，如果没有这个一条路径输出"help!"。
样例输入：
5 6 1
1 2 1
2 3 2
3 4 1
4 5 1
3 1 3
4 1 1
样例输出：
5
*/


#include <iostream>
#include <cstring>
using namespace std;

int g[505][505];
int n;

int dig(int s)
{
	int i, j;
	int index, min;
	int dst[505];
	int inset[505];
	memset(inset, 0, sizeof(inset));

	for(i = 1;i <= n + 1;i++)
		dst[i] = -1;

	inset[s] = 1;
	for(i = 1;i <= n + 1;i++)
		dst[i] = g[s][i];
//	cout << dst[n + 1]<< endl;

	for(i = 0;i <= n;i++)
	{
		min = -1;
		index = -1;
		for(j = 1;j <= n + 1;j++)
		{
			if (inset[j])
				continue;
			if ((min == -1 || min > dst[j]) && dst[j] != -1)
			{
				min = dst[j];
				index = j;
		//		cout << "update" << j << dst[j] << endl;
			}
		}

		if(index == -1)
			return -1;

		if (index == n + 1)
		{
		//	cout << "fdasf" << endl;
	//		cout <<i << endl;
	//		cout << index << min << endl;
			return min;
		}

		inset[index] = 1;
		dst[index] = min;

		for(j = 1;j <= n + 1;j++)
			if (!inset[j] && g[index][j] != -1)
			{
				if (g[index][j] + dst[index] < dst[j] || dst[j] == -1)
					dst[j] = g[index][j] + dst[index];
			}
	}
//	cout << "fdaf" << endl;
	return dst[n + 1];
}

int main()
{
	int s, m;
	int i, j, k;
	int a, b, c;
	int res, temp;

	while(cin >> n >> m >> s)
	{
		for(i = 1;i <= n + 1;i++)
			for(j = 1;j <= n + 1;j++)
				g[i][j] = -1;

		res = -1;
		for(i = 0;i < m;i++)
		{
			cin >> a >> b >> c;
			if (a == b)
			{
				if (a == s)
				{
					if (res == -1 || res > c)
						res = c;
				}
			}
			else if (g[a][b] == -1 || g[a][b] > c)
			{
				g[a][b] = c;
				if (b == s)
					g[a][n + 1] = c;
			}
		}
		g[s][n + 1] = -1;

		//floyd
		temp = dig(s);
		if (temp != -1 && res != -1)
			res = temp < res ? temp : res;
		else if (temp != -1 && res == -1)
			res = temp;

		if (res != -1)
			cout << res << endl;
		else
			cout << "help!" << endl;
	}
	return 0;
}
