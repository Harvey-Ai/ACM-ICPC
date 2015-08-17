/*
描述
给定一个整数数组，我们希望去掉其中一个数，使得剩下所有数的乘积最大，问应该去掉哪一个数
输入
第一行M，表示有M组数据
接下来2*M行，每两行表示一组测试数据，每组的第一行市一个整数N，表示是数组的长度，接下来一行有N个整数，表示数组的内容，3<=N<=100，且数组内每个数都在[-10000000,10000000]区间内.
输出
M行，每行一个整数，表示应该去掉的那个数，如果有多个选择，则输出最先输入的那个.
样例输入
4
3
0 1 2
5
2 3 5 4 8
5
-1 -2 -3 -4 -5
4
-1 -2 -3 -4
样例输出
0
2
-1
-4
*/


#include <stdio.h>


int minZ(int *arr, int n)
{
	int i;
	int min = 10000001;
	for(i = 0;i < n;i++)
		if (arr[i] < min && arr[i] > 0)
			min = arr[i];
	return min;
}

int maxF(int *arr, int n)
{
	int i;
	int max = -10000001;
	for(i = 0;i < n;i++)
		if (arr[i] > max && arr[i] < 0)
			max = arr[i];
	return max;
}

int minF(int *arr, int n)
{
	int i;
	int min = 0;
	for(i = 0;i < n;i++)
		if (arr[i] < min && arr[i] < 0)
			min = arr[i];
	return min;
}


int main()
{
	int ncase;
	int i;
	int n;
	int zz, ff, zh;
	int arr[1005];


	scanf("%d", &ncase);

	while(ncase--)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		ff = zz = zh = 0;
		for(i = 0;i < n;i++)
		{
			if (arr[i] == 0)
				zz++;
			if (arr[i] < 0)
				ff++;
			if (arr[i] > 0)
				zh++;
		}
		if (zz == 0)
		{
			if (ff % 2 == 0)
			{
				if (zh != 0)
					printf("%d\n", minZ(arr, n));
				else
					printf("%d\n", minF(arr, n));
			}
			else
				printf("%d\n", maxF(arr, n));
		}
		else if (zz == 1)
		{
			if (ff % 2 == 0)
				printf("0\n");
			else
			{
				if (arr[0] != 0)
					printf("%d\n", arr[0]);
				else
					printf("%d\n", arr[1]);
			}
		}
		else
			printf("%d\n", arr[0]);
	}
	return 0;
}
