/*
Description

Background 
Professor Hopper is researching the sexual behavior of a rare species of bugs. He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs. 
Problem 
Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.
Input

The first line of the input contains the number of scenarios. Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.
Output

The output for every scenario is a line containing "Scenario #i:", where i is the number of the scenario starting at 1, followed by one line saying either "No suspicious bugs found!" if the experiment is consistent with his assumption about the bugs' sexual behavior, or "Suspicious bugs found!" if Professor Hopper's assumption is definitely wrong.
Sample Input

2
3 3
1 2
2 3
1 3
4 2
1 2
3 4
Sample Output

Scenario #1:
Suspicious bugs found!

Scenario #2:
No suspicious bugs found!
*/



#include <stdio.h>
#include <string>
bool graph[2002][2002];
int visited[2002];
int main()
{
	bool dfs(int p,int n);
	int i,j,u,v,m,n,N,l;
	scanf("%d",&N);
	l=1;
	while(N--)
	{
		printf("Scenario #%d:\n",l++);
		scanf("%d%d",&m,&n);

		for(i=0;i<=m;i++)
			for(j=0;j<=m;j++)
				graph[i][j]=0;

		for(i=0;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			graph[u][v]=graph[v][u]=1;
		}
		memset(visited,0,sizeof(visited));
		for(i=1;i<=m;i++)
		{
			if(visited[i]==0)
				visited[i]=1;
			if(dfs(i,m)==0)
				break;
		}
		if(i>m)
			printf("No suspicious bugs found!\n\n");
		else
			printf("Suspicious bugs found!\n\n");
	}
	return 0;
}

bool dfs(int p,int n)
{
	int i;
	for(i=1;i<=n;i++)
		if(graph[p][i])
		{
			if(visited[i])
			{
				if(visited[p]==visited[i])
					return 0;
			}
			else
			{
				if(visited[p]==1)
					visited[i]=2;
				else
					visited[i]=1;
				if(dfs(i,n)==0)
					return 0;
			}
		}
	return 1;
}
