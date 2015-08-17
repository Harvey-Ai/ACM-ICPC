/*
Description

The Pizazz Pizzeria prides itself in delivering pizzas to its customers as fast as possible. Unfortunately, due to cutbacks, they can afford to hire only one driver to do the deliveries. He will wait for 1 or more (up to 10) orders to be processed before he starts any deliveries. Needless to say, he would like to take the shortest route in delivering these goodies and returning to the pizzeria, even if it means passing the same location(s) or the pizzeria more than once on the way. He has commissioned you to write a program to help him.

Input

Input will consist of multiple test cases. The first line will contain a single integer n indicating the number of orders to deliver, where 1 ≤ n ≤ 10. After this will be n + 1 lines each containing n + 1 integers indicating the times to travel between the pizzeria (numbered 0) and the n locations (numbers 1 to n). The jth value on the ith line indicates the time to go directly from location i to location j without visiting any other locations along the way. Note that there may be quicker ways to go from i to j via other locations, due to different speed limits, traffic lights, etc. Also, the time values may not be symmetric, i.e., the time to go directly from location i to j may not be the same as the time to go directly from location j to i. An input value of n = 0 will terminate input.

Output

For each test case, you should output a single number indicating the minimum time to deliver all of the pizzas and return to the pizzeria.

Sample Input

3
0 1 10 10
1 0 1 2
10 1 0 10
10 2 10 0
0
Sample Output

8

*/

#include <iostream>
#include <cstdio>
using namespace std;

int graph[15][15];
int dp[1 << 11][11];
int n;

void floyd()
{
	for(int k = 0;k <= n;k++)
		for(int i = 0;i <= n;i++)
		{
			if (i == k)
				continue;
			for(int j = 0;j <= n;j++)
			{
				if (i == j || j == k)
					continue;

				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
}

void dfs(int status, int cur, int val)
{
	if (dp[status][cur] != -1 && dp[status][cur] < val)
		return;

	dp[status][cur] = val;
	for(int i = 1;i <= n;i++)
	{
		if (status & (1 << i))
			continue;

		dfs(status | (1 << i), i, val + graph[cur][i]);
	}
}


int main()
{
	while(cin >> n, n)
	{
		for(int i = 0;i < n + 1;i++)
			for(int j = 0;j < n + 1;j++)
				scanf("%d", &graph[i][j]);

		floyd();
		for(int i = 0;i < (1 << (n + 1));i++)
			for(int j = 0;j < n + 1;j++)
				dp[i][j] = -1;
		dfs(1, 0, 0);

		int res = 1000000;
		for(int i = 0;i < n + 1;i++)
			if (res > dp[(1 << (n + 1)) - 1][i] + graph[i][0] && dp[(1 << (n + 1)) - 1][i] != -1)
				res = dp[(1 << (n + 1)) - 1][i] + graph[i][0];
		cout << res << endl;
	}
	return 0;
}
