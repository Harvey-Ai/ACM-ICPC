/*
Description

司令部的将军们打算在N*M的网格地图上部署他们的炮兵部队。一个N*M的地图由N行M列组成，地图的每一格可能是山地（用"H" 表示），也可能是平原（用"P"表示），如下图。在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示： 


如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：沿横向左右各两格，沿纵向上下各两格。图上其它白色网格均攻击不到。从图上可见炮兵的攻击范围不受地形的影响。 
现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。 
Input

第一行包含两个由空格分割开的正整数，分别表示N和M； 
接下来的N行，每一行含有连续的M个字符('P'或者'H')，中间没有空格。按顺序表示地图中每一行的数据。N <= 100；M <= 10。
Output

仅一行，包含一个整数K，表示最多能摆放的炮兵部队的数量。
Sample Input

5 4
PHPP
PPHH
PPPP
PHPP
PHHP
Sample Output

6
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int statusNum;
int status[105];
int statusOneNum[105];
int armMap[105];
int dp[105][105][105];
int m, n;

void getStatus(int n)
{
	statusNum = 0;
	int maxL = 1;
	for(int i = 0;i < n;i++)
		maxL *= 2;

	for(int i = 0;i < maxL;i++)
	{
		if (i & (i << 1))	continue;
		if (i & (i << 2))	continue;
		status[statusNum++] = i;
	}
}

void getStatusOneNum()
{
	for(int i = 0;i < statusNum;i++)
	{
		int temp = status[i];
		int oneSum = 0;
		while(temp)
		{
			temp = temp & (temp - 1);
			oneSum++;
		}
		statusOneNum[i] = oneSum;
	}
}


int main()
{
	cin >> m >> n;

	string arr[105];
	for(int i = 0;i < m;i++)
		cin >> arr[i];

	for(int i = 0;i < m;i++)
	{
		armMap[i] = 0;
		for(int j = 0;j < n;j++)
			if (arr[i][j] == 'P')
				armMap[i] |= 1 << j;
	}

	getStatus(n);
	getStatusOneNum();
	memset(dp, 0, sizeof(dp));

	for(int i = 0;i < statusNum;i++)
		if (!(~armMap[0] & status[i]))
			dp[0][0][i] = statusOneNum[i];

	for(int i = 1;i < m;i++)
		for(int j = 0;j < statusNum;j++)
		{
			if (~armMap[i] & status[j])
				continue;

			for(int k = 0;k < statusNum;k++)
			{
				if (~armMap[i - 1] & status[k])
					continue;
				if (status[j] & status[k])
					continue;

				if (i > 1)
				{
					for(int l = 0;l < statusNum;l++)
					{
						if (~armMap[i - 2] & status[l])
							continue;
						if (status[l] & status[k] || status[l] & status[j])
							continue;
						
						if (dp[i][k][j] < dp[i - 1][l][k] + statusOneNum[j])
							dp[i][k][j] = dp[i - 1][l][k] + statusOneNum[j];
					}
				}
				else
					dp[i][k][j] = statusOneNum[j] + statusOneNum[k];
			}
		}

	int res = 0;
	for(int i = 0;i < m;i++)
		for(int j = 0;j < statusNum;j++)
			for(int k = 0;k < statusNum;k++)
				if (res < dp[i][j][k])
					res = dp[i][j][k];
	cout << res << endl;

	return 0;
}
