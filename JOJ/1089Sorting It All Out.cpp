#include <iostream>
using namespace std;
int m,n;
int main()
{
	bool topoorder(int graph[27][27],int count[],int k);
	int graph[27][27],count1[27],count2[27];
	int i,j;
	char c1,c2;
	
	while(cin>>n>>m,n||m)
	{
		cin.get();
		for(i = 1;i <= 26; i++)
			for(j = 1;j <= 26; j++)
				graph[i][j] = 0;

		for(i = 1;i <= 26; i++)
			count1[i] = 0;
		
		for(i = 1;i <= m; i++)
		{
			c1 = cin.get();
			cin.get();
			c2 = cin.get();
			cin.get();
			j = 1;
			while(graph[c1-'A'+1][j++] != 0){}
			graph[c1-'A'+1][j-1] = c2-'A'+1;
			count1[c2-'A'+1]++;
			for(j = 1;j <= 26; j++)
				count2[j] = count1[j];
			if(topoorder(graph,count2,i))
				break;
		}
		while(++i <= m)
		{
			cin.get();cin.get();cin.get();cin.get();
		}
	}
	return 0;
}


bool topoorder(int graph[27][27],int count[],int k)
{
	int i,j,l,r,q,way[27],head[27];
	r = 1;;q = 1;
	bool flag = 1;

	for(i = 1;i <= n;i++)
		if(count[i] == 0)
			head[q++] = i;
		
	if(q == 1)
	{
		cout<<"Inconsistency found after "<<k<<" relations."<<endl;
		return 1;
	}
	q--;
	if(q > 1)
		flag = 0;
	
	while(q > 0)
	{
		if(q > 1)
			flag = 0;
		j = head[q--];
		way[r++] = j;
		l = 0;
		while(graph[j][++l] != 0)
			if(--count[graph[j][l]] == 0)
				head[++q] = graph[j][l];
	}

	for(j = 1;j <= n;j++)
		if(count[j] > 0)
		{
			cout<<"Inconsistency found after "<<k<<" relations."<<endl;
			return 1;
		}

	if(r == n+1 && flag)
	{
		cout<<"Sorted sequence determined after "<<k<<" relations: ";
		for(i = 1;i <= n;i++)
			cout<<char(way[i]+'A'-1);
		cout<<"."<<endl;
		return 1;
	}
	else
		if(k == m)
		{
			cout<<"Sorted sequence cannot be determined."<<endl;
			return 1;
		}
		else
			return 0;
}
















