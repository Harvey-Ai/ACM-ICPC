#include <stdio.h>

int main()
{
	int i, j, k;
	int a, b, c, d, n;
	int arr[100];
	int g[100][100];

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);

	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	for(i = 0;i < 100;i++)
		for(j = 0;j < 100;j++)
			g[i][j] = -1;


	for(i = 0;i < n;i++)
	{
		if (b > d)
		{
			if (d % 2)
			{
				for(j = 0;j < d;j+=2)
				{
					for(k = a + c - 1;k >= 0;k--)
						if (g[j][k] == - 1 && arr[i] > 0)
						{
							g[j][k] = i;
							arr[i]--;
							if (arr[i] == 0)
								break;
						}
					if (arr[i] == 0)
						break;
					for(k = 0;k < a + c;k++)
						if (g[j + 1][k] == - 1 && arr[i] > 0)
						{
							g[j + 1][k] = i;
							arr[i]--;
							if (arr[i] == 0)
								break;
						}
					if (arr[i] == 0)
							break;
				}
				for(k = a + c - 1;k >= 0;k--)
					if (g[d - 1][k] == - 1 && arr[i] > 0)
					{
						g[d - 1][k] = i;
						arr[i]--;
						if (arr[i] == 0)
							break;
					}
			}
			else
			{
				for(j = 0;j < d;j+=2)
				{
					for(k = a + c - 1;k >= 0;k--)
						if (g[j][k] == - 1 && arr[i] > 0)
						{
							g[j][k] = i;
							arr[i]--;
							if (arr[i] == 0)
								break;
						}
					if (arr[i] == 0)
						break;
					for(k = 0;k < a + c;k++)
						if (g[j + 1][k] == - 1 && arr[i] > 0)
						{
							g[j + 1][k] = i;
							arr[i]--;
							if (arr[i] == 0)
								break;
						}
					if (arr[i] == 0)
							break;
				}
				for(k = a + c - 1;k >= 0;k--)
					if (g[d - 1][k] == - 1 && arr[i] > 0)
					{
						g[d - 1][k] = i;
						arr[i]--;
						if (arr[i] == 0)
							break;
					}
			}
	}

	printf("YES\n");
	for(i = 0;i < b || i < d;i++)
	{
		for(j = 0;j < a + c;j++)
			if (g[i][j] != -1)
				printf("%c", g[i][j] + 'a');
			else
				printf(".");
		putchar('\n');
	}
}
