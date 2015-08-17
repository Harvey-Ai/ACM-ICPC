/*
题目描述：
中位数定义：一组数据按从小到大的顺序依次排列，处在中间位置的一个数（或最中间两个数据的平均数）.
给出一组无序整数，求出中位数，如果求最中间两个数的平均数，向下取整即可（不需要使用浮点数）
输入：
该程序包含多组测试数据，每一组测试数据的第一行为N，代表该组测试数据包含的数据个数，1<=N<=10000.
接着N行为N个数据的输入，N=0时结束输入
输出：
输出中位数，每一组测试数据输出一行
样例输入：
4
10
30
20
40
3
40
30
50
4
1
2
3
4
0
样例输出：
25
40
2

*/



#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i, n;
	int arr[10000];
	while(cin >> n, n)
	{
		for(i = 0;i < n;i++)
			cin >> arr[i];
		sort(&arr[0], &arr[n]);

		if (n % 2)
			cout << arr[n / 2] << endl;
		else
			cout << (arr[n / 2] + arr[n / 2 - 1]) / 2 << endl;
	}
	return 0;
}
