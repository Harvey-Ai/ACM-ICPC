/*
Description

FJ has moved his K (1 <= K <= 30) milking machines out into the cow pastures among the C (1 <= C <= 200) cows. A set of paths of various lengths runs among the cows and the milking machines. The milking machine locations are named by ID numbers 1..K; the cow locations are named by ID numbers K+1..K+C. 

Each milking point can "process" at most M (1 <= M <= 15) cows each day. 

Write a program to find an assignment for each cow to some milking machine so that the distance the furthest-walking cow travels is minimized (and, of course, the milking machines are not overutilized). At least one legal assignment is possible for all input data sets. Cows can traverse several paths on the way to their milking machine. 
Input

* Line 1: A single line with three space-separated integers: K, C, and M. 

* Lines 2.. ...: Each of these K+C lines of K+C space-separated integers describes the distances between pairs of various entities. The input forms a symmetric matrix. Line 2 tells the distances from milking machine 1 to each of the other entities; line 3 tells the distances from machine 2 to each of the other entities, and so on. Distances of entities directly connected by a path are positive integers no larger than 200. Entities not directly connected by a path have a distance of 0. The distance from an entity to itself (i.e., all numbers on the diagonal) is also given as 0. To keep the input lines of reasonable length, when K+C > 15, a row is broken into successive lines of 15 numbers and a potentially shorter line to finish up a row. Each new row begins on its own line. 
Output

A single line with a single integer that is the minimum possible total distance for the furthest walking cow. 
Sample Input

2 3 2
0 3 2 1 1
3 0 3 2 0
2 3 0 1 0
1 2 1 0 2
1 0 0 2 0
Sample Output

2
*/


#include <stdio.h>
#include <string.h>
#define MAX 1000000
int g[500][300],cx[500],cy[500],used[500];
int nx,ny,c,k;
int path(int u,int mid)
{
	int i;
	for(i=0;i<ny;i++)
	{
		if(g[u][i+k]<=mid&&!used[i])
		{
			used[i]=1;
			if(cy[i]==-1||path(cy[i],mid))
			{
				cx[u]=i;
				cy[i]=u;
				return 1;
			}
		}
	}
	return 0;
}
bool check(int mid)
{
	int i,res;
	res=0;
	memset(cx,0xff,sizeof(cx));
    memset(cy,0xff,sizeof(cy));
	for(i=0;i<nx;i++)
		if(cx[i]==-1)
		{
			memset(used,0,sizeof(used));
			res+=path(i,mid);
		}
	if(res<c)
		return 0;
	else
		return 1;
}
int main()
{
	int i,j,l,m,min,mid,max;
	scanf("%d%d%d",&k,&c,&m);
	for(i=0;i<k+c;i++)
		for(j=0;j<k+c;j++)
		{
			scanf("%d",&g[i][j]);
			if(g[i][j]==0)
				g[i][j]=MAX;
		}

	for(l=0;l<k+c;l++)
		for(i=0;i<k+c;i++)
			for(j=0;j<k+c;j++)
				if(g[i][l]+g[l][j]<g[i][j])
					g[i][j]=g[i][l]+g[l][j];

	max=0;
	for(i=0;i<k;i++)
		for(j=k;j<k+c;j++)
			if(g[i][j]>max)
				max=g[i][j];
	for(i=k-1;i>=0;i--)
		for(j=0;j<m;j++)
			for(l=0;l<k+c;l++)
				g[(i+1)*m-1-j][l]=g[i][l];
	min=0;
	nx=m*k;ny=c;
	while(min<=max)
	{
		mid=(min+max)/2;
		if(check(mid))
			max=mid-1;
		else
			min=mid+1;
	}
	printf("%d\n",min);
	return 0;
}
