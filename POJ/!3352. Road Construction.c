/*
Description

It's almost summer time, and that means that it's almost summer construction time! This year, the good people who are in charge of the roads on the tropical island paradise of Remote Island would like to repair and upgrade the various roads that lead between the various tourist attractions on the island.

The roads themselves are also rather interesting. Due to the strange customs of the island, the roads are arranged so that they never meet at intersections, but rather pass over or under each other using bridges and tunnels. In this way, each road runs between two specific tourist attractions, so that the tourists do not become irreparably lost.

Unfortunately, given the nature of the repairs and upgrades needed on each road, when the construction company works on a particular road, it is unusable in either direction. This could cause a problem if it becomes impossible to travel between two tourist attractions, even if the construction company works on only one road at any particular time.

So, the Road Department of Remote Island has decided to call upon your consulting services to help remedy this problem. It has been decided that new roads will have to be built between the various attractions in such a way that in the final configuration, if any one road is undergoing construction, it would still be possible to travel between any two tourist attractions using the remaining roads. Your task is to find the minimum number of new roads necessary.

Input

The first line of input will consist of positive integers n and r, separated by a space, where 3 ≤ n ≤ 1000 is the number of tourist attractions on the island, and 2 ≤ r ≤ 1000 is the number of roads. The tourist attractions are conveniently labelled from 1 to n. Each of the following r lines will consist of two integers, v and w, separated by a space, indicating that a road exists between the attractions labelled v and w. Note that you may travel in either direction down each road, and any pair of tourist attractions will have at most one road directly between them. Also, you are assured that in the current configuration, it is possible to travel between any two tourist attractions.

Output

One line, consisting of an integer, which gives the minimum number of roads that we need to add.

Sample Input

Sample Input 1
10 12
1 2
1 3
1 4
2 5
2 6
5 6
3 7
3 8
7 8
4 9
4 10
9 10

Sample Input 2
3 3
1 2
2 3
1 3
Sample Output

Output for Sample Input 1
2

Output for Sample Input 2
0

*/


#include <stdio.h>
#include <string.h>
#define N 1005

int g[N][N];
int visit[N];
int dp[N];
int depth[N];

void dfs(int k,int dep, int n)
{
	int i;
	if (!visit[k])
	{
		dp[k] = dep;
		depth[k] = dep;
		visit[k] = 1;
	}

	visit[k] = 1;

	for(i = 1;i <= n;i++)
	{
		if (g[k][i])
		{
			if (!visit[i])
				dfs(i, k + 1, n);
			
			if (dp[k] > dp[i])
				dp[k] = dp[i];

			if (dp[k] >= depth[k])
				res++;
		}
	}
}

int main()
{
	int n, r;
	int w, v;
	scanf("%d %d", &n, &r);
	memset(g, 0, sizeof(g));
	while(r--)
	{
		scanf("%d %d", &v, &w);
		g[v][w] = g[w][v] = 1;
	}

	res = 0;
	memset(dp, 0, sizeof(dp));
	memset(visit, 0, sizeof(visit));
	memset(depth, 0, sizeof(depth));
	dfs(1, 1, n);
	printf("%d\n", res);
	return 0;
}
