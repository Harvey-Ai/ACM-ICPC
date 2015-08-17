/*
Description

把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
Input

第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
Output

对输入的每组数据M和N，用一行输出相应的K。
Sample Input

1
7 3
Sample Output

8
*/


#include <iostream>
using namespace std;

int main()
{
	int ncase;
	cin >> ncase;

	while(ncase--)
	{
		int m, n;
		cin >> m >> n;
		
		int dp[15][15];
		for(int i = 0;i < 15;i++)
			for(int j = 0;j < 15;j++)
				dp[i][j] = 0;
		for(int i = 0;i < 15;i++)
			dp[0][i] = 1;


		for(int i = 1;i <= m;i++)
			for(int j = 1;j <= n;j++)
				if (j > i)
					dp[i][j] = dp[i][i];
				else
					dp[i][j] = dp[i][j - 1] + dp[i - j][j];

		cout << dp[m][n] << endl;
	}
	return 0;
}
