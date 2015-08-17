#include <iostream>
using namespace std;
bool graph[2000][2000],visited[2000];
bool check(bool graph[2000][2000],int i,int j);
int main()
{
	bool search(int v,bool graph[2000][2000]);
	int i,j,xi,yi,n,m;
	while(cin>>n>>m,m&&n)
	{
		for(i=0;i<2000;i++)
		{
			visited[i]=0;
			for(j=0;j<2000;j++)
				graph[i][j]=0;
		}
		while(m--)
		{
			cin>>xi>>yi;
			if(xi<yi)
				graph[xi-1][yi-1]=1;
			else
				graph[yi-1][xi-1]=1;
		}
		if(search(0,graph))
			cout<<"Perfect"<<endl;
		else
			cout<<"Imperfect"<<endl;
		cout<<endl;
	}
	return 0;
}

bool search(int v,bool graph[2000][2000])
{
	int i,j,w=-1;
	visited[v]=1;
	bool flag=1;
	for(i=v+1;i<2000;i++)
		if(graph[v][i])
		{
			w=i;
			break;
		}
	while(w!=-1)
	{
		if(visited[w]==0)
			flag=search(w,graph);
		else
			flag=check(graph,v,w);		
		if(flag==0)
			break;
		for(j=w+1;j<2000;j++)
			if(graph[v][j])
			{
				w=j;
				break;
			}
		if(j==2000)
			w=-1;
	}
	return flag;
}

bool check(bool graph[2000][2000],int i,int j)
{
	int k;
	bool flag1=0,flag2=0;
	for(k=0;k<2000;k++)
	{
		if(i>k)
			flag1=graph[k][i];
		else
			flag1=graph[i][k];
		if(j>k)
			flag2=graph[k][j];
		else
			flag2=graph[j][k];
		if(flag1&&flag2)
			break;
		}
	if(flag1&&flag2)
		return 1;
	else
		return 0;
}




