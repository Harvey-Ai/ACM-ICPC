/*
题目描述：
    当n为3时，我们在验证xxx定律的过程中会得到一个序列，3，5，8，4，2，1，将3称为关键数，5，8，4，2称为覆盖数。现在输入n个数字a[i]，根据关键数与覆盖数的理论，我们只需要验证其中部分数就可以确定所有数满足xxx定律，输出输入的n个数中的关键数。如果其中有多个关键数的话按照其输入顺序的逆序输出。
输入：
    输入数据包含多个用例,每个用例首先包含一个整数n，然后接下来一行有n个整数a[i]，其中: 1<=n<=500, 1<a[i]<=1000
输出：
    请计算并输出数组a中包含的关键数，并按照其输入顺序的逆序输出,每个用例输出占一行。
样例输入：
3
3 8 4
5
3 8 4 7 15
5
3 8 4 15 7
0
样例输出：
3
15 7 3
7 15 3

*/

#include <iostream>
#include <cstring>
using namespace std;

int flag[1005];
int arr[1005];
int work(int a)
{
	if (a == 1)
		return 0;
	if (a % 2)
	{
		if ((a * 3 + 1) / 2 < 1005)
			flag[(a * 3 + 1) / 2] = 1;
		return work((a * 3 + 1) / 2) + 1;
	}
	else
	{
		if (a / 2 < 1005)
			flag[a / 2] = 1;
		return work(a / 2) + 1;
	}
}

int main()
{
	int i;
	int n;
	while(cin >> n, n)
	{
		memset(flag, 0, sizeof(flag));
		for(i = 0;i < n;i++)
		{
			cin >> arr[i];
			if (!flag[arr[i]])
				work(arr[i]);
		//	cout << arr[i] << " " << flag[15] << endl;
		}

		int flag2 = 0;
		for(i = n - 1;i >= 0;i--)
			if (!flag[arr[i]])
			{
				if (flag2)
					cout << " " << arr[i];
				else
				{
					cout << arr[i];
					flag2 = 1;
				}
			}
		cout << endl;
	}
	return 0;
}
