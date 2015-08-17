/*
题目描述:
在服务器上运行的模块,往往要连续运行几个月不重启。这期间,各种程序会不停地申请、
释放内存,因而导致大量的内存碎片。例如,有一块大小为 4K 的内存,还有一块 5K 的内存,
但是由于二者地址不连续,无法从中申请一块 6K 的连续内存。
解决这个问题的方法之一是使用内存池,即把已释放的内存块链起来,而不直接还回操作系
统,下一次申请这个大小 的内存块的时候,直接从链表里获得内存即可。然而,这样做有
个风险:用户可能在一段时间内只需要长度为 L 的内存,过一段时间后全部释放;接下来申
请长度为 L’的内存,造成长度为 L 的内存大量浪费。为 了避免上述风险, 一般的做法是:
当程序申请长度为 L 的内存时,也可以给它分配一快长度为 L’(L’>L)的更大的内存块,
并且限 制内存池中内存长度的种类。
给出 n 个内存块申请,你的任务是计算出在最好情况下,至少需要多少内存才能满足所有的
需求。
注意:有的内存池允许将内存块串连起来,组成一个更大的内存块,但是串联需要使用指针,
在管理小内存的时候比 较浪费,所以本题规定内存块不许串连。
输入格式:
第一行为两个正整数 N 和 K,其中 N 表示内存请求的数目,K 表示内存池中允许有 K 种不同
的长度的内存块。以下 N 行每行包含两个正整数 Li 和 Ci, 表示申请长度为 Li 的内存块
104Ci 次。N<=10000, K<=200, Li < 1000000, Ci<=10000。
输出格式:
输出仅一个整数,即在最好情况下,至少需要多少内存才能满足所有的需求。
样例输入:
3 2
10 1
11 1
20 1
样例输出:
42
样例解释:
长度为 11 的块两个,长度为 20 的一个。
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10005
#define MAXK 205

struct mem
{
	int li;
	int ci;
}mem[MAX];
long long dp[MAX][MAXK][2];

int cmp(const void *a, const void *b)
{
	struct mem *aa = (struct mem *)a;
	struct mem *bb = (struct mem *)b;
	return bb->li - aa->li;
}

int main()
{
	int i, j;
	int n, k;
	long long min;
	long long lastId;

	while(scanf("%d %d", &n, &k) != EOF)
	{
		for(i = 0;i < n;i++)
			scanf("%d %d", &mem[i].li, &mem[i].ci);
		qsort(mem, n, sizeof(mem[0]), cmp);
		memset(dp, 0, sizeof(dp));

		dp[1][1][0] = mem[0].li * mem[0].ci;
		dp[1][1][1] = mem[0].li;

		for(i = 2;i <= n;i++)
			for(j = 1;j <= k;j++)
			{
				min = -1;
				if (dp[i - 1][j][0] > 0)
				{
					lastId = dp[i - 1][j][1];
					min = dp[i - 1][j][1]*mem[i - 1].ci + dp[i - 1][j][0];
				}
				if (dp[i - 1][j - 1][0] > 0 && (dp[i - 1][j - 1][0] + mem[i - 1].li * mem[i - 1].ci <= min || min == -1)
					&& dp[i - 1][j - 1][1] != (long long)mem[i - 1].li)
				{
					min = dp[i - 1][j - 1][0] + mem[i - 1].li * mem[i - 1].ci;
					lastId = mem[i - 1].li;
				}
				if (min > 0)
				{
					dp[i][j][0] = min;
					dp[i][j][1] = lastId;
				}
			}
		min = -1;
		for(i = 1;i <= k;i++)
			if ((min < dp[n][i][0] || min == -1)&& dp[n][i][0] > 0)
				min = dp[n][i][0];
		printf("%lld\n", dp[n][k][0]);
	}
	
	return 0;
}
