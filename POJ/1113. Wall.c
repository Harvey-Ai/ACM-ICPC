/*
Description

Once upon a time there was a greedy King who ordered his chief Architect to build a wall around the King's castle. The King was so greedy, that he would not listen to his Architect's proposals to build a beautiful brick wall with a perfect shape and nice tall towers. Instead, he ordered to build the wall around the whole castle using the least amount of stone and labor, but demanded that the wall should not come closer to the castle than a certain distance. If the King finds that the Architect has used more resources to build the wall than it was absolutely necessary to satisfy those requirements, then the Architect will loose his head. Moreover, he demanded Architect to introduce at once a plan of the wall listing the exact amount of resources that are needed to build the wall. 


Your task is to help poor Architect to save his head, by writing a program that will find the minimum possible length of the wall that he could build around the castle to satisfy King's requirements. 

The task is somewhat simplified by the fact, that the King's castle has a polygonal shape and is situated on a flat ground. The Architect has already established a Cartesian coordinate system and has precisely measured the coordinates of all castle's vertices in feet.
Input

The first line of the input file contains two integer numbers N and L separated by a space. N (3 <= N <= 1000) is the number of vertices in the King's castle, and L (1 <= L <= 1000) is the minimal number of feet that King allows for the wall to come close to the castle. 

Next N lines describe coordinates of castle's vertices in a clockwise order. Each line contains two integer numbers Xi and Yi separated by a space (-10000 <= Xi, Yi <= 10000) that represent the coordinates of ith vertex. All vertices are different and the sides of the castle do not intersect anywhere except for vertices.
Output

Write to the output file the single number that represents the minimal possible length of the wall in feet that could be built around the castle to satisfy King's requirements. You must present the integer number of feet to the King, because the floating numbers are not invented yet. However, you must round the result in such a way, that it is accurate to 8 inches (1 foot is equal to 12 inches), since the King will not tolerate larger error in the estimates.
Sample Input

9 100
200 400
300 400
300 300
400 300
400 400
500 400
500 200
350 200
200 200
Sample Output

1628
Hint

结果四舍五入就可以了
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1005
#define PI 3.141592653
#define CROSS(x1, y1, x2, y2) (((x1) * (y2)) - ((x2) * (y1)))
#define DIS(x, y) ((x) * (x) + (y) * (y))
#define DISTANCE(x, y) sqrt((double)(DIS(x, y)))

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
			return (DIS((aa->x - minX), (aa->y - minY))) - (DIS((bb->x - minX), (bb->y - minY)));
}

int Graham(struct point *pts, int n)
{
	int i, j;
	int cross;

	res[0] = point[0];
	res[1] = point[1];
	for(i  = 2, j = 1;i < n;i++)
	{
		cross = CROSS(point[i].x - res[j].x, point[i].y - res[j].y, res[j].x - res[j - 1].x, res[j].y - res[j - 1].y);
		while(j >= 1 && cross >= 0)
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
	int i, j, l, n, minId, pointNum;
	double len;
	struct point temp;

	scanf("%d %d", &n, &l);
	for(i = 0;i < n;i++)
		scanf("%d %d", &point[i].x, &point[i].y);

	minX = point[0].x;
	minY = point[0].y;
	minId = 0;

	for(i = 1;i < n;i++)
		if (point[i].y < minY || (point[i].y == minY && point[i].x < minX))
		{
			minX = point[i].x;
			minY = point[i].y;
			minId = i;
		}
	temp = point[minId];
	point[minId] = point[0];
	point[0] = temp;

	qsort(point + 1, n - 1, sizeof(point[0]), cmp);

	pointNum= Graham(point, n);

	len = DISTANCE((double)(res[0].x - res[pointNum - 1].x), (double)(res[0].y - res[pointNum - 1].y));

	for(i = 1; i < pointNum;i++)
		len += DISTANCE((double)(res[i].x - res[i - 1].x), (double)(res[i].y - res[i- 1].y));

	printf("%d\n", (int)(len +  2 * PI * l + 0.5));
	return 0;
}
