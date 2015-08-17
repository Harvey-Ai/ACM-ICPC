/*
描述
7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

(图1)

图1给出了一个数字三角形。从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，你的任务就是找到最大的和。

注意：路径上的每一步只能从一个数走到下一层上和它最近的左边的那个数或者右边的那个数。
输入
输入的是一行是一个整数N (1 < N <= 100)，给出三角形的行数。下面的N行给出数字三角形。数字三角形上的数的范围都在0和100之间。
输出
输出最大的和。
样例输入
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
样例输出
30
*/


#include <iostream>
using namespace std;
int main()
{
	int n;
	int i, j;
	int dp[200][200];
	int arr[200][200];
	int a, b;
	int max;
	cin >> n;

	for(i = 0;i < n;i++)
		for(j = 0;j <= i;j++)
			cin >> arr[i][j];


	dp[0][0] = arr[0][0];
	for(i = 1;i < n;i++)
		for(j = 0;j <= i;j++)
		{
			if (j > 0)
				a = dp[i - 1][j - 1];
			else
				a = 0;
			if (j < i)
				b = dp[i - 1][j];
			else
				b = 0;
			dp[i][j] = a > b ? a : b;
			dp[i][j] += arr[i][j];
		}

	max = 0;
	for(i = 0;i < n;i++)
		if (dp[n - 1][i] > max)
			max = dp[n - 1][i];

	cout << max << endl;
	return 0;
}
