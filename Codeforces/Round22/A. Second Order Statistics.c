#include <stdio.h>

int arr[105];
int main()
{
	int i;
	int n;
	int flag, res;
	int min;
	scanf("%d", &n);

	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	if (n == 1)
	{
		printf("NO\n");
		return 0;
	}

	flag = -1;
	min = arr[0];
	for(i = 1;i < n;i++)
	{
		if (arr[i] < min)
		{
			res = min;
			min = arr[i];
			flag = 1;
		}
		else if ((flag == -1 || arr[i] < res ) && arr[i] > min)
		{
			res = arr[i];
			flag = 1;
		}
	}

	if (flag == 1)
		printf("%d\n", res);
	else
		printf("NO\n");

	return 0;
}
