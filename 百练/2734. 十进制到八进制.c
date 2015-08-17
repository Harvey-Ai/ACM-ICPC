/*
描述
把一个十进制正整数转化成八进制
输入
一行，仅含一个十进制表示的整数a(0 < a < 65536)
输出
一行，a的八进制表示
样例输入
9
样例输出
11
*/


#include <iostream>
using namespace std;

int main()
{
	int a;
	int i;
	char str[1000];
	cin >> a;

	i = 0;
	while(a)
	{
		str[i++] = a % 8 + '0';
		a /= 8;
	}
	while(i--)
		cout << str[i];
	cout << endl;
	return 0;
}
