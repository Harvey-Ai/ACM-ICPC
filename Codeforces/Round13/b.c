#include <stdio.h>
struct line
{
	int a0, a1, b0, b1
};
struct point
{
	int x, y;
}
struct line ll[3];
struct point spot, p1, p2, lineEnd1, lineEnd2;
// inersect
const double eps=1e-10;
double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }
bool inter(point a, point b, point c, point d)
{
	if ( min(a.x, b.x) > max(c.x, d.x) ||
		 min(a.y, b.y) > max(c.y, d.y) ||
		 min(c.x, d.x) > max(a.x, b.x) ||
		 min(c.y, d.y) > max(a.y, b.y) ) return 0;
	double h, i, j, k;
	h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
	j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
	k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
	return h * i <= eps && j * k <= eps;
}


int main()
{
	int ncase;
	int pt1, pt11, pt21, pt22;
	scanf("%d", &ncase);
	while(ncase--)
	{
		for(i = 0;i < 3;i++)
			scanf("%d %d %d %d", &ll[i].a0, &ll[i].b0, &ll[i].a1, &ll[i].b1);
		for(i = 0;i < 3;i++)
		{
			for(j = i + 1;j < 3;j++)
			{
				if (ll[i].a0 == ll[j].a0 && ll[i].b0 == ll[j].b0)
				{
					spot.x = ll[i].a0;
					spot.y = ll[i].b0;
				}
				else (ll[i].a0 == ll[j].a0 && ll[i].a1 == ll[j].a1)
				{

			}

		}
		if(i < 4)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
