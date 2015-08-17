#include <stdio.h>
#define N 2005

int arr[N];
int main()
{
	int i, n, res, move, d;
	scanf("%d %d", &n, &d);
	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	res = 0;
	for(i = 1;i < n;i++)
		if (arr[i] <= arr[i - 1])
		{
			move = (arr[i - 1] + 1 - arr[i] + d - 1) / d;
			arr[i] += d * move;
			res += move;
		}
	printf("%d\n", res);
	return 0;
}
