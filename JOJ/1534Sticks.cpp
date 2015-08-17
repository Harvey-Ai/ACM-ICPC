#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	bool search(bool visited[],int stick[100],int len,int sum,int n);
	int i,n,max,sum,temp;
	int sticks[100];
	bool flag;
	bool visited[100];
	while(cin>>n,n)
	{
		max=1;sum=0;
		for(i=0;i<n;i++)
		{
			cin>>sticks[i];
			if(sticks[i]>max)
				max=sticks[i];
			sum+=sticks[i];
		}
		sort(&sticks[0],&sticks[n]);
		for(i=0;i<n/2;i++)
		{
			temp=sticks[i];
			sticks[i]=sticks[n-1-i];
			sticks[n-1-i]=temp;
		}
		max=sum/max;
		while(max>0)
		{
			flag=1;
			for(i=0;i<n;i++)
				visited[i]=0;
			for(i=0;i<max;i++)
				if(search(visited,sticks,sum/max,0,n)==0)
				{
					flag=0;
					break;
				}
			if(flag)
			{
				cout<<sum/max<<endl;
				break;
			}
			max--;
		}
	}
	return 0;
}


bool search(bool visited[],int stick[100],int len,int sum,int n)
{
	int i;
	bool flag=0;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			sum+=stick[i];
			visited[i]=1;
			if(sum>len)
				sum-=stick[i];
			if(sum==len)
				return 1;
			else
				return search(visited,stick,len,sum,n);
		}
	}
	return flag;
}

qsort(ss, 70, sizeof(ss[0]), cmp);