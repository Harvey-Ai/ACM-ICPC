/*
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	bool sh(int p[21],int q[21],int n,int s,int sum);
	int i,n,m;
	int p[21],q[21];
	while(cin>>n>>m)
	{
		for(i=0;i<n;i++)
			cin>>p[i];
		for(i=0;i<n;i++)
			cin>>q[i];
		sort(&p[0],&p[n]);
		sort(&q[0],&q[n]);
		if(sh(p,q,n,m,0))
			cout<<"Possible"<<endl;
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}


bool sh(int p[21],int q[21],int n,int s,int sum)
{
	int i,j,temp1,temp2,temp;
	bool flag=1;

	for(i=0;i<n;i++)
		if(p[i])
		{
			for(j=0;j<n;j++)
				if(q[j])
				{
					temp1=p[i];temp2=q[j];
					sum+=p[i]*q[j];
					p[i]=0;q[j]=0;
					if(sum>=s&&i!=n-1)
						break;
					if(sum<=s)
						flag=sh(p,q,n,s,sum);
					q[j]=temp2;p[i]=temp1;
					sum-=temp1*temp2;
					temp=temp1*temp2;
					if(flag)
						return 1;
				}
		}
	for(i=0;i<n;i++)
		if(p[i]&&q[i])
		{
			flag=0;
			break;
		}
	if(flag&&sum==s)
		return 1;
	else
		return 0;
}
*/	

#include <iostream>
#include <algorithm>
using namespace std;
int cmp(const void *p,const void *q)
{        
	return *(int *)p - *(int *)q;
}
int main()
{
	bool sh(long value[21][21],int i,int n,int s,int sum);
	int i,j,n,m;
	long p[21],q[21],value[21][21];
	while(cin>>n>>m)
	{
		for(i=0;i<n;i++)
			cin>>p[i];
		for(i=0;i<n;i++)
		{
			cin>>q[i];
			for(j=0;j<n;j++)
				value[i][j]=q[i]*p[j];
		}
		for(i=0;i<n;i++)
			qsort(value[i],n,sizeof(value[i][0]),cmp);
		if(sh(value,0,n,m,0))
			cout<<"Possible"<<endl;
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}


bool sh(int value[21][21],int i,long n,int s,long sum)
{
	int temp,j;
	bool flag;
	if(i<n)
	{
	for(j=0;j<n;j++)
	{
		if(value[i][j])
		{
			sum+=value[i][j];
			temp=value[i][j];
			value[i][j]=0;
			if(sum>s)
				break;
			else
				flag=sh(value,i+1,n,s,sum);
			if(flag)
				break;
			value[i][j]=temp;
			sum-=temp;
		}
	}
	}
	if(sum==s&&i==n||flag)
		return 1;
	else
		return 0;
}
		
		
		

