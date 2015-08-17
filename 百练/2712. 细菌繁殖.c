/*
描述
一种细菌的繁殖速度是每天成倍增长。例如：第一天有10个，第二天就变成20个，第三天变成40个，第四天变成80个，……。现在给出第一天的日期和细菌数目，要你写程序求出到某一天的时候，细菌的数目。
输入
第一行有一个整数n，表示测试数据的数目。其后n行每行有5个整数，整数之间用一个空格隔开。第一个数表示第一天的月份，第二个数表示第一天的日期，第三个数表示第一天细菌的数目，第四个数表示要求的那一天的月份，第五个数表示要求的那一天的日期。已知第一天和要求的一天在同一年并且该年不是闰年，要求的一天一定在第一天之后。数据保证要求的一天的细菌数目在长整数（long）范围内。
输出
对于每一组测试数据，输出一行，该行包含一个整数，为要求的一天的细菌数。
样例输入
2
1 1 1 1 2
2 28 10 3 2
样例输出
2
40
*/


#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int ncase;
	int m1, d1, m2, d2;
	int i;
	long long num;
	long long res;
	long long days;
	cin >> ncase;

	while(ncase--)
	{
		cin >> m1 >> d1 >> num >> m2 >> d2;
		days = (m2 - m1) * 30 + d2 - d1;

		for(i = m1;i < m2;i++)
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				days++;
			else if (i == 2)
				days -= 2;

		cout << (num << days) << endl;
	}

	return 0;
}
