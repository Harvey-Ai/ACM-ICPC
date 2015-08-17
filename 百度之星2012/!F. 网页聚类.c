/*
描述：有N（N2+ (y_j-y_i)2 + (z_j-z_i)2。请求出最大的t，使得N个网页可以聚成K类，其中每个类至少包含一个网页，且任意两个位于不同类中网页的相似度都至少为t。

输入
第一行包含两个整数N和K，后面N行每行三列，分别为x、y、z。

输出
最大的t的值，使用四舍五入在小数点后保留六位小数。

样例输入

5 3
0.1 0.2 0.4
0.2 0.8 0.7
0.3 0.4 0.5
0.0 0.5 0.0
0.3 0.3 0.2

样例输出

0.170000
*/


#include <iostream>
using namespace std;

double g[1005][1005];
struct tt
{
	double a, b, c;
}web[1005];

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%lf %lf %lf", &web[i].a, &web[i].b, &web[i].c);

	for(i = 0;i < n;i++)
		for(j = i;j < n;j++)
			g[i][j] = g[j][i] = (web[i].a - web[j].a) * (web[i].a - web[j].a) + (web[i].b - web[j].b) * (web[i].b - web[j].b) + (web[i].c - web[j].c) * (web[i].c - web[j].c);

	double max = 0.0;
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
			if (g[i][j] > max)
				max = g[i][j];
	printf("%.6lf\n", max);
	return 0;
}
