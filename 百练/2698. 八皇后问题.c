/*
描述
在国际象棋棋盘上放置八个皇后，要求每两个皇后之间不能直接吃掉对方。
输入
无输入。
输出
按给定顺序和格式输出所有八皇后问题的解（见Sample Output）。
样例输入
样例输出
No. 1
1 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 
0 1 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 
0 0 0 0 0 1 0 0 
0 0 1 0 0 0 0 0 
No. 2
1 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 0 1 0 0 0 0 
0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 1 
0 1 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 
0 0 1 0 0 0 0 0 
No. 3
1 0 0 0 0 0 0 0 
0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 1 
0 0 1 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 0 1 0 0 0 0 
0 1 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 
No. 4
1 0 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 
0 0 0 0 0 1 0 0 
0 0 1 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 1 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 
No. 5
0 0 0 0 0 1 0 0 
1 0 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 
0 1 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 
0 0 1 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 0 1 0 0 0 0 
No. 6
0 0 0 1 0 0 0 0 
1 0 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 
0 1 0 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 1 0 0 0 0 0 
0 0 0 0 0 1 0 0 
No. 7
0 0 0 0 1 0 0 0 
1 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 
0 0 0 1 0 0 0 0 
0 1 0 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 1 0 0 0 0 0 
0 0 0 0 0 1 0 0 
No. 8
0 0 1 0 0 0 0 0 
1 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 
0 1 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 
0 0 0 0 0 1 0 0 
No. 9
0 0 0 0 1 0 0 0 
1 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 
0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 1 
0 1 0 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 1 0 0 0 0 0 
...以下省略
*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int used[100], resolve[100];
int resNum;

struct bb
{
	char pai[100];
}res[1000];

int check(int row, int cl)
{
	for(int i = 1;i < row;i++)
		if (cl == resolve[i] || abs(cl - resolve[i]) == row - i)
			return 0;
	return 1;
}

int dfs(int row)
{
	int i;
	if (row == 9)
	{
		for(i = 1;i < 9;i++)
			res[resNum].pai[i - 1] = resolve[i] + '0';
		res[resNum++].pai[8] = '\0';
		return 0;
	}
	//cout << row << endl;
	for(i = 1;i < 9;i++)
		if (!used[i] && check(row, i))
		{
			resolve[row] = i;
			used[i] = 1;
			dfs(row + 1);
			used[i] = 0;
		}
}

bool cmp(const struct bb a, const struct bb b)
{
	if (strcmp(a.pai, b.pai) > 0)
		return 0;
	else
		return 1;
}

int main()
{
	int n;
	int num;
	int i, j, k;
	int g[10][10];
//	cin >> n;

	memset(used, 0, sizeof(used));
	resNum = 0;
	dfs(1);
	sort(&res[0], &res[resNum], cmp);

	for(i = 0;i < resNum;i++)
	{
		cout << "No. " << i + 1 << endl;

		for(j = 0;j < 8;j++)
		{
			for(k = 1;k <= 8;k++)
				if (res[i].pai[j] - '0' == k)
					g[j][k - 1] = 1;
				else
					g[j][k - 1] = 0;
		}

		for(k = 0;k < 8;k++)
		{
			for(j = 0;j < 8;j++)
				cout << g[j][k] << " ";
			cout << endl;
		}
	}
	return 0;
}
