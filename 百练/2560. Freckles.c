/*
描述
In an episode of the Dick Van Dyke show, little Richie connects the freckles on his Dad's back to form a picture of the Liberty Bell. Alas, one of the freckles turns out to be a scar, so his Ripley's engagement falls through. 
Consider Dick's back to be a plane with freckles at various (x,y) locations. Your job is to tell Richie how to connect the dots so as to minimize the amount of ink used. Richie connects the dots by drawing straight lines between pairs, possibly lifting the pen between lines. When Richie is done there must be a sequence of connected lines from any freckle to any other freckle.
输入
The first line contains 0 < n <= 100, the number of freckles on Dick's back. For each freckle, a line follows; each following line contains two real numbers indicating the (x,y) coordinates of the freckle.
输出
Your program prints a single real number to two decimal places: the minimum total length of ink lines that can connect all the freckles.
样例输入
3
1.0 1.0
2.0 2.0
2.0 4.0
样例输出
3.41
*/


#include <stdio.h>
#include <string.h>
#include <math.h>

struct point
{
	double x, y;
}pp[105];

double g[105][105];
int visited[105];
double dist[105];

int main()
{
	int n;
	int i, j, u;
	double min;
	double ans;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%lf %lf", &pp[i].x, &pp[i].y);

	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
			g[i][j] = sqrt((pp[i].x - pp[j].x) * (pp[i].x - pp[j].x) + (pp[i].y - pp[j].y) * (pp[i].y - pp[j].y));

	memset(visited, 0, sizeof(visited));
	dist[0] = 0;
	for(i = 1;i < n;i++)
		dist[i] = -1;
	ans = 0;
	visited[0] = 1;
	u = 0;
	for(i = 1;i < n;i++)
	{
		for(j = 0;j < n;j++)
			if (visited[j] == 0 &&
				((g[u][j] < dist[j]) || dist[j] == -1))
				dist[j] = g[u][j];

		min = -1;
		for(j = 0;j < n;j++)
			if (visited[j] == 0	&& (min == -1 || min > dist[j]))
			{
				u = j;
				min = dist[j];
			}
		ans += min;
		visited[u] = 1;
	}
	printf("%.2lf\n", ans);
	return 0;
}
