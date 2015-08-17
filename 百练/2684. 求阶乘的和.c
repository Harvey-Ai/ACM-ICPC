/*
描述
给定正整数n，求不大于n的正整数的阶乘的和（即求1!+2!+3!+...+n!）

输入
输入有一行，包含一个正整数n（1 < n < 12）。
输出
输出有一行：阶乘的和。
样例输入
5
样例输出
153
*/


#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int res = 0;
		for(int i = 1;i <= n;i++)
		{
			int k = 1;
			for(int j = 1;j <= i;j++)
				k *= j;
			res += k;
		}
		cout << res << endl;
	}
	return 0;
}
