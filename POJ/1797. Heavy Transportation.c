/*
Description

Background 
Hugo Heavy is happy. After the breakdown of the Cargolifter project he can now expand business. But he needs a clever man who tells him whether there really is a way from the place his customer has build his giant steel crane to the place where it is needed on which all streets can carry the weight. 
Fortunately he already has a plan of the city with all streets and bridges and all the allowed weights.Unfortunately he has no idea how to find the the maximum weight capacity in order to tell his customer how heavy the crane may become. But you surely know. 

Problem 
You are given the plan of the city, described by the streets (with weight limits) between the crossings, which are numbered from 1 to n. Your task is to find the maximum weight that can be transported from crossing 1 (Hugo's place) to crossing n (the customer's place). You may assume that there is at least one path. All streets can be travelled in both directions.
Input

The first line contains the number of scenarios (city plans). For each city the number n of street crossings (1 <= n <= 1000) and number m of streets are given on the first line. The following m lines contain triples of integers specifying start and end crossing of the street and the maximum allowed weight, which is positive and not larger than 1000000. There will be at most one street between each pair of crossings.
Output

The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print a single line containing the maximum allowed weight that Hugo can transport to the customer. Terminate the output for the scenario with a blank line.
Sample Input

1
3 3
1 2 3
1 3 4
2 3 5
Sample Output

Scenario #1:
4
*/


#include <stdio.h>
#include <string.h>
#define MAX 1000005
#define NMAX 1005
int n;
int g[NMAX][NMAX],dis[NMAX],used[NMAX];
void dijkstra()
{
	int i,j,v,u,ldis;
	v=0;
	for(i=0;i<n;i++)
	{
		dis[i]=0;
		used[i]=0;
	}
	dis[v]=MAX;
	used[v]=1;
	u=v;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(g[u][j]&&used[j]!=1&&dis[j]<dis[u]&&dis[j]<g[u][j])
			{
				if(g[u][j]<dis[u])
					dis[j]=g[u][j];
				else
					dis[j]=dis[u];
			}

		ldis=0;
		for(j=0;j<n;j++)
			if(dis[j]>ldis&&used[j]==0)
			{
				ldis=dis[j];
				u=j;
			}
		used[u]=1;
	}
	printf("%d\n",dis[n-1]);
}

int main()
{
	int i,m,l,a,b,c,ncase;
	l=1;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d%d",&n,&m);
		memset(g,0,sizeof(g));
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			g[a-1][b-1]=g[b-1][a-1]=c;
		}
		printf("Scenario #%d:\n",l++);
		dijkstra();
		putchar('\n');
	}
	return 0;
}
