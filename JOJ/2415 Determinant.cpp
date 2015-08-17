/*
#include <iostream>
using namespace std;
int main()
{
	int i,j,k,n;
	long long rel,sum;
	long long arr[10][10]; 
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>arr[i][j];
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==1)
		{
			if(arr[0][0]>0)
				cout<<arr[0][0]<<endl;
			else
				cout<<-arr[0][0]<<endl;
			continue;
		}
		else
		{
			if(n==2)
			{
				rel=arr[1][1]*arr[0][0]-arr[1][0]*arr[0][1];
				if(rel>0)
					cout<<rel<<endl;
				else
					cout<<-rel<<endl;
				continue;
			}
		}
		rel=0;
		for(j=0;j<n;j++)
		{
			sum=1;
			for(k=0;k<n;k++)
				sum*=arr[k][((j+k)%n)];
			rel+=sum;
		}
		for(j=n-1;j>=0;j--)
		{
			sum=1;
			for(k=0;k<n;k++)
				sum*=arr[k][((j-k+n)%n)];
				sum=-sum;
			rel+=sum;
		}
		if(rel<0)
			cout<<-rel<<endl;
		else
			cout<<rel<<endl;
	}
	return 0;
}
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long long fun(long long a,long long b);
	int i,j,l,n;
	long long arr[10][10][2],temp,k1,k2,s,b;
	long double rel;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				cin>>arr[i][j][0];
				arr[i][j][1]=1;
			}
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		}

		for(i=0;i<n-1;i++)
		{
			if(arr[i][i][0]==0)
				for(j=i+1;j<n;j++)
					if(arr[j][i][0]!=0)
					{
						for(l=i;l<n;l++)
						{
							temp=arr[i][l][0];
							arr[i][l][0]=arr[j][l][0];
							arr[j][l][0]=temp;
							temp=arr[i][l][1];
							arr[i][l][1]=arr[j][l][1];
							arr[j][l][1]=temp;
						}
						break;
					}
			if(arr[i][i][0]==0)
				break;

			for(j=i+1;j<n;j++)
			{
				k1=arr[i][i][1]*arr[j][i][0];
				k2=arr[i][i][0]*arr[j][i][1];
				for(l=i+1;l<n;l++)
				{
					arr[j][l][0]=arr[j][l][0]*arr[i][l][1]*k2-arr[j][l][1]*arr[i][l][0]*k1;
					arr[j][l][1]=arr[i][l][1]*k2*arr[j][l][1];
					if(arr[j][l][0]>arr[j][l][1])
					{
						s=arr[j][l][1];
						b=arr[j][l][0];
					}
					else
					{
						s=arr[j][l][0];
						b=arr[j][l][1];
					}
					if(s)
					{
						temp=fun(b,s);
						s/=temp;
						b/=temp;
					}
				}
			}
		}
		k1=1;k2=1;
		for(i=0;i<n;i++)
		{
			k1*=arr[i][i][0];
			k2*=arr[i][i][1];
		}
		if(k1>k2)
		{
			b=k1;s=k2;
		}
		else
		{
			b=k2;s=k1;
		}
		if(s)
		{
			temp=fun(b,s);
			b/=temp;
			s/=temp;
		}
		rel=b;
		rel/=s;
		cout.setf(ios::fixed);
		cout.precision(30);
		cout<<fabs(rel)<<endl;
	}
	return 0;
}


long long fun(long long a,long long b)
{
	if(b)
		return fun(b,a%b);
	else
		return a;
}

