#include <stdio.h>

int main()
{
	int n;
	int ncase;
	scanf("%d", &ncase);

	while(ncase--)
	{
		scanf("%d", &n);
		if (n < 3)
			printf("0\n");
		else
			printf("%d\n", n - 2);
	}
	return 0;
}
