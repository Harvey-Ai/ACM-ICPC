/*
Samball is going to travel in the coming vacation. Now it's time to make a plan. After choosing the destination city, the next step is to determine the travel route. As this poor guy has just experienced a tragic lost of money, he really has limited amount of money to spend. He wants to find the most costless route. Samball has just learned that the travel company will carry out a discount strategy during the vacation: the most expensive flight connecting two cities along the route will be free. This is really a big news.

Now given the source and destination cities, and the costs of all the flights, you are to calculate the minimum cost. It is assumed that the flights Samball selects will not have any cycles and the destination is reachable from the source.


Input

The input contains several test cases, each begins with a line containing names of the source city and the destination city. The next line contains an integer m (<=100), the number of flights, and then m lines follow, each contains names of the source city and the destination city of the flight and the corresponding cost. City names are composed of not more than 10 uppercase letters. Costs are integers between 0 to 10000 inclusively.

Process to the end of file.


Output

For each test case, output the minimum cost in a single line.


Sample Input

HANGZHOU BEIJING
2
HANGZHOU SHANGHAI 100
SHANGHAI BEIJING 200


Sample Output

100
*/

#include <stdio.h>
#include <string.h>
#define MAX 100000
#define NMAX 205
int path[NMAX],graph[NMAX][NMAX],dis[NMAX],s[NMAX];
int main()
{
	int dijkstra(int n);
	char city[102][20],sour[20],dest[20];
	int i,j,s,t,cnt,n,cost;
	while(scanf("%s%s",sour,dest)!=EOF)
	{
		for(i=0;i<201;i++)
			for(j=0;j<201;j++)
				graph[i][j]=-1;
		strcpy(city[0],sour);
		strcpy(city[1],dest);
		cnt=2;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s%s",sour,dest);
			s=t=-1;
			for(i=0;i<cnt;i++)
			{
				if(strcmp(sour,city[i])==0) s=i;
				if(strcmp(dest,city[i])==0) t=i;
			}
			if(s==-1) 
			{
				s=cnt;
				strcpy(city[cnt],sour);
				cnt++;
			}
			if(t==-1)
			{
				t=cnt;
				strcpy(city[cnt],dest);
				cnt++;
			}
			scanf("%d",&cost);
			graph[t][s]=graph[s][t]=cost;
		}
		printf("%d\n",dijkstra(cnt));
	}
	return 0;
}

int dijkstra(int n)
{
	int i,j,v,u,t,ldis,max[205];
	v=0;
	for(i=0;i<n;i++)
	{
		path[i]=-1;
		dis[i]=MAX;
		s[i]=0;
		max[i]=-1;
	}
	max[0]=0;
	dis[v]=0;
	s[v]=1;
	u=v;
	for(i=0;i<n;i++)
	{
		if(u==1)
			break;
		for(j=0;j<n;j++)
			if(graph[u][j]!=-1&&s[j]!=1)
			{
				if(max[u]>graph[u][j]) t=max[u];
				else t=graph[u][j];
				if(dis[u]+graph[u][j]+max[u]-t<dis[j])
				{
					dis[j]=dis[u]+graph[u][j]+max[u]-t;
					max[j]=t;
				}
			}
		ldis=MAX;
		for(j=0;j<n;j++)
			if(dis[j]<ldis&&s[j]==0)//&&dis[j]>0)
			{
				ldis=dis[j];
				u=j;
			}
		s[u]=1;
	}
	return dis[1];
}
