#include <stdio.h>
#define N 1005

long long arr[N];
int main()
{
	int ncase;
	int i, cc, j, n;
	long long min;
	long long common;
	long long cf, factor, temp;
	long long res;
	freopen("1.txt", "r", stdin);
	freopen("4.txt", "w", stdout);
	scanf("%d", &ncase);

	for(cc = 0;cc < ncase;cc++)
	{
		scanf("%d", &n);
		
		min = -1;
		for(i = 0;i < n;i++)
		{
			scanf("%lld", &arr[i]);
			for(j = 0;j < i;j++)
				if (arr[j] == arr[i])
				{
					i--;
					n--;
					break;
				}
		}

		min = -1;
		for(i = 0;i < n;i++)
			for(j = 0;j < n;j++)
				if (arr[i] > arr[j])
					if (min == -1 || arr[i] - arr[j] < min)
						min = arr[i] - arr[j];

		for(cf = min; cf > 0 ;cf--)
		{

			common = ((arr[0] - 1) / cf + 1) * cf - arr[0];

			for(j = 1;j < n;j++)
			{
				temp = ((arr[j] - 1) / cf + 1) * cf - arr[j];
				if (temp != common)
					break;
			}

			if (j >= n)
			{
				res = common;
				break;
			}
		}
		printf("Case #%d: %lld\n", cc + 1, res);
	}
	return 0;
}
