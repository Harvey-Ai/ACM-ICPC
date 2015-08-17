#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	bool prime(long k);
	bool flag;
	long i,j,sum,temp,m,n;
	long arr[2000][2];
	while(cin>>n>>m)
	{
		flag=1;
		if(n==0)
		{
			if(m==1)
				flag=1;
			else
				flag=0;
		}
		if(m==0)
			flag=0;
		if(m>n)
		{
			memset(arr,0,sizeof(arr));
			j=0;temp=m;
			while(temp%2==0)
			{
			arr[j][0]=2;
			arr[j][1]++;
			temp/=2;
			}
			if(arr[j][0])
				j++;
			for(i=3;i*i<=m;i+=2)
			{
				if(prime(i))
				{
					while(temp%i==0)
					{
						arr[j][0]=i;
						arr[j][1]++;
						temp/=i;
					}
					if(arr[j][0])
						j++;
				}
				if(temp==1)
					break;
			}
			if(temp!=1)
			{
				arr[j][0]=temp;
				arr[j][1]=1;
				j++;
			}
			for(i=0;i<j;i++)
			{
				sum=0;temp=arr[i][0];
				while(temp<=n)
				{
					sum+=n/temp;
					temp*=arr[i][0];
				}
				if(sum<arr[i][1])
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
			cout<<m<<" divides "<<n<<"!"<<endl;
		else
			cout<<m<<" does not divide "<<n<<"!"<<endl;
	}
	return 0;
}


bool prime(long k)
{
	int i;
	bool flag=1;
	if(k%2==0)
		return 0;
	for(i=3;i*i<=k;i+=2)
		if(k%i==0)
		{
			flag=0;
			break;
		}
	if(flag)
		return 1;
	else
		return 0;
}





