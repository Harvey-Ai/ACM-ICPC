/*
Description

在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
Input

输入含有多组测试数据。 
每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n 
当为-1 -1时表示输入结束。 
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。 
Output

对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
Sample Input

2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1
Sample Output

2
1
*/


#include <stdio.h>
#include <string.h>
int plat[10][10], used[10], able[10];
int res, qizi, putNum;
void dfs(int depth, int n)
{
	int i;
	if(able[depth] < qizi - putNum)
		return;
	if(depth == n)
	{
		res++;
		return;
	}
	dfs(depth + 1, n);
	for(i = 0;i < n;i++)
	{
		if (qizi - putNum && !used[i] && plat[depth][i])
		{
			used[i] = 1;
			putNum++;
			dfs(depth + 1, n);
			putNum--;
			used[i] = 0;
		}
	}
}

int
main ()
{
	int i, j, k, ab, n;
	char buf[20];
	int check[20];
	while (scanf("%d %d", &n, &k), n != -1 && k != -1)
    {
		qizi = k;
		memset(plat, 0, sizeof(plat));
		memset(used, 0, sizeof(used));
		res = 0;
		putNum = 0;
		for (i = 0; i < n; i++)
		{
			scanf ("%s", buf);
			for (j = 0; j < n; j++)
			if (buf[j] == '#')
				plat[i][j] = 1;
		}
		for(i = 0;i < n;i++)
		{
			for(j = n - 1; j >= 0; j--)
				if(plat[j][i])
					break;
			check[i] = j;
		}
		for(i = 0; i < n;i++)
		{
			ab = n;
			for(j = 0; j < n;j++)
				if (check[j] < i)
					ab--;
			able[i] = ab > n - i ? n - i : ab;
		}
		able[n] = 0;
		dfs(0, n);
		printf("%d\n", res);
	}
	return 0;
}
