/*
#include <iostream>
using namespace std;
int arr[1000][1000];
int main()
{
	int x,n,i,j,k;
	bool flag;
	while(cin>>x>>n)
	{
		for(i=0;i<1000;i++)
			for(j=0;j<1000;j++)
				arr[i][j]=-1;
		arr[0][0]=x;i=0;flag=1;
		while(flag)
		{
			j=0;k=0;
			while(arr[i][j]!=-1&&arr[i][j])
			{
				arr[i+1][k]=(arr[i][j]*2)%n;
				arr[i+1][k+1]=(arr[i][j]+1)%n;
				k+=2;j++;
			}
			if(arr[i][j]==0)
				flag=0;
			i++;
		}
		cout<<i-1<<endl;
	}
	return 0;
}
*/
#include<iostream>
#include<math.h>
using namespace std;
bool arr[1000050];
int buffer[1000050];
int main()
{
	int step,x,n,i,j,k,y,temp;
	bool flag;
	while(cin>>x>>n)
	{
		if(x>n)
			x%=n;
		if(x==0)
		{
			cout<<0<<endl;
			continue;
		}
		memset(arr,0,sizeof(arr));
		buffer[0]=x;
		i=0;j=1;step=0;flag=1;
		while(i<j)
		{
			k=j;
			for(;i<k;i++)
			{
				y=buffer[i];
				temp=(y*2);
				if(temp>=n)
					temp%=n;
				if(temp==0)
				{
					flag=0;
					break;
				}
				if(!arr[temp])
				{
					arr[temp]=1;
					buffer[j++]=temp;
				}

				temp=(y+1);
				if(temp>=n)
					temp%=n;
				if(temp==0)
				{
					flag=0;
					break;
				}
				if(!arr[temp])
				{
					arr[temp]=1;
					buffer[j++]=temp;
				}
			}
			if(flag==0)
				break;
			step++;
		}
		cout<<step<<endl;
	}
	return 0;
}
#include<iostream>
#include<math.h>
using namespace std;
bool arr[1000050];
int buffer[1000050];
int main()
{
	int step,x,n,i,j,k,y,temp;
	while(cin>>x>>n)
	{
		if(x>n)
			x%=n;
		if(x==0)
		{
			cout<<0<<endl;
			continue;
		}
		memset(arr,0,sizeof(arr));
		buffer[0]=x;
		i=0;j=1;step=1;
		while(i<j)
		{
			k=j;
			for(;i<k;i++)
			{
				y=buffer[i];
				temp=(y*2);
				if(temp>=n)
					temp%=n;
				if(temp==0)
					goto out;
				if(!arr[temp])
				{
					arr[temp]=1;
					buffer[j++]=temp;
				}

				temp=(y+1);
				if(temp>=n)
					temp%=n;
				if(temp==0) 
					goto out;
				if(!arr[temp])
				{
					arr[temp]=1;
					buffer[j++]=temp;
				}
			}
			step++;
		}
out:
		cout<<step<<endl;
	}
	return 0;
}