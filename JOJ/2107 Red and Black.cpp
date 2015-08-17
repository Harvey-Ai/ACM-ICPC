#include <stdio.h>
int main()
{
	int search(int graph[21][21],int r,int l,int m,int n);
	char c;
	int graph[21][21];
	int i,j,m,n,r,l;
	while(scanf("%d%d",&n,&m),m)
	{
		getchar();
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				c=getchar();
				switch(c)
				{
				case '.':{graph[i][j]=1;break;}
				case '#':{graph[i][j]=0;break;}
				case '@':{graph[i][j]=2;r=i;l=j;break;}
				}
			}
			getchar();
		}
		printf("%d\n",search(graph,r,l,m,n));
	}
	return 0;
}


int search(int graph[21][21],int r,int l,int m,int n)
{
	int sum=1;
	graph[r][l]=0;
	if(r)
		if(graph[r-1][l])
			sum+=search(graph,r-1,l,m,n);
	if(r<m-1)
		if(graph[r+1][l])
			sum+=search(graph,r+1,l,m,n);
	if(l)
		if(graph[r][l-1])
			sum+=search(graph,r,l-1,m,n);
	if(l<n-1)
		if(graph[r][l+1])
			sum+=search(graph,r,l+1,m,n);
	return sum;
}
			

