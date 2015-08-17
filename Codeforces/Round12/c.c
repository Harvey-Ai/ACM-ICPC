#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105

int cmp(const void *a, const void *b)
{
	return *((int *)a) > *((int *)b) ? 1 : -1;
}

int main()
{
	int i, j, cnt, m, n, max, min;
	int price[N], num[N], map[N];
	char fruit[N][N];
	scanf("%d %d", &n, &m);

	for(i = 0;i < n;i++)
		scanf("%d", &price[i]);

	qsort(price, n, sizeof(price[0]), cmp);

	memset(num, 0, sizeof(num));

	for(cnt = 0, i = 0;i < m;i++)
	{
		scanf("%s", fruit[i]);
		for(j = 0;j < cnt;j++)
			if (strcmp(fruit[i], fruit[map[j]]) == 0)
				break;
		if (j < cnt)
			num[j]++;
		else
		{
			map[cnt] = i;
			num[cnt++] = 1;
		}
	}

	qsort(num, cnt, sizeof(num[0]), cmp);

	max = min = 0;
	for(i = cnt -1, j = n -1;i >= 0;i--, j--)
	{
		max += num[i] * price[j];
		min += num[i] * price[n - 1 - j];
	}
	printf("%d %d\n", min, max);
	return 0;
}

