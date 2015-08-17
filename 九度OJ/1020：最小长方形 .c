/*
题目描述：
    给定一系列2维平面点的坐标(x, y)，其中x和y均为整数，要求用一个最小的长方形框将所有点框在内。长方形框的边分别平行于x和y坐标轴，点落在边上也算是被框在内。
输入：
    测试输入包含若干测试用例，每个测试用例由一系列坐标组成，每对坐标占一行，其中|x|和|y|小于 231；一对0 坐标标志着一个测试用例的结束。注意(0, 0)不作为任何一个测试用例里面的点。一个没有点的测试用例标志着整个输入的结束。
输出：
    对每个测试用例，在1行内输出2对整数，其间用一个空格隔开。第1对整数是长方形框左下角的坐标，第2对整数是长方形框右上角的坐标。
样例输入：
12 56
23 56
13 10
0 0
12 34
0 0
0 0
样例输出：
12 10 23 56
12 34 12 34
*/

#include <iostream>
using namespace std;

int main()
{
	int x, y;
	int left, right, top, bottom;

	while(cin >> x >> y, x || y)
	{
		left = right = x;
		top = bottom = y;

		while(cin >> x >> y, x || y)
		{
			if (left > x)
				left = x;
			if (right < x)
				right = x;
			if (top < y)
				top = y;
			if (bottom > y)
				bottom = y;
		}
		cout << left << " " << bottom << " " << right << " " << top << endl;
	}
	return 0;
}
