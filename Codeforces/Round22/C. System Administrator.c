#include <stdio.h>

int main()
{
	int i, j;
	int cN;
	int pre;
	int another;
	int m, n, v;

	scanf("%d %d %d", &m, &n, &v);

	if (m == 1 && n != 0)
	{
		printf("-1\n");
		return 0;
	}

	if ((m - 1) * (m - 2) / 2 + 1 < n || 
	   (n < m - 1))
	{
		printf("-1\n");
		return 0;
	}

	another = 1;
	if (v == 1)
		another = 2;

	cN = 0;
	pre = -1;
	for(i = 1; i <= m;i++)
		if (i != another)
		{
			if (pre != -1)
			{
				printf("%d %d\n", pre, i);
				cN++;
			}
			pre = i;
		}
	printf("%d %d\n", v, another);
	cN++;

	if (cN >= n)
		return 0;

	for(i = 1;i <= m;i++)
	{
		for(j = i + 2;j <= m;j++)
		{
			if (i != another && j != another &&
				!(j == i + 2 && another == i + 1))
			{
				printf("%d %d\n", i, j);
				cN++;
			}
			if (cN >= n)
				break;
		}
		if (cN >= n)
			break;
	}
	return 0;
}
