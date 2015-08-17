/*
#include <iostream>
using namespace std;
int main()
{
	int n,sum,i,j;
	int m[1000000];
	bool flag;
	while(cin>>n>>sum)
	{
		flag=0;
		for(i=1;i<=n;i++)
			cin>>m[i];
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
				if(m[i]+m[j]==sum)
				{
					flag=1;
					break;
				}
			}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int m[1000000];
int main()
{
	
	int n,sum,temp,s,i,j,l,k;
	bool flag;
	while(cin>>n>>sum)
	{
		flag=0;
		for(i=1;i<=n;i++)
			cin>>m[i];
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(m[j]<m[i])
				{
					temp=m[i];
					m[i]=m[j];
					m[j]=temp;
				}
		for(k=n;k>=1;k--)
		{
			s=m[k];
			if(s<sum/2)
				break;
			for(l=1;l<=n;l++)
			{
				s+=m[l];
				if(s>sum)
					break;
				else
					if(s==sum)
					{
						flag=1;
						break;
					}
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int n,sum,N,i;
	bool m[1000000000];
	bool flag;
	while(cin>>N>>sum)
	{
		for(i=0;i<=999999999;i++)
			m[i]=0;
		flag=0;
		for(i=1;i<=N;i++)
		{
			cin>>n;
			if(m[n]==1)
			{
				flag=1;
				break;
			}
			else
				m[sum-n]=1;
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
*/

#include <iostream>
#include <algorithm>
using namespace std;
int m[1000001];
int main()
{
	int n,sum,temp,i;
	int top,lev;
	bool flag;
	while(cin>>n>>sum)
	{
		flag=0;top=0;lev=n-1;
		for(i=0;i<=n-1;i++)
			cin>>m[i];
		sort(&m[0],&m[n]);
		temp=m[0]+m[n-1];
		while(lev>top)
		{
			if(temp==sum)
			{
				flag=1;
				break;
			}
			else
			if(temp>sum)
				lev--;
			else
				top++;
			temp=m[top]+m[lev];
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}





