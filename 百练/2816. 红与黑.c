/*
描述
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
输入
包括多个数据集合。每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不超过20。在接下来的H行中，每行包括W个字符。每个字符表示一块瓷砖的颜色，规则如下
1）‘.’：黑色的瓷砖；
2）‘#’：白色的瓷砖；
3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
当在一行中读入的是两个零时，表示输入结束。
输出
对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。
样例输入
6 9 
....#. 
.....# 
...... 
...... 
...... 
...... 
...... 
#@...# 
.#..#. 
0 0
样例输出
45
*/

#include <iostream>
#include <cstring>
using namespace std;

int m, n;
int used[50][50];
char str[50][50];
int res;

void dfs(int x, int y)
{
	if (x < 0 || x >= n)
		return;
	if (y < 0 || y >= m)
		return;

	if (used[y][x])
		return;

//	cout << str[y][x] << endl;
	if (str[y][x] == '.' || str[y][x] == '@')
	{
		res++;
		used[y][x] = 1;
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
	}
}

int main()
{
	int i, j;
	int posX, posY;
	while(cin >> n >> m, n != 0 && m != 0)
	{
		for(i = 0;i < m;i++)
			cin >> str[i];

		for(i = 0;i < m;i++)
			for(j = 0;j < n;j++)
				if (str[i][j] == '@')
				{
					posX = j;
					posY = i;
					break;
				}

		memset(used, 0, sizeof(used));
		res = 0;
		dfs(posX, posY);
		cout << res << endl;
	}
}
