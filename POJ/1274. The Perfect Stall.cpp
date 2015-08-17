/*
Description

Farmer John completed his new barn just last week, complete with all the latest milking technology. Unfortunately, due to engineering problems, all the stalls in the new barn are different. For the first week, Farmer John randomly assigned cows to stalls, but it quickly became clear that any given cow was only willing to produce milk in certain stalls. For the last week, Farmer John has been collecting data on which cows are willing to produce milk in which stalls. A stall may be only assigned to one cow, and, of course, a cow may be only assigned to one stall. 
Given the preferences of the cows, compute the maximum number of milk-producing assignments of cows to stalls that is possible. 
Input

The input includes several cases. For each case, the first line contains two integers, N (0 <= N <= 200) and M (0 <= M <= 200). N is the number of cows that Farmer John has and M is the number of stalls in the new barn. Each of the following N lines corresponds to a single cow. The first integer (Si) on the line is the number of stalls that the cow is willing to produce milk in (0 <= Si <= M). The subsequent Si integers on that line are the stalls in which that cow is willing to produce milk. The stall numbers will be integers in the range (1..M), and no stall will be listed twice for a given cow.
Output

For each case, output a single line with a single integer, the maximum number of milk-producing stall assignments that can be made.
Sample Input

5 5
2 2 5
3 2 3 4
2 1 5
3 1 2 5
1 2 
Sample Output

4
*/

#include <stdio.h>
#include <memory.h>
#define maxn 201
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
	int i,a,n,m,num;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		nx=n;ny=m;
		memset(g,0,sizeof(g));
		for(i=0;i<n;i++)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&a);
				g[i][a-1]=1;
			}
		}
		printf("%d\n",maxmatch());
	}
	return 0;
}
