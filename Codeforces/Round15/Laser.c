#include <stdio.h>
#include <math.h>

int main()
{
	long long n, m;
	long long x1, y1, x2, y2;
	long long vx, vy;
	long long  res;
	int ncase;

	scanf("%d", &ncase);

	while(ncase--)
	{
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &m, &n, &x1, &y1, &x2, &y2);
		vx = x1 - x2;
		vy = y1 - y2;

		if (vx < 0)
			vx = -vx;
		if (vy < 0)
			vy = -vy;

		res = (m - vx) * (n - vy) * 2;
		if (m > 2 * vx && n > 2 * vy)
			res -= (m - 2 * vx) *(n - 2 * vy);

		printf("%I64d\n", m * n - res);
	}
	return 0;
}
