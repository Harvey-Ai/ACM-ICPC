/*
Description

Welcome to the Annual Byteland Shooting Contest. Each competitor will shoot to a target which is a rectangular grid. The target consists of r*c squares located in r rows and c columns. The squares are coloured white or black. There are exactly two white squares and r-2 black squares in each column. Rows are consecutively labelled 1,..,r from top to bottom and columns are labelled 1,..,c from left to right. The shooter has c shots. 

A volley of c shots is correct if exactly one white square is hit in each column and there is no row without white square being hit. Help the shooter to find a correct volley of hits if such a volley exists. 
Example 
Consider the following target: 


Volley of hits at white squares in rows 2, 3, 1, 4 in consecutive columns 1, 2, 3, 4 is correct. 
Write a program that: verifies whether any correct volley of hits exists and if so, finds one of them.
Input

The first line of the input contains the number of data blocks x, 1 <= x <= 5. The following lines constitute x blocks. The first block starts in the second line of the input file; each next block starts directly after the previous one. 

The first line of each block contains two integers r and c separated by a single space, 2 <= r <= c <= 1000. These are the numbers of rows and columns, respectively. Each of the next c lines in the block contains two integers separated by a single space. The integers in the input line i + 1 in the block, 1 <= i <= c, are labels of rows with white squares in the i-th column. 
Output

For the i-th block, 1 <= i <= x, your program should write to the i-th line of the standard output either a sequence of c row labels (separated by single spaces) forming a correct volley of hits at white squares in consecutive columns 1, 2, ..., c, or one word NO if such a volley does not exists.
Sample Input

2
4 4
2 4
3 4
1 3
1 4
5 5
1 5
2 4
3 4
2 4
2 3
Sample Output

2 3 1 4
NO

*/


#include <stdio.h>
#include <string.h>
#define maxn 1005
int g[maxn][maxn],cx[maxn],cy[maxn],used[maxn];
int nx,ny;
int path(int u)
{
	int i;
	for(i=0;i<ny;i++)
	{
		if(g[u][i]&&!used[i])
		{
			used[i]=1;
			if(cy[i]==-1||path(cy[i]))
			{
				cx[u]=i;
				cy[i]=u;
				return 1;
			}
		}
	}
	return 0;
}
int maxmatch()
{
	int i,res;
	res=0;
	memset(cx,0xff,sizeof(cx));
    memset(cy,0xff,sizeof(cy));
	for(i=0;i<nx;i++)
		if(cx[i]==-1)
		{
			memset(used,0,sizeof(used));
			res+=path(i);
		}
	return res;
}

int main()
{
	int i,j,r,c,a,b,ncase;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d%d",&r,&c);
		memset(g,0,sizeof(g));
		for(i=0;i<c;i++)
		{
			scanf("%d%d",&a,&b);
			g[i][a-1]=1;
			g[i][b-1]=1;
		}
		nx=c;ny=r;
		if(r<=c&&maxmatch()==r)
		{
			if(cx[0]!=-1)
				printf("%d",cx[0]+1);
			else
			{
				for(i=0;i<r;i++)
					if(g[0][i])
					{
						printf("%d",i+1);
						break;
					}
			}
			for(i=1;i<c;i++)
			{
				if(cx[i]!=-1)
					printf(" %d",cx[i]+1);
				else
				{
					for(j=0;j<r;j++)
						if(g[i][j])
						{
							printf(" %d",j+1);
							break;
						}
				}
			}
			putchar('\n');
		}
		else
			printf("NO\n");
	}
	return 0;
}
