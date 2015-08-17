/*
Description

For their physical fitness program, N (2 ≤ N ≤ 1,000,000) cows have decided to run a relay race using the T (2 ≤ T ≤ 100) cow trails throughout the pasture.

Each trail connects two different intersections (1 ≤ I1i ≤ 1,000; 1 ≤ I2i ≤ 1,000), each of which is the termination for at least two trails. The cows know the lengthi of each trail (1 ≤ lengthi  ≤ 1,000), the two intersections the trail connects, and they know that no two intersections are directly connected by two different trails. The trails form a structure known mathematically as a graph.

To run the relay, the N cows position themselves at various intersections (some intersections might have more than one cow). They must position themselves properly so that they can hand off the baton cow-by-cow and end up at the proper finishing place.

Write a program to help position the cows. Find the shortest path that connects the starting intersection (S) and the ending intersection (E) and traverses exactly N cow trails.

Input

* Line 1: Four space-separated integers: N, T, S, and E
* Lines 2..T+1: Line i+1 describes trail i with three space-separated integers: lengthi , I1i , and I2i

Output

* Line 1: A single integer that is the shortest distance from intersection S to intersection E that traverses exactly N cow trails.

Sample Input

2 6 6 4
11 4 6
4 4 8
8 4 9
6 6 8
2 6 9
3 8 9
Sample Output

10
*/

#include <stdio.h>
#include <string.h>
int g[20][101][101],x[20],res[101],mid[101],arr[101];
int main()
{
	int i,j,k,l,n,t,s,e,a,b,len,nn,ll;
	scanf("%d%d%d%d",&n,&t,&s,&e);
	s--;e--;
	arr[0]=s;
	arr[1]=e;
	ll=2;
	for(i=0;n;i++)
	{
		x[i]=n%2;
		n/=2;
	}
	nn=i;
	while(t--)
	{
		scanf("%d%d%d",&len,&a,&b);
		a--;b--;
		for(i=0;i<ll;i++)
			if(arr[i]==a)
				break;
		if(i<ll)
			a=i;
		else
		{
			arr[ll]=a;
			a=ll;
			ll++;
		}
		for(i=0;i<ll;i++)
			if(arr[i]==b)
				break;
		if(i<ll)
			b=i;
		else
		{
			arr[ll]=b;
			b=ll;
			ll++;
		}
		g[0][b][a]=g[0][a][b]=len;
	}
	for(l=1;l<nn;l++)
		for(k=0;k<ll;k++)
			for(i=0;i<ll;i++)
				for(j=0;j<ll;j++)
					if(g[l-1][i][k]&&g[l-1][k][j])
					{
						if(g[l-1][i][k]+g[l-1][k][j]<g[l][i][j]||g[l][i][j]==0)
							g[l][i][j]=g[l-1][i][k]+g[l-1][k][j];
					}
	memset(res,0,sizeof(res));
	k=0;
	for(l=0;l<nn;l++)
	{
		if(x[l]==0)
			continue;
		if(k)
		{
			memset(mid,0,sizeof(mid));
			for(i=0;i<ll;i++)
				for(j=0;j<ll;j++)
					if(res[i]&&g[l][i][j])
					{
						if(res[i]+g[l][i][j]<mid[j]||mid[j]==0)
							mid[j]=res[i]+g[l][i][j];
					}
			for(i=0;i<ll;i++)
				res[i]=mid[i];
		}
		else
		{
			k=1;
			for(i=0;i<ll;i++)
				res[i]=g[l][0][i];
		}
	}
	printf("%d\n",res[1]);
	return 0;
}
