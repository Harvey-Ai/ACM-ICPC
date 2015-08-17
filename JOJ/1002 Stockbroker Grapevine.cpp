#include <iostream>
using namespace std;
int main()
{
	int n,m,k,s_time,time,srouce,i,j;
	bool flag;
	int graph[100][100];
	while(cin>>n,n)
	{
		s_time=10000;srouce=-1;
		for(i=0;i<=99;i++)
			for(j=0;j<=99;j++)
				graph[i][j]=0;

		for(i=0;i<=n-1;i++)
		{
			cin>>m;
			for(j=0;j<=m-1;j++)
			{
				cin>>k;
				cin>>graph[i][k-1];
			}
		}

		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				if(i!=k)
				for(j=0;j<n;j++)
					if(j!=k&&j!=i&&graph[i][k]!=0&&graph[k][j]!=0&&(graph[i][k]+graph[k][j]<graph[i][j]||graph[i][j]==0))
						graph[i][j]=graph[i][k]+graph[k][j];
		
		for(i=0;i<n;i++)
		{
			flag=1;time=0;
			for(j=0;j<n;j++)
			{
				if(graph[i][j]==0)
				{
					if(i!=j)
					{
						flag=0;
						break;
					}
				}
				else
					if(graph[i][j]>time)
						time=graph[i][j];
			}
			if(flag)
				if(time<=s_time)
				{
					s_time=time;
					srouce=i;
				}
		}
		if(srouce!=-1&&s_time!=10000)
			cout<<srouce+1<<" "<<s_time<<endl;
		else
		    cout<<"disjoint"<<endl;
	}
	return 0;
}