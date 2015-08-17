/*
Description

There is a straight highway with villages alongside the highway. The highway is represented as an integer axis, and the position of each village is identified with a single integer coordinate. There are no two villages in the same position. The distance between two positions is the absolute value of the difference of their integer coordinates. 

Post offices will be built in some, but not necessarily all of the villages. A village and the post office in it have the same position. For building the post offices, their positions should be chosen so that the total sum of all distances between each village and its nearest post office is minimum. 

You are to write a program which, given the positions of the villages and the number of post offices, computes the least possible sum of all distances between each village and its nearest post office. 
Input

Your program is to read from standard input. The first line contains two integers: the first is the number of villages V, 1 <= V <= 300, and the second is the number of post offices P, 1 <= P <= 30, P <= V. The second line contains V integers in increasing order. These V integers are the positions of the villages. For each position X it holds that 1 <= X <= 10000.
Output

The first line contains one integer S, which is the sum of all distances between each village and its nearest post office.
Sample Input

10 5
1 2 3 6 7 9 11 22 44 50
Sample Output

9
*/


#include <stdio.h>
#include <string.h>
#define NV 305
#define NP 35

int villages[NV];
int dp[NV][NP];
int dist[NV][NV], minDD[NV][NV];
int sumD[NV];

int minD(int s, int t)
{
	int i, minDist = 0;

	if (minDD[s][t])
		return minDD[s][t];
	for(i = s + 1;i < t;i++)
		if(dist[i][s] < dist[i][t])
			minDist += dist[i][s];
		else
			minDist += dist[i][t];
	minDD[s][t] = minDist;
	return minDist;
}

int main()
{
	int i, j, k, s, n, m, res, min, temp;
	scanf("%d %d", &n, &m);
	for(i = 0;i < n;i++)
		scanf("%d", &villages[i]);

	memset(minDD, 0, sizeof(minDD));

	for(i = 0;i < n;i++)
		for(j = i;j < n;j++)
			dist[i][j] = dist[j][i] = villages[j] - villages[i];
	
	for(i = 0;i < n;i++)
	{
		dp[i][0] = 0;
		for(j = 0;j < n;j++)
			dp[i][0] += dist[j][i];
	}


	for(i = 0;i < n;i++)
	{
		sumD[i] = 0;
		for(j = i + 1;j < n;j++)
			sumD[i] += dist[i][j];
	}

	for(i = 1;i < m;i++)
		for(j = i;j < n;j++)
		{
			min = 10000000;
			for(k = i - 1;k < j;k++)
			{
				temp = dp[k][i-1] + minD(k, j) - sumD[k];
				if (temp < min)
					min = temp;
			}
			dp[j][i] = min + sumD[j];
		}
	
	res = 10000000;
	for(j = m - 1;j < n;j++)
		if (res > dp[j][m-1])
			res = dp[j][m-1];
	printf("%d\n", res);
	return 0;
}
