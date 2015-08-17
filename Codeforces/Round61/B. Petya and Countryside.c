#include <stdio.h>

int main()
{
	int i, j;
	int n;
	int p1, p2;
	int max;
	int arr[1005];

	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	max = 0;
	for(i = 0;i < n;i++)
	{
		for(j = i - 1;j >= 0;j--)
			if (arr[j] > arr[j + 1])
				break;
		p1 = j + 1;

		for(j = i + 1;j < n;j++)
			if (arr[j] > arr[j - 1])
				break;
		p2 = j - 1;
		if (p2 - p1 + 1 > max)
			max = p2 - p1 + 1;
	}
	printf("%d\n", max);
	return 0;
}
