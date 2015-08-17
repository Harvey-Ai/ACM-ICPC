#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

int arr[100005];
long long num[100005];

void cal(int n)
{
	int i;
	num[1] = 1;
	for(i = 2;i <= n;i++)
		num[i] = num[i - 1] + i;
}
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int i, head, n;
	long long res;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);
//	qsort(arr, n, sizeof(arr[0]), cmp);
	cal(n + 2);

	head = 0;
	res = 0;
	// difference arr[n + 1]
	arr[n] = arr[n - 1] + 1;

	for(i = 1;i <= n;i++)
		if (arr[i] != arr[i - 1])
		{
		//	printf("%lld\n", num[i - head]);
			res += num[i - head];
			head = i;
		}

	printf("%I64d\n", res);
	return 0;
}
