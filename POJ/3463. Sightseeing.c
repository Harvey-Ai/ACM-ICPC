/*
Description

Tour operator Your Personal Holiday organises guided bus trips across the Benelux. Every day the bus moves from one city S to another city F. On this way, the tourists in the bus can see the sights alongside the route travelled. Moreover, the bus makes a number of stops (zero or more) at some beautiful cities, where the tourists get out to see the local sights.

Different groups of tourists may have different preferences for the sights they want to see, and thus for the route to be taken from S to F. Therefore, Your Personal Holiday wants to offer its clients a choice from many different routes. As hotels have been booked in advance, the starting city S and the final city F, though, are fixed. Two routes from S to F are considered different if there is at least one road from a city A to a city B which is part of one route, but not of the other route.

There is a restriction on the routes that the tourists may choose from. To leave enough time for the sightseeing at the stops (and to avoid using too much fuel), the bus has to take a short route from S to F. It has to be either a route with minimal distance, or a route which is one distance unit longer than the minimal distance. Indeed, by allowing routes that are one distance unit longer, the tourists may have more choice than by restricting them to exactly the minimal routes. This enhances the impression of a personal holiday.


For example, for the above road map, there are two minimal routes from S = 1 to F = 5: 1 → 2 → 5 and 1 → 3 → 5, both of length 6. There is one route that is one distance unit longer: 1 → 3 → 4 → 5, of length 7.

Now, given a (partial) road map of the Benelux and two cities S and F, tour operator Your Personal Holiday likes to know how many different routes it can offer to its clients, under the above restriction on the route length.

Input

The first line of the input file contains a single number: the number of test cases to follow. Each test case has the following format:

One line with two integers N and M, separated by a single space, with 2 ≤ N ≤ 1,000 and 1 ≤ M ≤ 10, 000: the number of cities and the number of roads in the road map.

M lines, each with three integers A, B and L, separated by single spaces, with 1 ≤ A, B ≤ N, A ≠ B and 1 ≤ L ≤ 1,000, describing a road from city A to city B with length L.

The roads are unidirectional. Hence, if there is a road from A to B, then there is not necessarily also a road from B to A. There may be different roads from a city A to a city B.

One line with two integers S and F, separated by a single space, with 1 ≤ S, F ≤ N and S ≠ F: the starting city and the final city of the route.

There will be at least one route from S to F.

Output

For every test case in the input file, the output should contain a single number, on a single line: the number of routes of minimal length or one distance unit longer. Test cases are such, that this number is at most 109 = 1,000,000,000.

Sample Input

2
5 8
1 2 3
1 3 2
1 4 5
2 3 1
2 5 3
3 4 2
3 5 4
4 5 3
1 5
5 6
2 3 1
3 2 1
3 1 10
4 5 2
5 2 7
5 2 7
4 1
Sample Output

3
2
Hint

The first test case above corresponds to the picture in the problem description.
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define MAX 0x7fffffff
#define NMAX 1005
int dis[NMAX];
int used[NMAX];
vector < pair <int, int> > graph[NMAX], gg[NMAX];
int dp[NMAX][2];
int v, ss;

void dijkstra(int n)
{
	int i, j, u, ldis;
	int p;
	for (i = 0; i < n; i++)
	{
		dis[i] = MAX;
		used[i] = 0;
		dp[i][0] = dp[i][1] = 0;
	}

	dp[v][0] = 1;
	dp[v][1] = 0;
	dis[v] = 0;
	ldis = 0;
	u = v;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < gg[u].size(); j++)
		{
			p = gg[u][j].first;
			if (used[p] && dis[p] + gg[u][j].second == ldis)
			{
				dp[u][0] += dp[p][0];
			//	dp[u][1] += dp[p][1];
			}
		}

		used[u] = 1;
		for (j = 0; j < graph[u].size(); j++)
		{
			p = graph[u][j].first;
			if (!used[p] && dis[u] + graph[u][j].second < dis[p])
			{
				dis[p] = dis[u] + graph[u][j].second;
			}
		}
		
		ldis = MAX;
		for (j = 0; j < n; j++)
			if (dis[j] < ldis && used[j] == 0)//&&dis[j]>0)
			{
				ldis = dis[j];
				u = j;
			}
	}
}

int work(int n)
{
	int u = v;
	int i, j;
	int ldis = 0;
	int p;
	memset(used, 0, sizeof(used));
	used[u] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < gg[u].size(); j++)
		{
			p = gg[u][j].first;
			if (dis[p] + gg[u][j].second == ldis)
				dp[u][1] += dp[p][1];
			else if (dis[p] + gg[u][j].second == ldis + 1)
				dp[u][1] += dp[p][0];
		}
	

		ldis = MAX;
		for (j = 0; j < n; j++)
			if (dis[j] < ldis && !used[j])//&&dis[j]>0)
			{
				ldis = dis[j];
				u = j;
			}
		used[u] = 1;
	}
	return 0;
}

int main()
{
	int ncase;
	int n, m;
	int a, b, c;
	int i, j;
	scanf("%d", &ncase);
	for(i = 0;i < NMAX;i++)
	{
		graph[i].clear();
		gg[i].clear();
	}
	while(ncase--)
	{
		scanf("%d %d", &n, &m);
		while(m--)
		{
			scanf("%d %d %d", &a, &b, &c);
			graph[a - 1].push_back(make_pair(b - 1, c));
			gg[b - 1].push_back(make_pair(a - 1, c));
		}
		scanf("%d %d", &v, &ss);
		v--;ss--;
		dijkstra(n);
		work(n);
		printf("%d\n", dp[ss][0] + dp[ss][1]);
		while(n--)
		{
			graph[n].clear();
			gg[n].clear();
		}
	}
	return 0;
}

