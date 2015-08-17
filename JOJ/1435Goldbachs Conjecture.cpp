#include <iostream>
using namespace std;
int prime[3600];
bool a[32770];
int b[32770]={0};
int main()
{
	int i,j,k,n,temp;
	for(i=1;i<=32769;i++)
		a[i]=1;

	i=2;
	while(i<=17000)
	{
		j=2;
		while(i*j<32769)
		{
			a[i*j]=0;
			j++;
		}
		while(a[++i]==0){}
	}
	
	k=1;
	for(i=2;i<=32769;i++)
		if(a[i]!=0)
			prime[k++]=i;

	for(i=1;i<=k-1;i++)
		for(j=i;j<=k-1;j++)
		{
			temp=prime[i]+prime[j];
			if(temp<=32770)
				b[temp]++;
		}

	while(cin>>n,n)
		cout<<b[n]<<endl;
	return 0;
}