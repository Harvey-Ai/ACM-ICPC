#include <stdio.h>

int main()
{
	int i, n;
	int ncase;

	freopen("j.in", "r", stdin);
	freopen("j.out", "w", stdout);
	scanf("%d", &ncase);

	while(ncase--)
	{
		scanf("%d", &n);
		if (n == 1)
		{
			printf("1\n1\n");
			if (ncase)
				putchar('\n');
			continue;
		}
		if (n % 2 == 0)
		{
			printf("Impossible\n");
			if (ncase)
				putchar('\n');
			continue;
		}

		printf("2");
		for(i = 2;i <= n;i++)
			printf(" %d", i % n + 1);
		putchar('\n');

		printf("%d", n);
		for(i = 1;i < n;i++)
			printf(" %d", i);
		putchar('\n');
		if (ncase)
			putchar('\n');
	}
	return 0;
}
