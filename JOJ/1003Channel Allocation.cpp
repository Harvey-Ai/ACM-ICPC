#include <iostream>
using namespace std;
int main()
{
	int dfs(int graph,int v,int visted);
	int i,j,n,max,cloror,graph[26][26];
	char c;
	while(cin>>n,n)
	{
		max=26;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				graph[i][j]=0;

		cin.get();
		for(i=0;i<n;i++)
		{
			cin.get();
			cin.get();
			while(c=cin.get(),c!='\n')
				graph[i][c-'A']=1;
		}

		for(i=0;i<n;i++)	
		{
			for(j=0;j<n;j++)
				visted[j]=0;
			cloror=dfs(graph,i,visted);
			if(cloror>max)
				max=cloror;
		}
	}
	return 0;
}


int dfs(int graph,int v,int visted)
{






