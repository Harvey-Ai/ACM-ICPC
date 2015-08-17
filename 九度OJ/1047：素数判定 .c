/*
题目描述：
给定一个数n，要求判断其是否为素数（0,1，负数都是非素数）。
输入：
测试数据有多组，每组输入一个数n。
输出：
对于每组输入,若是素数则输出yes，否则输入no。
样例输入：
13
样例输出：
yes

*/

#include <iostream>
using namespace std;

int main()
{
	int a;
	int i;

	while(cin >> a)
	{
		if (a < 2)
		{
			cout << "no" << endl;
			continue;
		}
		for(i = 2;i * i <= a;i++)
			if (a % i == 0)
				break;
		if (i * i <= a)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return 0;
}
