/*
Description

Up to thirty couples will attend a wedding feast, at which they will be seated on either side of a long table. The bride and groom sit at one end, opposite each other, and the bride wears an elaborate headdress that keeps her from seeing people on the same side as her. It is considered bad luck to have a husband and wife seated on the same side of the table. Additionally, there are several pairs of people conducting adulterous relationships (both different-sex and same-sex relationships are possible), and it is bad luck for the bride to see both members of such a pair. Your job is to arrange people at the table so as to avoid any bad luck.

Input

The input consists of a number of test cases, followed by a line containing 0 0. Each test case gives n, the number of couples, followed by the number of adulterous pairs, followed by the pairs, in the form "4h 2w" (husband from couple 4, wife from couple 2), or "10w 4w", or "3h 1h". Couples are numbered from 0 to n - 1 with the bride and groom being 0w and 0h.

Output

For each case, output a single line containing a list of the people that should be seated on the same side as the bride. If there are several solutions, any one will do. If there is no solution, output a line containing "bad luck".

Sample Input

10 6
3h 7h
5w 3w
7h 6w
8w 3w
7h 3w
2w 5h
0 0
Sample Output

1h 2h 3w 4h 5h 6h 7h 8h 9h
*/

#include <stdio.h>
#include <string.h>
int g[31][31][4],line[31];
int ok,n;
void dfs(int k)
{	
	int i;
	if(ok)
		return;
	if(k==n)
	{
		if(line[1])
			printf("1w");
		else
			printf("1h");
		for(i=2;i<n;i++)
		{
			if(line[i])
				printf(" %dw",i);
			else
				printf(" %dh",i);
		}
		putchar('\n');
		ok=1;
		return;
	}
	for(i=0;i<k;i++)
		if(g[i][k][3-2*line[i]])
			break;
	if(i>=k)
	{
		line[k]=0;
		//if(!g[k][k][3])
		dfs(k+1);
	}
	for(i=0;i<k;i++)
		if(g[i][k][2-2*line[i]])
			break;
	if(i>=k)
	{
		line[k]=1;
		//if(!g[k][k][0])
		dfs(k+1);
	}
}
int main()
{
	int i,m,a,b;
	char c1,c2;
	while(scanf("%d%d",&n,&m),m||n)
	{
		memset(g,0,sizeof(g));
		for(i=0;i<m;i++)
		{
			scanf("%d%c%c%d%c",&a,&c1,&c2,&b,&c2);
			if(c1=='h')
			{
				if(c2=='h')
					g[a][b][0]=g[b][a][0]=1;
				else
					g[a][b][1]=g[b][a][2]=1;
			}
			else
			{
				if(c2=='h')
					g[b][a][1]=g[a][b][2]=1;
				else
					g[a][b][3]=g[b][a][3]=1;
			}
		}
		line[0]=1;
		ok=0;
		dfs(1);
		if(ok==0)
			printf("bad luck\n");
	}
	return 0;
}
