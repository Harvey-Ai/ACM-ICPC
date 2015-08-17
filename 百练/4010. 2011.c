/*
描述
已知长度最大为200位的正整数n，请求出2011^n的后四位。
输入
第一行为一个正整数k，代表有k组数据，k<=200接下来的k行，

每行都有一个正整数n，n的位数<=200
输出
每一个n的结果为一个整数占一行，若不足4位，去除高位多余的0
样例输入
3
5
28
792
样例输出
1051
81
5521
*/


#include <iostream>
#include <cstring>
using namespace std;
int flag[1000000];
char str[300];

int main()
{
	unsigned int a;
	unsigned int b;
	int n;
	int cl;
	int i;

	memset(flag, -1, sizeof(flag));
	b = 1;
	flag[1] = 0;
	for(i = 1;;i++)
	{
		b *= 2011;
		b %= 10000;
		if (flag[b] == -1)
			flag[b] = i;
		else
		{
		//	cout << b << endl;
			cl = i;
		//	cout << i << endl;
			break;
		}
	}
//	cout << cl << endl;
	cin >> n;
	while(n--)
	{
		cin >> str;
		if (strlen(str) > 3)
			a = (str[(strlen(str) - 4)] - '0') * 1000 + (str[(strlen(str) - 3)] - '0') * 100 + (str[(strlen(str) - 2)] - '0') * 10 + (str[(strlen(str) - 1)] - '0');
		else if (strlen(str) > 2)
			a = (str[(strlen(str) - 3)] - '0') * 100 + (str[(strlen(str) - 2)] - '0') * 10 + (str[(strlen(str) - 1)] - '0');
		else if (strlen(str) > 1)
			a = (str[(strlen(str) - 2)] - '0') * 10 + (str[(strlen(str) - 1)] - '0');
		else 
			a = (str[(strlen(str) - 1)] - '0');

		a %= cl;
		for(i = 0;i < 10000;i++)
			if (flag[i] == a)
			{
				cout << i << endl;
				break;
			}
	}
	return 0;
}
