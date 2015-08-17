/*
Description

On a grid map there are n little men and n houses. In each unit time, every little man can move one unit step, either horizontally, or vertically, to an adjacent point. For each little man, you need to pay a $1 travel fee for every step he moves, until he enters a house. The task is complicated with the restriction that each house can accommodate only one little man. 

Your task is to compute the minimum amount of money you need to pay in order to send these n little men into those n different houses. The input is a map of the scenario, a '.' means an empty space, an 'H' represents a house on that point, and am 'm' indicates there is a little man on that point.


You can think of each point on the grid map as a quite large square, so it can hold n little men at the same time; also, it is okay if a little man steps on a grid with a house without entering that house.
Input

There are one or more test cases in the input. Each case starts with a line giving two integers N and M, where N is the number of rows of the map, and M is the number of columns. The rest of the input will be N lines describing the map. You may assume both N and M are between 2 and 100, inclusive. There will be the same number of 'H's and 'm's on the map; and there will be at most 100 houses. Input will terminate with 0 0 for N and M.
Output

For each test case, output one line with the single integer, which is the minimum amount, in dollars, you need to pay.
Sample Input

2 2
.m
H.
5 5
HH..m
.....
.....
.....
mm..H
7 8
...H....
...H....
...H....
mmmHmmmm
...H....
...H....
...H....
0 0
Sample Output

2
10
28
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int p, h;
int lx[105], ly[105];
int visitX[105], visitY[105];
int matchX[105], matchY[105];
int graph[105][105];

bool find(int x)
{
	visitX[x] = 1;
	int n = p;
	for(int i = 0;i < n;i++)
	{
		if (graph[x][i] != 0 && !visitY[i] && lx[x] + ly[i] == graph[x][i])
		{
			visitY[i] = 1;
			if (matchY[i] == -1 || find(matchY[i]))
			{
				matchX[x] = i;
				matchY[i] = x;
				return true;
			}
		}
	}
	return false;

}

int bestMatch()
{
	int n = p;
	for(int i = 0;i < n;i++)
		matchX[i] = matchY[i] = -1;
	for(int i = 0;i < n;i++)
	{
		ly[i] = 0;
		lx[i] = -100000000;
		for(int j = 0;j < n;j++)
			if (lx[i] < graph[i][j])
				lx[i] = graph[i][j];
	}

	int looseTime = 0;
	for(int i = 0;i < n;i++)
	{
		memset(visitX, 0, sizeof(visitX));
		memset(visitY, 0, sizeof(visitY));
		while(!find(i) && looseTime < n)
		{
			int dis = 10000000;
			for(int j = 0;j < n;j++)
			{
				if (visitX[j])
					for(int k = 0;k < n;k++)
					{
						if (!visitY[k])
							dis = min(dis, lx[j] + ly[k] - graph[j][k]);
					}
			}

			for(int j = 0;j < n;j++)
			{
				if (visitX[j])
					lx[j] -= dis;
				if (visitY[j])
					ly[j] += dis;
			}
			memset(visitX, 0, sizeof(visitX));
			memset(visitY, 0, sizeof(visitY));
		//	looseTime++;
		}
	}

	int matchValue = 0;
	for(int i = 0;i < n;i++)
		matchValue += graph[i][matchX[i]];

	return matchValue;
}

int main()
{
	int m, n;
	int person[105][2], home[105][2];
	
	while(cin >> m >> n, m || n)
	{
		string homeMap[105];
		for(int i = 0;i < m;i++)
			cin >> homeMap[i];

		p = h = 0;
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++)
			{
				if (homeMap[i][j] == 'm')
				{
					person[p][0] = i;
					person[p++][1] = j;
				}
				else if (homeMap[i][j] == 'H')
				{
					home[h][0] = i;
					home[h++][1] = j;
				}
			}

		for(int i = 0;i < p;i++)
		{
			for(int j = 0;j < h;j++)
				graph[i][j] = -(abs(person[i][0] - home[j][0]) +
						abs(person[i][1] - home[j][1]));
		}
	
		int res = bestMatch();
		cout << -res << endl;
	}

	return 0;
}
