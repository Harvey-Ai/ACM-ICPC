/*
题目描述：
读入两个小于100的正整数A和B,计算A+B.
需要注意的是:A和B的每一位数字由对应的英文单词给出.
输入：
测试输入包含若干测试用例,每个测试用例占一行,格式为"A + B =",相邻两字符串有一个空格间隔.当A和B同时为0时输入结束,相应的结果不要输出.
输出：
对每个测试用例输出1行,即A+B的值.
样例输入：
one + two =
three four + five six =
zero seven + eight nine =
zero + zero =
样例输出：
3
90
96
*/


#include <iostream>
#include <cstring>
using namespace std;


int convert(char *str)
{
	if (strcmp(str, "zero") == 0)
		return 0;
	else if (strcmp(str, "one") == 0)
		return 1;
	else if (strcmp(str, "two") == 0)
		return 2;
	else if (strcmp(str, "three") == 0)
		return 3;
	else if (strcmp(str, "four") == 0)
		return 4;
	else if (strcmp(str, "five") == 0)
		return 5;
	else if (strcmp(str, "six") == 0)
		return 6;
	else if (strcmp(str, "seven") == 0)
		return 7;
	else if (strcmp(str, "eight") == 0)
		return 8;
	else if (strcmp(str, "nine") == 0)
		return 9;
}
int main()
{
	char str[100];

	while(cin >> str)
	{
		int a = convert(str);
		cin >> str;
		while(str[0] != '+')
		{
			a *= 10;
			a += convert(str);
			cin >> str;
		}

		cin >> str;
		int b = convert(str);
		cin >> str;
		while(str[0] != '=')
		{
			b *= 10;
			b += convert(str);
			cin >> str;
		}
		if (a == 0 && b == 0)
			break;
		else
			cout << a + b << endl;
	}
	return 0;
}


