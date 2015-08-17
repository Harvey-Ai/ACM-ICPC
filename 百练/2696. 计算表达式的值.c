/*
描述
有些语言中表达式的运算符使用字符串表示，例如用mul代表*，用div代表/，用add代表+，用sub代表-，用mod代表%。
输入
第一行为表达式的个数n。其余n行每行一个表达式，表达式由两个整数及其中间的运算符字符串表示。
输出
输出为n行，每行是对应表达式的值。注意，此处要求的所有运算均为整数运算。
样例输入
5
345 mul 122
3945 div 12
321 add 343
340 sub 211
377 mod 27
样例输出
42090
328
664
129
26
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int a, b;
	char str[100];
	cin >> n;
	while(n--)
	{
		cin >> a;
		cin >> str;
		cin >> b;
		if (strcmp(str, "mul") == 0)
			cout << a * b << endl;
		else if (strcmp(str, "div") == 0)
			cout << a / b << endl;
		else if (strcmp(str, "add") == 0)
			cout << a + b << endl;
		else if (strcmp(str, "sub") == 0)
			cout << a - b << endl;
		else if (strcmp(str, "mod") == 0)
			cout << a % b << endl;
	}
	return 0;
}
