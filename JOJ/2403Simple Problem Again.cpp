#include <iostream>
using namespace std;
int main()
{
	int n,i,j,k,l,l_max,sum;
	int graph[14][14],max[14];
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>graph[i][j];

	sum=0;
	for(i=0;i<n;i++)
	{
		l=i;
		while(flag)
		{
			l_max=0;
			for(j=0;j<n;j++)
				if(graph[l][j]>l_max)
				{
					l_max=graph[l][j];
					max[l]=j;
				}
			for(k=0;k<i;k++)
				if(max[k]==max[l])
				{
					if(graph[k][max[k]]>graph[l][max[l]])
						graph[l][max[l]]=0;
					else
						if(graph[k][max[k]]<graph[l][max[l]])
						{
							sum+=graph[l][max[l]];
							sum-=graph[k][max[k]];
							graph[k][max[k]]=0;
						}





