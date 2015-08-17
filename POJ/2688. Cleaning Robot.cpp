/*
Description

Here, we want to solve path planning for a mobile robot cleaning a rectangular room floor with furniture. 

Consider the room floor paved with square tiles whose size fits the cleaning robot (1 * 1). There are 'clean tiles' and 'dirty tiles', and the robot can change a 'dirty tile' to a 'clean tile' by visiting the tile. Also there may be some obstacles (furniture) whose size fits a tile in the room. If there is an obstacle on a tile, the robot cannot visit it. The robot moves to an adjacent tile with one move. The tile onto which the robot moves must be one of four tiles (i.e., east, west, north or south) adjacent to the tile where the robot is present. The robot may visit a tile twice or more. 

Your task is to write a program which computes the minimum number of moves for the robot to change all 'dirty tiles' to 'clean tiles', if ever possible.
Input

The input consists of multiple maps, each representing the size and arrangement of the room. A map is given in the following format. 

w h 
c11 c12 c13 ... c1w 
c21 c22 c23 ... c2w 
... 
ch1 ch2 ch3 ... chw 

The integers w and h are the lengths of the two sides of the floor of the room in terms of widths of floor tiles. w and h are less than or equal to 20. The character cyx represents what is initially on the tile with coordinates (x, y) as follows. 

'.' : a clean tile 
'*' : a dirty tile 
'x' : a piece of furniture (obstacle) 
'o' : the robot (initial position) 

In the map the number of 'dirty tiles' does not exceed 10. There is only one 'robot'. 

The end of the input is indicated by a line containing two zeros.
Output

For each map, your program should output a line containing the minimum number of moves. If the map includes 'dirty tiles' which the robot cannot reach, your program should output -1.
Sample Input

7 5
.......
.o...*.
.......
.*...*.
.......
15 13
.......x.......
...o...x....*..
.......x.......
.......x.......
.......x.......
...............
xxxxx.....xxxxx
...............
.......x.......
.......x.......
.......x.......
..*....x....*..
.......x.......
10 10
..........
..o.......
..........
..........
..........
.....xxxxx
.....x....
.....x.*..
.....x....
.....x....
0 0
Sample Output

8
49
-1
*/


#include <iostream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

struct point
{
	int x, y;

	point()
	{
		x = y = 0;
	}
	point(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
};

int minDist[15][15];
int dp[1 << 12][12];
int dirtyNum;

void dfs(int status, int cur, int val)
{
	if (dp[status][cur] != -1 && dp[status][cur] < val)
		return;

	dp[status][cur] = val;
	for(int i = 0;i < dirtyNum;i++)
	{
		if (status & (1 << i))
			continue;

        if (minDist[cur][i] > 0)
            dfs(status | (1 << i), i, val + minDist[cur][i]);
	}
}


int main()
{
	char titleMap[21][21];
	point dirtyPoint[20];
	int h, w;
	int startIndex;
	
	while(cin >> w >> h, h || w)
	{
		dirtyNum = 0;
		for(int i = 0;i < h;i++)
		{
			cin >> titleMap[i];
			for(int j = 0;j < w;j++)
				if (titleMap[i][j] == '*' || titleMap[i][j] == 'o')
				{
					dirtyPoint[dirtyNum].x = i;
					dirtyPoint[dirtyNum].y = j;
					if (titleMap[i][j] == 'o')
						startIndex = dirtyNum;
					dirtyNum++;
				}
		}
		for(int i = 0;i < dirtyNum;i++)
			for(int j = 0;j < dirtyNum;j++)
				minDist[i][j] = -1;

		for(int i = 0;i < dirtyNum;i++)
		{
			queue<pair<point, int> > pointQ;
			pointQ.push(make_pair(dirtyPoint[i], 0));

			int visited[25][25];
			memset(visited, 0, sizeof(visited));
			visited[dirtyPoint[i].x][dirtyPoint[i].y] = 1;

			while(!pointQ.empty())
			{
				point currentPoint = pointQ.front().first;
				int dist = pointQ.front().second;
				int currentX = currentPoint.x, currentY = currentPoint.y;
				pointQ.pop();

				if (currentX - 1 >= 0 && titleMap[currentX - 1][currentY] != 'x' && !visited[currentX - 1][currentY])
				{
					pointQ.push(make_pair(point(currentX - 1, currentY), dist + 1));
					visited[currentX - 1][currentY] = 1;
				}
				if (currentX + 1 < h && titleMap[currentX + 1][currentY] != 'x' && !visited[currentX + 1][currentY])
				{
					pointQ.push(make_pair(point(currentX + 1, currentY), dist + 1));
					visited[currentX + 1][currentY] = 1;
				}
				if (currentY - 1 >= 0 && titleMap[currentX][currentY - 1] != 'x' && !visited[currentX][currentY - 1])
				{
					pointQ.push(make_pair(point(currentX, currentY - 1), dist + 1));
					visited[currentX][currentY - 1] = 1;
				}
				if (currentY + 1 < w && titleMap[currentX][currentY + 1] != 'x' && !visited[currentX][currentY + 1])
				{
					pointQ.push(make_pair(point(currentX, currentY + 1), dist + 1));
					visited[currentX][currentY + 1] = 1;
				}

				for(int j = 0;j < dirtyNum;j++)
				{
					if (j == i)	continue;
					if (dirtyPoint[j].x == currentPoint.x && dirtyPoint[j].y == currentPoint.y)
						minDist[i][j] = dist;
				}
			}
		}

		for(int i = 0;i < (1 << dirtyNum);i++)
			for(int j = 0;j < dirtyNum;j++)
				dp[i][j] = -1;
		dfs(1 << (startIndex), startIndex, 0);

		int res = -1;
		int fullStatus = (1 << dirtyNum) - 1;
		for(int i = 0;i < dirtyNum;i++)
		{
            if (dp[fullStatus][i] == -1)
                continue;
			if (res == -1 || res > dp[fullStatus][i])
				res = dp[fullStatus][i];
		}

		cout << res << endl;
	}
	return 0;
}
