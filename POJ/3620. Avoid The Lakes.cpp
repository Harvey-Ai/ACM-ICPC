/*
Description

Farmer John's farm was flooded in the most recent storm, a fact only aggravated by the information that his cows are deathly afraid of water. His insurance agency will only repay him, however, an amount depending on the size of the largest "lake" on his farm.

The farm is represented as a rectangular grid with N (1 ≤ N ≤ 100) rows and M (1 ≤ M ≤ 100) columns. Each cell in the grid is either dry or submerged, and exactly K (1 ≤ K ≤ N × M) of the cells are submerged. As one would expect, a lake has a central cell to which other cells connect by sharing a long edge (not a corner). Any cell that shares a long edge with the central cell or shares a long edge with any connected cell becomes a connected cell and is part of the lake.

Input

* Line 1: Three space-separated integers: N, M, and K
* Lines 2..K+1: Line i+1 describes one submerged location with two space separated integers that are its row and column: R and C

Output

* Line 1: The number of cells that the largest lake contains.　

Sample Input

3 4 5
3 2
2 2
3 1
2 3
1 1
Sample Output

4
*/


#include <stdio.h>
#include <string.h>
int g[101][101],f[101][101];
int m,n,tt;
void dfs(int r,int l)
{
	f[r][l]=1;
	if(r+1<=n&&g[r+1][l]&&f[r+1][l]==0)
	{
		tt++;
		dfs(r+1,l);
	}
	if(r-1>0&&g[r-1][l]&&f[r-1][l]==0)
	{
		tt++;
		dfs(r-1,l);
	}
	if(l+1<=m&&g[r][l+1]&&f[r][l+1]==0)
	{
		tt++;
		dfs(r,l+1);
	}
	if(l-1>0&&g[r][l-1]&&f[r][l-1]==0)
	{
		tt++;
		dfs(r,l-1);
	}
}
int main()
{
	int i,j,k,best,a,b;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&a,&b);
			g[a][b]=1;
		}
		best=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(f[i][j]==0&&g[i][j])
				{
					tt=1;
					dfs(i,j);
					if(tt>best)
						best=tt;
				}
		printf("%d\n",best);
	}
	return 0;
}
