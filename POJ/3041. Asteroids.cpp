/*
Description

Bessie wants to navigate her spaceship through a dangerous asteroid field in the shape of an N x N grid (1 <= N <= 500). The grid contains K asteroids (1 <= K <= 10,000), which are conveniently located at the lattice points of the grid. 

Fortunately, Bessie has a powerful weapon that can vaporize all the asteroids in any given row or column of the grid with a single shot.This weapon is quite expensive, so she wishes to use it sparingly.Given the location of all the asteroids in the field, find the minimum number of shots Bessie needs to fire to eliminate all of the asteroids.
Input

* Line 1: Two integers N and K, separated by a single space. 
* Lines 2..K+1: Each line contains two space-separated integers R and C (1 <= R, C <= N) denoting the row and column coordinates of an asteroid, respectively.
Output

* Line 1: The integer representing the minimum number of times Bessie must shoot.
Sample Input

3 4
1 1
1 3
2 2
3 2
Sample Output

2
Hint

INPUT DETAILS: 
The following diagram represents the data, where "X" is an asteroid and "." is empty space: 
X.X 
.X. 
.X. 

OUTPUT DETAILS: 
Bessie may fire across row 1 to destroy the asteroids at (1,1) and (1,3), and then she may fire down column 2 to destroy the asteroids at (2,2) and (3,2).
*/

#include <iostream>
#include <cstring>
using namespace std;

int n;
int graph[505][505];
int visited[505];
int matchX[505], matchY[505];

bool find(int x)
{
	for(int i = 0;i < n;i++)
	{
		if (graph[x][i] && !visited[i])
		{
			visited[i] = 1;
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

int maxMatch()
{
	for(int i = 0;i < n;i++)
		matchX[i] = matchY[i] = -1;
	
	int res = 0;
	for(int i = 0;i < n;i++)
	{
		memset(visited, 0, sizeof(visited));
		if (find(i))
			res++;
	}
	return res;
}

int main()
{
	int m;

	cin >> n >> m;

	for(int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
	}

	cout << maxMatch() << endl;

	return 0;
}
