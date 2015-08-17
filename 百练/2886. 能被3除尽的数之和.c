/*
描述
输入一个非负整数n（n≥0），求从0到n之间（注意包括n）所有能被3除尽的数之和。
输入
非负整数：n
输出
[0，n]之间能被3除尽的数之和：sum
样例输入
1
9
样例输出
0
18
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		// div1 = 0;
		int div2 = n / 3 * 3;

		int sum = (div2  + 3) * (n / 3);
		cout << sum / 2<< endl;
	}
	return 0;
}
