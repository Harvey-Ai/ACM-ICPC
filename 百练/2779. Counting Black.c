/*
描述
There is a board with 100 * 100 grids as shown below. The left-top gird is denoted as (1, 1) and the right-bottom grid is (100, 100). 

We may apply three commands to the board: 

1.	WHITE x, y, L // Paint a white square on the board, 
// the square is defined by left-top grid (x, y)
// and right-bottom grid (x+L-1, y+L-1)

2.	BLACK x, y, L // Paint a black square on the board, 
// the square is defined by left-top grid (x, y)
// and right-bottom grid (x+L-1, y+L-1)

3.	TEST x, y, L // Ask for the number of black grids 
// in the square (x, y)- (x+L-1, y+L-1) 

In the beginning, all the grids on the board are white. We apply a series of commands to the board. Your task is to write a program to give the numbers of black grids within a required region when a TEST command is applied.
输入
The first line of the input is an integer t (1 <= t <= 100), representing the number of commands. In each of the following lines, there is a command. Assume all the commands are legal which means that they won't try to paint/test the grids outside the board.
输出
For each TEST command, print a line with the number of black grids in the required region.
样例输入
5
BLACK 1 1 2
BLACK 2 2 2
TEST 1 1 3
WHITE 2 1 1
TEST 1 1 3
样例输出
7
6
*/

#include <iostream>
#include <cstring>
using namespace std;

int color[105][105];
void paint(int x1, int y1, int x2, int y2, int cl)
{
	int i, j;
	for(i = x1;i <= x2;i++)
		for(j = y1;j <= y2;j++)
			color[i][j] = cl;
}

int main()
{
	int i, j, n;
	int x, y, l;
	int cnt;
	char command[1005];
	cin >> n;
	for(i = 0;i < 101;i++)
		for(j = 0;j < 101;j++)
			color[i][j] = 0;
	while(n--)
	{
		cin >> command;
		cin >> x >> y >> l;
		if (strcmp(command, "BLACK") == 0)
			paint(x, y, x + l -1, y + l - 1, 1);
		if (strcmp(command, "WHITE") == 0)
			paint(x, y, x + l -1, y + l - 1, 0);
		if (strcmp(command, "TEST") == 0)
		{
			cnt = 0;
			for(i = x;i < l + x;i++)
				for(j = y;j < l + y;j++)
					if (color[i][j] == 1)
						cnt++;
			cout << cnt << endl;
		}
	}
	return 0;
}
