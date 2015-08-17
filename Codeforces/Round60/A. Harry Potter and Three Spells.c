#include <stdio.h>

int main()
{
	int a[6];
	int i;

	for(i = 0;i < 6;i++)
		scanf("%d", &a[i]);

	if (a[3] == 0)
	{
		printf("Hermione\n");
		return 0;
	}
	if (a[1] == 0)
	{
		if (a[2] == 0)
			printf("Ron\n");
		else
			printf("Hermione\n");
		return 0;
	}
	if (a[0] == 0 || a[2] == 0)
	{
		printf("Ron\n");
		return 0;
	}

	if (a[4] == 0)
	{
		if (a[5] != 0)
			printf("Ron\n");
		else
			printf("Hermione\n");
		return 0;
	}
	if (a[5] == 0)
	{
		printf("Hermione\n");
		return 0;
	}

	if (a[1] * a[3] * a[5] > a[0] * a[2] * a[4])
		printf("Ron\n");
	else
		printf("Hermione\n");
	return 0;
}
