/*
描述
给定一个整数序列，判断其中有多少个数，等于数列中其他两个数的和。 比如，对于数列1 2 3 4, 这个问题的答案就是2, 因为3 = 2 + 1, 4 = 1 + 3。
输入
第一行是一个整数T，表示一共有多少组数据。 1<= T <= 100
接下来的每组数据共两行，第一行是数列中数的个数n ( 1 <= n <= 100)，第二行是由n个整数组成的数列。
输出
对于每组数据，输出一个整数（占一行），就是数列中等于其他两个数之和的数的个数。
样例输入
2
4
1 2 3 4
5
3 5 7 9 10
样例输出
2
1
*/

#include <stdio.h>
#include <stdlib.h>

long long arr[105];
int n;

int cmp(const void *a, const void *b)
{
	long long aa = *(long long *)a;
	long long bb = *(long long *)b;
	if (aa > bb)
		return 1;
	else if (aa < bb)
		return -1;
	else
		return 0;
}

int bbsearch(long long a, int p1, int p2)
{
	int ll = 0, hh = n - 1;
	int mid;
	int i;
	while(ll <= hh)
	{
		mid = (ll + hh) / 2;
		if (a == arr[mid])
			break;
		else if (a < arr[mid])
			hh = mid - 1;
		else
			ll = mid + 1;
	}
	for(i = mid;i >= 0 && arr[i] == a;i--)
		if (i != p1 && i != p2)
			return 1;
	for(i = mid + 1;i < n && arr[i] == a;i++)
		if (i != p1 && i != p2)
			return 1;
	return 0;
}

int main()
{
	int ncase;
	int i, j, k, ans;

	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%lld", &arr[i]);

		ans = 0;
		qsort(arr, n, sizeof(arr[0]), cmp);

		for(i = 0;i < n;i++)
			for(j = 0;j < n;j++)
			{
				if (j == i)
					continue;
				if (bbsearch(arr[i] - arr[j], i, j))
				{
					ans++;
					break;
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}
