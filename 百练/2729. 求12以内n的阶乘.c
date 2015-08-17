/*
描述
求12以内n的阶乘。
输入
只有一行输入，整数n（n<=12）。
输出
只有一行输出，数值n!。
样例输入
3
样例输出
6
*/


#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long res = 1;
	for(int i = 2;i <= n;i++)
		res *= i;
	cout << res << endl;
	return 0;
}
