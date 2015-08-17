#include <stdio.h>

int arr[100005];

int main()
{
	int res;
	int temp;
	int i, n;
	int sum = 0;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	res = 0;
	temp = 0;
	for(i = 0;i < n - 1;i++)
	{
		temp += arr[i];
		if (sum - temp == temp)
			res++;
	}
	printf("%d\n", res);
	return 0;
}
