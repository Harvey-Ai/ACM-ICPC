#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	int aa = *((int *)a);
	int bb = *((int *)b);
	return aa - bb;
}

int main()
{
	int arr[105];
	int i, flag;
	int n, k;
	int ans;

	scanf("%d %d", &n, &k);

	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(arr[0]), cmp);

	flag = 1;
	ans = 0;
	while(flag)
	{
		flag = 0;
		for(i = 1;i < n;i++)
			if (arr[i] != arr[i - 1] && arr[i - 1] < k)
			{
				arr[i - 1]++;
				flag = 1;
			}
		if (arr[n - 1] < k)
		{
			flag = 1;
			arr[n - 1]++;
		}
		if (flag)
			ans++;
	}

	printf("%d\n", ans);
	return 0;
}
