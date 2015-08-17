/*
LZM同学比较牛，Lsy最近也越来越生猛，他们思路快，代码速度神勇。近期惊闻此二人均要参加校赛，队里决定出些题目卡他们，因为他们的罢工给题目组留下了繁重的负担……（报复报复）
于是，XsugarX瞄准了LZM不太喜欢看的数学题目以及Lsy猜公式的喜好，奸笑中（^.^）。这个数学问题是个比较古老的问题，有如下图的三角形被称为杨辉三角形：
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
我们记第一个1为第0行，往下依次编号。
其中三角形左右两斜边上的数字均为1，其他位置均为其两肩上的数之和。
此两牛看到偶数就会觉得复杂，被卡的时间与偶数的个数成正比，XsugarX希望能卡他们的时间越久越好。
给定任意杨辉三角的行数n，请输出杨辉三角中前n行中总共有多少偶数。
Input
  

一个数n（0<=n<=3,000,000）。表示求杨辉三角前n行中偶数的个数。
Output
  

一个数R。表示在杨辉三角前n行中共有R个偶数，由于结果可能会很大，请输出R mod 10,000,000的结果。
Sample Input
4
Sample Output
4
*/

#include <stdio.h>
#define MAX 3000001
#define MOD 10000000

int buf[100];
int res[MAX];

int main()
{
	int i, j, n, numOne, temp;
	res[0] = res[1] = 0;

	buf[0] = 1;
	for(i = 1;i <= 32;i++)
		buf[i] = (buf[i - 1] * 2);

	scanf("%d", &n);
	for(i = 2;i <= n;i++)
	{
		temp = i;
		res[i] = res[i-1];
		numOne = 0;
		while(temp)
		{
			if (temp & 0x01)
				numOne++;
			temp >>= 1;
		}
		res[i] += i + 1 - buf[numOne];
		while (res[i] >= MOD)
			res[i] %= MOD;
	}
	printf("%d\n", res[n]);
}
