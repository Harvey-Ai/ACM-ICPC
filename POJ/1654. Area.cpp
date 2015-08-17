/*
Description

You are going to compute the area of a special kind of polygon. One vertex of the polygon is the origin of the orthogonal coordinate system. From this vertex, you may go step by step to the following vertexes of the polygon until back to the initial vertex. For each step you may go North, West, South or East with step length of 1 unit, or go Northwest, Northeast, Southwest or Southeast with step length of square root of 2. 

For example, this is a legal polygon to be computed and its area is 2.5: 

Input

The first line of input is an integer t (1 <= t <= 20), the number of the test polygons. Each of the following lines contains a string composed of digits 1-9 describing how the polygon is formed by walking from the origin. Here 8, 2, 6 and 4 represent North, South, East and West, while 9, 7, 3 and 1 denote Northeast, Northwest, Southeast and Southwest respectively. Number 5 only appears at the end of the sequence indicating the stop of walking. You may assume that the input polygon is valid which means that the endpoint is always the start point and the sides of the polygon are not cross to each other.Each line may contain up to 1000000 digits.
Output

For each polygon, print its area on a single line.
Sample Input

4
5
825
6725
6244865
Sample Output

0
0
0.5
2
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int dir[10][2] = {{0, 0}, {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

int x[1000005], y[1000005];
int n;

long long cal()
{
	long long area = 0;
	for(int i = 1;i < n;i++)
		area += (long long)(x[i]) * y[i - 1] - x[i - 1] * y[i];
	area += x[0] * y[n - 1] - x[n - 1] * y[0];

	if (area < 0)
        return -area;
    else
        return area;
}

int main()
{
	int ncase;
	cin >> ncase;

	while(ncase--)
	{
		char str[1000005];
		scanf("%s", str);

		x[0] = 0, y[0] = 0;
		n = 1;
		for(int i = 0;str[i];i++)
		{
			x[i + 1] = x[i] + dir[(str[i] - '0')][0];
			y[i + 1] = y[i] + dir[(str[i] - '0')][1];
			n++;
		}
	
		long long res = cal();
        if (res  % 2)
            cout << res / 2 << ".5" << endl;
        else
            cout << res / 2 << endl;
	}

	return 0;
}
