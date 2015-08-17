/*
题目描述:
近期,百度采纳了员工们的提议,计划在总部大楼内部种植园艺,以提供更加温馨的工作环境。公司将园艺设计的任务交给了度度熊同学。公司总部大楼内部的构造可以分为 n 个区域,编号为 0, 1, ..., n–1,其中区域 i 与 i + 1 是相邻的(0 ≤ i < n – 1)。根据员工的投票和反馈,度度熊拿到了一份数据,表明在区域 i 种植园艺可以获得员工的满意度为 Ai。度度熊希望园艺的布置方案满足条件:
	1.至少覆盖 m 个区域;
	2.布置园艺的区域是连续的。
请帮他找到一种满足条件的方案,使布置园艺区域的员工的满意度的平均值最大。
输入
输入的第一行包含两个整数 n 和 m,分别表示总区域数和至少覆盖的区域数。第二行包含 n 个整数 A0, A1,..., An – 1,依次表示在每个区域种植园艺可以获得员工的满意度。
输出
输出一行,表示员工的平均满意度的最大值。如果这个数是一个整数,则直接按整数格式输出;否则,请用最简分数表示,分子分母以“/”分割,格式见样例。
样例输入
样例输入 1
3 1
2 3 1
125样例输入 2
5 3
1 8 2 4 8
样例输出
样例输出 1
3
样例输出 2
11/2
提示
样例 2 的正确答案为 11/2,尽管 22/4 数值也相同,但由于没有化简,所以是错误的。
对于 100%的数据,1 ≤ m ≤ n ≤ 106,1 ≤ Ai ≤ 106。
*/


#include <stdio.h>

long long gcd(long long a, long long b)
{
	long long temp = a;
	if (a < b)
	{
		a = b;
		b = temp;
	}

	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int dp[100006];
int arr[100006];
int main()
{
	int n, m;
	int i, j;
	long long zi, mu;
	int sum;
	int a;

	scanf("%d %d", &n, &m);
	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	sum = 0;
	for(i = 0;i < m;i++)
		sum += arr[i];

	dp[0] = sum;
	zi = sum;
	mu = m;
	for(j = 1;j + m <= n;j++)
	{
		dp[j] = dp[j - 1] - arr[j - 1] + arr[j + m - 1];
		if (dp[j] > zi)
			zi = dp[j];
	}

	for(i = m + 1;i <= n;i++)
		for(j = 0;j + i <= n;j++)
		{
			dp[j] = dp[j] + arr[j + i - 1];
			if (dp[j] * mu > zi * i)
			{
				mu = i;
				zi = dp[j];
			}
		}
	
	printf("%lld\n", zi * 1000 / mu);

	return 0;
}
