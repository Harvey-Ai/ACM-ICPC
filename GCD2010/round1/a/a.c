#include <stdio.h>
#define N 60

char g[N][N];
int n, kk;
int check()
{
	int i, j, k;
	int bCnt, rCnt;
	int bWin = 0, rWin = 0;
	for(i = 0;i < n;i++)
	{
		bCnt = rCnt = 0;
		for(j = 0;j < n;j++)
		{
			if (g[i][j] == 'R')
			{
				rCnt++;
				bCnt = 0;
				if (rCnt >= kk)
					rWin = 1;
			}
			else if (g[i][j] == 'B')
			{
				bCnt++;
				rCnt = 0;
				if (bCnt >= kk)
					bWin = 1;
			}
			else
			{
				bCnt = 0;
				rCnt = 0;
			}
		}
	}

	for(j = 0;j < n;j++)
	{
		bCnt = rCnt = 0;
		for(i = 0;i < n;i++)
		{
			if (g[i][j] == 'R')
			{
				bCnt = 0;
				rCnt++;
				if (rCnt >= kk)
					rWin = 1;
			}
			else if (g[i][j] == 'B')
			{
				rCnt = 0;
				bCnt++;
				if (bCnt >= kk)
					bWin = 1;
			}	
			else
			{
				bCnt = 0;
				rCnt = 0;
			}
		}
	}

	for(i = 0;i < n;i++)
	{
		bCnt = rCnt = 0;
		for(k = 0; i + k < n;k++)
		{
			if (g[i + k][k] == 'R')
			{
				bCnt = 0;
				rCnt++;
				if (rCnt >= kk)
					rWin = 1;
			}
			else if (g[i + k][k] == 'B')
			{
				rCnt = 0;
				bCnt++;
				if (bCnt >= kk)
					bWin = 1;
			}
			else
			{
				bCnt = 0;
				rCnt = 0;
			}
		}
	}

	for(j = 0;j < n;j++)
	{
		bCnt = rCnt = 0;
		for(k = 0; j + k < n;k++)
		{
			if (g[k][j + k] == 'R')
			{
				bCnt = 0;
				if (rCnt >= kk)
					rWin = 1;
				rCnt++;
			}
			else if (g[k][j + k] == 'B')
			{
				rCnt = 0;
				bCnt++;
				if (bCnt >= kk)
					bWin = 1;
			}
			else
			{
				bCnt = 0;
				rCnt = 0;
			}
		}
	}

	for(i = 0;i < n;i++)
	{
		bCnt = rCnt = 0;
		for(k = 0; i + k< n;k++)
		{
			if (g[i + k][n - 1 - k] == 'R')
			{
				rCnt++;
				if (rCnt >= kk)
					rWin = 1;
				bCnt = 0;
			}
			else if (g[i + k][n - 1 - k] == 'B')
			{
				bCnt++;
				if (bCnt >= kk)
					bWin = 1;
				rCnt = 0;
			}
			else
			{
				bCnt = 0;
				rCnt = 0;
			}
		}
	}

	for(j = 0;j < n;j++)
	{
		bCnt = rCnt = 0;
		{
		for(k = 0; j - k > -1;k++)
			if (g[k][j - k] == 'R')
			{
				bCnt = 0;
				rCnt++;
				if (rCnt >= kk)
					rWin = 1;
			}
			else if (g[k][j - k] == 'B')
			{
				bCnt++;
				rCnt = 0;
				if (bCnt >= kk)
					bWin = 1;
			}
			else
			{
				bCnt = 0;
				rCnt = 0;
			}
		}
	}
	if (rWin && bWin)
		return 3;
	if (rWin)
		return 1;
	if (bWin)
		return 2;
	return 0;
}
void rotate()
{
	char temp[N][N];
	int i, j, tr;

	// clockwise rotate
	for(i = 0;i < n;i++)
	{
		for(tr = n - 1,j = n - 1;j >= 0;j--)
		{
			if (g[i][j] != '.')
			{
				if (g[i][j] !='B' && g[i][j] != 'R')
				{
					putchar(g[i][j]);
					putchar('\n');
				}
				temp[tr--][n - 1 - i] = g[i][j];
			}
		}
		while(tr >= 0)
		{
			temp[tr][n - 1 - i] = '.';
			tr--;
		}
	}

	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
			g[i][j] = temp[i][j];
}
int main()
{
	int ncase, icase;
	int i;
	int rNum;
	int win;
	
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);
	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d", &n, &kk);
		for(i = 0;i < n;i++)
			scanf("%s", g[i]);

		win = 0;
		for(rNum = 0;rNum < 2;rNum++)
		{
			win = check();
			if (win)
				break;
			rotate();
		}
		switch(win)
		{
			case 1:
				printf("Case #%d: Red\n", icase);
				break;
			case 2:
				printf("Case #%d: Blue\n", icase);
				break;
			case 3:
				printf("Case #%d: Both\n", icase);
				break;
			case 0:
				printf("Case #%d: Neither\n", icase);
				break;
			default:
				break;
		}


	}
	return 0;
}

