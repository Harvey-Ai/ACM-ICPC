#include <stdio.h>
#include <math.h>

int main()
{
	int ncase;
	int i, j, k, n;
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	for(i = 0;i < ncase;i++)
	{
		scanf("%d %d", &n, &k);
		for(j = 0;j < n;j++)
		{
			if ((k & 0x01) != 1)
				break;
			k >>= 1;
		}

		printf("Case #%d: ", i + 1);
		if (j < n)
			printf("OFF\n");

		else
			printf("ON\n");
	}
}
