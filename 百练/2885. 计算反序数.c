/*
描述
编写函数，参数为一个整数，返回这个整数的反序数，例如参数是1576，返回一个整数6751，如果输入时1230，则返回321。在main函数中调用此函数，并将结果输出。
输入
一个整数
输出
它的反序数
样例输入
0
123
100
-23
-0
-100
样例输出
0
321
1
-32
0
-1
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
	while(cin >> str)
	{

	pos = 0;
	nag = 0;
	if (str[pos] == '-')
	{
		pos++;
		nag = 1;
	}

	for(i = strlen(str) - 1;i > pos;i--)
		if (str[i] != '0')
			break;

	if (str[pos] != '0' && nag)
		cout << "-";
	for(;i >= pos;i--)
		cout << str[i];
	cout << endl;
	}
	return 0;
}

