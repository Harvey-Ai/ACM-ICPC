/*
向量是几何中的一个重要概念。
考虑两个向量 v1=(x1,x2,...,xn)和v2=(y1,y2,...,yn)，向量的内积定义为
x1y1+x2y2+...+xnyn
例如向量(1,9,8,8)和(0,9,1,1)的内积是1×0+9×9+1×8+1×8=97。
下面我们考虑这样一个问题，如果我们能够任意的重新排列v1 和v2 中的分量（但是不能修改，删除和添加分量），然后再计算内积。显然这样计算的内积取决于选择的重排方式。
我们现在要问的是，通过重排向量中的分量，所能够获得的最小的内积是多少呢？
Input
  

输入数据包含3行。
第一行是一个整数N，N<=1000，代表了向量的维数。
第二行是N个整数，给出了v1 中的元素，每个整数都在32位整数的范围内，用一个空格隔开。
第二行是N个整数，给出了v2 中的元素，每个整数都在32位整数的范围内，用一个空格隔开。
Output
  

输出一个整数，代表了通过重排向量中的分量，所能够获得的最小内积值。数据保证了最后结果在32位整数的范围内。
Sample Input
5
1 2 3 4 5
1 0 1 0 1
Sample Output
6
*/

#include <stdio.h>
#include <stdlib.h>
#define N 1005

int cmp(const void *a, const void *b)
{
	int aa = *((int *)a);
	int bb = *((int *)b);

	return aa > bb ? 1 : -1;
}
int main()
{
	int i, n, res;
	int arr1[N], arr2[N];
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%d", &arr1[i]);
	qsort(arr1, n, sizeof(arr1[0]), cmp);

	for(i = 0;i < n;i++)
		scanf("%d", &arr2[i]);
	qsort(arr2, n, sizeof(arr2[0]), cmp);

	res = 0;
	for(i = 0;i < n;i++)
		res += arr1[i] * arr2[n - i - 1];
	printf("%d\n", res);
	return 0;
}
