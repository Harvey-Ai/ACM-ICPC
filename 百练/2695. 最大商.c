/*
描述
给一组数，前后相邻的两个数相除，输出商最大的两个数及商的值。
输入
第一行为数组中浮点数的个数n，n大于2，其余n行为每一行一个浮点数。
输出
以下面的形式输出结果，前两个数是相除的两个数，最后一个数为最大的商值。
printf("%f / %f = %f\n", a[maxi-1], a[maxi], maxq);
样例输入
10
41.0
18467.0
6334.0
26500.0
19169.0
15724.0
11478.0
29358.0
26962.0
24464.0
样例输出
18467.000000 / 6334.000000 = 2.915535
提示
应使用动态数组保存输入的浮点数。
运算过程中应只使用float类型的浮点数。
*/


#include <stdio.h>

int main()
{
	float pre, now, res;
	float d1, d2;
	int n;
	while(scanf("%d", &n) != EOF)
	{
	scanf("%f", &pre);
	scanf("%f", &now);
	d1 = pre;
	d2 = now;
	res = pre / now;
	pre = now;
	n -= 2;
	//printf("%d\n", n);

	while(n--)
	{
		scanf("%f", &now);
	//	if (now == 0.0)
	//	{
	//		pre = 0;
	//		continue;
	//	}
		if (pre / now > d1 / d2)
		{
			d1 = pre;
			d2 = now;
			res = pre / now;
		}
		pre = now;
	//	printf("%d\n", n);
	}

	printf("%f / %f = %f\n", d1, d2, res);
	}
	return 0;
}
