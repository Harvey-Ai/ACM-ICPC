/*
描述
班上有学生若干名，给出每名学生的年龄（整数），求班上所有学生的平均年龄，保留到小数点后两位。

输入
第一行有一个整数n（1<= n <= 100），表示学生的人数。其后n行每行有1个整数，表示每个学生的年龄，取值为15到25。
输出
输出一行，该行包含一个浮点数，为要求的平均年龄，保留到小数点后两位。
样例输入
2
18
17
样例输出
17.50
*/


#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int i, n;
	cin >> n;
	double sum = 0;
	int age;
	for(i = 0;i < n;i++)
	{
		cin >> age;
		sum += age;
	}
	printf("%.2lf\n", sum / n);
	return 0;
}
