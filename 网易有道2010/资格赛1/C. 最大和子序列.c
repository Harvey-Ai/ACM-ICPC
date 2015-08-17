#include <stdio.h>
#define N 100010

int arr[N];

long long bsum(int arr1[], int n, int *h, int *e)
{
	int i, j;
	long long sum = 0;
	long long bigest = 0;
	int flag = 0;
	int begin, end;
	int head = 0;
	for(i = 0;i < n;i++)
	{
		sum += arr1[i];

		if (i - head + 1 > n / 2)
		{
			sum -= arr[head];
			head++;
		}
		for(j = head;j < i;j++)
			if (arr[j] < 0)
			{
				sum -= arr[j];
				head = j + 1;
			}
			else
				break;
		if (sum <= 0)
		{
			if (flag == 0 || bigest < sum)
			{
				flag = 1;
				begin = i;
				end = i;
				bigest = sum;
			}
			head = i + 1;
			sum = 0;
		}
		else
		{
			if (sum > bigest)
			{
				flag = 1;
				begin = head;
				end = i;
				bigest = sum;
			}
		}
	}
	*h = begin;
	*e = end;
	return bigest;
}


int main()
{
	int i;
	int ncase;
	int begin, end;
	long long sum;
	long long tempSum;
	int n;
	scanf("%d", &ncase);

	while(ncase--)
	{
		scanf("%d", &n);
		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		for(i = n;i < 2 * n;i++)
			arr[i] = arr[i - n];

		sum = bsum(arr, 2 * n, &begin, &end);

		printf("%d\n", sum);
		if (end - begin + 1 == n)
		{
			printf("%lld\n", sum);
			continue;
		}
		else
		{
			for(i = begin;i <= end;i++)
				arr[i % n + n] = arr[i % n] = -10005;
			if (begin == end)
				sum += bsum(arr, 2 * n, &begin, &end);
			else
			{
				tempSum = sum;
				sum1 = sum;
				for(i = begin;i <= end;i++)
				{
					if (arr[i] < 0)
						tempSum -= arr[i];
					else
					{
						sum1 = tempSum;
						tempSum = sum;
					}
				}

				tempSum = bsum(arr, 2 * n, &begin, &end);
				if (tempSum > 0)
					sum += tempSum;
				if (sum1 > sum)
					sum = sum1;

			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
