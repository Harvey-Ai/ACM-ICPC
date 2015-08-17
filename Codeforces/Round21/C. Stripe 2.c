#include <stdio.h>
#define N 100005

__int64 arr[N];
int main()
{
	__int64 sum1, sum2, tempSum;
	__int64 sum;
	__int64 num1;
	__int64 res;
	int i;
	int n;
	scanf("%d", &n);

	sum = 0;
	for(i = 0;i < n;i++)
	{
		scanf("%I64d", &arr[i]);
		sum += arr[i];
	}

	if (sum % 3 != 0)
	{
		printf("0\n");
		return 0;
	}

	if (sum == 0)
	{
		num1 = 0;
		tempSum = 0;
		for(i = 0;i < n - 1;i++)
		{
			tempSum += arr[i];
			if (tempSum == 0)
				num1++;
		}
		printf("%I64d\n", (num1 * (num1 - 1)) / 2);
	}
	else
	{
		sum1 = sum / 3;
		sum2 = sum1 + sum1;
		tempSum = 0;
		res = 0;
		num1 = 0;
		for(i = 0;i < n - 1;i++)
		{
			tempSum += arr[i];
			if (tempSum == sum1)
				num1++;
			if (tempSum == sum2)
				res += num1;
		}
		printf("%I64d\n", res);
	}

	return 0;
}	
