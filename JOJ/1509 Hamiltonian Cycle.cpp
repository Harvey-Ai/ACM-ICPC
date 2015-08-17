#include <iostream>
using namespace std;
int main()
{
	int i,j,a,b,n;
	int graph[200][200];
	while(cin>>n)
	{
		for(i=0;i<200;i++)
		{
			count[i]=0;
			for(j=0;j<200;j++)
				graph[i][j]=0;
		}
		while(cin>>a,a!='%')
		{
			cin>>b;
			graph[a][b]=graph[b][a]=1;
		}
		for(i=0;i<200;i++)
			for(j=0;j<200;j++)
				if(graph[i][j])
					count[i]++;
		if(topo(count))
		{
			for(i=0;i<200;i++)
				if(count[i])
				{
					cout<<i;
					break;
				}
			while(i<200)
				cout<<" "<<i;
			cout<<endl;
		}
		else
			cout<<"N"<<endl;
	}
	return 0;
}
