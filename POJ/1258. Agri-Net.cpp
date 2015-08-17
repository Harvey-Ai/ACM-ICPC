/*
Description

Farmer John has been elected mayor of his town! One of his campaign promises was to bring internet connectivity to all farms in the area. He needs your help, of course. 
Farmer John ordered a high speed connection for his farm and is going to share his connectivity with the other farmers. To minimize cost, he wants to lay the minimum amount of optical fiber to connect his farm to all the other farms. 
Given a list of how much fiber it takes to connect each pair of farms, you must find the minimum amount of fiber needed to connect them all together. Each farm must connect to some other farm such that a packet can flow from any one farm to any other farm. 
The distance between any two farms will not exceed 100,000. 
Input

The input includes several cases. For each case, the first line contains the number of farms, N (3 <= N <= 100). The following lines contain the N x N conectivity matrix, where each element shows the distance from on farm to another. Logically, they are N lines of N space-separated integers. Physically, they are limited in length to 80 characters, so some lines continue onto others. Of course, the diagonal will be 0, since the distance from farm i to itself is not interesting for this problem.
Output

For each case, output a single integer length that is the sum of the minimum length of fiber required to connect the entire set of farms.
Sample Input

4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
Sample Output

28
*/

#include <stdio.h>
#define MAX 105
int graph[MAX][MAX],closet[MAX],prim[MAX];
int main()
{
	int i,j,v,n,min,rel;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&graph[i][j]);
	for(i=0;i<n;i++)
	{
		closet[i]=graph[0][i];
		prim[i]=0;
	}
	prim[0]=-1;
	rel=0;
	for(i=1;i<n;i++)
	{
		min=1000000;
		v=0;
		for(j=0;j<n;j++)
		{
			if(prim[j]!=-1&&closet[j]<min)
			{
				v=j;
				min=closet[j];
			}
		}
		if(v)
		{
			rel+=min;
			prim[v]=-1;
			for(j=0;j<n;j++)
				if(prim[j]!=-1&&graph[v][j]<closet[j])
				{
					closet[j]=graph[v][j];
					prim[j]=v;
				}
		}
	}
	printf("%d\n",rel);
	}
	return 0;
}
