#include <stdio.h>
#include <string.h>

int main()
{
	int i, a, n, res;
	int res1[33], res2[33], bit[33];

	bit[0] = 1;
	for(i = 1;i < 32;i++)
		bit[i] = bit[i-1] << 1;
	while(scanf("%d", &n), n)
	{
		res = 0;
		memset(res1, 0, sizeof(res1));
		memset(res2, 0, sizeof(res2));

		n *= 2;
		while(n--)
		{
			scanf("%d", &a);
			res ^= a;
			for(i = 0;i < 32;i++)
			{
				if (a & bit[i])
					res1[i] ^= a;
				else
					res2[i] ^= a;
			}
		}
		for(i = 0;i < 32;i++)
			if (res & bit[i])
			{
				res1[i] > res2[i] ? printf("%d %d\n", res2[i], res1[i]) : printf("%d %d\n", res1[i], res2[i]);
				break;
			}
	}
	return 0;
}

