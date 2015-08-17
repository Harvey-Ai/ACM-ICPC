/*
Description

Bessie, Farmer John's prize cow, has just won first place in a bovine beauty contest, earning the title 'Miss Cow World'. As a result, Bessie will make a tour of N (2 <= N <= 50,000) farms around the world in order to spread goodwill between farmers and their cows. For simplicity, the world will be represented as a two-dimensional plane, where each farm is located at a pair of integer coordinates (x,y), each having a value in the range -10,000 ... 10,000. No two farms share the same pair of coordinates. 

Even though Bessie travels directly in a straight line between pairs of farms, the distance between some farms can be quite large, so she wants to bring a suitcase full of hay with her so she has enough food to eat on each leg of her journey. Since Bessie refills her suitcase at every farm she visits, she wants to determine the maximum possible distance she might need to travel so she knows the size of suitcase she must bring.Help Bessie by computing the maximum distance among all pairs of farms. 

Input

* Line 1: A single integer, N 

* Lines 2..N+1: Two space-separated integers x and y specifying coordinate of each farm 
Output

* Line 1: A single integer that is the squared distance between the pair of farms that are farthest apart from each other. 
Sample Input

4
0 0
0 1
1 1
1 0
Sample Output

2
*/

#include <stdio.h>
#include <stdlib.h>
#define N 50001
#define CROSS(x1, y1, x2, y2) (((x1) * (y2)) - ((x2) * (y1)))

struct point
{
	int x, y;
};

struct point point[N], res[N];
int minX, minY;

int cmp(const void *a, const void *b)
{
	struct point *aa = (struct point *)a;
	struct point *bb = (struct point *)b;
	int cross;

	cross = CROSS(aa->x - minX, aa->y - minY, bb->x - minX, bb->y - minY);

	if (cross > 0)
		return -1;
	else
		if (cross < 0)
			return 1;
		else
		{
			if (aa->x > bb->x || aa->y > bb->y)
				return -1;
			else
				return 1;
		}
}

int Graham(struct point *pts, int n)
{
	int cross, i, j;

	res[0] = point[0];
	res[1] = point[1];
	for(i  = 2, j = 1;i < n;i++)
	{
		cross = CROSS(point[i].x - res[j].x, point[i].y - res[j].y, res[j].x - res[j - 1].x, res[j].y - res[j - 1].y);
		while(cross > 0)
		{
			j--;
			cross = CROSS(point[i].x - res[j].x, point[i].y - res[j].y, res[j].x - res[j - 1].x, res[j].y - res[j - 1].y);
		}
		res[++j].x = point[i].x;
		res[j].y = point[i].y;
	}

	return j + 1;
}

int main()
{
	int i, j, n, minId, pointNum, max, tempp;
	struct point temp;

	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%d %d", &point[i].x, &point[i].y);

	minX = point[0].x;
	minY = point[0].y;
	minId = 0;

	for(i = 1;i < n;i++)
		if (point[i].x < minX || point[i].y < minY)
		{
			minX = point[i].x;
			minY = point[i].y;
			minId = i;
		}
	temp.x = point[minId].x;
	temp.y = point[minId].y;
	point[minId].x = point[0].x;
	point[minId].y = point[0].y;
	point[0].x = temp.x;
	point[0].y = temp.y;

	qsort(point + 1, n - 1, sizeof(point[0]), cmp);

	pointNum= Graham(point, n);
	max = (res[0].x - res[pointNum - 1].x) * (res[0].x - res[pointNum - 1].x) + (res[0].y- res[pointNum - 1].y) * (res[0].y - res[pointNum - 1].y);

	for(i = 0; i < pointNum;i++)
		for(j = i + 1;j < pointNum;j++)
		{
			tempp = (res[i].x - res[j].x) * (res[i].x - res[j].x) + (res[i].y- res[j].y) * (res[i].y - res[j].y);
			if (tempp > max)
				max = tempp;
		}
	printf("%d\n", max);
	return 0;
}
