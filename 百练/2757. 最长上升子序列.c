/*
描述
一个数的序列bi，当b1 < b2 < ... < bS的时候，我们称这个序列是上升的。对于给定的一个序列(a1, a2, ..., aN)，我们可以得到一些上升的子序列(ai1, ai2, ..., aiK)，这里1 <= i1 < i2 < ... < iK <= N。比如，对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，如(1, 7), (3, 4, 8)等等。这些子序列中最长的长度是4，比如子序列(1, 3, 5, 8).

你的任务，就是对于给定的序列，求出最长上升子序列的长度。
输入
输入的第一行是序列的长度N (1 <= N <= 1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000。
输出
最长上升子序列的长度。
样例输入
7
1 7 3 5 9 4 8
样例输出
4
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int i, j;
	int arr[10007], dp[10007];

	cin >> n;

	for(i = 0;i < n;i++)
		cin >> arr[i];

	memset(dp, 0, sizeof(dp));
	for(i = 0;i < n;i++)
		dp[i] = 1;

	for(i = 1;i < n;i++)
		for(j = 0;j < i;j++)
			if (dp[i] < dp[j] + 1 && arr[j] < arr[i])
				dp[i] = dp[j] + 1;
	
	int max = 1;
	for(i = 1;i < n;i++)
		if (max < dp[i])
			max = dp[i];
	cout << max << endl;

	return 0;
}
