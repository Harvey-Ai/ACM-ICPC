/*
 Problem Description

升降序列的定义如下：给定N个不同的整数a1,a2,…,aN组成的集合，其中N为奇数，在这N个整数集合的一个排列中，如果对于所有1<i<N，i为偶数，都有ai-1 < ai > ai+1，那么称该序列为升降序列。
给定N个不同的整数组成的集合，请你构造出一个升降序列，使得该升降序列的字典序最小。
对于有N个元素的两个整数序列A和B，如果存在下标k，使得Ak<Bk，并且对于所有1≤i<k≤N，都有Ai=Bi，那么称序列A的字典序小于序列B；如果存在下标k，使得Ak>Bk，并且对于所有1≤i<k≤N，都有Ai=Bi，那么称序列A的字典序大于序列B；如果不存在下标k，使得Ak≠Bk(1≤k≤N)，那么称序列A的字典序等于序列B。
 Input

输入数据第一行为一整数T，表示有T组输入数据。每组输入数据的第一行为一个整数N(1≤N≤50,000，N为奇数)，以下一行为N个不同的整数ai(0≤ai≤1,000,000，1≤i≤N)，表示集合中的每一个元素。
 Output

对于每组数据，输出字典序最小的升降序列，每个元素之间请用一个空格分开。
 Sample Input

2
3
1 2 3
5
100 350 200 101 401
 Sample Output

1 3 2
100 200 101 401 350
*/


#include <stdio.h>
#include <stdlib.h>
#define N 50001

int cmp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1; 
}
int main()
{
	int arr1[N], arr2[N];
	int i, j, n, ncase;
	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%d", &arr1[i]);

		qsort(arr1, n, sizeof(arr1[0]), cmp);

		arr2[0] = arr1[0];
		for(i = 1,j = 2;i < n;i += 2, j +=2)
			arr2[j] = arr1[i];

		for(i = 2, j = 1;i < n;i += 2,j += 2)
			arr2[j] =arr1[i];

		for(i = 0;i < n - 1;i++)
			printf("%d ", arr2[i]);
		printf("%d\n", arr2[n - 1]);
	}
	return 0;
}
