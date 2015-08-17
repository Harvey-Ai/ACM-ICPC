/*
描述
给定两个正整数，求它们的最大公约数。
输入
有多组数据，每行为两个正整数，且不超过int可以表示的范围。
输出
行对应输出最大公约数。
样例输入
4 8
8 6
200 300
样例输出
4
2
100
*/


#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	int a, b;
	while(cin >> a >> b)
	{
		if (a < b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		cout << gcd(a, b) << endl;
	}
	return 0;
}
