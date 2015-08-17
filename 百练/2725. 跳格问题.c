/*
描述
有一种游戏，在纸上画有很多小方格，第一个方格为起点(S)，最后一个方格为终点。有一个棋子，初始位置在起点上，棋子每次可移动一次，棋子在起点时，可向前移动一个格子到第二个方格内；棋子在其他方格内时，可根据方格内的数字Ni进行移动。如果Ni大于零，就向前移动Ni个格子；如果Ni小于零，就向后移动-Ni个格子；如果Ni等于零，则此次原地不动一次，在下一步移动时可向前移动一步到下一个格子。显然，如果仅按此方案，会出现棋子永远移动不到终点的情形。为防止这种情况发生，我们规定，当棋子再次来到它曾经到过的方格时，它需要原地不动一次，在下一步移动时可向前移动一步到下一个格子。按此方案，棋子总能够走到终点(F)。如果给定一个方格图，试求棋子要走多少步才能从起点走到终点。（注：当然还可能会出现向前移动Ni个格子就跑过终点了，则把棋子放到终点上。如果Ni太小，使得棋子向后移动跑过了起点，则把棋子放到起点上。）（如图所示，其中S代表起点，F代表终点）（只有离开后再次来到一个方格时，才算来到它曾经到过的方格，包括起点S）

输入
第一行为所有中间格子的总数n（n<20）（即加上起点小格子和终点小格子，共有n+2个小格子）。
其余各行上分别为一个整数，表示对应的小格子上的初始数字。
输出
输出一行，要从起点跳到终点，共要跳多少步。（注：每跳一步，可能跳过多个格子，也可能原地不动）
样例输入
5
2
3
-2
0
-5
样例输出
19
提示

只有离开后再次来到一个方格时，才算来到它曾经到过的方格，包括起点S
如果有疑问可再读一遍题干！
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int i;
	int flag[30], block[30];
	int point, step, stayed;
	cin >> n;
	for(i = 1;i <= n;i++)
		cin >> block[i];
	block[0] = 1;
	block[n + 1] = 1;

	memset(flag, 0 , sizeof(flag));
	point = 0;
	step = 0;
	flag[0] = 1;
	stayed = 1;

	while(point != n + 1)
	{
	//	cout << point << endl;
		step++;
		if (flag[point] == 1)
		{
			if (stayed)
			{
				stayed = 0;
				point += 1;
			}
			else
				stayed = 1;
		}
		else
		{
			flag[point] = 1;
			if (block[point] != 0)
				point += block[point];
			else
				stayed = 1;
		}
	//	cout << point << endl;
		if (point < 0) point = 0;
		if (point >= n + 1)
			point = n + 1;
	}
	cout << step << endl;
	return 0;
}
