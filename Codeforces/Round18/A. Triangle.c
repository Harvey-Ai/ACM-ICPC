#include <stdio.h>
#define NUM 3

int check(int x[], int y[])
{
	int i, j;

	for(i = 0;i < NUM;i++)
		for(j = 0;j < i;j++)
			if (x[i] == x[j] && y[i] == y[j])
				return 0;
	return 1;
}

int right(int x[], int y[])
{
	int dist[NUM];
	int i, j, k;
	k = 0;
	for(i = 0;i < NUM;i++)
		for(j = 0;j < i;j++)
			dist[k++] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);

	for(i = 0;i < NUM;i++)
		if (dist[i] == dist[(i + 1) % NUM] + dist[(i + 2) % NUM])
			return 1;
	return 0;
}

int main()
{
	int x[3], y[3];
	int i;

	for(i = 0; i < NUM;i++)
		scanf("%d %d", &x[i], &y[i]);

	if (check(x, y) && right(x, y))
	{
		printf("RIGHT\n");
		return 0;
	}

	for(i = 0; i < NUM;i++)
	{
		x[i]--;
		if (check(x, y) && right(x, y))
		{
			printf("ALMOST\n");
			return 0;
		}
		x[i]++;y[i]--;
			if (check(x, y) && right(x, y))
		{
			printf("ALMOST\n");
			return 0;
		}
		y[i]++;x[i]++;
		if (check(x, y) && right(x, y))
		{
			printf("ALMOST\n");
			return 0;
		}
		x[i]--;y[i]++;
		if (check(x, y) && right(x, y))
		{
			printf("ALMOST\n");
			return 0;
		}
		y[i]--;
	}
	printf("NEITHER\n");
	return 0;
}
