/*
Given a graph G(V, E), a clique is a sub-graph g(v, e), so that for all vertex pairs v1, v2 in v, there exists an edge (v1, v2) in e. Maximum clique is the clique that has maximum number of vertex.


Input

Input contains multiple tests. For each test:

The first line has one integer n, the number of vertex. (1 < n <= 50)

The following n lines has n 0 or 1 each, indicating whether an edge exists between i (line number) and j (column number).

A test with n = 0 signals the end of input. This test should not be processed.


Output

One number for each test, the number of vertex in maximum clique.


Sample Input

5
0 1 1 0 1
1 0 1 1 1
1 1 0 1 1
0 1 1 0 1
1 1 1 1 0
0


Sample Output

4
*/
#include <stdio.h>
#include <memory.h>
int n,xl,max,V;
int g[51][51];
int x[51],c[51];
int found;
void search(int x[],int xl,int size)
{
	int i,j,k;
	int bak[51];
	if(xl==0) 
	{
		if (size>max)
		{
			max=size;
		//	found=1;
		}
		return;
	}
	if(size+xl<=max) return;
	for(i=V;i<n;i++) 
		if(x[i]==1)
		{
			x[i]=0;
			if(size+c[i]<=max) return;
			k=0;
			memset(bak,0,sizeof(bak));
			for(j=V;j<n;j++)
				if(g[i][j]==1&&x[j]==1)
				{
					k++;
					bak[j]=1;
				}
			search(bak,k,size+1);
		//	if(found==1) return;
		}
}
int main()
{
	int i,j;
	while (scanf("%d",&n),n!=0)
	{
		max=0;
		memset(c,1,sizeof(c));
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
		for(V=n-1;V>=0;V--)
		{
			xl=0;
		//	found=0;
			memset(x,0,sizeof(x));
			for (j=V+1;j<n;j++)
				if(g[V][j]==1)
				{
					xl++;
					x[j]=1;
				}
			search(x,xl,1);
			c[V]=max;
		}
		printf("%d\n",c[0]);
	}
	return 0;
}
