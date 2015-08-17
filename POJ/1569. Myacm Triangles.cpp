/*
Description



There has been considerable archeological work on the ancient Myacm culture. Many artifacts have been found in what have been called power fields: a fairly small area, less than 100 meters square where there are from four to fifteen tall monuments with crystals on top. Such an area is mapped out above. Most of the artifacts discovered have come from inside a triangular area between just three of the monuments, now called the power triangle. After considerable analysis archeologists agree how this triangle is selected from all the triangles with three monuments as vertices: it is the triangle with the largest possible area that does not contain any other monuments inside the triangle or on an edge of the triangle. Each field contains only one such triangle. 

Archeological teams are continuing to find more power fields. They would like to automate the task of locating the power triangles in power fields. Write a program that takes the positions of the monuments in any number of power fields as input and determines the power triangle for each power field. 

A useful formula: the area of a triangle with vertices (x1, y1), (x2, y2), and (x3, y3) is the absolute value of 

0.5 * [(y3 - y1)(x2 - x1) - (y2 - y1)(x3 - x1)]. 
Input

For each power field there are several lines of data. The first line is the number of monuments: at least 4, and at most 15. For each monument there is a data line that starts with a one character label for the monument and is followed by the coordinates of the monument, which are nonnegative integers less than 100. The first label is A, and the next is B, and so on. 

There is at least one such power field described. The end of input is indicated by a 0 for the number of monuments. The first sample data below corresponds to the diagram in the problem. 
Output

For each power field there is one line of output. It contains the three labels of the vertices of the power triangle, listed in increasing alphabetical order, with no spaces.
Sample Input

6
A 1 0
B 4 0
C 0 3
D 1 3
E 4 4
F 0 6
4
A 0 0
B 1 0
C 99 0
D 99 99
0
Sample Output

BEF
BCD
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char label[20];
int x[20], y[20];

int isLeft(int p1, int p2, int p)
{
	int xV = x[p2] - x[p1];
	int yV = y[p2] - y[p1];

	int px = x[p] - x[p1];
	int py = y[p] - y[p1];

	if (xV * py - yV * px > 0)
		return 1;
	else if (xV * py - yV * px < 0)
		return -1;
	if (xV * py - yV * px == 0)
		return 0;
}

bool inTriangle(int p1, int p2, int p3, int p)
{
	int flag1 = isLeft(p1, p2, p);
	int flag2 = isLeft(p2, p3, p);
	int flag3 = isLeft(p3, p1, p);	

	if ((flag1 <= 0 && flag2 <= 0 && flag3 <= 0) ||
			flag1 >= 0 && flag2 >= 0 && flag3 >= 0)
		return false;
	return true;
}

int main()
{
	int n;

	while(cin >> n, n)
	{
		for(int i = 0;i < n;i++)
		{
			getchar();
			scanf("%c", &label[i]);
			scanf("%d %d", &x[i], &y[i]);
		}
		
		int area = 0;
		char res[4];
		for(int i = 0;i < n;i++)
			for(int j = i + 1;j < n;j++)
				for(int k = j + 1;k < n;k++)
				{
					int flag = 1;
					for(int l = 0;l < n;l++)
					{
						if (l == i || l == j || l == k)
							continue;
						if (!inTriangle(i, j, k, l))
						{
							flag = 0;
							break;
						}
					}
					int x1 = x[j] - x[i], y1 = y[j] - y[i];
					int x2 = x[k] - x[j], y2 = y[k] - y[j];
					int x3 = x[i] - x[k], y3 = y[i] - y[k];
					
					int temp = abs(x1 * y2 - x2 * y1) + abs(x2 * y3 - x3 * y2) + abs(x3 * y1 - x1 * y3);
					if (temp > area && flag)
					{
						res[0] = label[i];
						res[1] = label[j];
						res[2] = label[k];
						area = temp;
					}
				}
		res[3] = '\0';
		sort(res, res + 3);
		cout << res << endl;
	}
	return 0;
}

