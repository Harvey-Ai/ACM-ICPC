/*
Description

Farmer John has purchased a lush new rectangular pasture composed of M by N (1 ≤ M ≤ 12; 1 ≤ N ≤ 12) square parcels. He wants to grow some yummy corn for the cows on a number of squares. Regrettably, some of the squares are infertile and can't be planted. Canny FJ knows that the cows dislike eating close to each other, so when choosing which squares to plant, he avoids choosing squares that are adjacent; no two chosen squares share an edge. He has not yet made the final choice as to which squares to plant.

Being a very open-minded man, Farmer John wants to consider all possible options for how to choose the squares for planting. He is so open-minded that he considers choosing no squares as a valid option! Please help Farmer John determine the number of ways he can choose the squares to plant.

Input

Line 1: Two space-separated integers: M and N 
Lines 2..M+1: Line i+1 describes row i of the pasture with N space-separated integers indicating whether a square is fertile (1 for fertile, 0 for infertile)
Output

Line 1: One integer: the number of ways that FJ can choose the squares modulo 100,000,000.
Sample Input

2 3
1 1 1
0 1 0
Sample Output

9
Hint

Number the squares as follows:
1 2 3
  4  

There are four ways to plant only on one squares (1, 2, 3, or 4), three ways to plant on two squares (13, 14, or 34), 1 way to plant on three squares (134), and one way to plant on no squares. 4+3+1+1=9.

*/

#include <iostream>
#include <cstring>
using namespace std;

#define MOD 100000000

bool check(int status)
{
	int onePos = -2;
	for(int i = 0;status;i++)
	{
		if (status & 0x01)
		{
			if (i == onePos + 1)
				return false;
			onePos = i;
		}
		status >>= 1;
	}

	return true;
}

int main()
{
	int m, n;
	cin >> m >> n;

	int twoPower[15];
	twoPower[0] = 1;
	for(int i = 1;i < 15;i++)
		twoPower[i] = twoPower[i - 1] * 2;

	int arr[15][15];
	for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];

	int dp[m][twoPower[n]];
	memset(dp, 0, sizeof(dp));

	for(int i = 0;i < twoPower[n];i++)
	{
		int temp = i;
		int flag = 1;
		if (!check(i))
		{
			dp[0][i] = 0;
			continue;
		}

		for(int j = n - 1;j >= 0;j--)
		{
			if (temp & 0x01 == 1 && arr[0][j] == 0)
			{
				flag = 0;
				break;
			}
			temp >>= 1;
		}
		if (flag)
			dp[0][i] = 1;
		else
			dp[0][i] = 0;
	}

	for(int i = 1;i < m;i++)
		for(int j = 0;j < twoPower[n];j++)
		{
			int temp = j;
			if (!check(j))
			{
				dp[i][j] = 0;
				continue;
			}

			int flag = 1;
			for(int k = n - 1;k >= 0;k--)
			{
				if (temp & 0x01 == 1 && arr[i][k] == 0)
					flag = 0;
				temp >>= 1;
			}
			if (flag == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			for(int k = 0;k < twoPower[n];k++)
			{
				int flag = 1;
				int temp1 = j, temp2 = k;
				for(int l = n - 1;l >= 0;l--)
				{
					if (temp1 & 0x01 == 1 && temp2 &0x01 == 1)
					{
						flag = 0;
						break;
					}
					temp1 >>= 1, temp2 >>= 1;
				}

				if (flag)
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD ;
			}
		}

	int res = 0;
	for(int i = 0;i < twoPower[n];i++)
		res = (res + dp[m - 1][i]) % MOD;

	cout << res << endl;
	return 0;
}
