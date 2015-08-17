#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int visited[11];
int bull[11], cow[11];
char temp[10];
char str[15][10];
char res[10];
int ans;
int n;

int check()
{
	int i, j, k;
	int bb, cc;
	for(i = 0;i < n;i++)
	{
		bb = cc = 0;
		for(j = 0;j < 4;j++)
		{
			for(k = 0;k < 4;k++)
				if (str[i][j] == temp[k])
					break;
			if (k < 4)
			{
				if (k == j)
					cc++;
				else
					bb++;
			}
		}
		if (cc != cow[i] || bb != bull[i])
			return 0;
	}
//	printf("%s %s %d %d %d\n", temp, str[1], n, bull[1], cow[1]);
//	printf("%d %d\n", bb, cc);
	return 1;
}

void dfs(int kk)
{
	int i;
	if (kk == 4)
	{
		if (check())
		{
			strcpy(res, temp);
			ans++;
		}
		return;
	}
	if (ans > 1)
		return;
	for(i = 0;i < 10;i++)
		if (!visited[i])
		{
			temp[kk] = i + '0';
			visited[i] = 1;
			dfs(kk + 1);
			visited[i] = 0;
		}
}

int main()
{
	int i;
	scanf("%d", &n);

	for(i = 0;i < n;i++)
		scanf("%s %d %d", str[i], &cow[i], &bull[i]);

	memset(visited, 0, sizeof(visited));
	dfs(0);
	if (ans == 1)
		printf("%s\n", res);
	else if (ans == 0)
		printf("Incorrect data\n");
	else printf("Need more data\n");
	return 0;
}
