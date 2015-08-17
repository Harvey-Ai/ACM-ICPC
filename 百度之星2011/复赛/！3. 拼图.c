/*
问题描述
度度熊有n块正方形的拼图，每块拼图的四条边上都标着一个大写英文字母。度度熊可以用这些拼图组成一个更大的图案，在组成图案时只有字母相同的边才能拼接到一起。每一块拼图都可以任意的旋转和翻转。

		-----------------------------
		|	A	 |	G	 |	 B		|
		|D		B|B		B|B		A	|
		|	C	 |	E	 |	 C		|
		-----------------------------
				|	 E	 |	 C		|
				|C		F|F		B	|
				|	 D	 |	D		|
				---------------------
度度熊想知道，用他现在已有的拼图能拼接出的最大的图案（即包含拼图数最多的图案）是多大？
输入描述
输入包含一组数据。
输入的第一行包含一个整数n，表示度度熊拥有的拼图数。
接下来n行，每行包含四个大写英文字母。字母中间没有任何空格。其中第 i 行的四个字母依次表示初始时第 i 块拼图上边、右边、下边、左边的字母。
输出描述
输出一行，包含一个整数，表示最大的图案中包含的拼图数。
样例输入
5
ABCD
BEBG
ACBB
CEFD
BDFC
样例输出
5
提示
对于所有测试数据， 1 ≤ n ≤ 10。
*/


#include <iostream>
#include <map>
#include <set>
#include <string.h>
using namespace std;

struct piece
{
	char s[10];
	int x, y;
}pc[20];

set< pair< int, int > > biao;
char paint[20][20];
int used[20];
int best;
int n;

int check(char temp[], char left, char right, char up, char down)
{
	if (temp[0] != up && up != ' ')
		return 0;
	if (temp[1] != right && right != ' ')
		return 0;
	if (temp[2] != down && down != ' ')
		return 0;
	if (temp[3] != left && left != ' ')
		return 0;
	return 1;
}

void dfs(int k, int x, int y)
{
	char left, right, up, down;
	int i, j;
	int l;
	char temp[10];
	char tt;

	if (best >= n)
		return;
	if (k > best)
		best = k;
	if (k >= n)
		return;

	left = right = up = down = ' ';
	// find adj x, y
	for(i = 0;i < k;i++)
	{
		if (pc[i].x == x - 1 && pc[i].y == y)
			left = pc[i].s[1];
		if (pc[i].x == x + 1 && pc[i].y == y)
			right = pc[i].s[3];
		if (pc[i].x == x && pc[i].y == y - 1)
			up = pc[i].s[2];
		if (pc[i].x == x && pc[i].y == y + 1)
			down = pc[i].s[0];
	}

	biao.insert(make_pair(x, y));
	// mei jue rect
	for(l = 0;l < n;l++)
	{
		if (used[l])
			continue;
		used[l] = 1;
		// four kind rotate
		for(i = 0;i < 4;i++)
		{
			for(j = 0;j < 4;j++)
				temp[(i + j) % 4] = paint[l][j];
			if (check(temp, left, right, up, down))
			{
				for(j = 0;j < 4;j++)
					pc[k].s[j] = temp[j];
				pc[k].x = x;
				pc[k].y = y;
				if (biao.count(make_pair(x - 1, y)) == 0)
					dfs(k + 1, x - 1, y);
				if (biao.count(make_pair(x + 1, y)) == 0)
					dfs(k + 1, x + 1, y);
				if (biao.count(make_pair(x, y - 1)) == 0)
					dfs(k + 1, x, y - 1);
				if (biao.count(make_pair(x, y + 1)) == 0)
					dfs(k + 1, x, y + 1);
			}
			tt = temp[0];
			temp[0] = temp[2];
			temp[2] = tt;
			if (check(temp, left, right, up, down))
			{
				for(j = 0;j < 4;j++)
					pc[k].s[j] = temp[j];
				pc[k].x = x;
				pc[k].y = y;
				if (biao.count(make_pair(x - 1, y)) == 0)
					dfs(k + 1, x - 1, y);
				if (biao.count(make_pair(x + 1, y)) == 0)
					dfs(k + 1, x + 1, y);
				if (biao.count(make_pair(x, y - 1)) == 0)
					dfs(k + 1, x, y - 1);
				if (biao.count(make_pair(x, y + 1)) == 0)
					dfs(k + 1, x, y + 1);
			}
			tt = temp[0];
			temp[0] = temp[2];
			temp[2] = tt;

			tt = temp[1];
			temp[1] = temp[3];
			temp[3] = tt;
			if (check(temp, left, right, up, down))
			{
				for(j = 0;j < 4;j++)
					pc[k].s[j] = temp[j];
				pc[k].x = x;
				pc[k].y = y;
				if (biao.count(make_pair(x - 1, y)) == 0)
					dfs(k + 1, x - 1, y);
				if (biao.count(make_pair(x + 1, y)) == 0)
					dfs(k + 1, x + 1, y);
				if (biao.count(make_pair(x, y - 1)) == 0)
					dfs(k + 1, x, y - 1);
				if (biao.count(make_pair(x, y + 1)) == 0)
					dfs(k + 1, x, y + 1);
			}
			tt = temp[1];
			temp[1] = temp[3];
			temp[3] = tt;
		}
		used[l] = 0;
	}
	biao.erase(make_pair(x, y));
}

int main()
{
	int i;

	while(scanf("%d", &n), n)
	{
		for(i = 0;i < n;i++)
			scanf("%s", paint[i]);

		best = 1;
		biao.clear();
		memset(used, 0, sizeof(used));
		dfs(0, 0, 0);
		printf("%d\n", best);
	}
	return 0;
}
