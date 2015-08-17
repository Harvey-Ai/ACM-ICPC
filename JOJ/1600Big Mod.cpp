#include <iostream>
using namespace std;
int main()
{
	long b,p,m,n;
	while(cin>>b>>p>>m)
	{
		b=b%m;n=1;
		while(p)
		{
			if(p%2)
			{
				n*=b;
				n=n%m;
			}
			b=(b*b)%m;
			p/=2;
		}
		cout<<n%m<<endl;
	}
	return 0;
}