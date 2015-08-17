#include <stdio.h>

char gg[15][15][15];
int que[5000][3];
int temp[100][3];

int main()
{
	int m, n, k;
	int queNum, tempNum;
	int ans;
	int i, j, x, y;
	int tt;
	scanf("%d %d %d", &k, &m, &n);
	tt = m;
	m = n;
	n = tt;

	for(i = 0;i < k;i++)
		for(j = 0;j < n;j++)
			scanf("%s", gg[i][j]);

	scanf("%d %d", &x, &y);
	que[0][0] = 0;
	que[0][1] = x - 1;
	que[0][2] = y - 1;
	gg[0][x - 1][y - 1] = '#';
	queNum = 1;
	ans = 1;

	while(queNum > 0)
	{
		queNum--;
		tempNum = 0;
		if (que[queNum][0] > 0)
		{
			if (gg[que[queNum][0] - 1][que[queNum][1]][que[queNum][2]] == '.')
			{
				temp[tempNum][0] = que[queNum][0] - 1;
				temp[tempNum][1] = que[queNum][1];
				temp[tempNum][2] = que[queNum][2];
				tempNum++;
				ans++;
				gg[que[queNum][0] - 1][que[queNum][1]][que[queNum][2]] = '#';
			}
		}
		if (que[queNum][0] < k - 1)
		{
			if (gg[que[queNum][0] + 1][que[queNum][1]][que[queNum][2]] == '.')
			{
				temp[tempNum][0] = que[queNum][0] + 1;
				temp[tempNum][1] = que[queNum][1];
				temp[tempNum][2] = que[queNum][2];
				tempNum++;
				ans++;
				gg[que[queNum][0] + 1][que[queNum][1]][que[queNum][2]] = '#';
			}
		}
		if (que[queNum][1] > 0)
		{
			if (gg[que[queNum][0]][que[queNum][1] - 1][que[queNum][2]] == '.')
			{
				temp[tempNum][0] = que[queNum][0];
				temp[tempNum][1] = que[queNum][1] - 1;
				temp[tempNum][2] = que[queNum][2];
				tempNum++;
				ans++;
				gg[que[queNum][0]][que[queNum][1] - 1][que[queNum][2]] = '#';
			}
		}
		if (que[queNum][1] < n - 1)
		{
			if (gg[que[queNum][0]][que[queNum][1] + 1][que[queNum][2]] == '.')
			{
				temp[tempNum][0] = que[queNum][0];
				temp[tempNum][1] = que[queNum][1] + 1;
				temp[tempNum][2] = que[queNum][2];
				tempNum++;
				ans++;
				gg[que[queNum][0]][que[queNum][1] + 1][que[queNum][2]] = '#';
			}
		}
		if (que[queNum][2] > 0)
		{
			if (gg[que[queNum][0]][que[queNum][1]][que[queNum][2] - 1] == '.')
			{
				temp[tempNum][0] = que[queNum][0];
				temp[tempNum][1] = que[queNum][1];
				temp[tempNum][2] = que[queNum][2] - 1;
				tempNum++;
				ans++;
				gg[que[queNum][0]][que[queNum][1]][que[queNum][2] - 1] = '#';
			}
		}
		if (que[queNum][2] < m - 1)
		{
			if (gg[que[queNum][0]][que[queNum][1]][que[queNum][2] + 1] == '.')
			{
				temp[tempNum][0] = que[queNum][0];
				temp[tempNum][1] = que[queNum][1];
				temp[tempNum][2] = que[queNum][2] + 1;
				tempNum++;
				ans++;
				gg[que[queNum][0]][que[queNum][1]][que[queNum][2] + 1] = '#';
			}
		}
		for(i = 0;i < tempNum;i++)
		{
			que[queNum][0] = temp[i][0];
			que[queNum][1] = temp[i][1];
			que[queNum][2] = temp[i][2];
			queNum++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
