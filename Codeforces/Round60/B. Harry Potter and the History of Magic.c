#include <stdio.h>

int main()
{
	int n;
	int i, j, k;
	int arr[1005];
	int res[1005];
	int temp, tempNum;
	int bt, num;
	int resNum;
	int min;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	bt = 0;
	resNum = 0;
	for(i = 0;i < n;i++)
	{
		temp = 1000;
		min = -1;
		for(j = 0;j < 4;j++)
		{
			num = arr[i] - ((arr[i] % (temp * 10)) / temp) * temp; 
			for(k = 0;k < 10;k++)
			{
				if (j == 0 && (k == 0 || k > 2))
					continue;
				tempNum = num + temp * k;
				if (tempNum >= bt && tempNum >= 1000 && tempNum <= 2011)
				{
					if (tempNum < min || min == -1)
					{
						min = tempNum;
					}
				}
			}
			temp /= 10;
		}
		if (min != -1)
		{
			res[resNum++] = min;
			bt = min;
		}
		else
			break;
	}
	if (resNum == n)
	{
		for(i = 0;i < n;i++)
			printf("%d\n", res[i]);
	}
	else
		printf("No solution\n");
	return 0;
}
