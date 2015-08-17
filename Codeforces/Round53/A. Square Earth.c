#include <stdio.h>
#include <math.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main()
{
	int n;
	int a1, a2, b1, b2;
	int res;
	scanf("%d %d %d %d %d", &n, &a1, &b1, &a2, &b2);

	res = fabs(a1 - a2) + fabs(b1 - b2);

	if (fabs(a1 - a2) == n)
	{
		res -= fabs(b1 - b2);
		res += MIN((b1 + b2), (2 * n - b1 - b2));
	}
	else
		if (fabs(b1 - b2) == n)
		{
			res -= fabs(a1 - a2);
			res += MIN((a1 + a2), (2 * n - a1 - a2));
		}

	printf("%d\n", res);
	return 0;
}
