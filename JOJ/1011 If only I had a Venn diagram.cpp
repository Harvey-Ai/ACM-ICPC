/*
#include <iostream>
using namespace std;
int main()
{
	int set[100],temp;
	int N,n,i,j,k;
	bool flag;
	cin>>N;
	while(N--)
	{
		n=0;flag=0;
		while((cin>>set[n++],set[n-1]))
	
		for(i=0;i<=n-1;i++)
			for(j=i+1;j<=n-1;j++)
				if(set[i]>set[j])
				{
					temp=set[i];
					set[i]=set[j];
					set[j]=temp;
				}
		n=n-2;k=n;
		while((cin>>temp,temp))
		{
			for(i=0;temp>set[i]&&i<=k;i++);
			if(temp==set[i])
				set[i]=0;
			else
			{
				n++;
				set[n]=temp;
			}
		}
		for(i=0;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(set[i]>set[j])
				{
					temp=set[i];
					set[i]=set[j];
					set[j]=temp;
				}
		cout<<"{";

		for(i=0;i<=n;i++)
		{
			if(set[i])
			{
				if(flag)
					cout<<",";
				else
					flag=1;
				cout<<set[i];
			}
		}
		cout<<"}"<<endl;
	}
	return 0;
}
*/
#include <iostream>
using namespace std;
int main()
{
	int set[100],temp;
	int n,i,j,count,N;
	bool flag;
	cin>>N;
	while(N--)
	{
		count=0;i=-1;
		while(count<2)
		{
			cin>>set[++i];
			if(set[i]==0)
				count++;
		}
		n=i-1;
		for(i=0;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(set[i]>set[j])
				{
					temp=set[i];
					set[i]=set[j];
					set[j]=temp;
				}
		i=1;flag=0;cout<<"{";
		while(i<=n)
		{
			if(set[i]==set[i+1])
				i+=2;
			else
			{
				if(flag)
					cout<<",";
				else
					flag=1;
				cout<<set[i];
				i++;
			}
		}
		cout<<"}"<<endl;
	}
	return 0;
}


			
