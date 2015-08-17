/*
Description

One cow from each of N farms (1 ≤ N ≤ 1000) conveniently numbered 1..N is going to attend the big cow party to be held at farm #X (1 ≤ X ≤ N). A total of M (1 ≤ M ≤ 100,000) unidirectional (one-way roads connects pairs of farms; road i requires Ti (1 ≤ Ti ≤ 100) units of time to traverse.

Each cow must walk to the party and, when the party is over, return to her farm. Each cow is lazy and thus picks an optimal route with the shortest time. A cow's return route might be different from her original route to the party since roads are one-way.

Of all the cows, what is the longest amount of time a cow must spend walking to the party and back?

Input

Line 1: Three space-separated integers, respectively: N, M, and X 
Lines 2..M+1: Line i+1 describes road i with three space-separated integers: Ai, Bi, and Ti. The described road runs from farm Ai to farm Bi, requiring Ti time units to traverse.
Output

Line 1: One integer: the maximum of time any one cow must walk.
Sample Input

4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
Sample Output

10
Hint

Cow 4 proceeds directly to the party (3 units) and returns via farms 1 and 3 (7 units), for a total of 10 time units.
*/


#include <stdio.h>
int graph[1005][1005],dd[1005];
int x;
void dijkstra(int n)
{
	int dis[1005],used[1005];
	int i,j,v,u,ldis;
	v=x-1;
	for(i=0;i<n;i++)
	{
		dis[i]=1000001;
		used[i]=0;
	}
	dis[v]=0;
	used[v]=1;
	u=v;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
			if(graph[u][j]&&!used[j]&&dis[u]+graph[u][j]<dis[j])
				dis[j]=dis[u]+graph[u][j];
		ldis=1000001;
		for(j=0;j<n;j++)
			if(dis[j]<ldis&&used[j]==0)
			{
				ldis=dis[j];
				u=j;
			}
		used[u]=1;
	}
	for(i=0;i<n;i++)
		dd[i]+=dis[i];
}

int main()
{
	int i,j,a,b,c,n,m,res,temp;
	scanf("%d%d%d",&n,&m,&x);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		graph[a-1][b-1]=c;
	}
	dijkstra(n);
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
		{
			temp=graph[i][j];
			graph[i][j]=graph[j][i];
			graph[j][i]=temp;
		}
	dijkstra(n);
	res=0;
	for(i=0;i<n;i++)
		if(dd[i]>res)
			res=dd[i];
	printf("%d\n",res);
	return 0;
}
