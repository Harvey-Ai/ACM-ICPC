/*
描述
Hello Kitty 想摘点花生送给她喜欢的米老鼠。她来到一片有网格状道路的矩形花生地(如下图)，从西北角进去，东南角出来。地里每个道路的交叉点上都有种着一株花生苗，上面有若干颗花生，经过一株花生苗就能摘走该它上面所有的花生。Hello Kitty只能向东或向南走，不能向西或向北走。问Hello Kitty 最多能够摘到多少颗花生。

输入
第一行是一个整数T，代表一共有多少组数据。1<=T <= 100
接下来是T组数据。

每组数据的第一行是两个整数，分别代表花生苗的行数R和列数 C ( 1<= R,C <=100)
每组数据的接下来R行数据，从北向南依次描述每行花生苗的情况。每行数据有 C 个整数，按从西向东的顺序描述了该行每株花生苗上的花生数目 M ( 0<= M <= 1000)。
输出
对每组输入数据，输出一行，内容为Hello Kitty能摘到得最多的花生颗数。
样例输入
2
2 2
1 1
3 4
2 3
2 3 4
1 6 5
样例输出
8
16
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int ncase;
	int i, j;
	int dp[200][200];
	int arr[200][200];
	int r, c;

	cin >> ncase;

	while(ncase--)
	{
		cin >> r >> c;

		memset(arr, 0, sizeof(arr));
		for(i = 1;i <= r;i++)
			for(j = 1;j <= c;j++)
				cin >> arr[i][j];

		memset(dp, 0, sizeof(dp));
		for(i = 1;i <= r;i++)
			for(j = 1;j <= c;j++)
			{
				dp[i][j] = dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];
				dp[i][j] += arr[i][j];
			}

		cout << dp[r][c] << endl;
	}
	return 0;
}
