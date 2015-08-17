#include <iostream>
using namespace std;
int main()
{
	bool prime(long long m);
	long long i,n,rel;
	while(cin>>n,n)
	{
		rel=n;
		while(n%2==0)
			n/=2;
		if(rel>n)
			rel/=2;
		for(i=3;i*i<=n;i+=2)
		{
			if(n%i==0)
				if(prime(i))
				{
					rel*=i-1;
					rel/=i;
				}
			while(n%i==0)
				n/=i;
		}
		if(n!=1)
		{
			rel*=(n-1);
			rel/=n;
		}
		cout<<rel<<endl;
	}
	return 0;
}


bool prime(long long m)
{
	long long i;
	if(m%2==0)
		return 0;
	for(i=3;i*i<=m;i+=2)
		if(m%i==0)
			return 0;
	return 1;
}

