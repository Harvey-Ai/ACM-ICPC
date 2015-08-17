/*
描述
You are to find the length of the shortest path through a chamber containing obstructing walls. The chamber will always have sides at x = 0, x = 10, y = 0, and y = 10. The initial and final points of the path are always (0, 5) and (10, 5). There will also be from 0 to 18 vertical walls inside the chamber, each with two doorways. The figure below illustrates such a chamber and also shows the path of minimal length. 

输入
The input data for the illustrated chamber would appear as follows.

2 
4 2 7 8 9 
7 3 4.5 6 7

The first line contains the number of interior walls. Then there is a line for each such wall, containing five real numbers. The first number is the x coordinate of the wall (0 < x < 10), and the remaining four are the y coordinates of the ends of the doorways in that wall. The x coordinates of the walls are in increasing order, and within each line the y coordinates are in increasing order. The input file will contain at least one such set of data. The end of the data comes when the number of walls is -1.
输出
The output should contain one line of output for each chamber. The line should contain the minimal path length rounded to two decimal places past the decimal point, and always showing the two decimal places past the decimal point. The line should contain no blanks.
样例输入
1
5 4 6 7 8
2
4 2 7 8 9
7 3 4.5 6 7
-1
样例输出
10.00
10.06
*/

#include <stdio.h>
#include <math.h>
#define DIS(x1, y1, x2, y2) (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 -y2)))

struct dd
{
	double x;
	double y[4];
}door[100];

int check(int i1, int j1, int i2, int j2)
{
	int i, flag;
	double k;
	double y;
	k = (door[i2].y[j2] - door[i1].y[j1]) / (door[i2].x - door[i1].x);

	for(i = i1 + 1;i < i2;i++)
	{
		y = door[i1].y[j1] + k * (door[i].x - door[i1].x);
		flag = 0;
		if (y >= door[i].y[0] && y <= door[i].y[1])
			flag = 1;
		if (y >= door[i].y[2] && y <= door[i].y[3])
			flag = 1;
		if (flag == 0)
			break;
	}
	if (i >= i2)
		return 1;
	return 0;
}

int main()
{
	int i, j, k, l;
	int n;
	double ans[200][4];
	double temp;

	while(scanf("%d", &n), n != -1)
	{
		for(i = 1;i <= n;i++)
		{
			scanf("%lf", &door[i].x);
			scanf("%lf %lf %lf %lf", &door[i].y[0],  &door[i].y[1],  &door[i].y[2],  &door[i].y[3]);
		}

		door[0].x = 0;
		door[0].y[0] = door[0].y[1] = door[0].y[2] = door[0].y[3] = 5;
		door[n + 1].x = 10;
		door[n + 1].y[0] = door[n + 1].y[1] = door[n + 1].y[2] = door[n + 1].y[3] = 5;

		ans[0][0] = ans[0][1] = ans[0][2] = ans[0][3] = 0;
		for(i = 1;i <= n + 1;i++)
			ans[i][0] = ans[i][1] = ans[i][2] = ans[i][3] = -1;

		for(i = 1;i <= n + 1;i++)
			for(k = 0;k < 4;k++)
				for(j = 0;j < i;j++)
					for(l = 0;l < 4;l++)
					{
					//	printf(" %d %d %d %d %d\n", j, l, i, k, check(j, l, i, k));
						if (check(j, l, i, k))
						{
							temp = DIS(door[i].x, door[i].y[k], door[j].x, door[j].y[l]);
						//	printf("%lf %lf %lf %lf\n", door[i].x, door[i].y[k], door[j].x, door[j].y[l]);
						//	printf("%lf %d %d %d %d\n", temp, i, k, j, l);
							if (temp + ans[j][l] < ans[i][k] || ans[i][k] == -1)
								ans[i][k] = temp + ans[j][l];
						//	if (ans[i][k] < door[i].x)
						//	{
						//		printf("%d %d %lf from %d %d %lf temp %lf\n", i, k, ans[i][k], j, l, ans[j][l], temp);
						//	}
						}
					}
		printf("%.2lf\n", ans[n + 1][0]);
	}
	return 0;
}
