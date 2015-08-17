/*
题目描述：
    读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。
输入：
    测试输入包含若干测试用例，每个测试用例占一行，每行不超过200个字符，整数和运算符之间用一个空格分隔。没有非法表达式。当一行中只有0时输入结束，相应的结果不要输出。
输出：
    对每个测试用例输出1行，即该表达式的值，精确到小数点后2位。
样例输入：
1 + 2
4 + 2 * 5 - 7 / 11
0
样例输出：
3.00
13.36
*/

#include <iostream>
using namespace std;

double dfs(int bg, int end)
{
	double num = 0;

	pos = bg;
	double res = readNum(pos);
	while(pos != end)
	{
		op = ss[pos];
		num = readNum(pos);

}

int main()
{
	char str[1000], ss[1000];
	while(cin.getline(str, 1000, '\n'))
	{
		if (strcmp(str, "0") == 0)
			break;

		for(i = 0, j = 0;str[i] != '\0';i++)
			if (str[i] != ' ')
				ss[j++] = str[i];

		double res = dfs(0, j - 1);
		cout << res << endl;
	}
	return 0;
}
