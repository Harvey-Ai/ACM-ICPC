/*
Description

Have you ever read any book about treasure exploration? Have you ever see any film about treasure exploration? Have you ever explored treasure? If you never have such experiences, you would never know what fun treasure exploring brings to you. 
Recently, a company named EUC (Exploring the Unknown Company) plan to explore an unknown place on Mars, which is considered full of treasure. For fast development of technology and bad environment for human beings, EUC sends some robots to explore the treasure. 
To make it easy, we use a graph, which is formed by N points (these N points are numbered from 1 to N), to represent the places to be explored. And some points are connected by one-way road, which means that, through the road, a robot can only move from one end to the other end, but cannot move back. For some unknown reasons, there is no circle in this graph. The robots can be sent to any point from Earth by rockets. After landing, the robot can visit some points through the roads, and it can choose some points, which are on its roads, to explore. You should notice that the roads of two different robots may contain some same point. 
For financial reason, EUC wants to use minimal number of robots to explore all the points on Mars.
As an ICPCer, who has excellent programming skill, can your help EUC?
Input

The input will consist of several test cases. For each test case, two integers N (1 <= N <= 500) and M (0 <= M <= 5000) are given in the first line, indicating the number of points and the number of one-way roads in the graph respectively. Each of the following M lines contains two different integers A and B, indicating there is a one-way from A to B (0 < A, B <= N). The input is terminated by a single line with two zeros.
Output

For each test of the input, print a line containing the least robots needed.
Sample Input

1 0
2 1
1 2
2 0
0 0
Sample Output

1
1
2
*/

#include <iostream>
#include <cstring>
using namespace std;

int graph[505][505];
int visited[505];
int matchX[505], matchY[505];
int nodeNum;

bool find(int x)
{
	for(int i = 0;i < nodeNum;i++)
	{
		if (graph[x][i] && !visited[i])
		{
			visited[i] = 1;
			if (matchY[i] == -1 || find(matchY[i]))
			{
				matchY[i] = x;
				matchX[x] = i;
				return true;
			}
		}
	}
	return false;
}

int maxMatch()
{
	int res = 0;
	for(int i = 0;i < nodeNum;i++)
		matchX[i] = matchY[i] = -1;

	for(int i = 0;i < nodeNum;i++)
	{
		memset(visited, 0, sizeof(visited));
		if (find(i))
			res++;
	}
	return res;
}

void floyd()
{
	for(int k = 0;k < nodeNum;k++)
		for(int i = 0;i < nodeNum;i++)
		{
			if (k == i)
				continue;
			for(int j = 0;j < nodeNum;j++)
			{
				if (j == k || j == i)
					continue;

				if (graph[i][k] && graph[k][j])
					graph[i][j] = 1;
			}
		}
}

int main()
{
	int n, m;

	while(cin >> n >> m, n || m)
	{
		memset(graph, 0, sizeof(graph));
		for(int i = 0;i < m;i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a - 1][b - 1] = 1;
		}

		
        nodeNum = n;
		floyd();
		cout << n - maxMatch() << endl;
	}

	return 0;
}
