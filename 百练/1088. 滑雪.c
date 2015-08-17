/*
描述
Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出
输出最长区域的长度。
样例输入
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
样例输出
25
*/

#include <iostream>
#include <cstring>
using namespace std;

int g[105][105], dp[105][105];
int m, n;

int dfs(int row, int cl)
{
	if (row < 0 || row >= m || cl < 0 || cl >= n)
		return 0;
	if (dp[row][cl] == 0)
	{
		int max = 0;
		int temp;
		if (row + 1 < m && g[row][cl] > g[row + 1][cl])
		{
			temp = dfs(row + 1, cl);
			if (temp > max)
				max = temp;
		}
		if (row - 1 >= 0 && g[row][cl] > g[row - 1][cl])
		{
			temp = dfs(row - 1, cl);
			if (temp > max)
				max = temp;
		}
		if (cl - 1 >= 0 && g[row][cl] > g[row][cl - 1])
		{
			temp = dfs(row, cl - 1);
			if (temp > max)
				max = temp;
		}
		if (cl + 1 < n && g[row][cl] > g[row][cl + 1])
		{
			temp = dfs(row, cl + 1);
			if (temp > max)
				max = temp;
		}
		dp[row][cl] = max + 1;
		return max + 1;
	}
	else
		return dp[row][cl];
}

int main()
{
	int i, j;
	cin >> m >> n;

	for(i = 0;i < m;i++)
		for(j = 0;j < n;j++)
			cin >> g[i][j];

	
//	cout << "fdsafd" << endl;
	memset(dp, 0, sizeof(dp));
	for(i = 0;i < m;i++)
		for(j = 0;j < n;j++)
			dfs(i, j);

	int max = 1;
	for(i = 0;i < m;i++)
		for(j = 0;j < n;j++)
			if (max < dp[i][j])
				max = dp[i][j];
//	cout << "fdsafd" << endl;
	cout << max << endl;
	return 0;
}
