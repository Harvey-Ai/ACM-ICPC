/*
描述
Starting from point (0,0) on a plane, we have written all non-negative integers 0,1,2, ... as shown in the figure. For example, 1, 2, and 3 has been written at points (1,1), (2,0), and (3, 1) respectively and this pattern has continued.


You are to write a program that reads the coordinates of a point (x, y), and writes the number (if any) that has been written at that point. (x, y) coordinates in the input are in the range 0...5000.
输入
The first line of the input is N, the number of test cases for this problem. In each of the N following lines, there is x, and y representing the coordinates (x, y) of a point.
输出
For each point in the input, write the number written at that point or write No Number if there is none.
样例输入
3
4 2
6 6
3 4
样例输出
6
12
No Number
*/


#include <iostream>
using namespace std;

int work(int x, int y)
{
	int	posx = 0, posy = 0;
	int num = 0;

	while(posx <= x || posy < y)
	{
		if (posx == x && posy == y)
			return num;
		else if (posx + 1 == x && posy + 1== y)
			return num + 1;
		else if (posx + 2 == x && posy == y)
			return num + 2;
		else if (posx + 3 == x && posy + 1 == y)
			return num + 3;
		posx += 2;
		posy += 2;
		num += 4;
	}
	return -1;
}

int main()
{
	int res;
	int x, y;
	int ncase;
	cin >> ncase;

	while(ncase--)
	{
		cin >> x >> y;
		res = work(x, y);
		if (res != -1)
			cout << res << endl;
		else
			cout << "No Number" << endl;
	}
	return 0;
}
