/*
描述
一个正整数,如果它能被x整除,或者它的十进制表示法中某个位数上的数字为x,则称其为与x相关的数.现求所有小于等于n(n<300)的与x无关的正整数的平方和.

输入
输入为一行,正整数n,(n<300)
输出
输出小于等于n的与3和5无关的正整数的平方和
样例输入
8
样例输出
134
*/


#include <iostream>
#include <string>
using namespace std;

int main()
{
	int flag[400];
	int a, b;
	int res;
	int i, n;

	for(i = 1;i < 300;i ++)
	{
		flag[i] = 0;
		if (i % 3 == 0 || i % 5 == 0)
			flag[i] = 1;

		a = i;
		while(a)
		{
			if (a % 10 == 3 || a % 10 == 5)
				flag[i] = 1;
			a /= 10;
		}
	}

	cin >> n;
	res = 0;
	for(i = 1;i <= n;i++)
		if (!flag[i])
			res += i * i;
	cout<< res;

	return 0;
}
