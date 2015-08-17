#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long arr[1000005];
long long tt[1000005];

int cmp(const void *a, const void *b)
{
	long long *aa = (long long *)a;
	long long *bb = (long long *)b;
	return *aa - *bb > 0 ? 1 : -1;
}

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else return gcd(b, a % b);
}

int check(long long a)
{
	long long tt = sqrt(a);
	if (tt * tt == a)
		return 1;
	else
		return 0;
}

int find(long long a, int n)
{
	int i;
	int mid, ll, hh;
	ll = 0;
	hh = n - 1;

	if (check(a) == 0)
		return 1;

	while(ll <= hh)
	{
		mid = (ll + hh) / 2;
		if (tt[mid] == a)
			return 1;
		else if (tt[mid] < a)
			ll = mid + 1;
		else
			hh = mid - 1;
	}
	return 0;
}

int main()
{
	int n;
	int i, j;
	int ans;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%lld", &arr[i]);

	qsort(arr, n, sizeof(arr[0]), cmp);
	for(i = 0;i < n;i++)
		tt[i] = arr[i] * arr[i];

	ans = n;
	for(i = 0;i < n;i++)
		for(j = 0;j < i;j++)
		{
			if (gcd(arr[i], arr[j]) == 1)
			{
				if (check(arr[i] * arr[i] - arr[j] * arr[j]))
					ans--;
				if (find(arr[i] * arr[i] + arr[j] * arr[j], n) == 0)
					ans--;
			}
		}

	printf("%d\n", ans);
}
