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
#define N 105

int sum[N * N];

int cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}
int Bsearch(int num, int n)
{
	int low = 0;
	int high = n - 1;
	int mid;

	while(low <= high)
	{
		mid = (high + low) / 2;
		if (num == sum[mid])
			return 1;
		else
		{
			if (sum[mid] > num)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return 0;
}
int main()
{
	int i, j, k, l, n;
	int ncase;
	int res;
	int arr[N];

	scanf("%d", &ncase);

	while(ncase--)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		k = 0;
		for(i = 0;i < n;i++)
			for(j = i + 1;j < n;j++)
				if (i != j)
				{
					if (arr[i] == 0 || arr[j] == 0)
					{
						for(l = 0;l < n;l++)
							if (arr[l] == arr[j] + arr[i] && l != j && l != i)
								break;
						if (l < n)
							sum[k++] = arr[i] + arr[j];
					}
					else
						sum[k++] = arr[i] + arr[j];
				}

		qsort(sum, k, sizeof(sum[0]), cmp);

		res = 0;
		for(i = 0;i < n;i++)
			if (Bsearch(arr[i], k))
				res++;
		printf("%d\n", res);
	}
	return 0;
}
