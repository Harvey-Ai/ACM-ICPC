/*
描述
费马数是一个正整数序列{Fn}，它的表达式为Fn = 2^2^n + 1，n = 0, 1, 2, ...

编写程序，输出前 k 个费马数 F0, F1, F2, ...

要求：
　　1、不能使用指数函数power
　　2、不能使用查表法，必须在程序里计算费马数
输入
非负整数k
输出
前k个费马数
样例输入
3
样例输出
3
5
17
*/


#include <iostream>
using namespace std;

int main()
{
	int n;
	int i;
	cin >> n;

	for(i = 0;i < n;i++)
	{
		int b = 1<<i;
		int a = 1<<b;
	//	cout <<a << b << endl;
		cout << a + 1 << endl;
	}
	return 0;
}
