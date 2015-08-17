#include <stdio.h>

int main()
{
	long long temp;
	int res;
	int times, cnt;
	long long l, b, p, c;
	int ncase, icase;
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%lld %lld %lld", &l, &p, &c);

		temp = l;
		cnt = 0;
		while(temp < p)
		{
			temp *= c;
			cnt++;
		}
		cnt--;

		res = 0;
		times = 1;
		while(times <= cnt)
		{
			times *= 2;
			res++;
		}
		printf("Case #%d: %d\n", icase, res);
	}
	return 0;
}

