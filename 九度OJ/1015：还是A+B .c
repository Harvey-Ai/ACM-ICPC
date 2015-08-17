/*
题目描述：
读入两个小于10000的正整数A和B，计算A+B。需要注意的是：如果A和B的末尾K（不超过8）位数字相同，请直接输出-1。
输入：
测试输入包含若干测试用例，每个测试用例占一行，格式为"A B K"，相邻两数字有一个空格间隔。当A和B同时为0时输入结束，相应的结果不要输出。
输出：
对每个测试用例输出1行，即A+B的值或者是-1。
样例输入：
1 2 1
11 21 1
108 8 2
36 64 3
0 0 1
样例输出：
3
-1
-1
100

*/


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, k;
	while(cin >> a >> b >> k, a || b)
	{
		int a1 = a % (int)(pow(10.0, (double)k));
		int b1 = b % (int)(pow(10.0, (double)k));
		if (a1 == b1)
			cout << -1 << endl;
		else
			cout << a + b << endl;
	}
	return 0;
}
