/*
题目描述：
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
输入：
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
输出：
对输入的每组数据M和N，用一行输出相应的K。
样例输入：
1
7 3
样例输出：
8

*/


#include <iostream>
using namespace std;

//S(n,n) = S(n,1) = 1,
//S(n,k) = S(n-1,k-1) + kS(n-1,k).
int st[15][15];

void initS()
{
	memset(st, 0, sizeof(st));
	//st[0][0] = 1;
	int i, j;

	for(i = 1;i < 11;i++)
		for(j = 1;j <= i;j++)
		{
			if (i == j || j == 1)
				st[i][j] = 1;
			else
			//	6 2				6 1				2 * 6 2
				st[i][j] = st[i - 1][j - 1] + j * st[i - 1][j];
		}
}

int main()
{
	int m, n, ncase;
	int i;
	cin >> ncase;

	initS();
	cout << st[6][2] << endl;
	while(ncase--)
	{
		cin >> n >> m;
		int res = 0;
		for(i = 1;i <= m;i++)
		{
			cout << st[n][i] << endl;
			res += st[n][i];
		}
		cout << res << endl;
	}
	return 0;
}
