#include <iostream>
using namespace std;
int main()
{
	long n;
	int k,i,rel;
	while(cin>>n)
	{
		for(i=3;i>=0;i--)
		{
			rel=n%256;
			n/=256;
			cout<<char(rel);
		}
	}
	return 0;
}