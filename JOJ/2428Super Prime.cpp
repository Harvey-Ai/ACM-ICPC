#include <iostream>
using namespace std;
int main()
{
	bool check(long n);
	bool flag;
	long prime[1000],dig,temp;
	int i,k;
	prime[0]=1;prime[1]=3;k=0;
	for(i=5;i<=1e+9;i+=2)
	{
		temp=10;flag=1;
		while(i/temp)
		{
			dig=i%temp;
			if(check(temp)==0)
			{
				flag=0;
				break;
			}
			temp*=10;
		}
		if(check(temp)==0)
			flag=0;
		if(flag)
			prime[k++]=i;
	}
	while(cin>>i)
		cout<<prime[i-1]<<endl;
	return 0;
}




bool check(long n)
{
	int i;
	for(i=3;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}