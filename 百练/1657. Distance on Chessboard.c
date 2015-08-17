/*
描述
国际象棋的棋盘是黑白相间的8 * 8的方格，棋子放在格子中间。如下图所示：


王、后、车、象的走子规则如下：
王：横、直、斜都可以走，但每步限走一格。
后：横、直、斜都可以走，每步格数不受限制。
车：横、竖均可以走，不能斜走，格数不限。
象：只能斜走，格数不限。


写一个程序，给定起始位置和目标位置，计算王、后、车、象从起始位置走到目标位置所需的最少步数。
输入
第一行是测试数据的组数t（0 <= t <= 20）。以下每行是一组测试数据，每组包括棋盘上的两个位置，第一个是起始位置，第二个是目标位置。位置用"字母-数字"的形式表示，字母从"a"到"h"，数字从"1"到"8"。
输出
对输入的每组测试数据，输出王、后、车、象所需的最少步数。如果无法到达,就输出"Inf".
样例输入
2
a1 c3
f5 f8
样例输出
2 1 2 1
3 1 1 Inf
*/


#include <stdio.h>
#include <math.h>

int vv[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

struct pos
{
	int x, y;
};

int main()
{
	int i;
	int n;
	struct pos pp1;
	struct pos pp2;
	struct pos temp[4];
	char p1[10], p2[10];
	int step[10];
	int add;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s %s", p1, p2);
		pp1.x = p1[1] - '0';
		pp1.y = p1[0] - 'a';
		pp2.x = p2[1] - '0';
		pp2.y = p2[0] - 'a';

		step[0] = step[1] = step[2] = step[3] = 0;
		if (pp1.x == pp2.x && pp1.y == pp2.y)
		{
			printf("0 0 0 0\n");
			continue;
		}
		for(i = 0; i < 4;i++)
		{
			temp[i].x = pp1.x;
			temp[i].y = pp1.y;
		}
		//king
		while(1)
		{
			add = -1;
			for(i = 0; i < 4;i++)
			{
				if (temp[i].x == pp2.x)
				{
					if (add == -1 || abs(temp[i].y - pp2.y) < add)
						add = abs(temp[i].y - pp2.y);
				}
				if (temp[i].y == pp2.y)
				{
					if (add == -1 || abs(temp[i].x - pp2.x) < add)
						add = abs(temp[i].x - pp2.x);
				}
			}
			if (add != -1)
			{
				step[0] += add;
				break;
			}

			for(i = 0;i < 4;i++)
			{
				temp[i].x += vv[i][0];
				temp[i].y += vv[i][1];
			}
			step[0]++;
		}
		//quen
		if (pp1.x == pp2.x || pp1.y == pp2.y || abs(pp1.x - pp2.x) == abs(pp1.y - pp2.y))
			step[1] = 1;
		else
			step[1] = 2;
		// car
		if (pp1.x == pp2.x || pp1.y == pp2.y)
			step[2] = 1;
		else
			step[2] = 2;

		//ele
		if (abs(pp1.x - pp2.x) == abs(pp1.y - pp2.y))
			step[3] = 1;
		else if (abs(pp1.x - pp1.y) % 2 == abs(pp2.x - pp2.y) % 2)
			step[3] = 2;
		else
			step[3] = -1;

		for(i = 0;i < 3;i++)
			printf("%d ", step[i]);
		if (step[3] == -1)
			printf("Inf\n");
		else
			printf("%d\n", step[3]);
	}
	return 0;
}
