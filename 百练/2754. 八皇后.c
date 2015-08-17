/*
描述
会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！这就是著名的八皇后问题。 
对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，其中bi为相应摆法中第i行皇后所处的列数。已经知道8皇后问题一共有92组解（即92个不同的皇后串）。
给出一个数b，要求输出第b个串。串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数b(1 <= b <= 92)
输出
输出有n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串。
样例输入
2
1
92
样例输出
15863724
84136275
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
	cin >> n;

	memset(used, 0, sizeof(used));
	resNum = 0;
	dfs(1);
	sort(&res[0], &res[resNum], cmp);
//	cout << resNum << endl;
	while(n--)
	{
		cin >> num;
		cout << res[num - 1].pai << endl;
	}
	return 0;
}
