/*
描述
某程序员开始工作，年薪N万，他希望在中关村公馆买一套60平米的房子，现在价格是200万，假设房子价格以每年百分之K增长，并且该程序员未来年薪不变，且不吃不喝，不用交税，每年所得N万全都积攒起来，问第几年能够买下这套房子（第一年房价200万，收入N万）

输入
有多行，每行两个整数N（10 <= N <= 50）, K（1 <= K <= 20）
输出
针对每组数据，如果在第20年或者之前就能买下这套房子，则输出一个整数M，表示最早需要在第M年能买下，否则输出Impossible，输出需要换行
样例输入
50 10
40 10
40 8
样例输出
8
Impossible
10
*/


#include <stdio.h>

int main()
{
	double n, k;
	double year;
	double mm;

	while(scanf("%lf %lf", &n, &k) != EOF)
	{
		mm = 200;
		year = 1;
		while(year <= 20)
		{
			if (mm <= n * year)
				break;
			else
				mm *= (1 + k * 1.0 / 100);
			year++;
		}
		if (year <= 20)
			printf("%.0lf\n", year);
		else
			printf("Impossible\n");
	}
	return 0;
}
