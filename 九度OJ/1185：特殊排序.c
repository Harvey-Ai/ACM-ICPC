/*
题目描述：
输入一系列整数，将其中最大的数挑出，并将剩下的数进行排序。
输入：
输入第一行包括1个整数N，1<=N<=1000，代表输入数据的个数。
接下来的一行有N个整数。
输出：
可能有多组测试数据，对于每组数据，
第一行输出一个整数，代表N个整数中的最大值，并将此值从数组中去除，将剩下的数进行排序。
第二行将排序的结果输出。
样例输入：
4
1 3 4 2
样例输出：
4
1 2 3
提示：
如果数组中只有一个数，当第一行将其输出后，第二行请输出"-1"。

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i;
	int arr[10000];
	int n;

	while(cin >> n)
	{
		for(i = 0;i < n;i++)
			cin >> arr[i];
		sort(&arr[0], &arr[n]);

		cout << arr[n-1] << endl;
		if (n == 1)
			cout << "-1" << endl;
		for(i = 0;i < n - 1;i++)
		{
			if (i > 0)
				cout << " ";
			cout << arr[i];
		}
		if (n != 1)
			cout << endl;
	}
	return 0;
}
