#include <iostream>
using namespace std;
int main()
{
	void horizontal1(int dig[],int s,int n);
	void horizontal2(int dig[],int s,int n);
	void horizontal3(int dig[],int s,int n);
	void vertica1(int dig[],int s,int n);
	void vertica2(int dig[],int s,int n);
	int s,n,dig[30],i;
	while(cin>>s>>n,s||n)
	{
		i=0;
		while(n!=0)
		{
			dig[i++]=n%10;
			n/=10;
		}
		horizontal1(dig,s,i-1);
		vertica1(dig,s,i-1);
		horizontal2(dig,s,i-1);
		vertica2(dig,s,i-1);
		horizontal3(dig,s,i-1);
		cout<<endl;
	}
	return 0;
}

void horizontal1(int dig[],int s,int n)
{	
	int i,j;
	for(i=n;i>=0;i--)
	{
		if(dig[i]==1||dig[i]==4)
		{
			for(j=1;j<=s+2;j++)
				cout<<" ";
		}
		else
		{
			cout<<" ";
			for(j=1;j<=s;j++)
				cout<<"-";
			cout<<" ";
		}
		if(i!=0)
			cout<<" ";
	}
	cout<<endl;
}

void horizontal2(int dig[],int s,int n)
{	
	int i,j;
	for(i=n;i>=0;i--)
	{
		if(dig[i]==1||dig[i]==7||dig[i]==0)
		{
			for(j=1;j<=s+2;j++)
				cout<<" ";
		}
		else
		{
			cout<<" ";
			for(j=1;j<=s;j++)
				cout<<"-";
			cout<<" ";
		}
		if(i!=0)
			cout<<" ";
	}
	cout<<endl;
}

void horizontal3(int dig[],int s,int n)
{	
	int i,j;
	for(i=n;i>=0;i--)
	{
		if(dig[i]==1||dig[i]==4||dig[i]==7)
		{
			for(j=1;j<=s+2;j++)
				cout<<" ";
		}
		else
		{
			cout<<" ";
			for(j=1;j<=s;j++)
				cout<<"-";
			cout<<" ";
		}
		if(i!=0)
			cout<<" ";
	}
	cout<<endl;
}
void vertica1(int dig[],int s,int n)
{
	int i,j,l;
	for(l=1;l<=s;l++)
	{
		for(i=n;i>=0;i--)
		{
			if(dig[i]==0||dig[i]==4||dig[i]==5||dig[i]==6||dig[i]==8||dig[i]==9)
			{
				cout<<"|";
				for(j=1;j<=s;j++)
					cout<<" ";
			}
			if(dig[i]==4||dig[i]==8||dig[i]==9||dig[i]==0)
				cout<<"|";
			else
				cout<<" ";
			if(dig[i]==2||dig[i]==3||dig[i]==7||dig[i]==1)
			{
				for(j=1;j<=s;j++)
					cout<<" ";
				cout<<"|";
			}
			if(i!=0)
				cout<<" ";
		}
		cout<<endl;
	}
}

void vertica2(int dig[],int s,int n)
{
	int i,j,l;
	for(l=1;l<=s;l++)
	{
		for(i=n;i>=0;i--)
		{
			if(dig[i]==2||dig[i]==6||dig[i]==8||dig[i]==0)
			{
				cout<<"|";
				for(j=1;j<=s;j++)
					cout<<" ";
			}
			if(dig[i]==8||dig[i]==0||dig[i]==6)
				cout<<"|";
			else
				cout<<" ";
			if(dig[i]==3||dig[i]==4||dig[i]==5||dig[i]==7||dig[i]==9||dig[i]==1)
			{
				for(j=1;j<=s;j++)
					cout<<" ";
				cout<<"|";
			}
			if(i!=0)
				cout<<" ";
		}
		cout<<endl;
	}
}






					



