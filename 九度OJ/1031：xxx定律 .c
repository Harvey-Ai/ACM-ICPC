/*
题目描述：
    对于一个数n，如果是偶数，就把n砍掉一半；如果是奇数，把n变成 3*n+ 1后砍掉一半，直到该数变为1为止。
    请计算需要经过几步才能将n变到1，具体可见样例。
输入：
    测试包含多个用例，每个用例包含一个整数n,当n为0 时表示输入结束。（1<=n<=10000）
输出：
    对于每组测试用例请输出一个数，表示需要经过的步数,每组输出占一行。
样例输入：
3
1
0
样例输出：
5
0
*/

#include <iostream>
using namespace std;

int work(int a)
{
	if (a == 1)
		return 0;
	if (a % 2)
		return work((a * 3 + 1) / 2) + 1;
	else
		return work(a / 2) + 1;
}
int main()
{
	int n;
	while(cin >> n, n)
	{
		int res = work(n);
		cout << res << endl;
	}
	return 0;
}
