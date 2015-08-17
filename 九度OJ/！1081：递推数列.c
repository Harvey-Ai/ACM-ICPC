/*
题目描述：
给定a0,a1,以及an=p*a(n-1) + q*a(n-2)中的p,q。这里n >= 2。 求第k个数对10000的模。
输入：
输入包括5个整数：a0、a1、p、q、k。
输出：
第k个数a(k)对10000的模。
样例输入：
20 1 1 14 5
样例输出：
8359
*/


#include <iostream>
using namespace std;

int flag[10005];
int main()
{
	int a0, a1, p, q, k;

	memset(flag, -1, sizeof(flag));
	
	cin >> a0 >> a1 >> p >> q >> k;

	flag[a0] = a0;
	flag[a1] = a1;
	res[0] = a0;
	res[1] = a1;

	a2 = p * a1 + q * a0;
	circle = 1;
	for(i = 2;i <= k && flag[a2] != -1;++)
	{
		res[i] = a2;
		a0 = a1;
		a1 = a2;
		a2 = p * a1 + q * a0;
	}


}
