/*
Description

The gopher family, having averted the canine threat, must face a new predator. 

The are n gophers and m gopher holes, each at distinct (x, y) coordinates. A hawk arrives and if a gopher does not reach a hole in s seconds it is vulnerable to being eaten. A hole can save at most one gopher. All the gophers run at the same velocity v. The gopher family needs an escape strategy that minimizes the number of vulnerable gophers.
Input

The input contains several cases. The first line of each case contains four positive integers less than 100: n, m, s, and v. The next n lines give the coordinates of the gophers; the following m lines give the coordinates of the gopher holes. All distances are in metres; all times are in seconds; all velocities are in metres per second.
Output

Output consists of a single line for each case, giving the number of vulnerable gophers.
Sample Input

2 2 5 10
1.0 1.0
2.0 2.0
100.0 100.0
20.0 20.0
Sample Output

1
*/


#include <iostream>
#include <cstring>
using namespace std;

int graph[105][105];
int visited[105];
int matchX[105], matchY[105];
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


bool check(double start[2], double end[2], double limit)
{
	double dist = (start[0] - end[0]) * (start[0] - end[0]) + (start[1] - end[1]) * (start[1] - end[1]);
	return dist <= (limit * limit);
}

int main()
{
	int n, m, s, v;
	double gopherPos[105][2], hole[105][2];
	
	while(cin >> n >> m >> s >> v)
	{
		for(int i = 0;i < n;i++)
			cin >> gopherPos[i][0] >> gopherPos[i][1];

		for(int i = 0;i < m;i++)
			cin >> hole[i][0] >> hole[i][1];

		memset(graph, 0, sizeof(graph));
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				if (check(gopherPos[i], hole[j], s * v))
					graph[i][j] = 1;

		nodeNum = max(m, n);
		int res = maxMatch();
		cout << n - res << endl;
	}
	return 0;
}
