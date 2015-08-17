/*
描述
给出一个正整数a，要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，并且1 < a1 <= a2 <= a3 <= ... <= an，问这样的分解的种数有多少。注意到a = a也是一种分解。
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a (1 < a < 32768)
输出
n行，每行输出对应一个输入。输出应是一个正整数，指明满足要求的分解的种数
样例输入
2
2
20
样例输出
1
4
*/

#include <iostream>
using namespace std;

int f(int num, int max)
{
	if (num == 1)
		return 1;
	int res = 0;
	for(int i = 2;i <= max;i++)
		if (num % i == 0)
		{
		//	cout << n << endl;
			res += f(num / i, i);
		}
	return res;
}

int main()
{
	int ncase;

	cin >> ncase;
	while(ncase--)
	{
		int a;
		cin >> a;
		cout << f(a, a) << endl;
	}
	return 0;
}
