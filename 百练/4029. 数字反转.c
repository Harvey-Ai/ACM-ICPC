/*
描述
给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例 2） 。

输入
输入共 1 行，一个整数 N。
输出
输出共 1 行，一个整数，表示反转后的新数。
样例输入
样例 #1:
123

样例 #2:
-380
样例输出
样例 #1:
321

样例 #2:
-83
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[100];
	int nag = 0;
	int i;
	int pos;
	cin >> str;

	pos = 0;
	if (str[pos] == '-')
	{
		pos++;
		nag = 1;
	}
	if (nag)
		cout << "-";

	for(i = strlen(str) - 1;i > pos;i--)
		if (str[i] != '0')
			break;

	for(;i >= pos;i--)
		cout << str[i];
	cout << endl;
	return 0;
}
